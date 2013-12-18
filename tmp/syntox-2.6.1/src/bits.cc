/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include <map>
#include <string>
using namespace std;

#include "errors.hh"
#include "bits.hh"
#include "vartable.hh"

/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
bitsInit(void){
  bitToStrTable[ERRORBIT]="ERROR";
  bitToStrTable[ROOTBIT]="ROOT";
  bitToStrTable[PLUSBIT]="+";
  bitToStrTable[MINUSBIT]="-";
  bitToStrTable[LEXBIT]="LEX";
  bitToStrTable[ARGBIT]="ARG";
  bitToStrTable[SYSBIT]="SYS";
  varTableIndex=MINBITS<<1;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
string
bitsToStr(bitset<MAXBITS> code)
{
  map<unsigned long int, string, less<unsigned long int> >::const_iterator varTableIt;
  string s;
  size_t count=code.count();
  size_t size=code.size();
  for( size_t i = 0 ; i < size && count > 0 ; i++ ) {
    if (code.test(i)){
      count--;
      varTableIt = bitToStrTable.find(i);
      if (s.size())
	s+="|"+varTableIt->second;
      else
	s=varTableIt->second;
    }
  }
  return s;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
unsigned int
bitsToInt(bitset<MAXBITS> code)
{
  for(unsigned int i = 0 ; i < code.size(); i++ ) 
    if (code[i])
      return i;
  return 0;
}

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void bitsToXML(bitset<MAXBITS>& code, xmlNodePtr nodeRoot)
{
  xmlNodePtr f=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"ALT", NULL);
  map<unsigned long, string, less<unsigned long> >::const_iterator varTableIt;
  for( int i = 0 ; i < (int) code.size(); i++ ) {
    if (code[i]){
      varTableIt = bitToStrTable.find(i);
      if (varTableIt != bitToStrTable.end()){
	xmlNewChild(f, NULL, (const xmlChar*)"OPT", (const xmlChar*)varTableIt->second.c_str());
      }
    }
  }
}
#endif
