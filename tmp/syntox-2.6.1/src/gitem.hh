/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef GITEM_H
#define GITEM_H

#include <set>
#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "rule.hh"
#include "item.hh"
#include "flags.hh"
#include "features.hh"
#include "environment.hh"
#include "statement.hh"
#include "statements.hh"
#include "term.hh"
#include "rule.hh"

#ifdef OUTPUT_ITEMS_DOT
extern ofstream outputItemsDotFile;
#endif

typedef set<unsigned int> intSet;

///////////////////////
//
///////////////////////
class Gitem : 
  public Item,
  public Flags {
  
private:
  static unsigned int uniqId;
  unsigned int id;
  intSet refs;
  vector<unsigned int> ranges;
  class Features *inheritedFeatures; //↑
  vector<class Features *>inheritedSonFeatures; //↓
  class Features *synthesizeFeatures; //⇑
  vector<class Features *> synthesizeSonFeatures; //⇓
  vector<class ForestIdentifier *> forestIdentifiers;
  class Statements *statements;
  class Statements *lexicalStatements;
  class Environment *environment;
  class Environment *lexicalEnvironment;
  list <int> history;  

public:
  Gitem (class Rule *rule, 
	 unsigned int index=0, 
	 unsigned int indexTerm=UINT_MAX, 
	 class Statements *statements=NULL,
	 class Features *inheritedFeatures=Features::nil);
  
  Gitem (class Rule *rule, 
	 unsigned int index, 
	 vector<unsigned int> &indexTerms, 
	 class Statements *statements,
	 class Features *inheritedFeatures);
  
  ~Gitem();

  inline unsigned int getId(void){return id;}
  inline void putId(int id){this->id=id;}

  inline void addHistory(int i){history.push_back(i);}
  inline list<int>&getHistory(void){return history;}
  inline void putHistory(list<int>&h){history=h;}
  
  inline intSet &getRefs(void){return refs;}
  inline void putRefs(intSet &refs){
    this->refs=refs;
  }
  inline bool addRefs(int ref){
    pair<intSet::iterator, bool> res=this->refs.insert(ref);
    return res.second;
  }

  void addItem(map<int, class Gitem*>&table, int clef, class Gitem *item){
    table.insert(pair<int, class Gitem *>(clef, item));
  }
  
  inline vector<unsigned int> &getRanges(void){return ranges;}
  inline void addRanges(unsigned int k){ranges.push_back(k);}
  inline void addRanges(vector<unsigned int>&l){
    for(vector<unsigned int>::const_iterator i=l.begin(); i!=l.end(); i++)
      addRanges(*i);
  }
  inline vector<unsigned int>::const_iterator rangesBegin(){return ranges.begin();}
  inline vector<unsigned int>::const_iterator rangesEnd(){return ranges.end();}
  inline unsigned int rangesSize(){return ranges.size();}

  inline vector<class ForestIdentifier *> &getForestIdentifiers(void){return forestIdentifiers;}
  inline void addForestIdentifiers(class ForestIdentifier *k, unsigned int i){forestIdentifiers[i]=k;}
  inline void addForestIdentifiers(vector<class ForestIdentifier *>&l){
    for(unsigned int i=0 ; i<l.size(); i++)
      forestIdentifiers[i]=l[i];
  }
  inline vector<class ForestIdentifier *>::const_iterator forestIdentifiersBegin(){return forestIdentifiers.begin();}
  inline vector<class ForestIdentifier *>::const_iterator forestIdentifiersEnd(){return forestIdentifiers.end();}
  inline unsigned int forestIdentifiersSize(){return forestIdentifiers.size();}

  inline vector<class Features *> &getSynthesizeSonFeatures(void){return synthesizeSonFeatures;}
  inline void addSynthesizeSonFeatures(class Features *fs, unsigned int i){synthesizeSonFeatures[i]=fs;}
  inline void putSynthesizeSonFeatures(vector<class Features *>&l){
    synthesizeSonFeatures=l;
  }
  inline void addSynthesizeSonFeatures(vector<class Features *>&l){
    for(unsigned int i=0 ; i<l.size(); i++)
      synthesizeSonFeatures[i]=l[i];
  }
  inline vector<class Features *>::const_iterator synthesizeSonFeaturesBegin(){return synthesizeSonFeatures.begin();}
  inline vector<class Features *>::const_iterator synthesizeSonFeaturesEnd(){return synthesizeSonFeatures.end();}
  inline unsigned int synthesizeSonFeaturesSize(){return synthesizeSonFeatures.size();}
    
  inline vector<class Features *> &getInheritedSonFeatures(void){return inheritedSonFeatures;}
  inline void addInheritedSonFeatures(class Features *k, unsigned int i){inheritedSonFeatures[i]=k;}
  inline void addInheritedSonFeatures(vector<class Features *>&l){
    for(unsigned int i=0 ; i<l.size(); i++)
      inheritedSonFeatures[i]=l[i];
  }
  inline vector<class Features *>::iterator inheritedSonFeaturesBegin(){return inheritedSonFeatures.begin();}
  inline vector<class Features *>::iterator inheritedSonFeaturesEnd(){return inheritedSonFeatures.end();}
  inline unsigned int inheritedSonFeaturesSize(){return inheritedSonFeatures.size();}
    
  inline class Features *getSynthesizeFeatures(void){return synthesizeFeatures;}
  inline void putSynthesizeFeatures(class Features *synthesizeFeatures){this->synthesizeFeatures=synthesizeFeatures;}
  
  inline class Features *getInheritedFeatures(void){return inheritedFeatures;}
  inline void putInheritedFeatures(class Features *inheritedFeatures){this->inheritedFeatures=inheritedFeatures;}

  void buildSynthesizeFeatures(class Synthesizer *);
  void buildInheritedSonFeatures(class Synthesizer *);

  inline class Environment *getEnvironment(void){return this->environment;}
  inline void putEnvironment(class Environment *e){this->environment=e;}
  void addEnvironment(class Environment *);
  void addEnvironment(class Environment *, class Environment *);
  
  inline class Environment *getLexicalEnvironment(void){return this->lexicalEnvironment;}
  inline void putLexicalEnvironment(class Environment *lexicalEnvironment){this->lexicalEnvironment=lexicalEnvironment;}
  void addLexicalEnvironment(class Environment *);
  
  inline class Statements *getStatements(void){return statements;}
  inline void putStatements(class Statements *statements){this->statements=statements;}
  void addStatements(class Statements *);
  void addStatements(class Statements *, class Environment *);
  
  inline class Statements *getLexicalStatements(void){return lexicalStatements;}
  inline void putLexicalStatements(class Statements *lStatements){this->lexicalStatements=lStatements;}
  void addLexicalStatements(class Statements *);

  void print(ostream&, class Synthesizer *);
  class Gitem *buildGhost(class Synthesizer *);
  bool split(class GitemSet *, class Synthesizer *synthesizer, bool getTrace);
  bool isFinished(void);
  bool isStarted(void){return ranges.size()==1;}

  // compare deux items
  struct less {
    bool operator() (class Gitem *i1, class Gitem *i2) 
    {
      /***
	  BUG;
	  i1->print(cerr, NULL, TRUE_HTML);
	  cerr << endl;
	  i2->print(cerr, NULL, TRUE_HTML);
	  cerr << endl;
      ***/

      if (i1->getRule()->getId() < i2->getRule()->getId())
	return true;
      if (i1->getRule()->getId() > i2->getRule()->getId())
	return false;
      
      if (i1->getIndex() < i2->getIndex())
        return true;
      if (i1->getIndex() > i2->getIndex())
	return false;
       
      if (i1->indexTerms.size() < i2->indexTerms.size())
	return true;
      if (i1->indexTerms.size() > i2->indexTerms.size())
	return false;
      
      if (i1->refs.size() < i2->refs.size())
	return true;
      if (i1->refs.size() > i2->refs.size())
	return false;

      if (i1->forestIdentifiers.size() < i2->forestIdentifiers.size())
	return true;
      if (i1->forestIdentifiers.size() > i2->forestIdentifiers.size())
	return false;
      
      intSet::const_iterator r1=i1->refs.begin();
      intSet::const_iterator r2=i2->refs.begin();
      while (r1!=i1->refs.end()){
	if ((*r1) < (*r2))
	  return true;
	if ((*r1) > (*r2))
	  return false;
	r1++; r2++;
      }
      
      vector<unsigned int>::const_iterator ind1=i1->indexTerms.begin();
      vector<unsigned int>::const_iterator ind2=i2->indexTerms.begin();
      while (ind1!=i1->indexTerms.end()){
	if ((*ind1) < (*ind2))
	  return true;
	if ((*ind1) > (*ind2))
	  return false;
	ind1++; ind2++;
      }
      
      vector<class ForestIdentifier *>::const_iterator t1=i1->forestIdentifiersBegin();
      vector<class ForestIdentifier *>::const_iterator t2=i2->forestIdentifiersBegin();
      while (t1!=i1->forestIdentifiersEnd()){
	if ((*t1) < (*t2))
	  return true;
	if ((*t1) > (*t2))
	  return false;
	t1++; t2++;
      }
      
      if ((i1->inheritedFeatures==NULL) && (i2->inheritedFeatures!=NULL))
	return true;
      if ((i1->inheritedFeatures!=NULL) && (i2->inheritedFeatures==NULL))
	return false;
      if ((i1->inheritedFeatures!=NULL) && (i2->inheritedFeatures!=NULL)){
	if (i1->inheritedFeatures->getSign() < i2->inheritedFeatures->getSign())
	  return true;
	if (i1->inheritedFeatures->getSign() > i2->inheritedFeatures->getSign())
	  return false;
      }
      
      return false;
    };
  };
  
  
};  

#endif // GITEM_H
