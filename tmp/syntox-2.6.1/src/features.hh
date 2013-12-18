/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef FEATURES_H
#define FEATURES_H

#include <list>
#include <set>
using namespace std;

#include "flags.hh"
#include "errors.hh"
#include "enum.hh"
#include "colors.hh"
#include "bits.hh"

class Features : 
  public Flags {

public:
  static class Features *nil;
  static class Features *bottom;
  
private:
  static unsigned int uniqId;
  unsigned int id;
  list<class Feature *> features;
  unsigned int pred;
  string *form;
  class Value *complexPred;
  bool memoizedComplexPred;
  string sign;
  //string comment;

 public:

  //void putComment(string s){comment = s;}
  
  Features(void);
  Features(class Feature *feature);
  Features(const bitset<NBRFLAGS>&);
  ~Features();
  
  inline unsigned int getId(void){return id;}
  inline void putId(unsigned int id){this->id=id;}
  
  inline void addFeature(class Feature *feature, bool_front front=FALSE_FRONT){
    if (front)
      this->features.push_front(feature);
    else
      this->features.push_back(feature);
  }

  inline void addFeatures(class Features *features, bool_front front=FALSE_FRONT){
    for (list<class Feature *>::const_iterator j=features->begin();
	 j!=features->end();
	 j++)
      if (front)
	this->features.push_front(*j);
      else
	this->features.push_back(*j);
  }
  inline list<class Feature *>::iterator erase(list<class Feature *>::iterator i){return features.erase(i);}

  inline size_t size(void){return features.size();}
  inline list<class Feature*>::iterator begin(void){return features.begin();}
  inline list<class Feature*>::iterator end(void){return features.end();}
  inline class Feature *front(void){return *(features.begin());}

  void print(ostream&, bool_html=TRUE_HTML);
#ifdef OUTPUT_XML
  void toXML(xmlNodePtr);
#endif
  class Features *copy(void);
  class Value *findFeature(bitset<MAXBITS> );

  bool buildEnvironment(class Environment *, class Features *, bool);
  void subFlags(const bitset<NBRFLAGS> &);
  unsigned int getPred(void);
  string *getForm(void);
  //void deleteVariables(class Environment *);
  void customizeVariables(unsigned int=0);
  string getSign(void);
  void buildLexicalEnvironment(class Environment *);
  inline bool isNil(void){return (this==nil);}
  inline bool isBottom(void){return (this==bottom);}
  bool exists(class Environment *);
  void disable(class Statement *, class Gitem *);
  //bool filter(class Features*, class Environment *);
  bool subsumes(class Features*, class Environment *);
  void deleteNIL(void);
};

#endif // FEATURES_H
