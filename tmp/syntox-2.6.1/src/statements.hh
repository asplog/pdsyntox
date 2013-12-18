/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <list>
#include "flags.hh"
#include "statement.hh"
#include "gitem.hh"

class Statements {
  
private:
  static unsigned int uniqId;
  unsigned int id;
  list<class Statement *> statements;
  
 public:

  Statements(void){  
    NEW("Statements"); 
    this->id=uniqId++;
  }
  
  Statements(class Statement *statement){
    NEW("Statements");
    this->statements.push_front(statement);
    this->id=uniqId++;
  }
  
  ~Statements();

  inline unsigned int getId(void){return id;}
  inline list<class Statement *> &getStatements(void){return this->statements;} 

  inline size_t size(void){return this->statements.size();}
  inline list<class Statement*>::iterator begin(void){return this->statements.begin();}
  inline list<class Statement*>::iterator end(void){return this->statements.end();}

  void addStatement(class Statement *);
  void addStatement(class Statement *, class Environment *);
  void customizeVariables(unsigned int=0);
  void print(ostream&, int=0);
  class Statements *copy(const bitset<NBRFLAGS>&savedFlags);
  bool exists(class Environment *);
  void order(class Gitem *, class Synthesizer *);
  bool apply(Synthesizer *synthesizer, class GitemSet *state, class Gitem*, bool *modification);

#ifdef OUTPUT_STATEMENT_DOT
  void dot(std::ostream&, unsigned int, string ="");
#endif
};

#endif // STATEMENTS_H
