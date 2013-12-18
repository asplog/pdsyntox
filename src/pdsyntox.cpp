#include<unistd.h>
#include<fcntl.h>
#include"pdsyntox.h"
#include"synthesizer.hh"
#include"bits.hh"
#include"vartable.hh"

#include<list>
#include<string>
#include<iostream>

t_class*pdsyntox_class=0;
t_symbol*s_pdsyntox=0;
t_symbol*s_grammar=0;
t_symbol*s_lexicon=0;
t_symbol*s_add=0;
t_symbol*s_load=0;
t_symbol*s_clear=0;
t_symbol*s_input=0;
t_symbol*s_remove=0;

pthread_mutex_t engine_locker = PTHREAD_MUTEX_INITIALIZER;
typedef struct
{
	pdsyntox_t*	self;
	pthread_cond_t*	broad;
	char*		input;
	char*		grammar;
	char*		lexicon;
	std::list<std::string>*l;
	std::list<std::string>*g;
}
args_t;
void dump(pdsyntox_t*self,const char*message)
{
	post(message);
	outlet_bang(self->out[3]);
}
void*invoke(void*args)
{
	pdsyntox_t*self=((args_t*)args)->self;
	char*input=strcpy((char*)malloc(strlen(((args_t*)args)->input)),((args_t*)args)->input);	
	char*grammar=strcpy((char*)malloc(strlen(((args_t*)args)->grammar)),((args_t*)args)->grammar);	
	char*lexicon=strcpy((char*)malloc(strlen(((args_t*)args)->grammar)),((args_t*)args)->lexicon);	
	pthread_cond_broadcast(((args_t*)args)->broad);
	{
		static pthread_mutex_t engine_locker=PTHREAD_MUTEX_INITIALIZER;
		switch(pthread_mutex_trylock(&engine_locker))
		{
			case 0:
				{
					extern class Synthesizer synthesizer;
					bitsInit();
					varTableInit();
					synthesizer.parseLexicon(lexicon);
					synthesizer.parseGrammar(grammar);
					try
					{
						std::list<std::string>*gens=synthesizer.parseInput(input);
						std::list<std::string>::iterator cur=gens->begin();
						sys_lock();
						while(cur!=gens->end())
							outlet_symbol(self->out[0],gensym((cur++)->c_str()));
						sys_unlock();
					}
					catch(std::string msg)
					{
						
					}
				}
				pthread_mutex_unlock(&engine_locker);
				break;
			case EBUSY:
				{
					sys_lock();
					dump(self,(char*)"Syntox engine is currently used");
					sys_unlock();
				}
				break;
		}
	}
	free(lexicon);
	free(grammar);
	free(input);
	return 0;
}
void submit(pdsyntox_t*self,char*input,char*grammar,char*lexicon)
{
	pthread_t	worker={0};
	pthread_mutex_t	lock=PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t	cond=PTHREAD_COND_INITIALIZER;
	args_t	args={self,&cond,input,grammar,lexicon};
	pthread_create(&worker,0,invoke,&args);
	pthread_cond_wait(&cond,&lock);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&lock);
}
int combin(int fd,const int argc,t_atom*argv)
{
	register int	sum=0;
	for(register unsigned int k=1,K=argc;k<K;++k)
	{
		register const char*p=atom_getsymbol(argv+k)->s_name;
		while(*p)
			sum+=write(fd,p++,1);
		sum+=write(fd," ",1);
	}
	sum+=write(fd,"\0",1);
	return sum;
}
void*pdsyntox_new()
{
	pdsyntox_t*self=(pdsyntox_t*)pd_new(pdsyntox_class);

	self->out[0]=outlet_new(&self->super,&s_);
	self->out[1]=outlet_new(&self->super,&s_);
	self->out[2]=outlet_new(&self->super,&s_);
	self->out[3]=outlet_new(&self->super,&s_bang);
	
	self->in[0]=inlet_new(&self->super,&self->super.ob_pd,s_grammar,s_grammar);
	self->in[1]=inlet_new(&self->super,&self->super.ob_pd,s_lexicon,s_lexicon);

	self->g=new std::list<std::string>;
	self->l=new std::list<std::string>;

	return self;
}
void parseArgs(pdsyntox_t*self,std::list<std::string>*target,t_symbol*message,int argc,t_atom*argv)
{
	t_symbol*method=atom_getsymbol(argv+0);
	if(method==s_clear)
		target->clear();
	else if(method==s_add)
	{
		if(1<argc)
		{
			register int cache[2],sum;
			pipe(cache);
			sum=combin(cache[1],argc,argv);
			close(cache[1]);
			{
				char*buf=(char*)calloc(sum+1,1);;
				read(cache[0],buf,sum);
				self->g->push_back(buf);
				free(buf);
			}
			close(cache[0]);
		}
		else dump(self,"No input");
	}
	else if(method==s_load)
	{
		if(1<argc)
		for(register int k=1,K=argc;k<K;++k)
		{
			int fd=open(atom_getsymbol(argv+k)->s_name,O_RDONLY);
			if(0<fd)
			{
				size_t size=lseek(fd,0,SEEK_END);
				if(0<size)
				{
					char*buf=(char*)calloc(size+1,1);
					lseek(fd,0,SEEK_SET);
					read(fd,buf,size);
					target->push_back(buf);
					free(buf);
				}
				else dump(self,"No data");
				close(fd);
			}
			else dump(self,"No file found");
		}
		else dump(self,"No input");
	}
	else if(method==s_remove)
	{
		if(1<argc)
		{
			register int cache[2],sum;
			pipe(cache);
			sum=combin(cache[1],argc,argv);
			close(cache[1]);
			{
				char*buf=(char*)calloc(sum+1,1);;
				read(cache[0],buf,sum);
				self->g->push_back(buf);
				free(buf);
			}
			close(cache[0]);	
		}
		else dump(self,"No input");
	}
	else if(self->g->empty())
		dump(self,"No rule exists");
	else for(register list<string>::iterator cur=target->begin(),end=target->end();cur!=end;++cur)
		outlet_symbol(self->out[1],gensym(cur->c_str()));
}
void pdsyntox_parse(pdsyntox_t*self,char*input)
{
	if(!input)dump(self,"xyz");
	else if(self->l->empty())dump(self,"No lexicon rules found");
	else if(self->g->empty())dump(self,"No grammar rules found");
	else 
	{
		char*grammar=0;
		char*lexicon=0;
		{
			using namespace std;
			int cache[2],sum=0;
			pipe(cache);
			for(register list<string>::iterator cur=self->g->begin(),end=self->g->end();cur!=end;++cur)
				sum+=write(cache[1],cur->c_str(),cur->size());
			close(cache[1]);
			grammar=(char*)calloc(sum+1,1);
			read(cache[0],grammar,sum);
			close(cache[0]);
		}
		{
			using namespace std;
			int cache[2],sum=0;
			pipe(cache);
			for(register list<string>::iterator cur=self->l->begin(),end=self->l->end();cur!=end;++cur)
				sum+=write(cache[1],cur->c_str(),cur->size());
			close(cache[1]);
			lexicon=(char*)calloc(sum+1,1);
			read(cache[0],lexicon,sum);
			close(cache[0]);
		}
		submit(self,input,grammar,lexicon);
		if(lexicon)free(lexicon);
		if(grammar)free(grammar);
	}
}
void pdsyntox_inp(pdsyntox_t*self,t_symbol*message,int argc,t_atom*argv)
{	
	register int cache[2],sum;
	pipe(cache);
	sum=combin(cache[1],argc,argv);
	close(cache[1]);
	{
		char*input=(char*)calloc(sum+1,1);;
		read(cache[0],input,sum);
		pdsyntox_parse(self,input);
		free(input);
	}
	close(cache[0]);
}
void pdsyntox_ild(pdsyntox_t*self,t_symbol*message,int argc,t_atom*argv)
{
	if(argc<1)dump(self,"No input");
	else for(register unsigned int k=0,K=argc;k<K;++k)
	{
		register int fd = open(atom_getsymbol(argv+k)->s_name,O_RDONLY);
		if(0<fd)
		{
			size_t size=lseek(fd,0,SEEK_END);
			if(0<size)
			{
				char*buf=(char*)calloc(size+1,1);
				lseek(fd,0,SEEK_SET);
				read(fd,buf,size);
				pdsyntox_parse(self,buf);
				free(buf);
			}
			close(fd);
		}
		else dump(self,"No file found");
	}
}
void pdsyntox_grm(pdsyntox_t*self,t_symbol*message,int argc,t_atom*argv)
{
	parseArgs(self,self->g,message,argc,argv);
}
void pdsyntox_lex(pdsyntox_t*self,t_symbol*message,int argc,t_atom*argv)
{
	parseArgs(self,self->l,message,argc,argv);
}
void pdsyntox_del(pdsyntox_t*self)
{
	delete self->l;
	delete self->g;

	inlet_free(self->in[1]);
	inlet_free(self->in[0]);

	outlet_free(self->out[3]);
	outlet_free(self->out[2]);
	outlet_free(self->out[1]);
	outlet_free(self->out[0]);
}
void pdsyntox_dump(pdsyntox_t*self)
{
	/*
	char	input[16384]={0};
	char	grammar[16384]={0};
	char	lexicon[16384]={0};
	{
		int	fd=open("etc/test.input",O_RDONLY);
		if(0<fd)
		{
			read(fd,input,sizeof(input));
			close(fd);
		}
	}

	{
		int	fd=open("etc/test.grammar",O_RDONLY);
		if(0<fd)
		{
			read(fd,grammar,sizeof(grammar));
			close(fd);
		}
	}

	{
		int	fd=open("etc/test.lexicon",O_RDONLY);
		if(0<fd)
		{
			read(fd,lexicon,sizeof(lexicon));
			close(fd);
		}
	}
	{
		submit(self,input,grammar,lexicon);
	}
	*/
}
extern"C"void pdsyntox_setup()
{
	s_pdsyntox=gensym("pdsyntox");
	s_grammar=gensym("grammar");
	s_lexicon=gensym("lexicon");
	s_add=gensym("add");
	s_load=gensym("load");
	s_clear=gensym("clear");
	s_input=gensym("input");
	s_remove=gensym("remove");

	pdsyntox_class=class_new
	(
		s_pdsyntox,
		(t_newmethod)pdsyntox_new,
		(t_method)pdsyntox_del,
		sizeof(pdsyntox_t),
		CLASS_DEFAULT,
		A_NULL,
		0
	);
	class_addmethod(pdsyntox_class,(t_method)pdsyntox_dump,gensym("dump"),A_NULL,0);

	class_addmethod(pdsyntox_class,(t_method)pdsyntox_ild,s_load,A_GIMME,0);
	class_addmethod(pdsyntox_class,(t_method)pdsyntox_inp,s_input,A_GIMME,0);
	class_addmethod(pdsyntox_class,(t_method)pdsyntox_grm,s_grammar,A_GIMME,0);
	class_addmethod(pdsyntox_class,(t_method)pdsyntox_lex,s_lexicon,A_GIMME,0);

}

