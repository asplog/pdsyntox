/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "terms.hh"
#include "vartable.hh"

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Terms::print(ostream& outStream, bool_html html)
{
  if (_checked && html)
    outStream << "<B>";
  if (_optional)
    outStream << "(";
  if (size()>1){
    bool first=true;
    for (vector<class Term *>::const_iterator term=begin();
	 term != end();
	 term++){
      if (first)
	first=false;
      else
	outStream << "|";
      (*term)->print(outStream, html);
    }
  }
  else
    terms[0]->print(outStream, html);
  if (_optional)
    outStream << ")";
  if (_checked && html)
    outStream << "</B>";
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Terms *
Terms::copy(){
  vector<class Term *> new_terms;
  for (vector<class Term *>::const_iterator t=begin();
       t != end();
       t++)
    new_terms.push_back((*t)->copy());
  return new Terms(new_terms, _optional, _checked);
  //return new Terms(new_terms, _optional);
}
