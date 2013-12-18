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

#include "value.hh"
#include "list.hh"
#include "feature.hh"
#include "features.hh"
#include "bits.hh"
#include "vartable.hh"
#include "environment.hh"
#include "gitem.hh"
#include "io.hh"

class Value *Value::_true=new Value((unsigned int)1, Value::BOOL);
class Value *Value::_nil=new Value((unsigned int)0, Value::BOOL);

unsigned int Value::uniqId=0;

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(unsigned int integer, const valuetype type){
  NEW("Value");
  this->id=uniqId++;
  this->type=type;
  this->putInteger(integer);
  //this->errors.reset();
  this->flags=0;
  this->sign="";
  this->left=NULL;
  this->right=NULL;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(float number){
  NEW("Value");
  this->id=uniqId++;
  this->type=NUMBER;
  this->putNumber(number);
  //this->errors.reset();
  this->flags=0;
  this->sign="";
  this->left=NULL;
  this->right=NULL;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(const valuetype type){
  NEW("Value");
  this->id=uniqId++;
  this->type=type;
  //this->errors.reset();
  this->flags=0;
  this->sign="";
  this->left=NULL;
  this->right=NULL;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(const valuetype type, class Value *left, class Value *right){
  NEW("Value");
  this->id=uniqId++;
  this->type=type;
  //this->errors.reset();
  this->flags=0;
  this->sign="";
  this->left=left;
  this->right=right;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(string *str, const valuetype type){
  NEW("Value");
  this->id=uniqId++;
  this->type=type;
  int found=0;
  if (type==IDENTIFIER){
    found=strToInt(*str);
    this->putInteger(found);
  } 
  else if (type==FORM){
    this->putForm(str);
  } 
  //this->errors.reset();
  this->flags=0;
  this->sign="";
  this->left=NULL;
  this->right=NULL;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(bitset<MAXBITS> *bits, const valuetype type){
  NEW("Value");
  this->id=uniqId++;
  this->type=type;
  this->putBits(bits);
  //this->errors.reset();
  this->flags=0;
  this->sign="";
  this->left=NULL;
  this->right=NULL;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(class Features *features){
  NEW("Value");
  this->id=uniqId++;
  this->type=FEATURES;
  this->putFeatures(features);
  //this->errors=0;
  this->flags=0;
  this->sign="";
  this->left=NULL;
  this->right=NULL;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::Value(class List *lst){
  NEW("Value");
  this->id=uniqId++;
  this->type=LIST;
  this->putList(lst);
  //this->errors.reset();
  this->flags=0;
  this->sign="";
  this->left=NULL;
  this->right=NULL;
};

/* ************************************************************
 *                                                            *
 ************************************************************ */
Value::~Value(){
  DELETE("Value");
  switch(type){
  case BOOL:
  case IDENTIFIER:
  case NUMBER:
    break;
  case FORM:
    delete getForm();
    break;
  case CONSTANT:
  case VARIABLE:
    delete getBits();
    break;
  case FEATURES:
    delete getFeatures();
    break;
  case LIST:
    delete getList();
    break;
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
Value::print(ostream &outStream, bool_html html){
  //outStream << comment;

  if (isNil())
    outStream << "NIL";
  else if (isTrue())
    outStream << "TRUE";
  else
    switch(type){
    case BOOL:
      FATAL_ERROR;
      break;
    case CONSTANT:
      outStream /*<< "C" */<< bitsToStr(*getBits());
      break;
    case VARIABLE:
      outStream /*<< "V" */<< bitsToStr(*getBits());
      break;
    case IDENTIFIER:
      outStream /*<< "I" */<< intToStr(getInteger());
      break;
    case NUMBER:
      outStream << getNumber();
      break;
    case FORM:
      if (html)
	outStream << "&quot;";
      else
	outStream << "\"";
      outStream << getForm()->c_str();
      if (html)
	outStream << "&quot;";
      else
	outStream << "\"";
      break;
    case FEATURES:
      getFeatures()->print(outStream, html);
      break;
    case LIST:
      getList()->print(outStream, true);
      break;
    }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool 
Value::exists(class Environment *e){
  bool ret=true;
  switch(type){
  case BOOL:
  case CONSTANT:
  case FORM:
  case IDENTIFIER:
  case NUMBER:
    break;
  case VARIABLE:
    if (!e->exists(*getBits()))
      ret=false;
    break;
  case FEATURES:
    if (!getFeatures()->exists(e))
      ret=false;
    break;
  case LIST:
    if (!getList()->exists(e))
      ret=false;
    break;
  }
  return ret;
}

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
Value::toXML(xmlNodePtr nodeRoot)
{
  xmlNodePtr v=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"VAL", NULL);
  switch(type){
  case BOOL:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"bool");
    if (isNil())
      xmlSetProp(v, (xmlChar*)"value", (const xmlChar*)"NIL");
    else 
      xmlSetProp(v, (xmlChar*)"value", (const xmlChar*)"TRUE");
    break;
  case CONSTANT:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"constant");
    bitsToXML(*getBits(), v);
    break;
  case VARIABLE:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"variable");
    bitsToXML(*getBits(), v);
    break;
  case IDENTIFIER:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"identifier");
    xmlNewChild(v, NULL, (const xmlChar*)"VAL", (const xmlChar*)intToStr(getInteger()).c_str());
    break;
  case NUMBER:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"number");
    //xmlNewChild(v, NULL, (const xmlChar*)"VAL", (const xmlChar*)getNumber().toString().c_str());
    break;
  case FORM:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"form");
    xmlNewChild(v, NULL, (const xmlChar*)"VAL", (const xmlChar*)(*getForm()).c_str());
    break;
  case FEATURES:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"fs");
    getFeatures()->toXML(v);
    break;
  case LIST:
    xmlSetProp(v, (xmlChar*)"type", (const xmlChar*)"list");
    getList()->toXML(v);
    break;
  }
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Value *
Value::copy(void)
{
  class Value *result=this;
  switch(type){
  case BOOL:
  case CONSTANT:
  case IDENTIFIER:
  case FORM:
  case NUMBER:
    result=this;
    break;
  case FEATURES:
    result=new Value(getFeatures()->copy());
    break;
  case LIST:
    result=new Value(getList()->copy());
    break;
  case VARIABLE:
    result=new Value(getBits(), VARIABLE);
    break;
  }
  return result;
}

/* ************************************************************
 *
 ************************************************************ */
bool
Value::buildEnvironment(class Environment *environment, class Value *value, bool acceptToFilterNULLVariables){
  /***
  cerr << "<H4>Value::buildEnvironment</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th></th><th></th><th>Environment</th></tr>";
  cerr << "<tr><td>";
  this->print(cerr);
  cerr << "</td><td>";
  if (value)
    value->print(cerr);
  else
    cerr << "NULL";
  cerr << "</td><td>";
  environment->print(cerr);
  cerr << "</td></tr></table>";
  ***/

  bool ret=true;
  switch(type){
  case BOOL:
    if (this->isNil())
      ret=false;
    else 
      FATAL_ERROR;
    break;
  case FEATURES:
    if (value->type == FEATURES){
      if (!this->getFeatures()->buildEnvironment(environment, value->getFeatures(), acceptToFilterNULLVariables))
	ret=false;
    }
    else
      ret=false;
    break;
  case CONSTANT:
    if (value->type == VARIABLE)
      environment->add(*(value->getBits()), this);
    else if ((*getBits() & *value->getBits()).none())
      ret=false;
    break;
  case IDENTIFIER:
    if (value->type == VARIABLE)
      environment->add(*(value->getBits()), this);
    else if (getInteger() != value->getInteger())
      ret=false;
    break;
  case NUMBER:
    if (value->type == VARIABLE)
      environment->add(*(value->getBits()), this);
    else if (getNumber() != value->getNumber())
      ret=false;
    break;
  case FORM:
    if (value->type == VARIABLE)
      environment->add(*(value->getBits()), this);
    else if (*getForm() != *value->getForm())
      ret=false;
    break;
  case LIST:
    if (value->type == LIST){
      if (!this->getList()->buildEnvironment(environment, value->getList(), acceptToFilterNULLVariables))
	ret=false;
    }
    else if (value->type == VARIABLE)
      environment->add(*(value->getBits()), this);
    else
      ret=false;
    break;
  case VARIABLE:
    if (value==NULL)
      environment->add(*(this->getBits()), _nil);
    else
      environment->add(*(this->getBits()), value);
    break;
  }
  /***
  cerr << "<H4>Result Value::buildEnvironment</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th>R&eacute;sultat</th><th>Environment</th></tr>";
  cerr << "<tr><td>" << (ret?"TRUE":"FALSE") << "</td><td>";
  environment->print(cerr);
  cerr << "</td></tr></table>";
  ***/
  return ret;
}

// /* ************************************************************
//  *
//  ************************************************************ */
// bool
// Value::filter(class Value *o, Environment *environment)
// {
//   bool ret=true;
//   /***/
//   cerr << "<DIV>";
//   cerr << "Value::filter (" << this << ")";
//   cerr << "<TABLE><TR>";
//   cerr << "<TD>";
//   //this->print(cerr);
//   cerr << "</TD><TD>";
//   o->print(cerr);
//   cerr << "</TD>";
//   cerr << "</TR></TABLE>";
//   cerr << "</DIV>";
//   /***/

//   if (o->type==VARIABLE){
//     environment->add(*(o->getBits()), this);
//     //FATAL_ERROR;
//   } 
//   else if (type==VARIABLE){
//     environment->add(*(this->getBits()), o);
//   } 
//   else if ((type != o->type)){
//     ret=false;
//   } 
//   else {
//     switch (o->type){
//     case BOOL:
//       FATAL_ERROR;
//       break;
//     case IDENTIFIER:
//       if (type!=IDENTIFIER)
// 	ret=false;
//       else if (getInteger()==o->getInteger())
// 	;
//       else
// 	ret=false;
//       break;
//     case NUMBER:
//       if (type!=NUMBER)
// 	ret=false;
//       else if (getNumber() == o->getNumber())
// 	;
//       else
// 	ret=false;
//       break;
//     case CONSTANT: 
//       if (type!=CONSTANT)
// 	ret=false;
//       else if ((*getBits() & *o->getBits()).none())
// 	ret=false;
//       break;
//     case FORM:
//       if (type!=FORM)
// 	ret=false;
//       else if (*getForm() == *o->getForm())
// 	;
//       else
// 	ret=false;
//       break;
//     case FEATURES:
//       if (type!=FEATURES)
// 	ret=false;
//       else
// 	ret=getFeatures()->filter(o->getFeatures(), environment);
//       break;
//     case VARIABLE: 
//       FATAL_ERROR;
//       break;
//     case LIST: 
//       if (type!=LIST)
// 	ret=false;
//       else
// 	ret=getList()->filter(o->getList(), environment);
//       break;
//     }
//   }
//   /***/
//   cerr << "<DIV>";
//   cerr << "result: (" << this << ")";
//   cerr << "</DIV>";
//   /***/
//   return ret;
// } 

/* ************************************************************
 * this < o
 ************************************************************ */
bool
Value::subsumes(class Value *o, Environment *environment)
{
  bool ret=true;
  /***
  cerr << "<DIV>";
  cerr << "Value::subsumes (" << this << ")";
  cerr << "<TABLE><TR>";
  cerr << "<TD>";
  this->print(cerr);
  cerr << "</TD>&lt;<TD>";
  o->print(cerr);
  cerr << "</TD>";
  cerr << "</TR></TABLE>";
  cerr << "</DIV>";
  ***/

  // X < …
  if (type==VARIABLE){
    environment->add(*(getBits()), o);
  } 
  // … < X
  else if (o->type==VARIABLE){
    //FATAL_ERROR;
    environment->add(*(o->getBits()), this);
    //FATAL_ERROR;
  } 
  // NIL < NIL
  else if (isNil() && o->isNil()){
  } 
  // NIL < …
  // … < NIL
  else if (isNil() || o->isNil()){
      FATAL_ERROR;
  } 
  // TRUE < TRUE
  else if (isTrue() && o->isTrue()){
  } 
  // TRUE < …
  // … < TRUE
  else if (isTrue() || o->isTrue()){
    ret=false;

  } 
  else if ((type != o->type)){
    ret=false;
  } 
  else {
    switch (o->type){
      // a < a 
    case IDENTIFIER:
      if (getInteger()==o->getInteger())
	;
      else
	ret=false;
      break;
    case NUMBER:
      if (getNumber() == o->getNumber())
	;
      else
	ret=false;
      break;
    case CONSTANT: 
      if ((*getBits() & *o->getBits()).none())
	ret=false;
      break;
    case FORM:
      if (*getForm() == *o->getForm())
	;
      else
	ret=false;
      break;
    case FEATURES:
      ret=getFeatures()->subsumes(o->getFeatures(), environment);
      break;
    case LIST: 
      ret=getList()->subsumes(o->getList(), environment);
      break;
    case BOOL:
    case VARIABLE: 
      FATAL_ERROR;
      break;
    }
  }
  /***
  cerr << "<DIV>";
  cerr << "result: (" << this << ")";
  cerr << "</DIV>";
  ***/
  return ret;
} 

/* ************************************************************
 *
 ************************************************************ */
bool
Value::equivalent(class Value *o)
{
  /***
  CERR_LINE;
  this->print(cerr);
  cerr << " == ";
  o->print(cerr);
  cerr << endl;
  ***/

  bool ret=true;
  if (o->isNil() && this->isNil()){
    ret = true;
  } 
  else if (o->isNil() || this->isNil()){
    ret = false;
  } 
  else if (o->type==VARIABLE){
    ret = true;
  } 
  else if (type==VARIABLE){
    ret = true;
  }
  else {
    switch (o->type){
    case BOOL:
      FATAL_ERROR;
      break;
    case IDENTIFIER:
      if (type==CONSTANT){
	FATAL_ERROR;
      }
      FATAL_ERROR;
      break;
    case CONSTANT: 
      if (type==CONSTANT){
	if ((*getBits() & *o->getBits()).none())
	  ret=false;
      }
      else if (type==IDENTIFIER){
	if (bitsToStr(*o->getBits()) != intToStr(getInteger()))
	  ret=false;
      }
      break;
    case FORM:
      if (type!=FORM)
	ret=false;
      else if (*getForm() != *o->getForm())
	ret=false;
      break;
    case NUMBER:
      if (type!=NUMBER)
	ret=false;
      else if (getNumber() != o->getNumber())
	ret=false;
      break;
    case FEATURES:
      if (type!=FEATURES)
	ret=false;
      else{
	ret=(getFeatures()->getSign()==o->getFeatures()->getSign());
	//CERR_LINE;
	//cerr << ret;
	//CERR_LINE; // equivalent ne peut pas usiliser sign ???
	// ret=getFeatures()->equivalent(o->getFeatures());
      }
      break;
    case VARIABLE: 
    case LIST: 
      FATAL_ERROR;
      break;
    }
  }
  return ret;
} 

/* ************************************************************
 *
 ************************************************************ */
bool
Value::less(class Value *o)
{
  bool ret=false;
  /***
  CERR_LINE;
  this->print(cerr);
  cerr << " < ";
  o->print(cerr);
  cerr << endl;
  ***/
  if (isNumber() && o->isNumber())
    return (getNumber() < o->getNumber());
  else
    FATAL_ERROR;
  return ret;
} 

// /* ************************************************************
//  *
//  ************************************************************ */
// void
// Value::deleteVariables(class Environment *but)
// {
//   switch(type){
//   case BOOL:
//   case IDENTIFIER:
//   case CONSTANT:
//   case FORM:
//   case VARIABLE:
//   case NUMBER:
//     FATAL_ERROR;
//     break;
//   case FEATURES:
//     getFeatures()->deleteVariables(but);
//     break;
//   case LIST:
//     getList()->deleteVariables(but);
//     break;
//   }
// }

/* ************************************************************
 *
 ************************************************************ */
void
Value::deleteNIL()
{
  switch(type){
  case BOOL:
  case IDENTIFIER:
  case CONSTANT:
  case FORM:
  case VARIABLE:
  case NUMBER:
    break;
  case FEATURES:
    getFeatures()->deleteNIL();
    break;
  case LIST:
    getList()->deleteNIL();
    break;
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Value::customizeVariables(unsigned int i)
{
  switch(type){
  case CONSTANT:
  case IDENTIFIER:
  case FORM:
  case BOOL:
  case NUMBER:
    break;
  case VARIABLE:
    {
      ostringstream oss;
      oss << bitsToStr(*getBits()) << "_" << i;
      string str = oss.str();
      bitset<MAXBITS> *variableBits=varTableAdd(str);
      this->putBits(variableBits);
      sign="";
      getSign();
    }
    break;
  case FEATURES:
    if (getFeatures())
      getFeatures()->customizeVariables(i);
    break;
  case LIST:
    if (getList())
      getList()->customizeVariables(i);
    break;
  }
}

/* ************************************************************
 *
 ************************************************************ */
string
Value::getSign(){
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
Value::buildLexicalEnvironment(class Environment *lexicalEnvironment)
{
  switch(type){
  case BOOL:
  case IDENTIFIER:
  case FORM:
  case CONSTANT:
  case NUMBER:
    break;
  case VARIABLE:
    lexicalEnvironment->add(*getBits());
    break;
  case FEATURES:
    getFeatures()->buildLexicalEnvironment(lexicalEnvironment);
    break;
  case LIST:
    getList()->buildLexicalEnvironment(lexicalEnvironment);
    break;
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
Value::disable(class Statement *root, class Gitem *gitem)
{
  switch(type){
  case BOOL:
  case IDENTIFIER:
  case FORM:
  case CONSTANT:
  case NUMBER:
    break;
  case VARIABLE:
    if ((gitem->getEnvironment()==NULL)
	|| (!gitem->getEnvironment()->exists(*getBits()))){
      root->addFlags(Flags::DISABLE);
    }
    break;
  case FEATURES:
    getFeatures()->disable(root, gitem);
    break;
  case LIST:
    getList()->disable(root, gitem);
    break;
  }
}

