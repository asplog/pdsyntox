/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef BITS_H
#define BITS_H

#include <iostream>
#include <map>
#include <bitset>
#ifdef OUTPUT_XML
#include <libxml/tree.h>
#endif
using namespace std;
//512
#define MAXBITS		512
#define ERRORBIT	0
#define ROOTBIT		1
#define PLUSBIT		2
#define MINUSBIT	3
#define LEXBIT		4
#define ARGBIT		5
#define SYSBIT		6

#define ERRORBITS		bitset<MAXBITS>(1ul << ERRORBIT)
#define ROOTBITS		bitset<MAXBITS>(1ul << ROOTBIT)
#define PLUSBITS		bitset<MAXBITS>(1ul << PLUSBIT)
#define MINUSBITS		bitset<MAXBITS>(1ul << MINUSBIT)
#define LEXBITS			bitset<MAXBITS>(1ul << LEXBIT)
#define ARGBITS			bitset<MAXBITS>(1ul << ARGBIT)
#define SYSBITS			bitset<MAXBITS>(1ul << SYSBIT)
#define MINBITS			SYSBITS

#define NBRERRORS 2
const bitset<NBRERRORS> BUG_ERROR		= bitset<NBRERRORS>(1ul << 0);

void bitsInit(void);
string bitsToStr(bitset<MAXBITS>);
unsigned int bitsToInt(bitset<MAXBITS>);
#ifdef OUTPUT_XML
void bitsToXML(bitset<MAXBITS>&, xmlNodePtr);
#endif

#endif // BITS_H
