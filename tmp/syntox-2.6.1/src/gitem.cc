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

#include "gitem.hh"
#include "gitemset.hh"
#include "enum.hh"
#include "rule.hh"
#include "statement.hh"
#include "statements.hh"
#include "features.hh"
#include "feature.hh"
#include "synthesizer.hh"
#include "flags.hh"
#include "terms.hh"

unsigned int Gitem::uniqId=0;

/* ************************************************************
 *                                                            *
 ************************************************************ */
Gitem::Gitem (class Rule *rule, 
	      unsigned int index, 
	      unsigned int indexTerm, 
	      class Statements *statements,
	      class Features *inheritedFeatures): Item(rule, index, indexTerm, statements) {
  NEW("Gitem");
  this->id=uniqId++;
  this->inheritedFeatures=inheritedFeatures;
  this->synthesizeFeatures=Features::nil;
  this->environment=NULL;
  this->lexicalEnvironment=NULL;
  this->statements=statements;
  this->lexicalStatements=NULL;
  vector<class Terms*> terms=rule->getRhs();
  for (vector<class Terms*>::const_iterator i=terms.begin();
       i!=terms.end();
       i++){
    forestIdentifiers.push_back(NULL);
    synthesizeSonFeatures.push_back(Features::nil);
    inheritedSonFeatures.push_back(Features::nil);
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
Gitem::Gitem (class Rule *rule, 
	      unsigned int index, 
	      vector<unsigned int> &indexTerms, 
	      class Statements *statements,
	      class Features *inheritedFeatures): Item(rule, index, indexTerms, statements) {
  NEW("Gitem");
  this->id=uniqId++;
  this->inheritedFeatures=inheritedFeatures;
  this->synthesizeFeatures=Features::nil;
  this->environment=NULL;
  this->lexicalEnvironment=NULL;
  this->statements=statements;
  this->lexicalStatements=NULL;
  vector<class Terms*> terms=rule->getRhs();
  for (vector<class Terms*>::const_iterator i=terms.begin();
       i!=terms.end();
       i++){
    forestIdentifiers.push_back(NULL);
    synthesizeSonFeatures.push_back(Features::nil);
    inheritedSonFeatures.push_back(Features::nil);
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
Gitem::~Gitem ()
{
  // don't delete features here (there are shared)
  ranges.clear();
  inheritedSonFeatures.clear();
  synthesizeSonFeatures.clear();
  forestIdentifiers.clear();
  if (statements){
    delete statements;
    statements=NULL;
  }
  if (lexicalStatements){
    delete lexicalStatements;
    lexicalStatements=NULL;
  }
  if (environment){
    delete environment;
    environment=NULL;
  }
  if (lexicalEnvironment){
    delete lexicalEnvironment;
    lexicalEnvironment=NULL;
  }
  DELETE("Gitem");
}
  
/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
Gitem::addStatements(class Statements *statements){
  if (this->statements==NULL)
    this->statements=new Statements();
  for (list<class Statement *>::const_iterator i=statements->begin(); 
       i!=statements->end(); 
       i++){
    this->getStatements()->addStatement(*i);
  }
  if (this->statements->size()==0){
    FATAL_ERROR;
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void 
Gitem::addLexicalStatements(class Statements *statements){
    if (this->lexicalStatements==NULL)
      this->lexicalStatements=new Statements();
    if (statements)
      for (list<class Statement *>::const_iterator i=statements->begin(); 
	   i!=statements->end(); 
	   i++){
	this->getLexicalStatements()->addStatement(*i);
      }
  }

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool 
Gitem::isFinished(void){
  return ranges.size()==(rule->getRhs().size()+1);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Gitem::addEnvironment(class Environment *e)
{
  if (this->environment==NULL)
    this->environment=new Environment();
  this->environment->add(e);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Gitem::addEnvironment(class Environment *e, class Environment *where)
{
  if (this->environment==NULL)
    this->environment=new Environment();
  this->environment->add(e, where);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Gitem::addLexicalEnvironment(class Environment *e)
{
  if (this->lexicalEnvironment==NULL)
    this->lexicalEnvironment=new Environment();
  this->lexicalEnvironment->add(e);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Gitem::addStatements(class Statements *statements, class Environment *where)
{
  if (this->statements==NULL)
    this->statements=new Statements();
  for (list<class Statement *>::const_iterator i=statements->begin(); 
       i!=statements->end(); 
       i++){
    this->getStatements()->addStatement(*i, where);
  }
  if (this->statements->size()==0){
    FATAL_ERROR;
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Gitem::print(ostream& outStream, class Synthesizer *synthesizer)
{
  bool s_id=true, s_history=false, s_flags=false, s_refs=false, s_item=true, s_index=false, s_indexTerms=false, s_terms=false, s_indexes=false, s_ranges=false, s_forestIdentifiers=false, s_inheritedFeatures=true, s_synthesizeFeatures=true, s_inheritedSonFeatures=true, s_synthesizeSonFeatures=true, s_statements=true, s_lexicalStatements=true, s_environment=true, s_lexicalEnvironment=true; 
  outStream << "<table border=\"1\" style=\"color:black; ";
  if (isSetFlags(Flags::BOTTOM)){
    //UNEXPECTED;
    outStream << " background-color:Pink;";
  }
  else if (isSetFlags(Flags::SEEN))
    outStream << " background-color:PaleTurquoise;";
  outStream << "\">";
  outStream << "<tr>";
  if (s_id)
    outStream << "<th>Id</th>";
  if (s_history)
    outStream << "<th>History</th>";
  if (s_flags)
    outStream << "<th>Flags</th>";
  if (s_refs)
    outStream << "<th>Refs</th>";
  if (s_item)
    outStream << "<th>Item</th>";
  if (s_index)
    outStream << "<th>Index</th>";
  if (s_indexTerms)
    outStream << "<th>IndexTerms</th>";
  if (s_terms)
    outStream << "<th>Terms</th>";
  if (s_indexes)
    outStream << "<th>Indexes</th>";
  if (s_ranges)
    outStream << "<th>Ranges</th>";
  if (s_forestIdentifiers)
    outStream << "<th>ForestIdentifiers</th>";
  if (s_inheritedFeatures)
    outStream << "<th bgcolor=\"lightyellow\"><center>↑</center></th>";
  if (s_synthesizeFeatures)
    outStream << "<th bgcolor=\"lightcyan\"><center>⇑</center></th>";
  if (s_inheritedSonFeatures)
    outStream << "<th bgcolor=\"lightyellow\"><center>↓i</center></th>";
  if (s_synthesizeSonFeatures)
    outStream << "<th bgcolor=\"lightcyan\"><center>⇓i</center></th>";
  if (s_statements && statements)
    outStream << "<th bgcolor=\"white\"><center>Statements</center></th>";
  if (s_environment && environment)
    outStream << "<th align=center>Environment</th>";
  if (s_lexicalStatements && lexicalStatements)
    outStream << "<th bgcolor=\"white\"><center>Lexical Statements</center></th>";
  if (s_lexicalEnvironment && lexicalEnvironment)
    outStream << "<th align=center><center>Lexical Environment</center></th>";
  outStream << "</tr>";
  outStream << "<tr>";

  if (s_id){
    outStream << "<td>#" << id << "</td>";
  }
  if (s_history){
    outStream << "<td>(";
    bool prems=true;
    for (list<int>::iterator i=history.begin(); i!=history.end(); i++, prems=false)
      outStream << (prems?"":", ") << "#" << *i;
    outStream << ")</td>";
  }
  if (s_flags){
    outStream << "<td>";
    Flags::print(outStream);
    outStream << "</td>";
  }
  if (s_refs){
    outStream << "<td>(";
    intSet::const_iterator ref=refs.begin();
    while (ref!=refs.end()){
      outStream << "#" << *ref;
      if (++ref!=refs.end())
	outStream << " ";
    }
    outStream << ")</td>";
  }
  if (s_item){
    outStream << "<td>";
    Item::print(outStream); 
    outStream << "</td>";
  }
  if (s_index){
    outStream << "<td>";
    if (getIndex()==UINT_MAX)
      outStream << "UINT_MAX";
    else
      outStream << getIndex();
    outStream << "</td>";
  }
  if (s_indexTerms){
    outStream << "<td>";
    for (vector<unsigned int>::iterator i = indexTerms.begin() ; i != indexTerms.end() ; i++)
      if ((*i) == UINT_MAX)
	outStream << "UINT_MAX" << "&nbsp;";
      else
	outStream << (*i) << "&nbsp;";
    outStream << "</td>";
  }
  if (s_terms){
    outStream << "<td>";
    class Terms *terms=getTerms();
    if (terms)
      terms->print(outStream); 
    else 
      outStream << "NULL";
    outStream << "</td>";
  }
  if (s_indexes){
    outStream << "<td>";//<center>Indexes</center><br>";
    for (vector<unsigned int>::iterator i = indexes.begin() ; i != indexes.end() ; i++)
      if ((*i) == UINT_MAX)
	outStream << "-" << "&nbsp;";
      else
	outStream << (*i) << "&nbsp;";
    outStream << "</td>";
  }
  if (s_ranges){
    outStream << "<td>";//<center>Ranges</center><br>";
    outStream << "(";
    for(vector<unsigned int>::const_iterator i=rangesBegin(); i!=rangesEnd();){
      outStream << (*i);
      if (++i!=rangesEnd()){
	outStream << ",";
      }
    }
    outStream << ")";
    outStream << "</td>";
  }
  if (s_forestIdentifiers){
    outStream << "<td>";//<center>ForestIdentifiers</center><br>";
    for(vector<class ForestIdentifier *>::const_iterator i=forestIdentifiersBegin(); i!=forestIdentifiersEnd();){
      if (*i)
	(*i)->print(outStream);
      else
	outStream << "NULL"; 
      if (++i!=forestIdentifiersEnd()){
	outStream << ",";
      }
    }
    outStream << "</td>";
  }
  if (s_inheritedFeatures){
    outStream << "<td bgcolor=\"lightyellow\">";//<center>↑</center><br>";
    inheritedFeatures->print(outStream, TRUE_HTML);
    outStream << "</td>";
  }
  if (s_synthesizeFeatures){
    outStream << "<td bgcolor=\"lightcyan\">";//<center>⇑</center><br>";
    if (synthesizeFeatures){
      synthesizeFeatures->print(outStream, TRUE_HTML);
    }else
      outStream << "null";
    outStream << "</td>";
  }
  if (s_inheritedSonFeatures){
    outStream << "<td bgcolor=\"lightyellow\"><table>";//<center>↓i</center><br>";
    for(vector<class Features *>::const_iterator i=inheritedSonFeaturesBegin(); i!=inheritedSonFeaturesEnd(); i++){
      outStream << "<tr><td>";
      if ((*i) != NULL)
	(*i)->print(outStream, TRUE_HTML);
      else
	outStream << "null";
      outStream << "</td></tr>";
    }
    outStream << "</table></td>";
  }
  if (s_synthesizeSonFeatures){
    outStream << "<td bgcolor=\"lightcyan\"><table>";//<center>⇓i</center><br>";
    for(vector<class Features *>::const_iterator i=synthesizeSonFeaturesBegin(); i!=synthesizeSonFeaturesEnd(); i++){
      outStream << "<tr><td>";
      if ((*i) != NULL)
	(*i)->print(outStream, TRUE_HTML);
      else
	outStream << "null";
      outStream << "</td></tr>";
    }
    outStream << "</table></td>";
  }
  if (s_statements && statements){
    outStream << "<td bgcolor=\"white\">";//<center>Statements</center><br>";
    if (statements)
      statements->print(outStream);
    else
      outStream << "&nbsp;";
    outStream << "</td>";
  }
  if (s_environment && environment){
    outStream << "<td align=center>";
    environment->print(outStream);
    outStream << "</td>";
  }
  if (s_lexicalStatements && lexicalStatements){
    outStream << "<td bgcolor=\"white\">";
    if (lexicalStatements)
      lexicalStatements->print(outStream);
    else
      outStream << "&nbsp;";
    outStream << "</td>";
  }
  if (s_lexicalEnvironment && lexicalEnvironment){
    outStream << "<td align=center>&nbsp;";
    if (lexicalEnvironment)
      lexicalEnvironment->print(outStream);
    else
      outStream << "&nbsp;";
    outStream << "</td>";
  }
  outStream << "</tr></table>";
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
class Gitem *
Gitem::buildGhost(class Synthesizer *synthesizer)
{
  class Gitem *it=new Gitem(getRule()->copy(),
			    getIndex(),
			    UINT_MAX,
			    getStatements()?getStatements()->copy(Flags::SEEN):NULL
			    );
  it->putHistory(getHistory());
  it->putEnvironment((getEnvironment()!=NULL)?getEnvironment()->copy():NULL);
  it->putLexicalEnvironment((getLexicalEnvironment()!=NULL)?getLexicalEnvironment()->copy():NULL);
  it->putLexicalStatements(getLexicalStatements());
  it->addFlags(Flags::SPLITTED);
  it->putIndexes(getIndexes());
  it->addRanges(getRanges());
  it->addForestIdentifiers(getForestIdentifiers());
  it->putRefs(getRefs());
  it->putInheritedFeatures(getInheritedFeatures());
  it->addInheritedSonFeatures(getInheritedSonFeatures());
  it->putSynthesizeSonFeatures(getSynthesizeSonFeatures());
  it->putSynthesizeFeatures(getSynthesizeFeatures());
  it->getTerms()->putOptional(true);
  it->getTerms()->putChecked(true);
	    
#ifdef OUTPUT_ITEMS_DOT
  if (synthesizer->getOutputItemsDotFile().is_open()){
    synthesizer->getOutputItemsDotFile() << getId() << " -> " << it->getId() << ";" << endl;
  }
#endif
  return it;
}

/* ************************************************************
 *                                                            *
 * bug: 
 * gitem1: •(X)
 * gitem2: •(X)
 * => .X 
 * => .X NO !!!
 * => .(X) 
 * => .(X) 
 ************************************************************ */
bool
Gitem::split(class GitemSet *state, class Synthesizer *synthesizer, bool getTrace)
{
#ifdef TRACESPLIT
  if (getTrace){
    cerr << "####################### SPLIT (" << getId() << ") #######################" << endl;
    print(cerr, NULL);
    cerr << endl;
  }
#endif
  if (isSetFlags(Flags::SPLITTED))
    FATAL_ERROR;
  bool modification=false;
  // Faire une copie pour éviter de propager le split sur l'ensemble des règles X -> Y . (Z) d'un même état.
  putRule(getRule()->copy());
  class Terms *terms=getTerms();
  if (terms->isOptional()){
    class Gitem *it=buildGhost(synthesizer);
    bool result=state->insert(it);
    if (!result){
      FATAL_ERROR;
      delete(it);
    } else {
      synthesizer->getItemMap().insert(pair<int, class Gitem*>(it->getId(), it));
      modification=true;
    }
    subFlags(Flags::SEEN);
    getTerms()->putOptional(false);
    getTerms()->putChecked(true);
    modification=true;
  }
  
  if (terms->size()>1){
    for (unsigned int indexTerm1=0;
	 indexTerm1 < terms->size();
	 indexTerm1++){
      class Gitem *it=new Gitem(getRule()->copy(),
				getIndex(),
				indexTerm1,
				(getStatements()!=NULL)?getStatements()->copy(Flags::SEEN):NULL);
      it->getRule()->getRhs()[getIndex()]=new Terms(terms->index(indexTerm1));
      it->putEnvironment((getEnvironment()!=NULL)?getEnvironment()->copy():NULL);
      it->putLexicalEnvironment((getLexicalEnvironment()!=NULL)?getLexicalEnvironment()->copy():NULL);
      it->putLexicalStatements(getLexicalStatements());
      it->addFlags(Flags::SPLITTED);
      it->putIndexes(getIndexes());
      it->addRanges(getRanges());
      it->addForestIdentifiers(getForestIdentifiers());
      it->putRefs(getRefs());
      it->putInheritedFeatures(getInheritedFeatures());
      it->addInheritedSonFeatures(getInheritedSonFeatures());
      it->putSynthesizeSonFeatures(getSynthesizeSonFeatures());
      it->putSynthesizeFeatures(getSynthesizeFeatures());
      it->getTerms()->putChecked(true);
#ifdef OUTPUT_ITEMS_DOT
      if (synthesizer->getOutputItemsDotFile().is_open()){
	synthesizer->getOutputItemsDotFile() << getId() << " -> " << it->getId() << ";" << endl;
      }
#endif
      bool result=state->insert(it);
      if (!result){
	FATAL_ERROR;
      } else {
	synthesizer->getItemMap().insert(pair<int, class Gitem*>(it->getId(), it));
	modification=true;
      }
    }
    synthesizer->getItemMap().erase(getId());
    state->erase(this);
    }
#ifdef TRACESPLIT
  if (getTrace){
    cerr << "####################### SPLIT DONE #######################" << endl;
    state->print(cerr, NULL);
    cerr << endl;
  }
#endif
  return modification;
}

