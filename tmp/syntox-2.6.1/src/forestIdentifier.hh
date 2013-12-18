/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef FORESTIDENTIFIER_H
#define FORESTIDENTIFIER_H

#include <map>
#include <string>
#include "errors.hh"

using namespace std;

class ForestIdentifier {
   
public:
  typedef enum{LEAF, ROOT, EMPTY, OTHER} enum_kind;
  
 private:
  unsigned int id;
  unsigned int from;
  unsigned int to;
  enum_kind kind;
  string sign;

public:
  
  ForestIdentifier (unsigned int id, unsigned int from, unsigned int to, enum_kind kind, string sign){
    NEW("ForestIdentifier");
    this->id=id;
    this->from=from;
    this->to=to;
    this->kind=kind;
    this->sign=sign;
  };
  
  ~ForestIdentifier (){
    DELETE("ForestIdentifier");
  };
  
  inline unsigned int getFrom(void){return from;};
  inline unsigned int getTo(void){return to;};
  inline unsigned int getId(void){return id;};
  inline enum_kind getKind(void){return kind;};
  void print(ostream &);

    bool operator < (class ForestIdentifier *o) const {
    if (this->id < o->id)
      return true;
    if (this->id > o->id)
      return false;
    
    if (this->from < o->from)
      return true;
    if (this->from > o->from)
      return false;
    
    if (this->to < o->to)
      return true;
    if (this->to > o->to)
      return false;

    if (this->sign < o->sign)
      return true;
    if (this->sign > o->sign)
      return false;
    
    return false;
  };
  
  struct less{
    bool operator() (class ForestIdentifier *a1, class ForestIdentifier *a2) const{
      if (a1->id < a2->id)
	return true;
      if (a1->id > a2->id)
	return false;
      
      if (a1->from < a2->from)
	return true;
      if (a1->from > a2->from)
	return false;
      
      if (a1->to < a2->to)
	return true;
      if (a1->to > a2->to)
	return false;

      if (a1->sign < a2->sign)
	return true;
      if (a1->sign > a2->sign)
	return false;

      return false;
    }
  };

};

#endif // FORESTIDENTIFIER_H
