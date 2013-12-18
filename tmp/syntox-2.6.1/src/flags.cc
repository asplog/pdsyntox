/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "flags.hh"

const bitset<NBRFLAGS> Flags::COUNT 		= 	bitset<NBRFLAGS>(1ul<<0);
const bitset<NBRFLAGS> Flags::SEEN 		= 	bitset<NBRFLAGS>(1ul<<1);
const bitset<NBRFLAGS> Flags::XML 		= 	bitset<NBRFLAGS>(1ul<<2);
const bitset<NBRFLAGS> Flags::EVAL 		= 	bitset<NBRFLAGS>(1ul<<3);
const bitset<NBRFLAGS> Flags::GEN 		= 	bitset<NBRFLAGS>(1ul<<4);
const bitset<NBRFLAGS> Flags::DOTTED		= 	bitset<NBRFLAGS>(1ul<<5);
const bitset<NBRFLAGS> Flags::DISABLE		= 	bitset<NBRFLAGS>(1ul<<6);
const bitset<NBRFLAGS> Flags::ENABLE		= 	bitset<NBRFLAGS>(1ul<<7);
const bitset<NBRFLAGS> Flags::NUL		= 	bitset<NBRFLAGS>(1ul<<8);
const bitset<NBRFLAGS> Flags::BOTTOM		= 	bitset<NBRFLAGS>(1ul<<9);
const bitset<NBRFLAGS> Flags::TRUE		= 	bitset<NBRFLAGS>(1ul<<10);
const bitset<NBRFLAGS> Flags::CHOOSEN		= 	bitset<NBRFLAGS>(1ul<<11);
const bitset<NBRFLAGS> Flags::REJECTED		= 	bitset<NBRFLAGS>(1ul<<12);
const bitset<NBRFLAGS> Flags::SPLITTED		= 	bitset<NBRFLAGS>(1ul<<13);
const bitset<NBRFLAGS> Flags::CUSTOMIZED	= 	bitset<NBRFLAGS>(1ul<<14);
const bitset<NBRFLAGS> Flags::CLOSED		= 	bitset<NBRFLAGS>(1ul<<15);
//const bitset<NBRFLAGS> Flags::ALL 		=	bitset<NBRFLAGS>(~0ul);

/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
Flags::print(ostream &outStream){
  if (isSetFlags(COUNT))
    outStream << "COUNT ";
  if (isSetFlags(SEEN))
    outStream << "SEEN ";
  if (isSetFlags(XML))
    outStream << "XML ";
  if (isSetFlags(EVAL))
    outStream << "EVAL ";
  if (isSetFlags(GEN))
    outStream << "GEN ";
  if (isSetFlags(DOTTED))
    outStream << "DOTTED ";
  if (isSetFlags(DISABLE))
    outStream << "DISABLE ";
  if (isSetFlags(ENABLE))
    outStream << "ENABLE ";
  if (isSetFlags(NUL))
    outStream << "NUL ";
  if (isSetFlags(BOTTOM))
    outStream << "BOTTOM ";
  if (isSetFlags(TRUE))
    outStream << "TRUE ";
  if (isSetFlags(CHOOSEN))
    outStream << "CHOOSEN ";
  if (isSetFlags(REJECTED))
    outStream << "REJECTED ";
  if (isSetFlags(SPLITTED))
    outStream << "SPLITTED ";
  if (isSetFlags(CUSTOMIZED))
    outStream << "CUSTOMIZED ";
  if (isSetFlags(CLOSED))
    outStream << "CLOSED";

}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void Flags::addFlags(const bitset<NBRFLAGS> &f){
  this->flags |= f;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
void Flags::subFlags(const bitset<NBRFLAGS> &f){
  this->flags &= ~f;
};
