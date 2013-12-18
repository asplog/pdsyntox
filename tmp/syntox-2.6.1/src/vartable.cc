/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "vartable.hh"
#include "errors.hh"

unsigned int intToStrIndex;
bitset<MAXBITS> varTableIndex;
map<string, bitset<MAXBITS>, less<string> > varTable;
map<unsigned int, string, less<unsigned int> > intToStrTable;
map<string, unsigned int, less<string> > strToIntTable;
map<unsigned long int, string, less<unsigned long int> > bitToStrTable;

/* ************************************************************
 *                                                            *
 ************************************************************ */
void varTableInit()
{
  intToStrTable[_END_]="_END_";
  intToStrTable[_STARTTERM_]="_STARTTERM_";
  intToStrTable[_EMPTY_]="_EMPTY_";
  intToStrTable[_OPEN_]="_OPEN_";
  intToStrTable[_FIRSTID_]="_FIRSTID_";
  intToStrIndex=_FIRSTID_;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bitset<MAXBITS> *varTableAdd(string str)
{
  bitset<MAXBITS> *result = new bitset<MAXBITS>;
  map<string, bitset<MAXBITS>, less<string> >::const_iterator varTableIt;
  varTableIt = varTable.find(str);
  if (varTableIt == varTable.end()){
    //if (varTableIndex.none())
    //WARNING;
    varTable[str]=varTableIndex;
    *result=varTableIndex;
    size_t i=0;
    for (;(i<varTableIndex.size()) && !varTableIndex.test(i); i++);
    bitToStrTable[i]=str;
    varTableIndex <<= 1;
    if (varTableIndex.none())
      ERROR("Too much values");
  } else {
    *result=varTableIt->second;
  }
  return result;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
unsigned int strToInt(string str)
{
  unsigned int code;
  map<string, unsigned int, less<string> >::const_iterator it(strToIntTable.find(str));
  if (it==strToIntTable.end()){
    code=intToStrIndex;
    strToIntTable[str]=intToStrIndex;
    intToStrTable[intToStrIndex]=str;
    intToStrIndex++;
  } else 
    code = it->second;
  return code;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
string intToStr(unsigned int i)
{
  if (i!=UINT_MAX)
    return intToStrTable[i];
  else
    return string("UINT_MAX");
}
