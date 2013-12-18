/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef STATEMENT_H
#define STATEMENT_H

#include <vector>
#include <bitset>
#include <string>

#include "flags.hh"
#include "errors.hh"
#include "bits.hh"
#include "statement.hh"
#include "enum.hh"
#include "value.hh"

class Statement: 
  public Flags {

public:

typedef enum {
  DOLLAR,
  AFF,
  SUBSET,
  UP,
  UP2,
  DOWN,
  DOWN2,
  FEATURES,
  VARIABLE,
  CONSTANT,
  NIL,
  TRUE,
  UNIF,
  FILTER,
  TRACE,
  DOLLARS,
  ORDER,
  TEST,
  IF,
  THEN,
  STMS,
  STR,
  LIST,
  SORT,
  NUMBER,
  FCT,
  FINISHED
} statementop;

typedef enum {
  NOT, AND, OR, EQUAL, LT, LE, GT, GE, PLUS, MINUS, TIMES, DIVIDE, MODULO, MINUS_U,
  ABS
} statementfct;

union EQVALUE {
  struct pair {
    unsigned int first;
    unsigned int second;
  } slots;
  bitset<MAXBITS> *bits;
  string *str;
  statementfct fct;
  class Features *features;
  class List *list;
  class Statements *statements;
  float number;
};
  
 private:
  static unsigned int uniqId;
  unsigned int id;
  statementop op;
  class Statement *lhs;
  class Statement *rhs;
  union EQVALUE slots;
  string sign;

public:
  
  Statement (statementop op, class Statement *lhs=NULL, class Statement *rhs=NULL);
  Statement (statementop op, class Statement *lhs, class Statement *rhs, union EQVALUE slots);
  Statement (statementop op, unsigned int first, unsigned int second=UINT_MAX);
  Statement (statementop op, class Features *features);
  Statement (statementop op, class Value *value);
  Statement (statementop op, bitset<MAXBITS> *bits);
  Statement (statementop op, string *str);
  Statement (statementop op, statementfct fct, class Statement *lhs=NULL, class Statement *rhs=NULL);
  Statement (class List *);
  Statement (class Statements *);
  Statement (float);
  Statement (void);
  ~Statement (void);
  
  inline unsigned int getId(void){return id;}
  inline statementop getOp(void){return this->op;} 
  inline statementfct getFct(void){return slots.fct;}
  inline void putOp(statementop op){this->op=op;} 
  inline class Statement *getLhs(void){return lhs;}
  inline void putLhs(class Statement *rhs){this->lhs=lhs;}
  inline class Statement *getRhs(void){return rhs;}
  inline void putRhs(class Statement *rhs){this->rhs=rhs;}
  inline class Features *getFeatures(void){return slots.features;}
  inline void putFeatures(class Features *features){this->slots.features=features;}
  inline bitset<MAXBITS> *getBits(void){return slots.bits;}
  inline void putBits(bitset<MAXBITS> *bits){this->slots.bits=bits;}
  inline unsigned int getFirst(void){return slots.slots.first;}
  inline unsigned int getSecond(void){return slots.slots.second;}
  inline void putSecond(unsigned int second){slots.slots.second=second;}
  inline string *getStr(void){return slots.str;}
  inline class List *getList(void){return slots.list;}
  inline void putList(class List *list){this->slots.list=list;}
  inline class Statements *getStatements(void){return this->slots.statements;}
  inline float getNumber(void){return this->slots.number;}
  
  void print(ostream&, int=0);
  class Features *evalFeatures(class Gitem*, bool);
  class List *evalList(class Gitem *, bool);
  class Value *evalValue(class Gitem*, bool);
  class Features *unif(class Features *, class Features *, class Gitem *);
  class Statement *copy(const bitset<NBRFLAGS> &savedFlags);
  void buildInheritedSonFeatures(class Gitem *, class Statement *, class Synthesizer *);
  void buildSynthesizeFeatures(class Gitem *, class Statement *, class Synthesizer *);
  void buildEnvironmentWithInherited(class Gitem *, class Statement *, class Synthesizer *);
  void buildEnvironmentWithSynthesize(class Gitem *, class Statement *, class Synthesizer *);
  void buildEnvironmentWithValue(class Gitem *, class Statement *, class Synthesizer *, bool*);
  void test(class Gitem *, class Statement *, class Synthesizer *);
  void filter(class Gitem *, class Statement *, class Synthesizer *);
  void trace(class Gitem *, class Statement *, ostream&, class Synthesizer *);
  void order(class Gitem *, class Synthesizer *);
  void customizeVariables(unsigned int=0);
  string signature(void);
  bool exists(class Environment *);
#ifdef OUTPUT_STATEMENT_DOT
  void dot(std::ostream&, unsigned int, string left="");
#endif
  void disable(class Statement *, class Gitem *);
  bool apply(Synthesizer *synthesizer, class GitemSet *state, class Gitem*, bool *modification);
}; 

#endif // STATEMENT_H
