/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <map>
#include "feature.hh"
#include "value.hh"
#include "bits.hh"
#include "vartable.hh"
#include "gitem.hh"

unsigned int Feature::uniqId=0;

/* ************************************************************
 * 
 ************************************************************ */
Feature::Feature(bitset<MAXBITS> lhs, class Value *rhs, featuretype type)
{
  NEW("Feature");
  this->id=uniqId++;
  this->lhs=lhs;
  this->rhs=rhs;
  this->type=type;
  this->sign="";
};

/* ************************************************************
 * 
 ************************************************************ */
Feature::~Feature()
{
  DELETE("Feature");
  if (rhs){
    //delete rhs;
  }
}

/* ************************************************************
 *
 ************************************************************ */
void
Feature::print(ostream& outStream, bool_html html)
{
  switch(type){
  case Feature::PRED:
    if (html)
      outStream << "<TD ALIGN=\"LEFT\">";
    outStream << "PRED";
    if (html)
      outStream << "</TD>";
    if (html)
      outStream << "<TD ALIGN=\"LEFT\">";
    else
      outStream << ":";
    if (rhs)
      rhs->print(outStream, html);
    else
      outStream << "NIL";
    if (html)
      outStream << "</TD>";
    break;
  case Feature::FORM:
    if (html)
      outStream << "<TD ALIGN=\"LEFT\">";
    outStream << "FORM";
    if (html)
      outStream << "</TD>";
    if (html)
      outStream << "<TD ALIGN=\"LEFT\">";
    else
      outStream << ":";
    if (rhs)
      rhs->print(outStream, html);
    else
      outStream << "NIL";
    if (html)
      outStream << "</TD>";
    break;
  case Feature::CONSTANT:
    if (html)
      outStream << "<TD ALIGN=\"LEFT\">";
    outStream << getLhsStr();
    if (html)
      outStream << "</TD>";
    if (html)
      outStream << "<TD ALIGN=\"LEFT\">";
    else
      outStream << ":";
    if (rhs)
      rhs->print(outStream, html);
    else
      outStream << "NIL";
    if (html)
      outStream << "</TD>";
    break;
  case Feature::VARIABLE:
    if (html)
      outStream << "<TD ALIGN=\"LEFT\">";
    outStream << getLhsStr();
    if (html)
      outStream << "</TD>";
    if (rhs && !rhs->isNil()){
      if (html)
	outStream << "<TD ALIGN=\"LEFT\">";
      else
	outStream << ":";
      rhs->print(outStream, html);
      if (html){
	outStream << "</TD>";
      }
    }
    break;
  }
}

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Feature::toXML(xmlNodePtr nodeRoot)
{
  xmlNodePtr f=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"F", NULL);
  
  switch(type){
  case Feature::PRED:
    xmlSetProp(f, (xmlChar*)"type", (const xmlChar*)"pred");
    if (rhs)
      rhs->toXML(f);
    break;
  case Feature::FORM:
    xmlSetProp(f, (xmlChar*)"type", (const xmlChar*)"form");
    if (rhs)
      rhs->toXML(f);
    break;
  case Feature::CONSTANT:
    xmlSetProp(f, (xmlChar*)"type", (const xmlChar*)"constant");
    xmlSetProp(f, (xmlChar*)"name", (const xmlChar*)getLhsStr().c_str());
    if (rhs)
      rhs->toXML(f);
    break;
  case Feature::VARIABLE:
    xmlSetProp(f, (xmlChar*)"type", (const xmlChar*)"variable");
    xmlSetProp(f, (xmlChar*)"name", (const xmlChar*)getLhsStr().c_str());
    if (rhs)
      rhs->toXML(f);
    break;
    //case Feature::UNKNOWN:
    //xmlSetProp(f, (xmlChar*)"type", (const xmlChar*)"unknown");
    //break;
  }
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Feature *
Feature::copy()
{
  /*switch(type){
  case Feature::LEMMA:
  case Feature::FORM:
  case Feature::UNKNOWN:
    return this;
    break;
  case Feature::CONSTANT:
  case Feature::VARIABLE:
    return new Feature(lhs, (rhs!=NULL)?rhs->copy():NULL, type);
    break;
  }
  */class Feature *result;
  result=new Feature(lhs, (rhs!=NULL)?rhs->copy():NULL, type);
  return result;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Feature::customizeVariables(unsigned int i)
{
  switch(type){
  case Feature::PRED:
    if (rhs)
      rhs->customizeVariables(i);
    break;
  case Feature::FORM:
    break;
  case Feature::CONSTANT:
    if (rhs)
      rhs->customizeVariables(i);
    break;
  case Feature::VARIABLE:
    {
      ostringstream oss;
      oss << getLhsStr() << "_" << i;
      string str = oss.str();
      bitset<MAXBITS> *variableBits=varTableAdd(str);
      lhs=*variableBits;
      if (rhs)
	rhs->customizeVariables(i);
      sign="";
      signature();
    }
    break;
  }
}

/* ************************************************************
 *
 ************************************************************ */
string
Feature::signature(){
  ostringstream oss;
  if (sign.size())
    return sign;
  print(oss, FALSE_HTML);
  sign=oss.str();
  return sign;
}

/* ************************************************************
 *
 ************************************************************ */
void
Feature::disable(class Statement *root, class Gitem *gitem)
{
  switch(type){
  case Feature::FORM:
  case Feature::PRED:
    break;
  case Feature::CONSTANT:
    if (rhs)
      rhs->disable(root, gitem);
    break;
  case Feature::VARIABLE:
    if ((gitem->getEnvironment()==NULL)
	|| (!gitem->getEnvironment()->exists(getLhs()))){
      //CERR_LINE;
      root->addFlags(Flags::DISABLE);
    }
    break;
  }
}

