/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef ITEM_H
#define ITEM_H

#include <vector>
using namespace std;

#include "enum.hh"
#include "errors.hh"

class Item {
  //  <i, A -> \alpha \bullet \beta, forestList, termList>

protected:
  class Rule *rule;
  unsigned int index; // the \bullet position
  vector<unsigned int> indexes; // the position of the \bullet on the term
  vector <unsigned int> indexTerms; // the parsing order of the terms
  class Statements *statements;

public:
  //
  Item (class Rule *rule, unsigned int index, unsigned int indexTerm, class Statements *statements);
  Item (class Rule *rule, unsigned int index, vector<unsigned int> &indexTerms, class Statements *statements);
  
  ~Item(){
    DELETE("Item");
  };
  
  class Term *getFirstTerm(void);
  class Terms *getTerms(void);

  inline class Rule *getRule(void){return rule;}
  inline unsigned int getIndex(void){return index;}
  inline vector<unsigned int> &getIndexTerms(void){return indexTerms;}
  inline void putRule(class Rule *rule){this->rule=rule;}
  
  inline vector<unsigned int> &getIndexes(void){return indexes;}
  inline void putIndexes(vector<unsigned int> &indexes){this->indexes=indexes;}
  inline void addIndexes(unsigned int k){indexes.push_back(k);}
  inline void addIndexes(vector<unsigned int>&l){
    for(vector<unsigned int>::const_iterator i=l.begin(); i!=l.end(); i++)
      addIndexes(*i);
  }
  inline vector<unsigned int>::const_iterator indexesBegin(){return indexes.begin();}
  inline vector<unsigned int>::const_iterator indexesEnd(){return indexes.end();}
  inline unsigned int indexesSize(){return indexes.size();}

  class Term *getLhs(void);
  vector<class Terms*> &getRhs(void);
  
  inline class Statements *getStatements(void){return statements;}
  inline void putStatements(class Statements *statements){this->statements=statements;}

  void print(ostream&, bool_html=TRUE_HTML);
  void initialize(void);
};

#endif // ITEM_H
