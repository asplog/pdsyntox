/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <set>
#include <list>
#include "rule.hh"
#include "term.hh"

using namespace std;

typedef set<unsigned int> intSet;
typedef set<class Rule *, Rule::less> ruleSet;

class Grammar {
  
 private:
  intSet terminals;
  intSet nonTerminals;
  ruleSet rules;
  class Term *startTerm;
  class Rule *firstRule;
  unsigned int idMax;
  
 public:
  Grammar (void){    
    NEW ("Grammar");
  }
  ~Grammar (){
    DELETE ("Grammar");
    terminals.clear();
    nonTerminals.clear();
    for (ruleSet::const_iterator iterRules=rulesBegin(); iterRules != rulesEnd(); iterRules++){
      delete (*iterRules);
    }
    rules.clear();
    //delete startTerm;
    //startTerm=NULL;
  }

  inline intSet &getTerminals(void){return terminals;};
  inline intSet &getNonTerminals(void){return nonTerminals;};
  inline ruleSet &getRules(void){return rules;};
  inline class Term *getStartTerm(void){return startTerm;};
  inline class Rule *getFirstRule(void){return firstRule;};
  inline unsigned int *getRefIdMax(void){return &idMax;};
  inline void putTerminals(intSet &terminals){this->terminals=terminals;};
  inline void putNonTerminals(intSet &nonTerminals){this->nonTerminals=nonTerminals;};
  inline void putRules(ruleSet &rules){this->rules=rules;};
  inline void putStartTerm(class Term *startTerm){this->startTerm=startTerm;};
  inline void putFirstRule(class Rule *firstRule){this->firstRule=firstRule;};
  
  inline ruleSet::const_iterator rulesBegin(void){
    return rules.begin();
  }

  inline ruleSet::const_iterator rulesEnd(void){
    return rules.end();
  }
  
  inline bool addRule(class Rule *rule){
    pair<ruleSet::iterator, bool> result=rules.insert(rule);
    return result.second;
  };
  
  void addNewStartTerm(bool);
  void addNonTerminal(unsigned int);
  void addTerminal(unsigned int);
  void print(ostream&, class Gitem *);
  bool isTerminal(Term *);
  bool isNonTerminal(Term *);
  void findTerms(void);
#ifdef OUTPUT_XML
  void toXML(const xmlNodePtr);
#endif
  list<class Rule*> *findRules(class Term *lhs);
};

#endif // GRAMMAR_H
