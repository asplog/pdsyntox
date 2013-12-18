/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "io.hh"
#include "entry.hh"
#include "features.hh"
#include "value.hh"

unsigned int Entry::uniqId = 0;

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Entry::toXML(xmlNodePtr nodeRoot)
{
  xmlNodePtr a=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"ENTRY", NULL);
  if (this->code!=(unsigned int)-1){
    xmlSetProp(a, (xmlChar*)"code", (xmlChar*)intToStr(this->code).c_str());
    xmlSetProp(a, (xmlChar*)"codeStr", (xmlChar*)intToStr(this->code).c_str());
  }
  if (this->codePred!=(unsigned int)-1){
    xmlSetProp(a, (xmlChar*)"codePred", (xmlChar*)intToStr(this->codePred).c_str());
    xmlSetProp(a, (xmlChar*)"codePredStr", (xmlChar*)intToStr(this->codePred).c_str());
  }
  if (this->codeForm!=(unsigned int)-1){
    xmlSetProp(a, (xmlChar*)"codeForm", (xmlChar*)intToStr(this->codeForm).c_str());
    xmlSetProp(a, (xmlChar*)"codeFormStr", (xmlChar*)intToStr(this->codeForm).c_str());
  }
  if (this->features){
    this->features->toXML(a);
  }
  
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Entry::print(ostream &out){
  out << "(code: " << intToStr(this->code);
  if ((this->codePred!=(unsigned int)UINT_MAX))
    out << ", pred: " << intToStr(this->codePred);
  if (this->codeForm!=(unsigned int)UINT_MAX)
    out << ", form: " << intToStr(this->codeForm);
  out << ")";
  if (this->getFeatures())
    this->getFeatures()->print(out);
  else
    out << "NULL";
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Entry::printArgs(ostream &out){
  if (args && features){
    out << "(";
    bool first=true;
    for (list<bitset<MAXBITS> *>::iterator arg=args->begin(); arg!=args->end(); ++arg){
      if (first)
	first=false;
      else 
	out << ",";
      class Value *v=features->findFeature(**arg);
      if (v)
	v->print(out);
      else
	out << "NIL";//out << bitsToStr(**arg);
      
    }
    out << ")";
  }
}
