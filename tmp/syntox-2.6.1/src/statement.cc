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
#include <cmath>

#include "statement.hh"
#include "statements.hh"
#include "feature.hh"
#include "gitem.hh"
#include "synthesizer.hh"
#include "vartable.hh"
#include "value.hh"
#include "terms.hh"
#include "list.hh"

unsigned int Statement::uniqId=0;
map<string, class Statement *, less<string> > signToStm;

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (){
  NEW("Statement");
  this->id=uniqId++;
  this->lhs=NULL;
  this->rhs=NULL;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (statementop op, class Statement *lhs, class Statement *rhs){
  NEW("Statement");
  this->id=uniqId++;
  this->op=op;
  this->lhs=lhs;
  this->rhs=rhs;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (statementop op, class Statement *lhs, class Statement *rhs, union EQVALUE slots){
  NEW("Statement");
  this->id=uniqId++;
  this->op=op;
  this->lhs=lhs;
  this->rhs=rhs;
  this->slots=slots;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (statementop op, unsigned int first, unsigned int second){
  NEW("Statement");
  this->id=uniqId++;
  this->op=op;
  this->lhs=NULL;
  this->rhs=NULL;
  this->slots.slots.first=first;
  this->slots.slots.second=second;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (statementop op, string *str){
  NEW("Statement");
  this->id=uniqId++;
  this->op=op;
  this->lhs=NULL;
  this->rhs=NULL;
  this->slots.str=str;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (statementop op, statementfct fct, class Statement *lhs, class Statement *rhs){
  NEW("Statement");
  this->id=uniqId++;
  this->op=op;
  this->lhs=lhs;
  this->rhs=rhs;
  this->slots.fct=fct;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (float number){
  NEW("Statement");
  this->id=uniqId++;
  this->op=NUMBER;
  this->lhs=NULL;
  this->rhs=NULL;
  this->slots.number=number;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (statementop op, class Features *features){
  NEW("Statement");
  this->id=uniqId++;
  if ((op != FEATURES) &&
      (op != FILTER))
    FATAL_ERROR;
  this->op=op;
  this->lhs=NULL;
  this->rhs=NULL;
  this->slots.features=features;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (statementop op, bitset<MAXBITS> *bits){
  NEW("Statement");
  this->id=uniqId++;
  this->op=op;
  this->lhs=NULL;
  this->rhs=NULL;
  this->slots.bits=bits;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (class List *list){
  NEW("Statement");
  this->id=uniqId++;
  this->op=LIST;
  this->lhs=NULL;
  this->rhs=NULL;
  this->slots.list=list;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::Statement (class Statements *statements){
  NEW("Statement");
  this->id=uniqId++;
  this->op=STMS;
  this->lhs=NULL;
  this->rhs=NULL;
  this->slots.statements=statements;
  this->sign="";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
Statement::~Statement()
{
  if (lhs){
    delete lhs;
    lhs=NULL;
  }
  if (rhs){
    delete rhs;
    rhs=NULL;
  }
  DELETE("Statement");
}

/***************************
 *
 ***************************/
bool
Statement::exists(class Environment *where){
  bool ret=true;
  switch (this->op) {
  case SORT:
  case TEST:
  case AFF:
  case SUBSET:
  case FCT:
  case TRACE:
  case UNIF:
  case IF:
  case THEN:
    if ((lhs && !lhs->exists(where))
	||(rhs && !rhs->exists(where)))
      ret=false;
    break;
  case NIL:
  case TRUE:
  case CONSTANT:
  case UP:
  case UP2:
  case DOLLAR:
  case DOWN:
  case DOLLARS:
  case ORDER:
  case DOWN2:
  case STR:
  case NUMBER:
  case FINISHED:
    break;
  case VARIABLE:
    if (!where->exists(*getBits())){
      ret=false;
    }
    break;
  case FILTER:
  case FEATURES:
    if (!getFeatures()->exists(where))
      ret=false;
    break;
  case LIST:
    if (!getList()->exists(where))
      ret=false;
    break;
  case STMS:
    if (!getStatements()->exists(where))
      ret=false;
    break;
  }
  return ret;
}

#ifdef OUTPUT_STATEMENT_DOT
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Statement::dot(std::ostream& outStream, unsigned int id, string with)
{
  if (isSetFlags(Flags::DOTTED))
    return;
  addFlags(Flags::DOTTED);
  if (id){
    outStream << "N" << id << " -- N" << this->id;
    if (with.size())
      outStream << "[label=\"" << with << "\"]";
    outStream << ";" << endl;
  }
  switch (this->op){
  case FCT:
    outStream << "N" << this->id << " [label=\"FCT\"];" << endl;
    lhs->dot(outStream, this->id);
    rhs->dot(outStream, this->id);
    break;
  case SORT:
    outStream << "N" << this->id << " [label=\"SORT\"];" << endl;
    lhs->dot(outStream, this->id);
    rhs->dot(outStream, this->id);
    break;
  case TEST:
    outStream << "N" << this->id << " [label=\"TEST\"];" << endl;
    lhs->dot(outStream, this->id);
    break;
  case NIL:
    outStream << "N" << this->id << " [label=\"NIL\"];" << endl;
    break;
  case TRUE:
    outStream << "N" << this->id << " [label=\"TRUE\"];" << endl;
    break;
  case AFF:
    outStream << "N" << this->id << " [label=\"AFF\"];" << endl;
    lhs->dot(outStream, this->id);
    rhs->dot(outStream, this->id);
    break;
  case SUBSET:
    outStream << "N" << this->id << " [label=\"SUBSET\"];" << endl;
    lhs->dot(outStream, this->id);
    rhs->dot(outStream, this->id);
    break;
  case CONSTANT:
    outStream << "N" << this->id << " [label=\"CONSTANT: " << bitsToStr(*getBits()) << "\"];" << endl;
    break;
  case VARIABLE:
    outStream << "N" << this->id << " [label=\"VARIABLE: " << bitsToStr(*getBits()) << "\"];" << endl;
    break;
  case NUMBER:
    outStream << "N" << this->id << " [label=\"NUMBER" << "\"];" << endl;
    break;
  case FINISHED:
    outStream << "N" << this->id << " [label=\"FINISHED" << "\"];" << endl;
    break;
  case TRACE:
    outStream << "N" << this->id << " [label=\"TRACE\"];" << endl;
    lhs->dot(outStream, this->id);
    break;
  case FEATURES:
    outStream << "N" << this->id << " [label=\"FEATURES ";
    getFeatures()->print(outStream, FALSE_HTML);
    outStream << "\"];" << endl;
    break;
  case LIST:
    outStream << "N" << this->id << " [label=\"LIST\"];" << endl;
    break;
  case FILTER:
    outStream << "N" << this->id << " [label=\"FILTER\"];" << endl;
    break;
  case UNIF:
    outStream << "N" << this->id << " [label=\"UNIF\"];" << endl;
    lhs->dot(outStream, this->id);
    rhs->dot(outStream, this->id);
    break;
  case UP:
    outStream << "N" << this->id << " [label=\"↑\"];" << endl;
    break;
  case UP2:
    outStream << "N" << this->id << " [label=\"⇑\"];" << endl;
    break;
  case DOLLAR:
    outStream << "N" << this->id << " [label=\"$";
    outStream << getFirst()+1;
    if (getSecond()!=UINT_MAX){
      outStream << "." << getSecond()+1;
    }
    outStream << "\"];" << endl;
    break;
  case DOWN:
    outStream << "N" << this->id << " [label=\"↓";
    outStream << getFirst()+1;
    if (getSecond()!=UINT_MAX){
      outStream << "." << getSecond()+1;
    }
    outStream << "\"];" << endl;
    break;
  case DOLLARS:
    outStream << "N" << this->id << " [label=\"DOLLARS\"];" << endl;
    lhs->dot(outStream, this->id);
    if (rhs)
      rhs->dot(outStream, this->id);
    break;
  case ORDER:
    outStream << "N" << this->id << " [label=\"ORDER\"];" << endl;
    lhs->dot(outStream, this->id);
    break;
  case DOWN2:
    outStream << "N" << this->id << " [label=\"⇓";
    outStream << getFirst()+1;
    outStream << "\"];" << endl;
    break;
  case IF:
    outStream << "N" << this->id << " [label=\"IF\"];" << endl;
    lhs->dot(outStream, this->id);
    rhs->dot(outStream, this->id);
    break;
  case THEN:
    outStream << "N" << this->id << " [label=\"THEN\"];" << endl;
    lhs->dot(outStream, this->id, "1");
    if (rhs)
      rhs->dot(outStream, this->id, "2");
    break;
  case STR:
    outStream << "N" << this->id << " [label=\"STR &quot;" << *getStr() << "&quot;\"];" << endl;
    outStream << "&quot;" << *getStr() << "&quot;";
    break;
  case STMS:
    outStream << "N" << this->id << " [label=\"STMS\"];" << endl;
    getStatements()->dot(outStream, this->id);
    break;
  }
}
#endif

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
void
Statement::print(ostream& outStream, int left)
{
  string red="", green="", blue="";
  switch (this->op) {
  case SORT:
  case TEST:
  case AFF:
  case SUBSET:
  case TRACE:
  case FILTER:
  case ORDER:
  case IF:
    for (int j=1 ; j<=left ; j++)
      outStream << "&nbsp;";
    break;
  default:
    break;
  }

  if (isSetFlags(Flags::CHOOSEN))
    {red="00"; green="FF"; blue="00";}
  if (isSetFlags(Flags::REJECTED))
    {red="AA"; green="00"; blue="00";}
  if (isSetFlags(Flags::SEEN))
    {red="00"; green="00"; blue="FF";}
  if (isSetFlags(Flags::DISABLE))
    {red="D0"; green="D0"; blue="D0";}
  if (isSetFlags(Flags::BOTTOM))
    {red="FF"; green="00"; blue="00";}
  string color="";
  if (red!="" || green!="" || blue!="")
    color="#"+red+green+blue;
  if (color!="")
    outStream << "<SPAN style=\"color:" << color << ";\">";
  
  // if (isSetFlags(Flags::SEEN))
  //   outStream << "•";
  
  switch (this->op) {
  case SORT:
    outStream << "sort&nbsp;";
    lhs->print(outStream);
    outStream << " with&nbsp;";
    rhs->print(outStream);
    break;
  case TEST:
    outStream << "test&nbsp;";
    lhs->print(outStream);
    break;
  case NIL:
    outStream << "NIL";
    break;
  case TRUE:
    outStream << "TRUE";
    break;
  case FINISHED:
    outStream << "finished";
    break;
  case AFF:
    lhs->print(outStream);
    outStream << "&nbsp;:=&nbsp;";
    rhs->print(outStream);
    break;
  case SUBSET:
    lhs->print(outStream);
    outStream << "&nbsp;⊂&nbsp;";
    rhs->print(outStream);
    break;
  case FCT:
    switch (this->getFct()) {
    case ABS:
      outStream << "&nbsp;abs(";
      lhs->print(outStream);
      outStream << ")&nbsp;";
      break;
    case NOT:
      outStream << "¬";
      outStream << "&nbsp;(";
      lhs->print(outStream);
      outStream << ")&nbsp;";
      break;
    case AND:
      outStream << "&nbsp;(";
      // if (  (lhs->getFct()==OR)
      // 	    &&(rhs->getFct()==OR)
      // 	    &&(lhs->lhs->getFct()==NOT)
      // 	    &&(rhs->rhs->getFct()==NOT)
      // 	    &&(lhs->lhs->lhs->signature()==rhs->lhs->signature())
      // 	    &&(lhs->rhs->signature()==rhs->rhs->lhs->signature())){
      // 	lhs->lhs->lhs->print(outStream);
      // 	outStream << "&nbsp;⇔&nbsp;";
      // 	rhs->rhs->lhs->print(outStream);
      // } else {
      // 
      lhs->print(outStream);
      outStream << "&nbsp;∧&nbsp;";
      rhs->print(outStream);
      //      }
      outStream << ")&nbsp;";
      break;
    case OR:
      outStream << "&nbsp;(";
      // if (lhs->getFct()==NOT){
      // 	lhs->lhs->print(outStream);
      // 	outStream << "&nbsp;⇒&nbsp;";
      // 	rhs->print(outStream);
      // } else {
      //
      lhs->print(outStream);
      outStream << "&nbsp;∨&nbsp;";
      rhs->print(outStream);
      //}
      outStream << ")&nbsp;";
      break;
    case EQUAL:
      outStream << "&nbsp;(";
      lhs->print(outStream);
      outStream << "&nbsp;=&nbsp;";
      rhs->print(outStream);
      outStream << ")&nbsp;";
      break;
    case PLUS:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;+&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case MINUS:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;-&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case TIMES:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;*&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case DIVIDE:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;/&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case MODULO:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;%&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case LT:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;<&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case LE:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;≤&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case GT:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;>&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case GE:
      outStream << "(";
      lhs->print(outStream);
      outStream << "&nbsp;≥&nbsp;";
      rhs->print(outStream);
      outStream << ")";
      break;
    case MINUS_U:
      outStream << "-&nbsp;";
      lhs->print(outStream);
      break;
    }
    break;
  case CONSTANT:
  case VARIABLE:
    outStream << bitsToStr(*getBits());
    break;
  case TRACE:
    outStream << "trace&nbsp;";
    lhs->print(outStream);
    break;
  case FEATURES:
    getFeatures()->print(outStream, FALSE_HTML);
    break;
  case LIST:
    getList()->print(outStream, true);
    break;
  case FILTER:
    getFeatures()->print(outStream, FALSE_HTML);
    break;
  case UNIF:
    outStream << "&nbsp;(";
    lhs->print(outStream);
    outStream << "&nbsp;∪&nbsp;";
    rhs->print(outStream);
    outStream << ")&nbsp;";
    break;
  case UP:
    outStream << "↑";
    break;
  case UP2:
    outStream << "⇑";
    break;
  case DOLLAR:
    outStream << "$";
    outStream << getFirst()+1;
    if (getSecond()!=UINT_MAX){
      outStream << ":" << getSecond()+1;
    }
    break;
  case DOWN:
    outStream << "↓";
    outStream << getFirst()+1;
    if (getSecond()!=UINT_MAX){
      outStream << "." << getSecond()+1;
    }
    break;
  case DOLLARS:
    lhs->print(outStream);
    outStream << "&nbsp;";
    if (rhs)
      rhs->print(outStream);
    break;
  case ORDER:
    outStream << "order ";
    lhs->print(outStream);
    break;
  case DOWN2:
    outStream << "⇓";
    outStream << getFirst()+1;
    break;
  case IF:
    outStream << "if (";
    lhs->print(outStream);
    outStream << ")";
    rhs->print(outStream, left);
    break;
  case THEN:
    outStream << "<DIV";
    if (color!="")
      outStream << " style=\"color:" << color << "\"";
    outStream << ">";
    lhs->print(outStream, left+3);
    outStream << "</DIV>";
    if (rhs){
      for (int j=1 ; j<=left ; j++)
	outStream << "&nbsp;";
      outStream << "else ";
      outStream << "<DIV>";
      rhs->print(outStream, left+3);
      outStream << "</DIV>";
    }
    break;
  case STR:
    outStream << "&quot;" << *getStr() << "&quot;";
    break;
  case STMS:
    getStatements()->print(outStream, left);
    break;
  case NUMBER:
    outStream << getNumber();
    break;
  }

  switch (this->op) {
  case SORT:
  case TEST:
  case AFF:
  case SUBSET:
  case TRACE:
  case FILTER:
  case ORDER:
    outStream << ";<BR>";
    break;
  default:
    break;
  }

  if (color!="")
    outStream << "</SPAN>";
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
class Statement*
Statement::copy(const bitset<NBRFLAGS> &savedFlags)
{
  class Statement *statement=this;
  switch (this->op){
  case UP:
  case UP2:
  case NIL:
  case TRUE:
  case DOLLAR:
  case DOLLARS:
  case DOWN:
  case DOWN2:
  case CONSTANT:
  case STR:
  case ORDER:
  case NUMBER:
  case FINISHED:
    statement=this;
    break;
  case FEATURES:
  case FILTER:
    statement=new Statement(this->op, getFeatures()->copy());
    break;
  case LIST:
    statement=new Statement(getList()->copy());
    break;
  case VARIABLE:
    statement=new Statement(this->op, getBits());
    break;
  case TEST:
  case TRACE:
    statement=new Statement(this->op, lhs?lhs->copy(savedFlags):NULL);
    break;
  case IF:
  case THEN:
  case UNIF:
  case SORT:
  case AFF:
  case SUBSET:
    statement=new Statement(this->op, lhs?lhs->copy(savedFlags):NULL, rhs?rhs->copy(savedFlags):NULL);
    break;
  case FCT:
    statement=new Statement(this->op, this->getFct(), lhs?lhs->copy(savedFlags):NULL, rhs?rhs->copy(savedFlags):NULL);
    break;
  case STMS:
    statement=new Statement(getStatements()->copy(savedFlags));
    break;
  }
  statement->resetFlags();
  statement->addFlags(savedFlags & flags);
  return statement;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Features *
Statement::evalFeatures(class Gitem *gitem, bool replaceVariables)
{
  /***
  cerr << "<DIV>evalFeatures</DIV>";
  this->print(cerr);
  cerr << endl;
  gitem->print(cerr, NULL);
  cerr << endl;
  ***/

  class Features *resultFeatures=Features::nil;
  switch (this->op){
  case STR:
  case ORDER:
  case DOLLAR:
  case DOLLARS:
  case TRACE:
  case TEST:
  case CONSTANT:
  case NIL:
  case TRUE:
  case IF:
  case THEN:
  case AFF:
  case SUBSET:
  case DOWN:
  case UP2:
  case LIST:
  case SORT:
  case STMS:
  case NUMBER:
  case FCT: 
  case FINISHED: 
    FATAL_ERROR;
    break;
  case FEATURES:
  case FILTER:
    resultFeatures = getFeatures()->copy();
    if (replaceVariables && gitem->getEnvironment() && gitem->getEnvironment()->size() > 0)
      gitem->getEnvironment()->replaceVariables(resultFeatures);
    break;
  case UP:
    resultFeatures = gitem->getInheritedFeatures()->copy();
    if (replaceVariables && gitem->getEnvironment() && gitem->getEnvironment()->size() > 0)
      gitem->getEnvironment()->replaceVariables(resultFeatures);
    break;
  case VARIABLE:
    if (gitem->getEnvironment()){
      class Value *value=gitem->getEnvironment()->_find(*getBits());
      if (value==NULL)
	FATAL_ERROR;
      if (value && value->getType()==Value::FEATURES)
	resultFeatures=value->getFeatures()->copy();
    }
    break;
  case DOWN2:
    resultFeatures=gitem->getSynthesizeSonFeatures()[getFirst()]->copy();
    if (replaceVariables && gitem->getEnvironment() && gitem->getEnvironment()->size() > 0)
      gitem->getEnvironment()->replaceVariables(resultFeatures);
    break;
  case UNIF:
    {
      class Features *fs1=lhs->evalFeatures(gitem, replaceVariables);
      class Features *fs2=rhs->evalFeatures(gitem, replaceVariables);
      if ((fs1==NULL) || (fs2==NULL)){
	resultFeatures=NULL;
      } else {
	fs1->subFlags(Flags::SEEN);
	fs2->subFlags(Flags::SEEN);
	resultFeatures = unif(fs1, fs2, gitem);
	if (replaceVariables && gitem->getEnvironment() && gitem->getEnvironment()->size() > 0)
	  gitem->getEnvironment()->replaceVariables(resultFeatures);
      }
    }
    break;
  }
  //gitem->getEnvironment()->replaceVariables(resultFeatures);
  //CERR_LINE;
  resultFeatures->deleteNIL();
  /***
  cerr << "<DIV>Result of evalFeatures</DIV>";
  this->print(cerr);
  cerr << endl;
  if (resultFeatures)
    resultFeatures->print(cerr, TRUE_HTML);
  else
    cerr << "NULL";
  cerr << endl;
  ***/
  return resultFeatures;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class List *
Statement::evalList(class Gitem *gitem, bool replaceVariables)
{
  /***
  cerr << "<DIV>evalList</DIV>";
  this->print(cerr);
  cerr << endl;
  ***/

  class List *resultList=List::nil;
  switch (this->op){
  case STR:
  case ORDER:
  case DOLLAR:
  case DOLLARS:
  case TRACE:
  case TEST:
  case CONSTANT:
  case NIL:
  case TRUE:
  case IF:
  case THEN:
  case AFF:
  case SUBSET:
  case DOWN:
  case UP2:
  case FEATURES:
  case FILTER:
  case UP:
  case DOWN2:
  case UNIF:
  case STMS:
  case NUMBER:
  case FCT:
  case FINISHED:
    FATAL_ERROR;
    break;
  case SORT:
    {
      class Value *v=lhs->evalValue(gitem, replaceVariables);
      class Value *with=rhs->evalValue(gitem, replaceVariables);
      if (v==NULL)
	resultList=NULL;
      else if (v->isNil())
	resultList=List::nil;
      else if (v->isList())
	resultList=v->getList()->copy();
      else 
	WARNING_MSG("sorting something which is not a list");
      if ((with!=NULL)
	  && (!with->isNil())
	  && (with->isConstant())){
	resultList->sort(with->getBits());
	//NOT_YET;
      }
      else 
	WARNING_MSG("failing sort");
    }
    break;
  case LIST:
    resultList = getList()->copy();
    if (replaceVariables && gitem->getEnvironment() && gitem->getEnvironment()->size() > 0)
      gitem->getEnvironment()->replaceVariables(resultList);
    break;
  case VARIABLE:
    if (gitem->getEnvironment()){
      class Value *value=gitem->getEnvironment()->_find(*getBits());
      if (value==NULL){
	FATAL_ERROR;
	resultList=NULL;
      }
      else if (value->isNil())
	resultList=List::nil;
      else if (value->isList())
	resultList=value->getList()->copy();
      else {
	ostringstream oss1, oss2;
	this->print(oss1);
	gitem->getRule()->print(oss2, -1, true, TRUE_HTML);
	ERROR("<P>Variable " + oss1.str() + " not initialized in</P>" + oss2.str());
      } 
    }
    break;
  }
  /***
  cerr << "<DIV>Result of evalList</DIV>";
  this->print(cerr);
  cerr << endl;
  if (resultList)
    resultList->print(cerr, TRUE_HTML);
  else
    cerr << "NULL";
  cerr << endl;
  ***/
  return resultList;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Value *
Statement::evalValue(class Gitem *gitem, bool replaceVariables)
{
  /***
  cerr << "<DIV>evalValue (" << replaceVariables << ")";
  gitem->print(cerr, NULL);
  this->print(cerr, 0);
  cerr << "</DIV>";
  ***/

  class Value *resultValue=NULL;
  class Features *resultFeatures=NULL;
  class List *resultList=NULL;
  switch (this->op){
  case NIL:
    resultValue=Value::_nil;
    break;
  case TRUE:
    resultValue=Value::_true;
    break;
  case FINISHED:
    if (gitem->isFinished())
      resultValue=Value::_true;
    else 
      resultValue=Value::_nil;
    break;
  case ORDER:
  case DOLLARS:
  case TRACE:
  case IF:
  case AFF:
  case SUBSET:
  case DOWN:
  case UP2:
  case THEN:
  case STR:
  case FILTER:
  case STMS:
    FATAL_ERROR;
    break;
    
  case DOLLAR:
    {
      class Terms *t=gitem->getRule()->getRhs()[getFirst()];
      // if ($i)
      if (t->isOptional())
	resultValue=Value::_nil;
      else {
	// if ($i)
	if (getSecond()==UINT_MAX)
	  resultValue=Value::_true;
	//if ($i:j)
	else {
	  if (getSecond() == gitem->getIndexTerms()[getFirst()]){
	    resultValue=Value::_true;
	  }
	  else {
	    resultValue=Value::_nil;
	  }
	}
      }
      goto valueBuilt;
    }
    break;
    
  case NUMBER:
    {
      resultValue = new Value(getNumber());
      goto valueBuilt;
    }
    break;
  case FEATURES:
    resultFeatures = getFeatures();
    break;
  case UP:
    resultFeatures = gitem->getInheritedFeatures();
    break;
  case VARIABLE:
    if (replaceVariables && gitem->getEnvironment()){
      class Value *value=gitem->getEnvironment()->_find(*getBits());
      resultValue=value;
      goto valueBuilt;
    }
    else if (replaceVariables){
      resultValue=NULL;
      goto valueBuilt;
    } 
    else {
      resultValue=new Value(getBits(), Value::VARIABLE);;
    }
    break;
  case CONSTANT:
    resultValue=new Value(getBits(), Value::CONSTANT);
    break;
  case DOWN2:
    resultFeatures=gitem->getSynthesizeSonFeatures()[getFirst()];
    break;
  case TEST:
    resultValue = lhs->evalValue(gitem, replaceVariables);
    goto valueBuilt;
    break;
  case UNIF:
    {
      class Features *fs1=lhs->evalFeatures(gitem, replaceVariables);
      if (fs1==NULL){
	resultValue=NULL;
	goto valueBuilt;
      } else {
	class Features *fs2=rhs->evalFeatures(gitem, replaceVariables);
	if (fs2==NULL){
	  resultValue=NULL;
	  goto valueBuilt;
	} else {
	  fs1->subFlags(Flags::SEEN);
	  fs2->subFlags(Flags::SEEN);
	  resultFeatures = unif(fs1, fs2, gitem);
	}
      }
    }
    break;
  case LIST:
  case SORT:
    resultList=evalList(gitem, replaceVariables);
    break;
  case FCT:
    switch (getFct()){
    case ABS:
      {
	class Value *v=lhs->evalValue(gitem, replaceVariables);
	if ((v==NULL))
	  resultValue=NULL;
	else if ((v->isNumber()))
	  resultValue=new Value(fabs(v->getNumber()));
	else
	  resultValue=NULL;
	goto valueBuilt;
      }
      break;
    case PLUS:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL) || (v2==NULL))
	  resultValue=NULL;
	else if ((v1->isNumber()) && (v2->isNumber()))
	  resultValue=new Value(v1->getNumber() + v2->getNumber());
	else
	  resultValue=NULL;
	goto valueBuilt;
      }
      break;
    case MINUS:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL) || (v2==NULL))
	  resultValue=NULL;
	else if ((v1->isNumber()) && (v2->isNumber()))
	  resultValue=new Value(v1->getNumber() - v2->getNumber());
	else
	  resultValue=NULL;
	goto valueBuilt;
      }
      break;
    case TIMES:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL) || (v2==NULL))
	  resultValue=NULL;
	else if ((v1->isNumber()) && (v2->isNumber()))
	  resultValue=new Value(v1->getNumber() * v2->getNumber());
	else
	  resultValue=NULL;
	goto valueBuilt;
      }
      break;
    case DIVIDE:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL) || (v2==NULL))
	  resultValue=NULL;
	else if ((v1->isNumber()) && (v2->isNumber()))
	  resultValue=new Value(v1->getNumber() / v2->getNumber());
	else
	  resultValue=NULL;
	goto valueBuilt;
      }
      break;
    case MODULO:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL) || (v2==NULL))
	  resultValue=NULL;
	else if ((v1->isNumber()) && (v2->isNumber()))
	  resultValue=new Value(fmod(v1->getNumber(), v2->getNumber()));
	else
	  resultValue=NULL;
	goto valueBuilt;
      }
      break;
    case MINUS_U:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL))
	  resultValue=NULL;
	else if ((v1->isNumber()))
	  resultValue=new Value(-v1->getNumber());
	else
	  resultValue=NULL;
	goto valueBuilt;
      }
      break;
    case AND:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL) || (v2==NULL))
	  resultValue=NULL;
	else if ((v1->isNil()) || (v2->isNil()))
	  resultValue=Value::_nil;
	else
	  resultValue=Value::_true;
	goto valueBuilt;
      }
      break;
    case OR:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	if ((v1==NULL) || (v2==NULL)){
	  FATAL_ERROR;//resultValue=NULL;
	}
	else if ((v1->isNil()) && (v2->isNil()))
	  resultValue=Value::_nil;
	else
	  resultValue=Value::_true;
	goto valueBuilt;
      }
      break;
    case EQUAL:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	// si l'une est variable libre
	if ((v1==NULL) || (v2==NULL)){
	  resultValue=Value::_nil;
	}
	else if (v1->equivalent(v2))
	  resultValue=Value::_true;
	else
	  resultValue=Value::_nil;
	goto valueBuilt;
      }
      break;
    case LT:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	// si l'une est variable libre
	if ((v1==NULL) || (v2==NULL)){
	  resultValue=Value::_nil;
	}
	else if (v1->less(v2))
	  resultValue=Value::_true;
	else
	  resultValue=Value::_nil;
	goto valueBuilt;
      }
      break;
    case LE:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	// si l'une est variable libre
	if ((v1==NULL) || (v2==NULL)){
	  resultValue=Value::_nil;
	}
	else if ((v1->less(v2)) || (v1->equivalent(v2)))
	  resultValue=Value::_true;
	else
	  resultValue=Value::_nil;
	goto valueBuilt;
      }
      break;
    case GT:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	// si l'une est variable libre
	if ((v1==NULL) || (v2==NULL)){
	  resultValue=Value::_nil;
	}
	else if (!v1->less(v2))
	  resultValue=Value::_true;
	else
	  resultValue=Value::_nil;
	goto valueBuilt;
      }
      break;
    case GE:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	class Value *v2=rhs->evalValue(gitem, replaceVariables);
	// si l'une est variable libre
	if ((v1==NULL) || (v2==NULL)){
	  resultValue=Value::_nil;
	}
	else if ((!v1->less(v2)) || (v1->equivalent(v2)))
	  resultValue=Value::_true;
	else
	  resultValue=Value::_nil;
	goto valueBuilt;
      }
      break;
    case NOT:
      {
	class Value *v1=lhs->evalValue(gitem, replaceVariables);
	if (v1==NULL){
	  FATAL_ERROR;//resultValue=NULL;
	}
	else if (v1->isNil())
	  resultValue=Value::_true;
	else
	  resultValue=Value::_nil;
	goto valueBuilt;
      }
      break;
    }
    break;
  }
  if (!resultFeatures && !resultValue && !resultList){
    FATAL_ERROR;
  } 
  if (resultList){
    if (replaceVariables && gitem->getEnvironment() && gitem->getEnvironment()->size() > 0)
      gitem->getEnvironment()->replaceVariables(resultList);
    resultValue=new Value(resultList);
  }
  else if (resultFeatures){
    if (resultFeatures->isNil())
      resultValue=Value::_nil;
    else {
      if (replaceVariables && gitem->getEnvironment() && gitem->getEnvironment()->size() > 0)
	gitem->getEnvironment()->replaceVariables(resultFeatures);
      resultValue=new Value(resultFeatures);
    }
  }
 valueBuilt:
  /***
  cerr << "<DIV>Result evalValue ";
  this->print(cerr, TRUE_ROOT);
  cerr << "</DIV>";
  cerr << "<H3>";
  if (resultValue)
    resultValue->print(cerr, TRUE_HTML);
  else
    cerr << "NULL";
  cerr << "</H3>";
  ***/
  return resultValue;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Features *
Statement::unif(class Features *fs1, class Features *fs2, class Gitem *gitem)
{
  /***
  cerr << "<H1>unif</H1>" << endl;
  fs1->print(cerr);
  cerr << endl;
  cerr << " and " << endl;
  fs2->print(cerr);
  cerr << endl;
  ***/
  class Features *result=NULL;
  
  if (fs1->isBottom() || fs2->isBottom()){
    result=Features::bottom;
    goto endUnif;
  }

  if (fs1->isNil() && fs2->isNil()){
    result=Features::nil;
    goto endUnif;
  }

  if (fs1->isNil()){
    result=fs2;
    goto endUnif;
  }

  if (fs2->isNil()){
    result=fs1;
    goto endUnif;
  }

  result=new Features();
  for (list<class Feature *>::const_iterator i1=fs1->begin();
       i1!=fs1->end();
       i1++){
    
    if ((*i1)->getType()==Feature::PRED){
      list<class Feature *>::const_iterator i2=fs2->begin();
      while(i2!=fs2->end()){
	if ((*i2)->getType()==Feature::PRED){
	  
	  switch ((*i1)->getRhs()->getType()){
	  case Value::FORM:
	  case Value::BOOL:
	  case Value::CONSTANT:
	  case Value::VARIABLE:
	  case Value::LIST:
	  case Value::IDENTIFIER:
	  case Value::NUMBER:
	    FATAL_ERROR;
	    break;
	  case Value::FEATURES:
	    if ((*i2)->getRhs()->getType() != Value::FEATURES){
	      result=Features::bottom;
	      goto endUnif;
	    } else {
	      class Features *features=unif((*i1)->getRhs()->getFeatures(), (*i2)->getRhs()->getFeatures(), gitem);
	      if (features->isBottom()){
		result=features;
		goto endUnif;
	      }
	    }
	    break;
	  } 
	  (*i2)->addFlags(Flags::SEEN);
	  break;
	}
	else if ((*i2)->getType()==Feature::FORM){
	  result=Features::bottom;
	  goto endUnif;
	} 
	i2++;
      }
      result->addFeature(*i1);
    }
    
    else if ((*i1)->getType()==Feature::FORM){
      list<class Feature *>::const_iterator i2=fs2->begin();
      while(i2!=fs2->end()){
     	if ((*i2)->getType()==Feature::FORM){
    	  if (*(*i1)->getRhs()->getForm() != *(*i2)->getRhs()->getForm()){
     	    result=Features::bottom;
     	    goto endUnif;
    	  }
	  (*i2)->addFlags(Flags::SEEN);
     	  break;
     	} 
    	if ((*i2)->getType()==Feature::PRED){
     	  result=Features::bottom;
     	  goto endUnif;
    	} 
     	i2++;
      }
      result->addFeature(*i1);
    }
    
    else if ((*i1)->getType()==Feature::CONSTANT){
      list<class Feature *>::const_iterator i2=fs2->begin();
      while(i2!=fs2->end()){
	if (((*i2)->getType()==Feature::CONSTANT) 
	    && ((*i1)->getLhs() & (*i2)->getLhs() ).any()){
	  (*i2)->addFlags(Flags::SEEN);
	  if (((*i1)->getRhs()==NULL)
	      || ((*i2)->getRhs()==NULL)
	      || ((*i1)->getRhs()->getType() != (*i1)->getRhs()->getType())){
	    result=Features::bottom;
	    goto endUnif;
	  }	  
	  switch ((*i1)->getRhs()->getType()){
	  case Value::FORM:
	    FATAL_ERROR;
	    break;
	  case Value::BOOL:
	    {
	      switch ((*i2)->getRhs()->getType()){
	      case Value::FORM:
	      case Value::IDENTIFIER:
	      case Value::FEATURES:
	      case Value::LIST:
	      case Value::CONSTANT:
	      case Value::NUMBER:
		FATAL_ERROR;
		result=Features::bottom;
		goto endUnif;
		break;
	      case Value::BOOL:
	     	if ((*i1)->getRhs()->isNil() != (*i2)->getRhs()->isNil()){
		  result=Features::bottom;
		  goto endUnif;
		} 
		result->addFeature(new Feature((*i1)->getLhs(), (*i1)->getRhs(), Feature::CONSTANT));
		break;
	      case Value::VARIABLE:
		result->addFeature(new Feature((*i2)->getLhs(), (*i1)->getRhs(), Feature::CONSTANT));
		if (gitem->getEnvironment()==NULL)
		  gitem->putEnvironment(new Environment());
		gitem->getEnvironment()->add(*(*i2)->getRhs()->getBits(), (*i1)->getRhs());
		break;
	      }
	    }
	    break;
	  case Value::NUMBER:
	    {
	      switch ((*i2)->getRhs()->getType()){
	      case Value::BOOL:
	      case Value::FORM:
	      case Value::IDENTIFIER:
	      case Value::FEATURES:
	      case Value::LIST:
	      case Value::CONSTANT:
	      	FATAL_ERROR;
		break;
	      case Value::NUMBER:
		if ((*i1)->getRhs()->getNumber() != (*i2)->getRhs()->getNumber()){
		  result=Features::bottom;
		  goto endUnif;
		} 
		result->addFeature(new Feature((*i1)->getLhs(), new Value((*i1)->getRhs()->getNumber()), Feature::CONSTANT));
		break;
	      case Value::VARIABLE:
		result->addFeature(new Feature((*i2)->getLhs(), (*i1)->getRhs(), Feature::CONSTANT));
		if (gitem->getEnvironment()==NULL)
		  gitem->putEnvironment(new Environment());
		gitem->getEnvironment()->add(*(*i2)->getRhs()->getBits(), (*i1)->getRhs());
		break;
	      }
	    }
	    break;
	  case Value::IDENTIFIER:
	    {
	      switch ((*i2)->getRhs()->getType()){
	      case Value::BOOL:
	      case Value::FORM:
	      case Value::CONSTANT:
	      case Value::FEATURES:
	      case Value::LIST:
	      case Value::NUMBER:
	      	FATAL_ERROR;
		break;
	      case Value::IDENTIFIER:
		if ((*i1)->getRhs()->getInteger() != (*i2)->getRhs()->getInteger()){
		  result=Features::bottom;
		  goto endUnif;
		} 
		result->addFeature(new Feature((*i1)->getLhs(), new Value((*i1)->getRhs()->getInteger(), Value::IDENTIFIER), Feature::CONSTANT));
		break;
	      case Value::VARIABLE:
		result->addFeature(new Feature((*i2)->getLhs(), (*i1)->getRhs(), Feature::CONSTANT));
		if (gitem->getEnvironment()==NULL)
		  gitem->putEnvironment(new Environment());
		gitem->getEnvironment()->add(*(*i2)->getRhs()->getBits(), (*i1)->getRhs());
		break;
	      }
	    }
	    break;
	  case Value::CONSTANT:
	    {
	      switch ((*i2)->getRhs()->getType()){
	      case Value::BOOL:
	      case Value::FORM:
	      case Value::IDENTIFIER:
	      case Value::FEATURES:
	      case Value::LIST:
	      case Value::NUMBER:
		(*i2)->getRhs()->print(cerr);
	      	FATAL_ERROR;
		break;
	      case Value::CONSTANT:
		if (((*(*i1)->getRhs()->getBits()) & (*(*i2)->getRhs()->getBits())).none()){
		  result=Features::bottom;
		  goto endUnif;
		} 
		result->addFeature(new Feature((*i1)->getLhs(), new Value(new bitset<MAXBITS>((*(*i1)->getRhs()->getBits()) & (*(*i2)->getRhs()->getBits())), Value::CONSTANT), Feature::CONSTANT));
		break;
	      case Value::VARIABLE:
		result->addFeature(new Feature((*i2)->getLhs(), (*i1)->getRhs(), Feature::CONSTANT));
		if (gitem->getEnvironment()==NULL)
		  gitem->putEnvironment(new Environment());
		gitem->getEnvironment()->add(*(*i2)->getRhs()->getBits(), (*i1)->getRhs());
		break;
	      }
	    }
	    break;
	  case Value::VARIABLE:
	    result->addFeature(new Feature((*i1)->getLhs(), (*i2)->getRhs(), Feature::CONSTANT));
	    if (gitem){
	      if (gitem->getEnvironment()==NULL)
		gitem->putEnvironment(new Environment());
	      gitem->getEnvironment()->add(*(*i1)->getRhs()->getBits(), (*i2)->getRhs());
	    }
	    break;
	  case Value::FEATURES:
	    {
	      class Features *features=unif((*i1)->getRhs()->getFeatures(), (*i2)->getRhs()->getFeatures(), gitem/*, synthesizer*/);
	      if (features->isBottom()){
		result=features;
		goto endUnif;
	      } else
		result->addFeature(new Feature((*i1)->getLhs(), new Value(features), Feature::CONSTANT));
	    }
	    break;
	  case Value::LIST:
	    result->addFeature(new Feature((*i1)->getLhs(), (*i1)->getRhs(), Feature::CONSTANT));
	    break;
	  } 
	  break;
	} 
	i2++;
      }
      if (i2==fs2->end())
	result->addFeature(*i1);
    } 
  }

  for (list<class Feature *>::const_iterator i2=fs2->begin();
       i2!=fs2->end();
       i2++){
    if ((*i2)->isUnsetFlags(Flags::SEEN))
      result->addFeature(*i2);
  }
  
  for (list<class Feature *>::const_iterator i1=fs1->begin();
       i1!=fs1->end();
       i1++){
    (*i1)->subFlags(Flags::SEEN);
  }

  for (list<class Feature *>::const_iterator i2=fs2->begin();
       i2!=fs2->end();
       i2++){
    (*i2)->subFlags(Flags::SEEN);
  }
  
 endUnif:
  
  /***
  cerr << "result:";
  if (result)
    result->print(cerr);
  else
    cerr << "NULL";
  cerr << endl;
  ***/
  
  return result;
}

/* ************************************************************
 * ↓1 := … 
 ************************************************************ */
void
Statement::buildInheritedSonFeatures(class Gitem *gitem, class Statement *root, class Synthesizer *synthesizer)
{
  /***
  cerr << "buildInheritedSonFeatures: ";
  print (cerr);
  cerr << endl;
  ***/
  class Features *features=rhs->evalFeatures(gitem, true); 
  if (features->isNil()){
    root->addFlags(Flags::BOTTOM);
    gitem->addFlags(Flags::BOTTOM);
  } else{
    root->addFlags(Flags::SEEN);
    gitem->getInheritedSonFeatures()[gitem->getIndex()] = features;
  }
}

/* ************************************************************
 * ⇑ := …
 ************************************************************ */
void
Statement::buildSynthesizeFeatures(class Gitem *gitem, class Statement *root, class Synthesizer *synthesizer)
{
  class Features *features=rhs->evalFeatures(gitem, true);
  if (features->isNil()){
    root->addFlags(Flags::BOTTOM);
    gitem->addFlags(Flags::BOTTOM);
  } else {
    root->addFlags(Flags::SEEN);
    gitem->putSynthesizeFeatures(features);
  }
}

/* ************************************************************
 * [ … X … ] ⊂ ⇓1;
 * X := ⇓1;
 ************************************************************ */
void
Statement::buildEnvironmentWithSynthesize(class Gitem *gitem, class Statement *root, class Synthesizer *synthesizer)
{
  switch (this->op) {
  case AFF:
    {
      // X :=  ⇓1;
      root->addFlags(Flags::SEEN);
      class Environment *environment;
      if (gitem->getEnvironment()){
	environment=gitem->getEnvironment();
      } else {
	environment = new Environment();
	gitem->putEnvironment(environment);
      }
      class Features *sonSynth = rhs->evalFeatures(gitem, true);
      if (sonSynth)
	environment->add(*(lhs->getBits()), new Value(sonSynth));
      else
	FATAL_ERROR;
    }
    break;
    
  case SUBSET:
    {
      // [ … X … ] ⊂  ⇓1;
      root->addFlags(Flags::SEEN);
      class Features *left=lhs->evalFeatures(gitem, false);
      if (left==NULL)
	FATAL_ERROR;
      class Environment *environment;
      if (gitem->getEnvironment())
	environment=gitem->getEnvironment();
      else {
	environment = new Environment();
	gitem->putEnvironment(environment);
      }
      class Features *sonSynth = rhs->evalFeatures(gitem, true);
      if (sonSynth){
	if (!left->buildEnvironment(environment, sonSynth, true)){
	  root->addFlags(Flags::BOTTOM);
	  gitem->addFlags(Flags::BOTTOM);
	}
      } else {
	FATAL_ERROR;
      }
    }
    break;
    
  default:
    FATAL_ERROR;
    break;
  }
}

/* ************************************************************
 * [ … X … ] ⊂ ↑;
 * X := ↑;
 ************************************************************ */
void
Statement::buildEnvironmentWithInherited(class Gitem *gitem, class Statement *root, class Synthesizer *synthesizer)
{
  /***
  cerr << "<DIV>buildEnvironmentWithInherited ";
  this->print(cerr, "", TRUE_ROOT);
  cerr << "</DIV>";
  ***/
  switch (this->op) {
  case AFF:
    {
      // 	 X = ↑;
      addFlags(Flags::SEEN);
      class Features *right=rhs->evalFeatures(gitem, true);
      if (right==NULL)
	FATAL_ERROR;
      class Environment *environment;
      if (gitem->getEnvironment()){
	environment=gitem->getEnvironment();
      } else {
	environment = new Environment();
	gitem->putEnvironment(environment);
      }
      environment->add(*(lhs->getBits()), new Value(right));
    }
    break;
      
  case SUBSET:
    {
      root->addFlags(Flags::SEEN);
      class Features *left=lhs->evalFeatures(gitem, false);
      if (left==NULL)
	FATAL_ERROR;
      class Features *right=rhs->evalFeatures(gitem, true);
      if (right==NULL)
	FATAL_ERROR;
      class Environment *environment;
      if (gitem->getEnvironment()){
	environment=gitem->getEnvironment();
      } else {
	environment = new Environment();
	gitem->putEnvironment(environment);
      }
      if (!left->buildEnvironment(environment, right, true)){
	root->addFlags(Flags::BOTTOM);
	gitem->addFlags(Flags::BOTTOM);
      }
    }
    break;
    
  default:
    FATAL_ERROR;
    break;
  }
}

/* ************************************************************
// [ … X … ] ⊂ Y;
// [ … X … ] ⊂ [ … ];
// X := a;
// X := [ … ];
// X := (...);
// X := sort X with a;
// X := <expr>
// ( … ) := ( … )
// ( … ) := sort X with a;
// ( … ) := X;
 ************************************************************ */
void
Statement::buildEnvironmentWithValue(class Gitem *gitem, class Statement *root, class Synthesizer *synthesizer, bool *effect)
{
  /***
  cerr << "<DIV>buildEnvironmentWithValue</DIV>";
  cerr << "<DIV>";
  this->print(cerr, "BLACK", 0);
  cerr << "</DIV>";
  ***/
  switch (this->op) {
  case AFF:
  
    // 	 X := a;
    // 	 X := Y;
    // 	 X := … ∪ … ;
    // 	 X := [ … ];
    // 	 X := <expr>;
    // 	 X := ( … )
    // 	 X := sort X with a;
    
    if (lhs->getOp()==VARIABLE){
      root->addFlags(Flags::SEEN);
      *effect=true;
      class Value *right=rhs->evalValue(gitem, true);
      if (right==NULL)
	FATAL_ERROR;
      class Environment *environment;
      if (gitem->getEnvironment()){
	environment=gitem->getEnvironment();
      } else {
	environment = new Environment();
	gitem->putEnvironment(environment);
      }
      environment->add(*(lhs->getBits()), right);
    }
    
    // 	 ( … ) := X;
    // 	 ( … ) := ( … )
    // 	 ( … ) := sort X with a;
    else if (lhs->getOp()==LIST){
      root->addFlags(Flags::SEEN);
      *effect=true;
      class List *right=rhs->evalList(gitem, true);
      if (right==NULL)
	FATAL_ERROR;
      if (right->isNil()){
	root->addFlags(Flags::BOTTOM);
	gitem->addFlags(Flags::BOTTOM);
      }
      class List *left=lhs->evalList(gitem, false);
      if (left==NULL)
	FATAL_ERROR;
      class Environment *environment;
      if (gitem->getEnvironment()){
	environment=gitem->getEnvironment();
      } else {
	environment = new Environment();
	gitem->putEnvironment(environment);
      }
      if (!left->buildEnvironment(environment, right, true)){
	root->addFlags(Flags::BOTTOM);
	gitem->addFlags(Flags::BOTTOM);
      }
    }
    
    else 
      FATAL_ERROR;
    break;

  case SUBSET:
    {
      class Features *right=rhs->evalFeatures(gitem, true);
      if (right==NULL)
	FATAL_ERROR;
      if (right->isNil())
	;
      root->addFlags(Flags::SEEN);
      *effect=true;
      class Features *left=lhs->evalFeatures(gitem, false);
      if (left==NULL)
	FATAL_ERROR;
      class Environment *environment;
      if (gitem->getEnvironment()){
	environment=gitem->getEnvironment();
      } else {
	environment = new Environment();
	gitem->putEnvironment(environment);
      }
      if (!left->buildEnvironment(environment, right, true)){
	root->addFlags(Flags::BOTTOM);
	gitem->addFlags(Flags::BOTTOM);
      }
    }
    break;
  
  default:
    FATAL_ERROR;
    break;
  }
}

/* ************************************************************
 * test
 ************************************************************ */
void
Statement::test(class Gitem *gitem, class Statement *root, class Synthesizer *synthesizer)
{
  /***
  cerr << "<DIV>test</DIV>";
  cerr << "<DIV>";
  this->print(cerr, "BLACK", 0);
  cerr << "</DIV>";
  ***/
  switch (this->op) {
  case TEST:
    {
      root->addFlags(Flags::SEEN);
      class Value *v=lhs->evalValue(gitem, true);
      if (v
	  && (v->isNil() 
	      || ((v->getType()==Value::FEATURES) && (v->getFeatures()->isBottom())))){
	root->addFlags(Flags::BOTTOM);
	gitem->addFlags(Flags::BOTTOM);
      }
    }
    break;
  default:
    FATAL_ERROR;
    break;
  }
}

/* ************************************************************
 * filter
 ************************************************************ */
void
Statement::filter(class Gitem *gitem, class Statement *root, class Synthesizer *synthesizer)
{
  /***
      cerr << "<DIV>filter ";
      gitem->print(cerr, NULL);
      cerr << "</DIV>";
  ***/
  if (isSetFlags(Flags::DISABLE | Flags::SEEN)){
    FATAL_ERROR;
  } else {
    root->addFlags(Flags::SEEN);
    class Features *lhs=getFeatures();
    if (lhs==NULL){
      FATAL_ERROR;
    }
    class Environment *environment;
    // Subsitue les variables dans gitem->getInheritedFeatures()
    if (gitem->getEnvironment()){
      environment=gitem->getEnvironment();
      if (gitem->getEnvironment()->size())
	gitem->getEnvironment()->replaceVariables(gitem->getInheritedFeatures());
    } else {
      environment = new Environment(); 
      gitem->putEnvironment(environment);
    }
    class Features *rhs = gitem->getInheritedFeatures();
    if (rhs==NULL){
      FATAL_ERROR;
    }
    if (!lhs->buildEnvironment(environment, rhs, false)){
      root->addFlags(Flags::BOTTOM);
      gitem->addFlags(Flags::BOTTOM);

    }
    if (gitem->getEnvironment()->size()==0){
      delete gitem->getEnvironment();
      gitem->putEnvironment(NULL);
    }
  }
  /***
      cerr << "<DIV>filter done";
      gitem->print(cerr, NULL);
      cerr << "</DIV>";
  ***/
}

/* ************************************************************
 * trace
 ************************************************************ */
void
Statement::trace(class Gitem *gitem, class Statement *root, ostream& outStream, class Synthesizer *synthesizer)
{
  addFlags(Flags::SEEN);
  if (lhs->getOp()==STR){
    outStream << *lhs->getStr();
  } else {
    class Value *value = lhs->evalValue(gitem, true);
    if (value==NULL)
      FATAL_ERROR;
    value->print(outStream, TRUE_HTML);
  }
}

/* ************************************************************
 * order
 ************************************************************ */
void
Statement::order(class Gitem *gitem, class Synthesizer *synthesizer)
{
  addFlags(Flags::SEEN);
  unsigned int i=0;
  for (class Statement *eq = getLhs();
       eq!=NULL;
       eq=eq->getRhs()){
    gitem->getIndexes()[i++]=eq->getLhs()->getFirst();
  }
}

//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
void
Statement::customizeVariables(unsigned int i)
{
  switch (this->op) {
  case VARIABLE:
    {
      ostringstream oss;
      oss << bitsToStr(*getBits()) << "_" << i;
      string str = oss.str();
      bitset<MAXBITS> *variableBits=varTableAdd(str);
      this->putBits(variableBits);
      sign="";
      signature();
    }
    break;
  case CONSTANT:
  case NIL:
  case STR:
  case TRUE:
  case NUMBER:
  case UP:
  case UP2:
  case DOLLAR:
  case DOWN2:
  case DOWN:
  case DOLLARS:
  case FINISHED:
    break;
  case AFF:
  case SUBSET:
  case FCT:
  case UNIF:
  case SORT:
  case TEST:
  case TRACE:
  case ORDER:
  case IF:
  case THEN:
    if (lhs)
      lhs->customizeVariables(i);
    if (rhs)
      rhs->customizeVariables(i);
    break;
  case FEATURES:
  case FILTER:
    getFeatures()->customizeVariables(i);
    break;
  case LIST:
    getList()->customizeVariables(i);
    break;
  case STMS:
    getStatements()->customizeVariables(i);
    break;
  }
}

/* ************************************************************
 *
 ************************************************************ */
string
Statement::signature(){
  ostringstream oss;
  if (sign.size())
    return sign;
  this->print(oss);
  sign=oss.str();
  return sign;
}

/* ************************************************************
 *
 ************************************************************ */
void
Statement::disable(class Statement *root, class Gitem *gitem)
{
  /***
  cerr << "<DIV>disable ";
  //gitem->print(cerr, NULL);
  this->print(cerr, TRUE_ROOT);
  cerr << "</DIV>";
  ***/
  //root->subFlags(Flags::DISABLE);
  switch (this->op) {
  case AFF:
    rhs->disable(root, gitem);
    if (root->isUnsetFlags(Flags::DISABLE)){
      switch (lhs->getOp()){
      case DOWN: 
	lhs->disable(root, gitem);
	break;
      default:
	break;
      }
    }
    break;

  case SUBSET:
    rhs->disable(root, gitem);
    break;

  case IF:
    lhs->disable(root, gitem);
    break;

  case STMS:
    for (list<class Statement *>::const_iterator i=getStatements()->begin();
	 i!=getStatements()->end();
	 i++){
      if ((*i)->isSetFlags(Flags::SEEN))
	continue;
      (*i)->disable(*i, gitem);
    }
    break;

  case TEST:
  case TRACE:
    lhs->disable(root, gitem);
    break;

  case FCT:
  case UNIF:
  case ORDER:
    if (lhs)
      lhs->disable(root, gitem);
    if (rhs)
      rhs->disable(root, gitem);
    break;

  case DOWN:
    if ((gitem->getRhs()[getFirst()]->isUnchecked())
	|| (getFirst()!=gitem->getIndex())
	|| (gitem->getTerms()->isOptional())){
      root->addFlags(Flags::DISABLE);
    }
    break;

  case DOLLAR:
    if (gitem->getRhs()[getFirst()]->isUnchecked())
      root->addFlags(Flags::DISABLE);
    break;

  case DOWN2:
    if (gitem->getSynthesizeSonFeatures()[getFirst()]->isNil())
      root->addFlags(Flags::DISABLE);
    break;

  case VARIABLE:
    {
      if (gitem->getEnvironment()){
	if (!(gitem->getEnvironment()->exists(*getBits())))
	  root->addFlags(Flags::DISABLE);
      }
      else
	root->addFlags(Flags::DISABLE);
    }
    break;

  case LIST:
    getList()->disable(root, gitem);
    break;

  case FEATURES:
    getFeatures()->disable(root, gitem);
    break;

  case DOLLARS:
  case SORT:
  case FILTER:
  case THEN:
  case CONSTANT:
  case NIL:
  case TRUE:
  case UP2:
  case STR:
  case UP:
  case FINISHED:
  case NUMBER:
    break;
  }
  /***
  cerr << "<DIV>disable DONE (" << (root->isSetFlags(Flags::DISABLE)?"yes":"no") << ")";
  //gitem->print(cerr, NULL);
  this->print(cerr, TRUE_ROOT);
  cerr << "</DIV>";
  ***/
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool 
Statement::apply(Synthesizer *synthesizer, GitemSet *state, class Gitem *item, bool *modification)
{
  bool ret=true;
  /***
      cerr << "<DIV>apply statement";
      //item->print(cerr, NULL);
      print(cerr);
      cerr << "</DIV>";
  ***/
  if (getOp()==Statement::IF){
    
    class Statement *left = getRhs()->getLhs();
    class Statement *right = getRhs()->getRhs();
    
    int resif=2;// 0:false, 1:true
    if (left->isSetFlags(Flags::CHOOSEN))
      resif=1; 
    else if (right && right->isSetFlags(Flags::CHOOSEN))
      resif=0; 
    else {
      class Value *res=getLhs()->evalValue(item, true);
      if ((res==NULL) || (res==Value::_nil)){
	left->addFlags(Flags::REJECTED);
	if (right)
	  right->addFlags(Flags::CHOOSEN);
	resif=0;
      }
      else {
	left->addFlags(Flags::CHOOSEN);
	if (right)
	  right->addFlags(Flags::REJECTED);
	resif=1;
      }
    }
    if (resif==1){
      left->disable(left, item);
      if (left->isUnsetFlags(Flags::DISABLE)){
	if (!left->apply(synthesizer, state, item, modification)){
	  addFlags(Flags::BOTTOM);
	  item->addFlags(Flags::BOTTOM);
	}
      }
    }
    else if (resif==0){
      if (right){
	right->disable(right, item);
	if (right->isUnsetFlags(Flags::DISABLE)){
	  if (!right->apply(synthesizer, state, item, modification)){
	    addFlags(Flags::BOTTOM);
	    item->addFlags(Flags::BOTTOM);
	  }
	}
      }
    }
  }
  
  // […]
  else if (getOp()==Statement::FILTER){
    filter(item, this, synthesizer);
  }
  
  // ↓1 := … 
  else if ((getOp()==Statement::AFF)
	   && (getLhs()->getOp()==Statement::DOWN)){
    buildInheritedSonFeatures(item, this, synthesizer);
  }
  
  // [ … X … ] ⊂ ⇓1
  // X := ⇓1
  else if (((getOp()==Statement::SUBSET)
	    && (getRhs()->getOp()==Statement::DOWN2)
	    && (getLhs()->getOp()==Statement::FEATURES))
	   ||
	   ((getOp()==Statement::AFF)
	    && (getRhs()->getOp()==Statement::DOWN2)
	    && (getLhs()->getOp()==Statement::VARIABLE))){
    buildEnvironmentWithSynthesize(item, this, synthesizer);
  }
  
  // [ … X … ] ⊂ ↑
  // X := ↑
  else if (((getOp()==Statement::SUBSET)
	    && (getRhs()->getOp()==Statement::UP)
	    && (getLhs()->getOp()==Statement::FEATURES))
	   ||
	   ((getOp()==Statement::AFF)
	    && (getRhs()->getOp()==Statement::UP)
	    && (getLhs()->getOp()==Statement::VARIABLE))){
    buildEnvironmentWithInherited(item, this, synthesizer);
  }
  
  // X := a;
  // X := Y;
  // X := … ∪ … ;
  // X := [ … ];
  // X := <expr>;
  // X := ( … )
  // X := sort X with a;
  //
  // ( … ) := X;
  // ( … ) := ( … )
  // ( … ) := sort X with a;
  //
  // […X…] ⊂ Y
  // […X…] ⊂ […]
  else if (((getOp()==Statement::AFF)
	    && (getLhs()->getOp()==Statement::VARIABLE)
	    && ((getRhs()->getOp()==Statement::CONSTANT)
		||(getRhs()->getOp()==Statement::VARIABLE)
		||(getRhs()->getOp()==Statement::UNIF)
		||(getRhs()->getOp()==Statement::FEATURES)
		||(getRhs()->getOp()==Statement::NUMBER)
		||(getRhs()->getOp()==Statement::FCT)
		||(getRhs()->getOp()==Statement::LIST)
		||(getRhs()->getOp()==Statement::SORT)))
	   ||((getOp()==Statement::AFF)
	      && (getLhs()->getOp()==Statement::LIST)
	      && ((getRhs()->getOp()==Statement::VARIABLE)
		  ||(getRhs()->getOp()==Statement::LIST)
		  ||(getRhs()->getOp()==Statement::SORT)))
	   ||((getOp()==Statement::SUBSET)
	      && (getLhs()->getOp()==Statement::FEATURES)
	      && ((getRhs()->getOp()==Statement::VARIABLE)
		  ||(getRhs()->getOp()==Statement::FEATURES)))){
    bool effect=false;
    buildEnvironmentWithValue(item, this, synthesizer, &effect);
  }
  
  // ⇑ := … 
  else if ((getOp()==Statement::AFF)
	   && (getLhs()->getOp()==Statement::UP2)){
    buildSynthesizeFeatures(item, this, synthesizer);
  }
  
  // test … 
  else if (getOp()==Statement::TEST){
    test(item, this, synthesizer);
  }
  
  // trace
  else if (getOp()==Statement::TRACE){
    trace(item, this, cout, synthesizer);
  }
  
  // order
  else if (getOp()==Statement::ORDER){
  }
  
  // order
  else if (getOp()==Statement::STMS){
    if (!getStatements()->apply(synthesizer, state, item, modification))
      ret=false;
    //return false;
  }
  
  else
    FATAL_ERROR;
 
  if (isSetFlags(Flags::BOTTOM)){
    item->addFlags(Flags::BOTTOM);
    ret=false;
    //return false;
  }
  /***
      cerr << "<DIV>•••apply statement (" << (ret?"ok":"ko") << ")";
      item->print(cerr, NULL);
      print(cerr);
      cerr << "</DIV>";
  ***/
  return ret;
  //return true;
}
