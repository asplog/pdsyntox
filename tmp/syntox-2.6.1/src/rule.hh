/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef RULE_H
#define RULE_H

//#include <iostream>
//#include <map>
//#include <bitset>
#include <vector>
#include "enum.hh"
#include "errors.hh"
#ifdef OUTPUT_XML
#include <libxml/tree.h>
#endif
using namespace std;


typedef vector<class Term*> termVector;
typedef vector<termVector*> termsVector;
  
class Rule {
  friend class Item;

 private:
  static unsigned int uniqId;
  int id;
  class Term *lhs;
  vector<class Terms *> rhs;
  class Statements *statements;
  unsigned int usages;
  
public:
  Rule(class Term *lhs, vector<class Terms *>&rhs, class Statements *statements=NULL){
    NEW("Rule");
    this->id=uniqId++;
    this->lhs=lhs;
    this->rhs=rhs;
    this->statements=statements;
    this->usages=0;
  }
  
   Rule(class Term *lhs, class Statements *statements=NULL){
     NEW("Rule");
     this->id=uniqId++;
     this->lhs=lhs;
     this->statements=statements;
     this->usages=0;
   }
  
  ~Rule();
  
  inline  int getId(void){return id;}
  inline class Term *getLhs(void){return lhs;}
  inline vector<class Terms *>&getRhs(void){return rhs;}
  inline void putLhs(class Term *lhs){this->lhs=lhs;}
  inline void putRhs(vector<class Terms *>&rhs){this->rhs=rhs;}
  inline class Statements *getStatements(void){return statements;}
  inline void putStatements(class Statements *statements){this->statements=statements;}
  inline unsigned int getUsages(void){
    return usages;
  }
  inline unsigned int incUsages(void){
    return ++usages;
  }
  inline void resetUsages(void){usages=0;}

  class Rule *copy();
  void print(ostream&, unsigned int, bool, bool_html=TRUE_HTML);
#ifdef OUTPUT_XML
  void toXML(const xmlNodePtr);
#endif
  void addDefaults(void);

  struct less {
    bool operator()(const class Rule *r1, const class Rule *r2) const {
      return r1->id < r2->id;
    }
  };

};

#endif // RULE_H
