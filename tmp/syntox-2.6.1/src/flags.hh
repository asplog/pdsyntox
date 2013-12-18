/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef FLAGS_H
#define FLAGS_H

#include <bitset>
#ifdef OUTPUT_XML
#include <libxml/tree.h>
#endif
using namespace std;

#include "errors.hh"

#define NBRFLAGS 16
class Flags {
  
public:
  
  static const bitset<NBRFLAGS> COUNT;
  static const bitset<NBRFLAGS> SEEN;
  static const bitset<NBRFLAGS> XML;
  static const bitset<NBRFLAGS> EVAL;
  static const bitset<NBRFLAGS> GEN;
  static const bitset<NBRFLAGS> DOTTED;
  static const bitset<NBRFLAGS> DISABLE;
  static const bitset<NBRFLAGS> ENABLE;
  static const bitset<NBRFLAGS> NUL;
  static const bitset<NBRFLAGS> BOTTOM;
  static const bitset<NBRFLAGS> TRUE;
  static const bitset<NBRFLAGS> REJECTED;
  static const bitset<NBRFLAGS> CHOOSEN;
  static const bitset<NBRFLAGS> SPLITTED;
  static const bitset<NBRFLAGS> CUSTOMIZED;
  static const bitset<NBRFLAGS> CLOSED;
  //static const bitset<NBRFLAGS> ALL;
  
public:
  bitset<NBRFLAGS> flags;
  
  Flags(void){
    NEW("Flags");
    this->flags=0;
  }
  
  Flags(const bitset<NBRFLAGS> &flags)
  {
    NEW("Flags");
    this->flags=flags;
  }
  
  ~Flags(void)
  {
    DELETE("Flags");
  }

private:
  inline void put(bitset<NBRFLAGS> &flags){this->flags=flags;}
  inline bitset<NBRFLAGS> &get(void){return this->flags;}

public:
  inline void resetFlags(void){this->flags=0;}
  inline bool isSetFlags(const bitset<NBRFLAGS> & cmp){return (this->flags & cmp).any();}
  inline bool isUnsetFlags(const bitset<NBRFLAGS> & cmp){return (this->flags & cmp).none();}
  void addFlags(const bitset<NBRFLAGS> &f);
  void subFlags(const bitset<NBRFLAGS> &f);
  void print(ostream&);
  
};

#endif // FLAGS_H
