/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <list>
using namespace std;

class Environment {
  
private:
  map<unsigned int, class Value *> env;
  
  inline void replace(unsigned int a, class Value *b=NULL){
    map<unsigned int, class Value *>::iterator i=env.find(a);
    if (i==env.end()){
      env.insert ( pair <unsigned int, class Value *>(a, b) );
    }else{
      i->second = b;
    }
  }

public:
  
  Environment(){
    NEW("Environment");
  }

  ~Environment(){
    env.clear();
    DELETE("Environment");    
  }

  void add(bitset<MAXBITS> a, class Value *b=NULL){
    replace (bitsToInt(a), b);
  }
  void add(unsigned int i, class Value *b=NULL){
    replace(i, b);
  }
  void add(class Environment *e){
    for (map<unsigned int, class Value *>::const_iterator i=e->begin(); i!=e->end(); i++)
      replace(i->first, i->second);
  }
  void add(class Environment *e, class Environment *where){
    if (where)
      for (map<unsigned int, class Value *>::const_iterator i=e->begin(); i!=e->end(); i++)
	if (where->env.find(i->first)!=where->env.end())
	  replace(i->first, i->second);
  }
  
  inline map<unsigned int, class Value *>::const_iterator begin(){return env.begin();}
  inline map<unsigned int, class Value *>::const_iterator end(){return env.end();}
  inline unsigned int size(){return env.size();}

  void print(ostream&);
  class Environment *copy(void);
  class Value *_find(bitset<MAXBITS>);
  class Value *_find(unsigned int);
  bool exists(bitset<MAXBITS>);
  bool exists(unsigned int);
  class Value *replaceVariables(class Value *);
  void replaceVariables(class Features *);
  void replaceVariables(class List *);
};
#endif // ENVIRONMENT_H
