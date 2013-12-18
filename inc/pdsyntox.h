#include<string>
#include<list>
#include"m_pd.h"
#include"pthread.h"
typedef struct
{
	t_object	super;
	t_outlet*	out[4];
	t_inlet*	in[2];
	
	std::list<std::string>*l;
	std::list<std::string>*g;
}
pdsyntox_t;

void*pdsyntox_new();
void pdsyntox_del(pdsyntox_t*);
void pdsyntox_dump(pdsyntox_t*);
extern"C"void pdsyntox_setup();
