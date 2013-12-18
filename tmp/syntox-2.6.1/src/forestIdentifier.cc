/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "forestIdentifier.hh"
#include <map>
#include <iostream>
using namespace std;

/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
ForestIdentifier::print(ostream &out){
  out << "#" << id << "[" << from << "-" << to << "]";
};
