/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef TERM_H
#define TERM_H

#include <iostream>
#include "flags.hh"
#include "enum.hh"
using namespace std;

class Term :
  public Flags{
  
private:
  unsigned int code;
  
public:
  Term(unsigned int code=0){
    NEW("Term");
    this->code=code;
  }

  ~Term(){
    DELETE("Term");
  }

  inline unsigned int getCode(void){return code;}
  inline void putCode(unsigned int code){this->code=code;}
  
  void print(ostream& outStream=cout, bool_html=TRUE_HTML);
  class Term *copy(void);

  // compare deux termes
  struct less {
    bool operator() (struct Term *t1, struct Term *t2) 
    {
      if (t1->getCode() < t2->getCode())
        return true;
      if (t1->getCode() > t2->getCode())
	return false;
     
      return false;
    }
  };

};  

#endif // TERM_H
