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
#include <bitset>

#include "io.hh"
#include "feature.hh"
#include "features.hh"
#include "value.hh"
#include "bits.hh"
#include "environment.hh"
#include "vartable.hh"
#include "gitem.hh"

class Features *Features::bottom=new Features();
class Features *Features::nil=new Features();
unsigned int Features::uniqId=0;

/* ************************************************************
 *
 ************************************************************ */
Features::Features(void){
  NEW("Features");
  this->id=uniqId++;
  this->sign="";
  this->pred=0;
  this->form=NULL;
  this->memoizedComplexPred=false;
  this->complexPred=NULL;
}

/* ************************************************************
 *
 ************************************************************ */
Features::Features(class Feature *feature){
  NEW("Features");
  this->id=uniqId++;
  features.push_front(feature);
  this->sign="";
  this->pred=0;
  this->form=NULL;
  this->memoizedComplexPred=false;
  this->complexPred=NULL;
}

/* ************************************************************
 *
 ************************************************************ */
Features::Features(const bitset<NBRFLAGS> &flags): Flags(flags){
  NEW("Features");
  this->id=uniqId++;
  this->sign="";
  this->pred=0;
  this->form=NULL;
  this->memoizedComplexPred=false;
  this->complexPred=NULL;
}

/* ************************************************************
 *
 ************************************************************ */
Features::~Features(void){
  DELETE("Features");
  if (!isNil() && !isBottom()){
    for (list<class Feature *>::iterator f=features.begin();
	 f!=features.end();
	 f++){
      delete (*f);
    }
  }
}

/* ************************************************************
 *
 ************************************************************ */
bool
Features::exists(class Environment *e)
{
  bool ret=true;
  if (isNil())
    ;
  else if (isBottom())
    ;
  else {
    for (list<class Feature *>::const_iterator f=features.begin();
	 f!=features.end();
	 f++){
      switch ((*f)->getType()){
      case Feature::FORM:
      	break;
      case Feature::CONSTANT:
      case Feature::PRED:
      	if (!(*f)->getRhs()->exists(e)){
	  ret=false;
	  goto endFind;
	}
	break;
      case Feature::VARIABLE:
	if (!e->exists((*f)->getLhs())){
	  ret=false;
	  goto endFind;
	}
	break;
      }
    }
  }
 endFind:
  return ret;
}

/* ************************************************************
 *
 ************************************************************ */
void
Features::print(ostream& outStream, bool_html html)
{
  //outStream << comment;
  if (isNil())
  outStream << "NIL";
  else if (isBottom())
    outStream << "⊥";
  else {
    if (html) {
      outStream << "<TABLE BORDER=\"1\">";
      outStream << "<TBODY align=\"left\"><tr><td><table border=\"0\">";
    } else {
      outStream << "[";
    }
    if (features.size()){
      bool first=true;
      for (int t=Feature::first_featuretype ; t <= Feature::last_featuretype ; t++){
	for (list<class Feature *>::const_iterator f=features.begin();
	     f!=features.end();
	     f++){
	  if ((*f)->getType()==t){
	    if (html)
	      outStream << "<TR>";
	    else
	      if (first) first=false; else outStream << ",";
	    (*f)->print(outStream, html);
	    if (html)
	      outStream << "</TR>";
	  }
	}
      }
    } else {
      if (html)
	outStream << "<tr><td></td></tr>";
    }
    if (html)
      outStream << "</table></td></tr></TBODY></TABLE>";
    else 
      outStream << "]";
  }
}

/* ************************************************************
 *
 ************************************************************ */
unsigned int
Features::getPred()
{
  int ret=UINT_MAX;
  if (pred)
    return pred;
  for (list<class Feature *>::const_iterator f=features.begin();
       f!=features.end();
       f++){
    // […, PRED=…, …]
    if ((*f)->getType()==Feature::PRED){
      // PRED=xxx
      if ((*f)->getRhs()->getType()==Value::IDENTIFIER){
	FATAL_ERROR;
	ret=(*f)->getRhs()->getInteger();
      } 
      // PRED=[xxx, list]
      else if ((*f)->getRhs()->getType()==Value::FEATURES){
	for (list<class Feature *>::const_iterator f2=(*f)->getRhs()->getFeatures()->begin();
	     f2!=(*f)->getRhs()->getFeatures()->end();
	     f2++){
	  if ((*f2)->getLhs() == LEXBITS){
	    ret=(*f2)->getRhs()->getInteger();
	  } 
	}
      }
      pred=ret;
    }
  }
  return ret;
}

/* ************************************************************
 *
 ************************************************************ */
string *
Features::getForm()
{
  if (form)
    return form;
  string *ret=NULL;
  for (list<class Feature *>::const_iterator f=features.begin();
       f!=features.end();
       f++){
    if ((*f)->getType()==Feature::FORM){
      ret=(*f)->getRhs()->getForm();
      form=ret;
    }
  }
  return ret;
}

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Features::toXML(xmlNodePtr nodeRoot){
  xmlNodePtr f=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"FS", NULL);
  xmlErrors(f);
  if (id){
    xmlSetProp(f, (xmlChar*)"id", (xmlChar*)toStr(id).c_str());
  }
  if (features.size())
    for (list<class Feature *>::const_iterator i=features.begin();
	 i!=features.end();
	 i++)
      (*i)->toXML(f);
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Features*
Features::copy(void){
  if (isNil() || isBottom())
    return this;
  class Features *result=new Features();
  for (list<class Feature *>::const_iterator i=features.begin();
       i!=features.end();
       i++)
    result->features.push_back((*i)->copy());
  result->sign=sign;
  result->pred=pred;
  result->form=form;
  return result;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Value *
Features::findFeature(bitset<MAXBITS> code){
  for (list<class Feature *>::const_iterator i1=features.begin();
       i1!=features.end();
       i1++){
    if (((*i1)->getLhs() & code).any()){
      return (*i1)->getRhs();
    }
  }
  return NULL;
}

/* ************************************************************
 *
 ************************************************************ */
bool
Features::buildEnvironment(class Environment *environment, class Features *features, bool acceptToFilterNULLVariables){
  bool ret=true;
  /***
  cerr << "<H4>Features::buildEnvironment</H4>" << endl;
  cerr << "<table border=\"1\"><tr><th>this</th><th>features</th><th>Environment</th></tr>";
  cerr << "<tr><td>";
  this->print(cerr);
  cerr << "</td><td>";
  if (features)
    features->print(cerr);
  else
    cerr << "NULL";
  cerr << "</td><td>";
  environment->print(cerr);
  cerr << "</td></tr></table>";
  ***/
  
  // Traite tous les attributs constants
  for (list<class Feature *>::const_iterator i1=begin();
       i1!=end();
       i1++){
    if (((*i1)->getType()==Feature::PRED)
	|| ((*i1)->getType()==Feature::CONSTANT)){
      
      list<class Feature *>::const_iterator i2=features->begin();
      while(i2!=features->end()){
	if (((*i1)->getRhs()==NULL) || ((*i2)->getRhs()==NULL)){
	  FATAL_ERROR;
	}
	
	// Si deux constantes matchent
	// ou deux PRED matchent
	if ((((*i2)->getType()==Feature::CONSTANT) && ((*i1)->getType()==Feature::CONSTANT) && (((*i1)->getLhs() & (*i2)->getLhs()).any()))
	    ||
	    (((*i1)->getType()==Feature::PRED) && ((*i2)->getType()==Feature::PRED))){
	  // Si l'une des valeurs est NIL 
	  if (((*i1)->getRhs()->isNil()) || ((*i2)->getRhs()->isNil())){
	    ret=false;
	  }
	  // Sinon on construit l'environnement avec les deux valeurs
	  else if (!(*i1)->getRhs()->buildEnvironment(environment, (*i2)->getRhs(), acceptToFilterNULLVariables)){
	    ret=false;
	  }
	  (*i2)->addFlags(SEEN);
	  break;
	} 
	i2++;
      }
      // Trait i1 inexistant
      if (i2==features->end()){
	// i1: a=X
	if (((*i1)->getType()==Feature::PRED)
	    || ((*i1)->getType()==Feature::CONSTANT)){
	  if ((*i1)->getRhs()->getType()==Value::VARIABLE){
	    // => X=NIL
	    if (acceptToFilterNULLVariables){
	      environment->add(*(*i1)->getRhs()->getBits(), Value::_nil);
	    } else {
	      ret=false;
	    }
	  }
	  else if ((*i1)->getRhs()->isNil()){
	  }
	  // i1: a=...
	  else {
	    if (!acceptToFilterNULLVariables){
	      ret=false;
	    }
	  }
	}
      }
    }
  }
  
  // traite les variables de structures
  for (list<class Feature *>::const_iterator i1=begin();
       i1!=end();
       i1++){
    
    // i1: X
    if ((*i1)->getType()==Feature::VARIABLE){
      if ((*i1)->getRhs()!=NULL){
	this->print(cerr);
  	ERROR("A variable attribute is not allowed in this context");
      } else {
	class Features *nFeatures=new Features();
	list<class Feature *>::const_iterator i2=features->begin();
	while(i2!=features->end()){
	  if ((*i2)->isUnsetFlags(Flags::SEEN)){
	    (*i2)->addFlags(Flags::SEEN);
	    nFeatures->addFeature(*i2);
	  }
	  i2++;
	}
	environment->add((*i1)->getLhs(), new Value(nFeatures));
      }
    }
  }
  
  features->subFlags(SEEN);
    
  /***
  cerr << "<H4>Result Features::buildEnvironment</H4>" << endl;
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
// Features::filter(class Features *o, class Environment *environment)
// {
//   /***/
//   cerr << "<DIV>";
//   cerr << "Filter (" << this << ")";
//   cerr << "<TABLE><TR>";
//   cerr << "<TD>";
//   this->print(cerr);
//   cerr << "</TD><TD>";
//   o->print(cerr);
//   cerr << "</TD>";
//   cerr << "</TR></TABLE>";
//   cerr << "</DIV>";
//   /***/

//   bool ret=true;
//   if (isNil() && o->isNil()){
//     // OK
//   } 
//   else if (isNil() || o->isNil()){
//     ret=false;
//   }
//   else {
//     list<class Feature *>::const_iterator i1;
//     list<class Feature *>::const_iterator i2;
//     for (i1=begin(); i1!=end(); i1++){
//       for (i2=o->begin(); i2!=o->end(); i2++){
// 	// this:[PRED:X] o:[PRED:Y]
// 	// this:[att:X] o:[att:Y]
// 	if ((((*i1)->getType()==Feature::PRED) && ((*i2)->getType()==Feature::PRED))
// 	    || (((*i1)->getType()==Feature::CONSTANT) && ((*i2)->getType()==Feature::CONSTANT) && (((*i1)->getLhs() & (*i2)->getLhs()).any()))){
// 	  class Value *v1=(*i1)->getRhs();
// 	  class Value *v2=v2;
// 	  if (v1->isNil() && v2->isNil()){
// 	    // OK
// 	  } 
// 	  else if (v1->isNil() || v2->isNil()){
// 	    ret=false;
// 	  }
// 	  else if (!v1->filter(v2, environment)){
// 	    ret=false;
// 	  }
// 	  break;
// 	}
//       }
//     }
//   }
//   /***/
//   cerr << "<DIV>";
//   cerr << "result: (" << this << ")";
//   cerr << (ret?"true":"false") << endl;
//   environment->print(cerr);
//   cerr << "</DIV>";
//   /***/
//   return ret;
// }

/* ************************************************************
 * true if this subsumes o
 * if it does, change variables in this
 ************************************************************ */
bool
Features::subsumes(class Features *o, class Environment *environment)
{
  /***
  cerr << "<DIV>";
  cerr << "Subsumes (" << this << ")";
  cerr << "<TABLE><TR>";
  cerr << "<TD>";
  this->print(cerr);
  cerr << "</TD><TD>&lt;</TD><TD>";
  o->print(cerr);
  cerr << "</TD>";
  cerr << "</TR></TABLE>";
  cerr << "</DIV>";
  ***/

  bool ret=true;
  // NIL < NIL
  if (isNil() && o->isNil()){
    // OK
  } 
  // NIL < […]
  // […] < NIL
  else if (isNil() || o->isNil()){
    ret=false;
  }
  // ⊥ < […]
  // […] < ⊥
  else if (isBottom() || o->isBottom()){
    ret=false;
  }
  else {
    list<class Feature *>::const_iterator i1;
    list<class Feature *>::const_iterator i2;
    for (i1=begin(); i1!=end(); i1++){
      for (i2=o->begin(); i2!=o->end(); i2++){
	// [PRED:X]  < [PRED:Y]
	// [att:X] < [att:Y]
	// X < Y
	if ((((*i1)->getType()==Feature::PRED) && ((*i2)->getType()==Feature::PRED))
		 || (((*i1)->getType()==Feature::CONSTANT) && ((*i2)->getType()==Feature::CONSTANT) && (((*i1)->getLhs() & (*i2)->getLhs()).any()))){
	  class Value *v1=(*i1)->getRhs();
	  class Value *v2=(*i2)->getRhs();
	  //CERR_LINE;
	  if (!v1->subsumes(v2, environment)){
	    ret=false;
	  }
	  break;
	}
      }
    }
  }
  /***
  cerr << "<DIV>";
  cerr << "result: (" << this << ")";
  cerr << (ret?"true":"false") << endl;
  //environment->print(cerr);
  cerr << "</DIV>";
  ***/
  return ret;
}

/* ************************************************************
 *
 ************************************************************ */
void
Features::subFlags(const bitset<NBRFLAGS> &flags){
  for (list<class Feature *>::const_iterator i=begin();
       i!=end();
       i++)
    (*i)->subFlags(flags);
}

// /* ************************************************************
//  *
//  ************************************************************ */
// void
// Features::deleteVariables(class Environment *but)
// {
//  redo:
//   for (list<class Feature *>::iterator feature=features.begin(); feature!=features.end(); feature++){
//     if (((*feature)->getType()==Feature::CONSTANT) 
// 	&& (!(*feature)->getRhs()->isNil())
// 	&& ((*feature)->getRhs()->getType()==Value::VARIABLE)){
//       if ((but==NULL)
// 	  || (!but->exists(*(*feature)->getRhs()->getBits()))){
// 	features.erase(feature);
// 	goto redo;
// 	return;
//       }
//     }
//   }
// }

/* ************************************************************
 *
 ************************************************************ */
void
Features::deleteNIL()
{
 redo:
  for (list<class Feature *>::iterator feature=features.begin(); feature!=features.end(); feature++){
    switch ((*feature)->getType()){
    case Feature::FORM:
    case Feature::PRED:
      break;
    case Feature::VARIABLE:
    case Feature::CONSTANT:
      if ((*feature)->getRhs()){
	(*feature)->getRhs()->deleteNIL();
	if ((*feature)->getRhs() && (*feature)->getRhs()->isNil()){
	  features.erase(feature);
	  goto redo;
	  return;
	}
      }
      break;
    }
  }
}

// /* ************************************************************
//  *
//  ************************************************************ */
// void
// Features::deleteVariables(class Environment *but)
// {
//  again:
//   for (list<class Feature *>::iterator feature=features.begin(); feature!=features.end(); feature++){
//     if (((*feature)->getType()==Feature::CONSTANT) 
// 	&& (!(*feature)->getRhs()->isNil())
// 	&& ((*feature)->getRhs()->getType()==Value::VARIABLE)){
//       if ((but==NULL)
// 	  || (but->_find(*(*feature)->getRhs()->getBits())->isNil())){
// 	features.erase(feature);
// 	goto again;
// 	return;
//       }
//     }
//   }
// }

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Features::customizeVariables(unsigned int i)
{
  for (list<class Feature *>::iterator feature=features.begin(); feature!=features.end(); feature++)
    (*feature)->customizeVariables(i);
  sign="";
  getSign();
}

/* ************************************************************
 *
 ************************************************************ */
string
Features::getSign(){
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
Features::buildLexicalEnvironment(class Environment *lexicalEnvironment)
{
  for (list<class Feature *>::iterator feature=features.begin(); feature!=features.end(); feature++){
    switch ((*feature)->getType()){
    case Feature::PRED:
    case Feature::CONSTANT:
      if ((*feature)->getRhs())
	(*feature)->getRhs()->buildLexicalEnvironment(lexicalEnvironment);
      break;
    case Feature::VARIABLE:
    case Feature::FORM:
      break;
    }
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Features::disable(class Statement *root, class Gitem *gitem)
{
  for (list<class Feature *>::iterator feature=features.begin(); feature!=features.end(); feature++)
    (*feature)->disable(root, gitem);
}

