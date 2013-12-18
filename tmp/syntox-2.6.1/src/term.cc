/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "term.hh"
#include "vartable.hh"

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Term::print(ostream& outStream, bool_html html)
{
  outStream << intToStr(code);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Term *
Term::copy(){
  return new Term(code);
}
