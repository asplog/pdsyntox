/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef TERMS_H
#define TERMS_H

#include <vector>
using namespace std;

#include "flags.hh"
#include "term.hh"


class Terms :
  public Flags{
  
public:

private:
  vector<class Term *> terms;
  bool _optional;
  bool _checked;
  
public:
  Terms(vector<class Term *> &terms, bool optional=false, bool checked=false){
    NEW("Terms");
    this->terms=terms;
    this->_optional=optional;
    this->_checked=checked;
  }

  Terms(class Term *term, bool optional=false, bool checked=false){
    NEW("Terms");
    this->terms.push_back(term);
    this->_optional=optional;
    this->_checked=checked;
  }

  ~Terms(){
    DELETE("Terms");
  }

  inline bool isOptional(void){return _optional;}
  inline bool isNotOptional(void){return !_optional;}
  inline void putOptional(bool optional){this->_optional=optional;}

  inline bool isChecked(void){return _checked;}
  inline bool isUnchecked(void){return !_checked;}
  inline void putChecked(bool checked){this->_checked=checked;}

  inline size_t size(void){return terms.size();}
  inline vector<class Term*>::iterator begin(void){return terms.begin();}
  inline vector<class Term*>::iterator end(void){return terms.end();}
  inline void erase(vector<class Term*>::iterator begin, vector<class Term*>::iterator end){terms.erase(begin, end);}
  inline void push_back(class Term *term){terms.push_back(term);}
  inline class Term *index(unsigned int i){return terms[i];}
 
  void print(ostream& outStreamy=cout, bool_html=TRUE_HTML);
  class Terms *copy(void);
#ifdef OUTPUT_XML
  void toXML(const xmlNodePtr);
#endif
  
  // compare deux termses
  struct less {
    bool operator() (struct Terms *t1, struct Terms *t2) 
    {
      if (t1->_optional < t2->_optional)
        return true;
      if (t1->_optional > t2->_optional)
	return false;
      
      if (t1->_checked < t2->_checked)
        return true;
      if (t1->_checked > t2->_checked)
	return false;
      
      if (t1->size() < t2->size())
	return true;
      if (t1->size() > t2->size())
	return false;
      
      vector<class Term*>::const_iterator s1=t1->begin();
      vector<class Term*>::const_iterator s2=t2->begin();
      while (s1!=t1->end()){
	if ((*s1) < (*s2))
	  return true;
	if ((*s1) > (*s2))
	  return false;
	s1++; s2++;
      }

      return false;
    }
  };

};  

#endif // TERMS_H
