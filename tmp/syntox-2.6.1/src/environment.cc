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

#include "feature.hh"
#include "environment.hh"
#include "statements.hh"
#include "statement.hh"
#include "list.hh"
#include "features.hh"
#include "vartable.hh"
#include "value.hh"

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Value *
Environment::_find(unsigned int variable){
  /***
      cerr << "findValue: " << intToStr(variable) << endl;
      print(cerr);
      cerr << endl;
  ***/
  class Value *ret=NULL;
  map<unsigned int, class Value *>::iterator i=env.find(variable);
  if (i!=env.end())
    ret=i->second;
  /***
      if (ret)
      ret->print(cerr);
      else 
      cerr << "NULL";
      cerr << endl;
  ***/
  return ret;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Value *
Environment::_find(bitset<MAXBITS> a){
  for (unsigned i=0; i<=a.size(); i++)
    if (a.test(i))
      return _find(i);
  return NULL;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool
Environment::exists(unsigned int variable){
  /***
  cerr << "exists: " << intToStr(variable) << endl;
  print(cerr);
  cerr << endl;
  ***/
  map<unsigned int, class Value *>::iterator i=env.find(variable);
  if (i==env.end())
    return false;
  else
    return true;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool
Environment::exists(bitset<MAXBITS> a){
  for (unsigned i=0; i<=a.size(); i++)
    if (a.test(i))
      if (exists(i))
	return true;
      else
	return false;
  return false;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Environment::print(ostream &out){
  bool first=true;
  map<unsigned int, class Value *>::const_iterator i=begin();
  out << "<TABLE border=\"0\"><TR>";
  while(i!=end()){
    if (first)
      first=false;
    else
      out << "</TR><TR>";
    out << "<TD>";
    map<unsigned long int, string, less<unsigned long int> >::const_iterator varTableIt;
    varTableIt = bitToStrTable.find((*i).first);
    if (varTableIt != bitToStrTable.end())
      out << varTableIt->second;
    else
      FATAL_ERROR;
    if ((*i).second){
      out << ":</TD><TD>";
      (*i).second->print(out, TRUE_HTML);
    }
    out << "</TD>";
    i++;
  }
  out << "</TR></TABLE>";
}

/* ************************************************************
 * 
 ************************************************************ */
void
Environment::replaceVariables(class Features *features){
  /***
  cerr << "<H4>Environment::replaceVariables(features)</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th>Features</th><th>Environment</th></tr>";
  cerr << "<tr><td>";
  features->print(cerr);
  cerr << "</td><td>";
  this->print(cerr);
  cerr << "</td></tr></table>";
  ***/
  //redo:
  for (list<class Feature *>::iterator feature=features->begin();
       feature!=features->end();
       feature++){
    switch ((*feature)->getType()){
    case Feature::PRED:
      if ((*feature)->getRhs()){
	(*feature)->putRhs(replaceVariables((*feature)->getRhs()));
      }
      break;
    case Feature::FORM:
      break;
    case Feature::CONSTANT:
      if ((*feature)->getRhs()){
	class Value *v=replaceVariables((*feature)->getRhs());
	if (v==NULL){
	  // CERR_LINE;
	  // features->erase(feature);
	  // goto redo;
	  // return;
	} 
	else
	  (*feature)->putRhs(v);
      }     
      break;
    case Feature::VARIABLE:
      {
	class Value *value=_find((*feature)->getLhs());
	if (!value){
	  FATAL_ERROR;
	  /* do nothing */
	} 
	else if (value->isNil()){
	  FATAL_ERROR;
	  /* do nothing */
	} 
	else if (value->isFeatures()){
	  features->erase(feature);
	  for (list<class Feature *>::iterator f=value->getFeatures()->begin();
	       f!=value->getFeatures()->end();
	       f++){
	    features->addFeature(*f);
	  }
	  replaceVariables(features);
	  return;
	}
	else if (value->isConstant()){
	  (*feature)->putType(Feature::CONSTANT);
	  (*feature)->putLhs(*value->getBits());
	}
	else {
	  FATAL_ERROR;
	}
      }     
      break;
    }
  }
  /***
      cerr << "<H4>Environment::replaceVariables(features) result</H4>" << endl;
      cerr << "<table border=\"1\"><tr><th>Features</th></tr>";
      cerr << "<tr><td>";
      features->print(cerr);
      cerr << "</td></tr></table>";
  ***/
}

/* ************************************************************
 *
 ************************************************************ */
class Value *
Environment::replaceVariables(class Value *value){
  class Value *ret=value;
  /***
  cerr << "<H4>Environment::replaceVariables(value)</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th>Value</th><th>Environment</th></tr>";
  cerr << "<tr><td>";
  value->print(cerr);
  cerr << "</td><td>";
  this->print(cerr);
  cerr << "</td></tr></table>";
  ***/
  if (value->isNil())
    ;
  else if (value->isTrue())
    ;
  else {
    switch(value->getType()){
    case Value::BOOL:
    case Value::FORM:
    case Value::CONSTANT:
    case Value::IDENTIFIER:
    case Value::NUMBER:
      break;
    case Value::FEATURES:
      replaceVariables(value->getFeatures());
      break;
    case Value::LIST:
      replaceVariables(value->getList());
      break;
    case Value::VARIABLE:
      class Value* val=_find(*value->getBits());
      if (val)
	ret=replaceVariables(val);
      else
	ret=value;
      break;
    }
  }
  /***
      cerr << "<H4>Environment::replaceVariables(value) result</H4>" << endl;
      cerr << "<table border=\"1\"><tr><th>List</th></tr>";
      cerr << "<tr><td>";
      ret->print(cerr);
      cerr << "</td></tr></table>";
  ***/
  return ret;
}

/* ************************************************************
 * 
 ************************************************************ */
void
Environment::replaceVariables(class List *list){
  /***
      cerr << "<H4>Environment::replaceVariables(list)</H4>" << endl;
      cerr << "<table border=\"1\"><tr><th>List</th><th>Environment</th></tr>";
      cerr << "<tr><td>";
      list->print(cerr);
      cerr << "</td><td>";
      this->print(cerr);
      cerr << "</td></tr></table>";
      ***/

  //if (list->isSetFlags(SEEN_FLAG))
  //return;
  //list->addFlags(SEEN_FLAG);
  switch (list->getType()){
  case List::ATOM:
    list->putValue(replaceVariables(list->getValue()));
    break;
  case List::PAIRP:
    replaceVariables(list->car());
    replaceVariables(list->cdr());
    break;
  case List::NIL:
    break;
} 
  /***
      cerr << "<H4>Environment::replaceVariables(list) result</H4>" << endl;
      cerr << "<table border=\"1\"><tr><th>List</th></tr>";
      cerr << "<tr><td>";
      list->print(cerr);
      cerr << "</td></tr></table>";
      ***/
}

/* ************************************************************
 * 
 ************************************************************ */
class Environment *
Environment::copy(void){
  class Environment *environment=new Environment();
  for (map<unsigned int, class Value *>::const_iterator i=begin();
       i!=end();
       i++){
    environment->add((*i).first, 
		     ((*i).second==NULL)?NULL:(*i).second->copy());
  }
  return environment;
}
