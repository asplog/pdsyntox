/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include <iostream>

#include "item.hh"
#include "rule.hh"
#include "term.hh"
#include "terms.hh"

/* ************************************************************
 *                                                            *
 ************************************************************ */
Item::Item (class Rule *rule, unsigned int index, unsigned int indexTerm, class Statements *statements){
  NEW ("Item");
  this->rule=rule;
  this->index=index;
  vector<class Terms*> terms=rule->getRhs();
  unsigned j=0;
  for (vector<class Terms*>::const_iterator i=terms.begin();
       i!=terms.end();
       i++, j++){
    indexes.push_back(j);
    indexTerms.push_back(0);
  }
  if (terms.size()>=index+1)
    this->indexTerms[index]=indexTerm;
  this->statements=statements;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
Item::Item (class Rule *rule, unsigned int index, vector<unsigned int> &indexTerms, class Statements *statements){
  NEW ("Item");
  this->rule=rule;
  this->index=index;
  this->indexTerms=indexTerms;
  vector<class Terms*> terms=rule->getRhs();
  unsigned j=0;
  for (vector<class Terms*>::const_iterator i=terms.begin();
       i!=terms.end();
       i++, j++){
    indexes.push_back(j);
  }
  this->statements=statements;
}

// /* ************************************************************
//  *                                                            *
//  ************************************************************ */
class Terms *
Item::getTerms(void){
  if (index >= rule->getRhs().size())
    return NULL;
  return rule->getRhs()[index];
}

// /* ************************************************************
//  *                                                            *
//  ************************************************************ */
class Term *
Item::getFirstTerm(void){
  if (index >= rule->getRhs().size())
    return NULL;
  class Terms *terms=rule->getRhs()[index];
  if (terms->size()>1)
    return NULL;
  return (*terms->begin());
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Item::print(ostream& outStream, bool_html html)
{
  if (rule)
    rule->print(outStream, index, false, html);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Item::initialize()
{
  vector<unsigned int>::const_iterator i;
  unsigned int j=0;
  unsigned int min=UINT_MAX;
  bool ok=false;
  for(i=indexesBegin();
      i!=indexesEnd();
      i++, j++){
    if ((*i) < min){
      ok=true;
      min = *i;
      index=j;
    }
  }
  if (!ok){
    index=rule->rhs.size();
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Term *
Item::getLhs(void){
  return rule->getLhs();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
vector<class Terms*> &
Item::getRhs(void){
  return rule->getRhs();
}
