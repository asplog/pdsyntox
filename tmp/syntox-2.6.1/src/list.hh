/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef LIST_H
#define LIST_H

#include <list>
#include "flags.hh"
#include "errors.hh"
#include "enum.hh"

void listInit(void);

class List : 
  public Flags {
  
public:
  typedef enum {ATOM, PAIRP, NIL} typeList;
  static class List *nil;

private:
  static bitset<MAXBITS> *gwith;
  static unsigned int uniqId;
  unsigned int id;
  typeList type;
  union {
    class Value *value;
    struct {
      class List *car;
      class List *cdr;
    } pairP;
  };
  public:
  List (class Value *value);  
  List (class List *car, class List *cdr);  
  List (void);  
 ~List();
  inline unsigned int getId(void){return id;}
  inline typeList getType(void){return type;}
  inline void putType(typeList type){this->type=type;}
  inline class Value *getValue(void){return value;}
  inline void putValue(class Value *value){this->value=value;}
  inline class List *car(void){return pairP.car;}
  inline class List *cdr(void){return pairP.cdr;}
  inline class List *cadr(void){return cdr()->pairP.car;}
  inline class List *cddr(void){return cdr()->pairP.cdr;}
  inline class List *caar(void){return car()->pairP.car;}
  inline class List *cdar(void){return car()->pairP.cdr;}
  inline bool isNil(void){return (this==nil);}
  
  bitset<MAXBITS> *getBits(void);
  class Features *getFeatures(void);
  int getInteger(void);

  void print(ostream&, bool par);
  bool buildEnvironment(class Environment *, class List *, bool);
  //void deleteVariables(class Environment *);
  void deleteNIL(void);
  void customizeVariables(unsigned int=0);
#ifdef OUTPUT_XML
  void toXML(const xmlNodePtr);
#endif
  void buildLexicalEnvironment(class Environment *);
  class List *copy(void);
  bool exists(class Environment *);
  static bool compare_values (class Value *, class Value *);
  void sort(bitset<MAXBITS> *);
  void disable(class Statement *, class Gitem *);
  //bool filter(class List *, class Environment *);
  bool subsumes(class List *, class Environment *);
};

#endif // LIST_H
