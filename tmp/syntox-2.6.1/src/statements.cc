/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "statements.hh"
#include "statement.hh"
#include "gitem.hh"
#include "errors.hh"
#include "node.hh"
#include "forest.hh"
#include "terms.hh"
#include "synthesizer.hh"

unsigned int Statements::uniqId=0;
/***************************
 *
 ***************************/
Statements::~Statements(){
  DELETE("Statements");
  //for (list<class Statement *>::iterator i=statements.begin(); i!=statements.end(); i++)
  //delete *i;
  statements.clear();
}

/***************************
 *
 ***************************/
void 
Statements::addStatement(class Statement *statement){
  for (list<class Statement *>::const_iterator i=statements.begin(); i!=statements.end(); i++){
    if ((*i)->signature() == statement->signature())
      return;
  }
  this->statements.push_back(statement);
} 

/***************************
 *
 ***************************/
void 
Statements::addStatement(class Statement *statement, class Environment *where){
  if (statement->exists(where)){
    addStatement(statement->copy(0));
  } 
}

/***************************
 *
 ***************************/
void 
Statements::print(ostream& outStream, int left){
  for (int j=1 ; j<=left ; j++)
    outStream << "&nbsp;";
  outStream << "{<DIV>";
  left+=3;
  for (list<class Statement *>::const_iterator i=statements.begin(); i!=statements.end(); i++){
    (*i)->print(outStream, left);
  }
  left-=3;
  for (int j=1 ; j<=left ; j++)
    outStream << "&nbsp;";
  outStream << "}</DIV>";
}

/***************************
 *
 ***************************/
class Statements * 
Statements::copy(const bitset<NBRFLAGS> &savedFlags){
  class Statements *statements=new Statements();
  for (list<class Statement *>::const_iterator i=this->statements.begin(); i!=this->statements.end(); i++){
    statements->addStatement((*i)->copy(savedFlags));
  }
  return statements;
}

/***************************
 *
 ***************************/
void
Statements::customizeVariables(unsigned int i){
  for (list<class Statement *>::const_iterator j=this->statements.begin(); j!=this->statements.end(); j++)
    (*j)->customizeVariables(i);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Statements::order(class Gitem *gitem, class Synthesizer *synthesizer)
{
  /***
      BUG;
      cerr << "<H1>order</H1>";
      this->print(cerr, synthesizer);
      cerr << endl;
  ***/
  //beginOrder:
  for (list<class Statement *>::iterator statement=begin(); 
       statement!=end(); 
       statement++){
    if ((*statement)->isSetFlags(Flags::DISABLE | Flags::SEEN))
      continue;
    if ((*statement)->getOp()==Statement::ORDER){
      (*statement)->order(gitem, synthesizer);
    }
  }
}

#ifdef OUTPUT_STATEMENT_DOT
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Statements::dot(std::ostream& outStream, unsigned int id, string with)
{
  if (isSetFlags(Flags::DOTTED))
    return;
  addFlags(Flags::DOTTED);
  /*if (id){
    outStream << "N" << id << " -- N" << this->id;
    if (with.size())
      outStream << "[label=\"" << with << "\"]";
    outStream << ";" << endl;
  }
  */
  for (list<class Statement *>::const_iterator i=statements.begin(); i!=statements.end(); i++){
    (*i)->dot(outStream, id, with);
  }
}
#endif //DOT

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool
Statements::exists(class Environment *where)
{
  for (list<class Statement *>::const_iterator i=statements.begin(); i!=statements.end(); i++){
    if ((*i)->exists(where))
      return true;
  }
  return false;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool 
Statements::apply(Synthesizer *synthesizer, GitemSet *state, class Gitem *gitem, bool *modification)
{
  bool ret=true;
  /***
  cerr << "<DIV>apply statements•••";
  gitem->print(cerr, NULL);
  //print(cerr);
  cerr << "</DIV>";
  ***/
  bool seen;
  do {
    seen=false;
    for (list<class Statement *>::const_iterator statement=begin(); statement!=statements.end(); statement++){
      
      if ((*statement)->isSetFlags(Flags::SEEN))
	continue;
      
      // /* ****************************************  */
      // cerr << "<DIV>disable (";
      // (*statement)->print(cerr);
      // cerr << ")</DIV>";
      // /*       **************************************** */

      (*statement)->subFlags(Flags::DISABLE);
      (*statement)->disable(*statement, gitem);
      
      // /* **************************************** */
      // cerr << "<DIV>disable (";
      // (*statement)->print(cerr);
      // cerr << ") DONE ";
      // gitem->print(cerr, NULL);
      // cerr << "</DIV>";
      // /*       **************************************** */
     
      if ((*statement)->isSetFlags(Flags::DISABLE))
	continue;
      
      if (!(*statement)->apply(synthesizer, state, gitem, modification)){
	gitem->addFlags(Flags::BOTTOM);
	ret=false;
	break;
      }
      
      if ((*statement)->isSetFlags(Flags::SEEN))
	seen=true;
    }
  }
  while (seen);
  /***
      cerr << "<DIV>•••apply statements (" << (ret?"ok":"ko") << ")";
      gitem->print(cerr, NULL);
      //print(cerr);
      cerr << "</DIV>";
  ***/
#ifdef TRACEACTION
  if (synthesizer->getVerbose()){
    cerr << "####################### ACTION " << (ret?"DONE":"FAILS") << " #######################" << endl;
    gitem->print(cerr, synthesizer);
    cerr << endl;
  }
#endif
  return ret;
}
