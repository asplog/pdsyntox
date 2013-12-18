/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef VARTABLE_H
#define VARTABLE_H

#include "bits.hh"

#include <bitset>
#include <string>
using namespace std;

extern bitset<MAXBITS> varTableIndex; // vartable.cc
extern map<unsigned long int, string, less<unsigned long int> > bitToStrTable; 

#define _END_ (unsigned int)0
#define _STARTTERM_ (unsigned int)1
#define _EMPTY_ (unsigned int)2
#define _OPEN_ (unsigned int)3
#define _FIRSTID_ (unsigned int)4

void varTableInit(void);
bitset<MAXBITS> *varTableAdd(string); // string -> bit
void varTableInit(void);
unsigned int strToInt(string); // string -> integer
string intToStr(unsigned int);

#endif // VARTABLE_H
