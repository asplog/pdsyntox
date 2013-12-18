/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "value.hh"
#include "list.hh"
#include "environment.hh"
#include "features.hh"

class List *List::nil=new List();
unsigned int List::uniqId=0;
bitset<MAXBITS> *List::gwith;

/* ************************************************************
 *
 ************************************************************ */
List::List(class Value *value)
{
  NEW("List");
  this->id=uniqId++;
  this->type=ATOM;
  this->value=value;
};

/* ************************************************************
 *
 ************************************************************ */
List::List(class List *car, class List *cdr)
{
  NEW("List");
  this->id=uniqId++;
  this->type=PAIRP;
  this->pairP.car=car;
  this->pairP.cdr=cdr;
}

 /* ************************************************************
  *
  ************************************************************ */
 List::List()
 {
   NEW("List");
   this->id=uniqId++;
   this->type=NIL;
   this->value=NULL;
 }

/* ************************************************************
 *
 ************************************************************ */
List::~List()
{
  DELETE("List");
  if (this->isNil())
    return;
  else {
    switch (type){
    case NIL:
      break;
    case ATOM:
      if (value)
	delete value;
      break;
    case PAIRP:
      delete car();
      delete cdr();
      break;
    }
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bitset<MAXBITS> *
List::getBits()
{
  return value->getBits();
}
  
/* ************************************************************
 *                                                            *
 ************************************************************ */
class Features *
List::getFeatures(void)
{
  return value->getFeatures();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
int
List::getInteger(void)
{
  return value->getInteger();
}

#ifdef DOT
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
List::dot(std::ostream& outStream, unsigned int id)
{
  if (id)
    outStream << "N" << id << " -- " << "N" << this->id << ";" << endl;
  switch (type){
  case NIL:
    outStream << "N" << this->id << " [label=\"NIL\"];" << endl;
    break;
  case ATOM:
    outStream << "N" << this->id << " [label=\"ATOM\\n";
    if (value)
      value->print(outStream, FALSE_HTML);
    outStream << "\"];" << endl;
    break;
  case PAIRP:
    outStream << "N" << this->id << " [label=\"PAIRP" << "\"];" << endl;
    car()->dot(outStream, this->id);
    cdr()->dot(outStream, this->id);
    break;
  }
}
#endif

/* ************************************************************
 *
 ************************************************************ */
void
List::print(ostream& outStream, bool par)
{
  //CERR_LINE;
  //outStream << "•";
  switch (type){
  case NIL:
    outStream << "&lt;&gt;";
    break;
  case ATOM:
    if (value)
      value->print(outStream);
    break;
  case PAIRP:
    {
      if (par ||
	  ((!cdr()->isNil()) && cdr()->getType()==ATOM))
	outStream << "&lt;";
      car()->print(outStream, par);	
      if ((!cdr()->isNil()) && cdr()->getType()==ATOM){
	outStream << "::";
	cdr()->print(outStream, par);
      } 
      else if ((!cdr()->isNil()) && cdr()->getType()==PAIRP){
	outStream << ",";
	cdr()->print(outStream, false);
      } 
      if (par ||
	  ((!cdr()->isNil()) && cdr()->getType()==ATOM))
	outStream << "&gt;";
    }
    break;
  }
}

/* ************************************************************
 *
 ************************************************************ */
bool
List::exists(class Environment *e)
{
  bool ret=true;
  switch (type){
  case NIL:
    ret=false;
    break;
  case ATOM:
    if (value && (!value->exists(e)))
	ret=false;
    break;
  case PAIRP:
    if ((car() && !car()->exists(e))
	||(cdr() && !cdr()->exists(e)))
      ret=false;
    break;
  }
  return ret;
}

/* ************************************************************
 *
 ************************************************************ */
bool
List::buildEnvironment(class Environment *environment, class List *list, bool acceptToFilterNULLVariables)
{
  bool ret=true;
  /***
  cerr << "<H4>List::buildEnvironment</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th>this</th><th>list</th><th>Environment</th></tr>";
  cerr << "<tr><td>";
  this->print(cerr);
  cerr << "</td><td>";
  list->print(cerr);
  cerr << "</td><td>";
  environment->print(cerr);
  cerr << "</td></tr></table>";
  ***/

  switch (this->type){
  case NIL:
    //UNEXPECTED;
    break;
  case ATOM:
    if (this->value->getType()==Value::VARIABLE){
      if (list){
	switch (list->getType()){
	case NIL:
	  environment->add(*this->value->getBits(), Value::_nil);
	  break;
	case ATOM:
	  environment->add(*this->value->getBits(), list->getValue());
	  break;
	case PAIRP:
	  environment->add(*this->value->getBits(), new Value(list));
	  break;
	}
      } else {
	FATAL_ERROR;
      }
    }
    else if (list==NULL){
      ret=false;
    }
    else if (list->getType()==ATOM){
      if (list->value->getType()==Value::VARIABLE)
	environment->add(*list->value->getBits(), this->getValue());
      else if (!this->value->buildEnvironment(environment, list->value, acceptToFilterNULLVariables))
	ret=false;
    }
    else
      ret=false;
    break;
  case PAIRP:
    if (list->getType()==PAIRP){
      if (!this->car()->buildEnvironment(environment, list->car(), acceptToFilterNULLVariables)){
	ret=false;
	break;
      }
      if (!this->cdr()->buildEnvironment(environment, list->cdr(), acceptToFilterNULLVariables)){
	ret=false;
      }
    } else
      ret=false;
    break;
  }
  /***
  cerr << "<H4>Result List::buildEnvironment</H4>" << endl;
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
// void
// List::deleteVariables(class Environment *but)
// {
//   switch (type){
//   case NIL:
//     FATAL_ERROR;
//     break;
//   case ATOM:
//     if (value)
//       value->deleteVariables(but);
//     break;
//   case PAIRP:
//     car()->deleteVariables(but);
//     cdr()->deleteVariables(but);
//     break;
//   }
// }

/* ************************************************************
 *
 ************************************************************ */
void
List::deleteNIL()
{
  switch (type){
  case NIL:
    break;
  case ATOM:
    if (value)
      value->deleteNIL();
    break;
  case PAIRP:
    car()->deleteNIL();
    cdr()->deleteNIL();
    break;
  }
}

/* ************************************************************
 *
 ************************************************************ */
void
List::customizeVariables(unsigned int i)
{
  switch (type){
  case NIL:
    break;
  case ATOM:
    if (value)
      value->customizeVariables(i);
    break;
  case PAIRP:
    car()->customizeVariables(i);
    cdr()->customizeVariables(i);
    break;
  }
}

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
List::toXML(xmlNodePtr nodeRoot)
{
  xmlNodePtr l=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"LIST", NULL);
  switch (type){
  case NIL:
    break;
  case ATOM:
    value->toXML(l);
    break;
  case PAIRP:
    car()->toXML(l);
    cdr()->toXML(l);
    break;
  }
}
#endif

/* ************************************************************
 *
 ************************************************************ */
void
List::buildLexicalEnvironment(class Environment *lexicalEnvironment)
{
  switch (type){
  case NIL:
    break;
  case ATOM:
    if (value)
      value->buildLexicalEnvironment(lexicalEnvironment);
    break;
  case PAIRP:
    car()->buildLexicalEnvironment(lexicalEnvironment);
    cdr()->buildLexicalEnvironment(lexicalEnvironment);
    break;
  }
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
class List*
List::copy()
{
  switch (type){
  case NIL:
    return nil;
    break;
  case ATOM:
    if (value)
      return new List(value->copy());
    break;
  case PAIRP:
    return new List(car()->copy(), cdr()->copy());
    break;
  }
  return NULL;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool 
List::compare_values (class Value *v1, class Value *v2)
{
  if ((v1->getType()==Value::FEATURES)
      &&(v2->getType()==Value::FEATURES)){
    class Value *va1=v1->getFeatures()->findFeature(*gwith);
    class Value *va2=v2->getFeatures()->findFeature(*gwith);
    if ((va1->getType()==Value::CONSTANT)
	&& (va2->getType()==Value::CONSTANT)){
      if (bitsToStr(*va1->getBits()) < bitsToStr(*va2->getBits()))
	return true;
      else
	return false;
    } 
    else
      FATAL_ERROR
  }
  else
    FATAL_ERROR
  return false;
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
void
List::sort(bitset<MAXBITS> *with)
{
  /***
  cerr << "<H4>List::sort</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th>this</th><th>with</th></tr>";
  cerr << "<tr><td>";
  this->print(cerr);
  cerr << "</td><td>";
  cerr << bitsToStr(*with);
  cerr << "</td></tr></table>";
  ***/
  list<class Value *>lst;
  class List *l=this;
  while(l
	&& l->getType()==PAIRP
	&& l->car()->getType()==ATOM){
    lst.push_back(l->car()->getValue());
    l=l->cdr();
  }
  gwith=with;
  lst.sort(compare_values);
  l=this;
  while(l
	&& l->getType()==PAIRP
	&& l->car()->getType()==ATOM){
    l->car()->putValue(lst.front());
    lst.pop_front();
    l=l->cdr();
  }
  /***
  cerr << "<H4>List::sort result</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th>this</th></tr>";
  cerr << "<tr><td>";
  this->print(cerr);
  cerr << "</td></tr></table>";
  ***/
}

// /* ************************************************************
//  *
//  ************************************************************ */
// bool
// List::filter(class List *o, class Environment *environment)
// {
//   /***
//   BUG;
//   this->print(cerr);
//   cerr << " ";
//   o->print(cerr);
//   cerr << endl;
//   ***/

//   switch (type){
//   case NIL:
//     if (o->getType()!=NIL)
//       return false;
//     break;
//   case ATOM:
//     if (o->getType()!=ATOM)
//       return false;
//     else if (!value->filter(o->getValue(), environment))
//       return false;
//     break;
//   case PAIRP:
//     if (o->getType()!=PAIRP)
//       return false;
//     else if (!car()->filter(o->car(), environment))
//       return false;
//     else if (!cdr()->filter(o->cdr(), environment))
//       return false;
//     break;
//   }
//   return true;
// }

/* ************************************************************
 * this < o
 ************************************************************ */
bool
List::subsumes(class List *o, class Environment *environment)
{
  /***
  BUG;
  this->print(cerr);
  cerr << " ";
  o->print(cerr);
  cerr << endl;
  ***/

  switch (type){
    // NIL < L
  case NIL:
    if (o->getType()!=NIL)
      return false;
    break;
    // atom < L
  case ATOM:
    if (o->getType()!=ATOM)
      return false;
    else if (!value->subsumes(o->getValue(), environment))
      return false;
    break;
    // (a1::a2) < L
  case PAIRP:
    if (o->getType()!=PAIRP)
      return false;
    else if (!car()->subsumes(o->car(), environment))
      return false;
    else if (!cdr()->subsumes(o->cdr(), environment))
      return false;
    break;
  }
  return true;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
List::disable(class Statement *root, class Gitem *gitem)
{
  switch (type){
  case NIL:
    break;
  case ATOM:
    value->disable(root, gitem);
    break;
  case PAIRP:
    car()->disable(root, gitem);
    cdr()->disable(root, gitem);
    break;
  }
}
