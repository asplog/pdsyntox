/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

extern map<unsigned int, string, less<unsigned int> > intToStr;
extern map<string, unsigned int, less<string> > strToInt;
extern unsigned int idInt;

string toStr(unsigned int t);

#endif // IO_H
#include "io.hh"

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
std::string toStr(unsigned int t){
  ostringstream oss;
  oss << t;
  return oss.str();
}
