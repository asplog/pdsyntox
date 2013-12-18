/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef FEATURE_H
#define FEATURE_H

#include <list>
using namespace std;

#include "flags.hh"
#include "enum.hh"
#include "bits.hh"

class Feature :
  public Flags
{
  
public:
  
  typedef enum {	      
    PRED,
    FORM,
    CONSTANT, 
    VARIABLE
  } featuretype;
  
  static const featuretype first_featuretype = PRED;
  static const featuretype last_featuretype = VARIABLE;
  
private:
  static unsigned int uniqId;
  unsigned int id;
  bitset<MAXBITS> lhs; // variable ou constante
  class Value *rhs;
  featuretype type;
  string sign;

public:
  
  Feature(void){
    NEW("Feature");
    id=uniqId++;
    this->type=CONSTANT;
    sign="";
  }
  Feature(featuretype type){
    NEW("Feature");
    id=uniqId++;
    this->type=type;
    sign="";
  }
  Feature(bitset<MAXBITS> lhs, class Value *rhs, featuretype typeFeature);
  ~Feature();
  inline class Value *getRhs(void){return this->rhs;}
  inline void putRhs(class Value *rhs){this->rhs=rhs;}
  inline int getId(void){return this->id;}
  inline featuretype getType(void){return this->type;}
  inline void putType(featuretype type){this->type=type;}
  
  inline bitset<MAXBITS> &getLhs(void){return this->lhs;}
  inline string getLhsStr(void){return bitsToStr(lhs);}
  inline void putLhs(bitset<MAXBITS> &lhs){
    this->lhs=lhs;
  }
  class Feature *copy(void);
  void print(ostream&, bool_html=TRUE_HTML);
#ifdef OUTPUT_XML
  void toXML(xmlNodePtr nodeRoot);
#endif
  void customizeVariables(unsigned int=0);
  string signature(void);
  void disable(class Statement *, class Gitem *);
};

#endif // FEATURE_H
