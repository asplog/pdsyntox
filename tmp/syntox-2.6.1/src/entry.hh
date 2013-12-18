/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef ENTRY_H
#define ENTRY_H

#include "errors.hh"
#include "vartable.hh"
#include "features.hh"

class Entry
{
private:
  static unsigned int uniqId;
  unsigned int id;
  unsigned int code;
  unsigned int codePred; 
  unsigned int codeForm;
  class Features *features;
  class Statements *statements;
  list<bitset<MAXBITS> *> *args;

public:
  Entry(unsigned int code=(unsigned int)UINT_MAX, unsigned int codePred=(unsigned int)UINT_MAX, unsigned int codeForm=(unsigned int)UINT_MAX, class Features *features=NULL, class Statements *statements=NULL, list<bitset<MAXBITS> *> *args=NULL){
    NEW("Entry");
    this->id=this->uniqId++;
    this->code=code;
    this->codePred=codePred;
    this->codeForm=codeForm;
    this->features=features;
    this->statements=statements;
    this->args=args;
  }
  Entry(unsigned int code, unsigned int codePred, string form, class Features *features=NULL, class Statements *statements=NULL, list<bitset<MAXBITS> *> *args=NULL){
    NEW("Entry");
    this->id=this->uniqId++;
    this->code=code;
    this->codePred=codePred;
    this->codeForm=strToInt(form);
    this->features=features;
    this->statements=statements;
    this->args=args;
  }
  Entry(unsigned int code, string pred, string form, class Features *features=NULL, class Statements *statements=NULL, list<bitset<MAXBITS> *> *args=NULL){
    NEW("Entry");
    this->id=this->uniqId++;
    this->code=code;
    this->codePred=strToInt(pred);
    this->codeForm=strToInt(form);
    this->features=features;
    this->statements=statements;
    this->args=args;
  }
  ~Entry(){
    DELETE("Entry");
  }
    
  inline unsigned int getId(void){return id;};
  inline void putId(unsigned int id){this->id=id;};
  inline unsigned int getCode(void){return code;}
  inline void putCode(unsigned int code){this->code=code;}
  inline unsigned int getCodePred(void){return codePred;}
  inline unsigned int getCodeForm(void){return codeForm;}
  inline void putForm(string form){
    unsigned int found=strToInt(form);
    this->codeForm=found;
  }
  inline class Features *getFeatures(void){return features;};
  
  inline class Statements *getStatements(void){return statements;}

  inline void putArgs(list<bitset<MAXBITS>*>*args){this->args=args;}
  inline list<bitset<MAXBITS>*>*getArgs(void){return this->args;}
  
#ifdef OUTPUT_XML
  void toXML(xmlNodePtr nodeRoot);
#endif
  void print(ostream&);
  void printArgs(ostream &);

  bool operator < (class Entry *rhs) const {
    if (this->code < rhs->code)
      return true;
    else if (this->code > rhs->code)
      return false;
    else if (this->codePred < rhs->codePred)
      return true;
    else if (this->codePred > rhs->codePred)
      return false;
    else if (this->codeForm < rhs->codeForm)
      return true;
    else if (this->codeForm > rhs->codeForm)
      return false;
    if ((this->features==NULL) && (rhs->features!=NULL))
      return true;
    if ((this->features!=NULL) && (rhs->features==NULL))
      return false;
    if ((this->features!=NULL) && (rhs->features!=NULL)){
      if (this->features->getSign() < rhs->features->getSign())
	return true;
      if (this->features->getSign() > rhs->features->getSign())
	return false;
    }
    return false;
  }   
  
};

#endif // ENTRY_H
