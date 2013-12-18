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
#include <stdio.h>
#include <time.h>
#include <sockhelp.h>

#include "synthesizer.hh"
#include "node.hh"
#include "enum.hh"
#include "forest.hh"
#include "entries.hh"
#include "io.hh"
#include "gitemset.hh"
#include "item.hh"
#include "terms.hh"
#include "value.hh"

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::printLexicon(ostream& out)
{
  out << "<ul>";
  for (map<unsigned int, map<unsigned int, class Entries* > * >::iterator i=beginLexicon();
       i!=endLexicon();
       i++){
    out << "<li>";
    out << intToStr((*i).first);
    out << "<ul>";
    for (map<unsigned int, class Entries*>::iterator j=(*i).second->begin();
	 j!=(*i).second->end();
	 j++){
      out << "<li>";
      if ((*j).first==0)
	out << "0 =&gt; ";
      else if ((*j).first==UINT_MAX)
	out << "UINT_MAX =&gt; ";
      else
	out << intToStr((*j).first) << " =&gt; ";

      (*j).second->print(out);
      out << "</li>";
    }
    out << "</ul>";
    out << "</il>";
  }
  out << "</ul>";
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::printState(ostream& outStream, GitemSet *state, bool_html html)
{
  outStream << "Q" << state->getId();
  state->print(outStream, this, html);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::close(GitemSet *state, int row)
{
  bool modification;
  do {
    modification=false;
    
#ifdef TRACECLOSE
    if (verbose){
      cerr << "####################### CLOSE STAGE #######################" << endl;
      state->print(cerr, this, TRUE_HTML);
      cerr << endl;
    }
#endif
    
    // Iterate through list
    for (set<Gitem*>::iterator actualItem=state->begin(); 
	 actualItem!=state->end() && !modification; 
	 actualItem++){

      if ((*actualItem)->isSetFlags(Flags::SEEN))
	continue;

      if ((*actualItem)->isSetFlags(Flags::BOTTOM))
	FATAL_ERROR; //continue;
      
      (*actualItem)->addFlags(Flags::SEEN);
      (*actualItem)->initialize();
      
#ifdef OUTPUT_ITEMS_DOT
      if (outputItemsDotFile.is_open()){
 	outputItemsDotFile << (*actualItem)->getId() << " [label=\"" << (*actualItem)->getId() << "\\n";
 	(*actualItem)->Item::print(outputItemsDotFile, FALSE_HTML);
 	outputItemsDotFile << "\"];" << endl;
      }
#endif
      
      // action if statements
      if ((*actualItem)->getStatements()){
	// apply (effect);
	if (!(*actualItem)->getStatements()->apply(this, state, *actualItem, &modification)){
	  state->erase(actualItem);
	  itemMap.erase((*actualItem)->getId());
	  modification=true;
	  break;
	}
      }
      
      // split if optional
      if ((*actualItem)->isUnsetFlags(Flags::SPLITTED)
	  && ((*actualItem)->getRule()->getRhs().size() > (*actualItem)->getIndex())
	  && ((*actualItem)->getTerms()!=NULL)
	  && (((*actualItem)->getTerms()->isOptional()) || ((*actualItem)->getTerms()->size() > 1))){
	if ((*actualItem)->split(state, this, verbose)){
#ifdef TRACECLOSE
	  if (verbose){
	    cerr << "####################### MODIFICATION (SPLITTED) #######################" << endl;
	    state->print(cerr, this, TRUE_HTML);
	    cerr << endl;
	  }
#endif
	  modification=true;
	  break;
	}
      }
      
      // check $i
      if ((*actualItem)->getTerms())
	(*actualItem)->getTerms()->putChecked(true);

      // action if statements
      if ((*actualItem)->getStatements()){
	// apply (effect);
	if (!(*actualItem)->getStatements()->apply(this, state, *actualItem, &modification)){
	  state->erase(actualItem);
	  itemMap.erase((*actualItem)->getId());
	  modification=true;
	  break;
	}
      }
      
      // <i, k, X -> alpha • beta>
      if (!(*actualItem)->isFinished()){
	if ((*actualItem)->getTerms()){

	  // On est devant un terme que l'on peut passer
	  // <A -> alpha • beta*|? gamma>
	  // => <A -> alpha beta*|? • gamma>
	  if ((*actualItem)->getTerms()->isOptional()){
#ifdef OUTPUT_ITEMS_DOT
	    if (outputItemsDotFile.is_open()){
	      outputItemsDotFile << (*actualItem)->getId() << " [style=\"filled\", fillcolor=\"#A0A0A0\"];" << endl;
	    }
#endif
#ifdef TRACECLOSE
	    if (verbose){
	      cerr << "####################### CLOSE (X -> α • (Y) β) #######################" << endl;
	      (*actualItem)->print(cerr, this);
	      cerr << endl;
	    }
#endif
	    class Gitem *it=new Gitem((*actualItem)->getRule(),
				      (*actualItem)->getIndex()+1,
				      (*actualItem)->getIndexTerms(),
				      (*actualItem)->getStatements()?(*actualItem)->getStatements()->copy(Flags::SEEN):NULL,
				      Features::nil);
	    it->putHistory((*actualItem)->getHistory());
	    it->addHistory((*actualItem)->getId());
	    it->putInheritedFeatures((*actualItem)->getInheritedFeatures());
	    it->putEnvironment(((*actualItem)->getEnvironment()!=NULL)?(*actualItem)->getEnvironment()->copy():NULL);
	    it->putLexicalEnvironment(((*actualItem)->getLexicalEnvironment()!=NULL)?(*actualItem)->getLexicalEnvironment()->copy():NULL);
	    it->putLexicalStatements((*actualItem)->getLexicalStatements());
	    it->putIndexes((*actualItem)->getIndexes());
	    it->getIndexes()[it->getIndex()-1]=UINT_MAX;
	    it->addRanges((*actualItem)->getRanges());
	    it->addRanges(row);
	    it->addForestIdentifiers((*actualItem)->getForestIdentifiers());
	    it->putRefs((*actualItem)->getRefs());
	    it->addInheritedSonFeatures((*actualItem)->getInheritedSonFeatures());
	    it->putSynthesizeSonFeatures((*actualItem)->getSynthesizeSonFeatures());
	    it->putSynthesizeFeatures((*actualItem)->getSynthesizeFeatures());
	    
#ifdef OUTPUT_ITEMS_DOT
	    if (outputItemsDotFile.is_open()){
	      outputItemsDotFile << (*actualItem)->getId() << " -> " << it->getId() << "[label=\"ε\"];" << endl;
	    }
#endif
	    
#ifdef TRACECLOSE
	    if (verbose){
	      cerr << "####################### CLOSE (X -> α (Y) • β) #######################" << endl;
	      it->print(cerr, this);
	      cerr << endl;
	    }
#endif
	    bool result=states[row]->insert(it);
	    if (result==false){
	      delete(it);
	    } else {
	      itemMap.insert(pair<int, Gitem*>(it->getId(), it));
#ifdef TRACECLOSE
	      if (verbose){
		cerr << "####################### MODIFICATION (X -> α (Y) • β) #######################" << endl;
		state->print(cerr, this, TRUE_HTML);
		cerr << endl;
	      }
#endif
	    }
	    modification = true;
	    break;
	  }
	  
	  // On est devant un terme non terminal
	  // A -> a • X b (X a non terminal term)
	  //(*term)->print(cerr);
	  //cerr << endl;
	  if ((*actualItem)->getFirstTerm()
	      && (grammar->isNonTerminal((*actualItem)->getFirstTerm()))
	      && ((*actualItem)->getTerms()->isNotOptional())
	      && ((*actualItem)->getTerms()->isChecked())){
#ifdef OUTPUT_ITEMS_DOT
	    if (outputItemsDotFile.is_open()){
	      outputItemsDotFile << (*actualItem)->getId() << " [style=\"filled\", fillcolor=\"#A0FFFF\"];" << endl;
	    }
#endif
#ifdef TRACECLOSE
	    if (verbose){
	      cerr << "####################### CLOSE (X -> α • Y β) #######################" << endl;
	      (*actualItem)->print(cerr, this);
	      cerr << endl;
	    }
#endif
	    
	    /*
	      for(vector<class Features *>::iterator i=(*actualItem)->inheritedSonFeaturesBegin(); i!=(*actualItem)->inheritedSonFeaturesEnd(); i++){
	      if ((*i)==Features::nil)
	      (*i)=(*actualItem)->getInheritedFeatures();
	xs      }
	    */
      
	    // force ↓:=[]; si ↓==nil
	    if ((*actualItem)->getInheritedSonFeatures()[(*actualItem)->getIndex()]==Features::nil){
	      if (verbose){
		cerr << "####################### Default: ↓i := [] #######################" << endl;
		(*actualItem)->print(cerr, this);
		cerr << endl;
	      }
	      (*actualItem)->getInheritedSonFeatures()[(*actualItem)->getIndex()]=new Features();
	    }
	    
	    class Features *inheritedSonFeatures=(*actualItem)->getInheritedSonFeatures()[(*actualItem)->getIndex()];
	    if ((*actualItem)->getEnvironment() && (*actualItem)->getEnvironment()->size() > 0){
	      (*actualItem)->getEnvironment()->replaceVariables(inheritedSonFeatures);
	      inheritedSonFeatures->deleteNIL();
	    }
	    
	    //inheritedSonFeatures->deleteVariables((*actualItem)->getLexicalEnvironment());
	    if (!inheritedSonFeatures->isNil() && !inheritedSonFeatures->isBottom()){
	      for (ruleSet::const_iterator iterRules=grammar->getRules().begin(); 
		   iterRules != grammar->getRules().end();
		   iterRules++){
		
		if (((*iterRules)->getLhs()->getCode()==(*actualItem)->getFirstTerm()->getCode())){
		  
		  class Gitem *it;
		  class Rule *rule=(*iterRules)->copy();
		  if (rule->incUsages() > maxUsages){
		    putMaxUsagesMsg(true);
		  }
		  else
		    {	  
		      it = new Gitem(rule,
				     0,
				     0,
				     (rule->getStatements()!=NULL)?rule->getStatements()->copy(0):NULL,
				     inheritedSonFeatures);
			    
		      if (it->getStatements()){
			it->getStatements()->order(it, this);
		      }
		      it->addRanges(row);
		      if ((*actualItem)->getLexicalEnvironment())
			it->addLexicalEnvironment((*actualItem)->getLexicalEnvironment());
		      if ((*actualItem)->getLexicalStatements())
			it->addLexicalStatements((*actualItem)->getLexicalStatements());
		      // Insérer ce nouvel item dans l'ensemble gitems
		      set<Gitem*>::iterator found=state->find(it);
		      if (found==state->end()){
			if (!it->addRefs((*actualItem)->getId())){
			  FATAL_ERROR;
			}
			bool result = state->insert(it);
			if (result==false){
			FATAL_ERROR;
		      } else {
			itemMap.insert(pair<int, Gitem*>(it->getId(), it));
#ifdef TRACECLOSE
			if (verbose){
			  cerr << "•••####################### CLOSE (Y -> • γ) #######################" << endl;
			  it->print(cerr, this);
			  cerr << endl;
			}
#endif
			modification = true;
		      }
		    } else {
		      if (!(*found)->addRefs((*actualItem)->getId())){
			FATAL_ERROR;
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
      
      // <i, k, X -> delta •>
      else {
	if ((*actualItem)->getSynthesizeFeatures()==NULL)
	  FATAL_ERROR;
	if ((*actualItem)->getSynthesizeFeatures()->isNil()){
	  (*actualItem)->putSynthesizeFeatures((*actualItem)->getInheritedFeatures());
	}	
	if (!(*actualItem)->getSynthesizeFeatures()->isBottom()){
#ifdef TRACEREDUCE
	if (verbose){
	  cerr << "####################### REDUCE Y -> γ • #######################" << endl;
	  (*actualItem)->print(cerr, this);
	  cerr << endl;
	}
#endif
	
	// If Axiom reduced or debug Transients
	if (reduceAll
	    || (*actualItem)->getRefs().size()==0){
	  
#ifdef TRACEREDUCE
	  if (verbose){
	    cerr << "####################### REDUCE S -> γ • (AXIOM REDUCED) #######################" << endl;
	    (*actualItem)->print(cerr, this);
	    cerr << endl;
	  }
#endif
	  class Node *node = NULL;
	  unsigned int k=0;
	  while (k < (*actualItem)->getForestIdentifiers().size()){
	    class ForestIdentifier *f=(*actualItem)->getForestIdentifiers()[k];
	    if (f){
	      map <class ForestIdentifier *, class Forest *>::const_iterator forestMapIt=forestMap.find(f);
	      if (forestMapIt!=forestMap.end()){
		class Forest *son=(*forestMapIt).second;
		if (node==NULL)
		  node=new Node();
		node->getSons().push_back(son);
	      } else {
		FATAL_ERROR;
	      }
	    }
	    k++;
	  }
	  if (node){
	    class Forest *forestFound=NULL;
	    class ForestIdentifier *fi;
	    fi=new ForestIdentifier((*actualItem)->getId(), (*actualItem)->getRanges()[0], row, ForestIdentifier::OTHER, "");
	    map <class ForestIdentifier *, class Forest *>::const_iterator forestMapIt=forestMap.find(fi);
	    if (forestMapIt!=forestMap.end()){
	      //FATAL_ERROR;
	    } else {
	      forestFound=new Forest(new Entry((*actualItem)->getLhs()->getCode()), (*actualItem)->getRanges()[0], row);
	      forestMap.insert(pair<class ForestIdentifier *, class Forest *>(fi, forestFound));
	    }
	    if (forestFound){
	      if (!forestFound->addNode(node)){
		FATAL_ERROR;
	      }
	      rootForest->addNode(new Node(forestFound));
	    }
	  }
#ifdef OUTPUT_ITEMS_DOT
	  if (outputItemsDotFile.is_open()){
	    outputItemsDotFile << (*actualItem)->getId() << " [style=\"filled\", fillcolor=\"#AAFFAA\"];" << endl;
	  }
#endif
	} else {
#ifdef OUTPUT_ITEMS_DOT
	  if (outputItemsDotFile.is_open()){
	    outputItemsDotFile << (*actualItem)->getId() << " [style=\"filled\", fillcolor=\"#FFFFAA\"];" << endl;
	  }
#endif
	}
	
	for (intSet::const_iterator ref=(*actualItem)->getRefs().begin();
	     ref!=(*actualItem)->getRefs().end();
	     ref++){
	  class Gitem *precItem=itemMap[*ref];
	  if (precItem){
	    
#ifdef TRACECLOSE
	    if (verbose){
	      cerr << "####################### REDUCE (X -> α • Y β) #######################" << endl;
	      precItem->print(cerr, this);
	      cerr << endl;
	    }
#endif
	    class Gitem *it=new Gitem(precItem->getRule(),
				      precItem->getIndex()+1,
				      precItem->getIndexTerms(),
				      (precItem->getStatements()!=NULL)?precItem->getStatements()->copy(Flags::SEEN):NULL,
				      Features::nil);
	    it->putHistory(precItem->getHistory());
	    it->addHistory(precItem->getId());
	    it->putLexicalStatements(precItem->getLexicalStatements());
	    it->putIndexes(precItem->getIndexes());
	    it->getIndexes()[it->getIndex()-1]=UINT_MAX;
	    it->addRanges(precItem->getRanges());
	    it->addRanges(row);
	    it->addForestIdentifiers(precItem->getForestIdentifiers());
	    it->putInheritedFeatures(precItem->getInheritedFeatures());
	    it->putSynthesizeFeatures(precItem->getSynthesizeFeatures());
	    // On transmet le contexte de precItem
	    class Node *node = NULL;
	    unsigned int k=0;
	    while (k < (*actualItem)->getForestIdentifiers().size()){
	      class ForestIdentifier *f=(*actualItem)->getForestIdentifiers()[k];
	      if (f){
		map <class ForestIdentifier *, class Forest *>::const_iterator forestMapIt=forestMap.find(f);
		if (forestMapIt!=forestMap.end()){
		  class Forest *son=(*forestMapIt).second;
		  if (node==NULL)
		    node = new Node();
		  node->getSons().push_back(son);
		} else {
		  FATAL_ERROR;
		}
	      }
	      k++;
	    }
	    if (node){
	      class Forest *forestFound=NULL;
	      class ForestIdentifier *fi;
	      fi=new ForestIdentifier((*actualItem)->getId(), (*actualItem)->getRanges()[0], row, ForestIdentifier::OTHER, "");
	      map <class ForestIdentifier *, class Forest *>::const_iterator forestMapIt=forestMap.find(fi);
	      if (forestMapIt!=forestMap.end()){
		forestFound=forestMapIt->second;
	      } else {
		forestFound=new Forest(new Entry((*actualItem)->getLhs()->getCode()), (*actualItem)->getRanges()[0], row);
		forestMap.insert(pair<class ForestIdentifier *, class Forest *>(fi, forestFound));
	      }
	      if (!forestFound->addNode(node)){
	      }
	      it->addForestIdentifiers(fi, it->getIndex()-1);
	    }
	    
	    it->putRefs(precItem->getRefs());
	    it->putSynthesizeSonFeatures(precItem->getSynthesizeSonFeatures());
	    it->addSynthesizeSonFeatures((*actualItem)->getSynthesizeFeatures(), it->getIndex()-1);
	    it->addInheritedSonFeatures(precItem->getInheritedSonFeatures());
	    it->putEnvironment((precItem->getEnvironment()!=NULL)?precItem->getEnvironment()->copy():NULL);
	    it->putLexicalEnvironment(precItem->getLexicalEnvironment());
	    it->putLexicalStatements(precItem->getLexicalStatements());
	    
	    if ((*actualItem)->getLexicalEnvironment())
	      it->addLexicalEnvironment((*actualItem)->getLexicalEnvironment());
	    
	    if ((*actualItem)->getLexicalStatements())
	      it->addLexicalStatements((*actualItem)->getLexicalStatements());
	    
	    if ((*actualItem)->getLexicalEnvironment()
	    	&& (*actualItem)->getEnvironment()){
	      it->addEnvironment((*actualItem)->getEnvironment(), (*actualItem)->getLexicalEnvironment());
	    }
	    
	    if ((*actualItem)->getLexicalStatements()
	    	&& (*actualItem)->getEnvironment()){
	      it->addStatements((*actualItem)->getLexicalStatements(), (*actualItem)->getEnvironment());
	    }
	    
#ifdef OUTPUT_ITEMS_DOT
	    if (outputItemsDotFile.is_open()){
	      outputItemsDotFile << precItem->getId() << " -> " << it->getId() << "[label=\"" << intToStr((*actualItem)->getLhs()->getCode()) << "\"];" << endl;
	      outputItemsDotFile << (*actualItem)->getId() << " -> " << it->getId() << "[];" << endl;
	    }
#endif
	    
#ifdef TRACECLOSE
	    if (verbose){
	      cerr << "####################### REDUCE (X -> α Y • β) #######################" << endl;
	      it->print(cerr, this);
	      cerr << endl;
	    }
#endif
	    bool result=states[row]->insert(it);
	    if (result==false){
	      FATAL_ERROR;
	    } else {
	      itemMap.insert(pair<int, Gitem*>(it->getId(), it));
	      modification=true;
	    }
	  } 
	}
      }
      }
    }
  } while (modification);
    for (set<Gitem*>::const_iterator i=state->begin(); 
	 i!=state->end(); 
	 i++){
      (*i)->subFlags(Flags::SEEN);
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool
Synthesizer::shift(GitemSet *state, int row){
  bool modificationOnce=false;
  bool modification;
  do {
    modification=false;
    
#ifdef TRACESHIFT
    if (verbose){
      cerr << "####################### SHIFT STAGE #######################" << endl;
      state->print(cerr, this, TRUE_HTML);
      cerr << endl;
    }
#endif
    
    // Iterate through list
    for (set<Gitem*>::iterator actualItem=state->begin(); 
	 actualItem!=state->end() && !modification; 
	 actualItem++){
      if ((*actualItem)->isSetFlags(Flags::SEEN))
	continue;
      (*actualItem)->addFlags(Flags::SEEN);
      if ((*actualItem)->isSetFlags(Flags::BOTTOM)){
	continue;
      }
      
      
      if (((*actualItem)->getRule()->getRhs().size() > (*actualItem)->getIndex())
	  && ((*actualItem)->getTerms())
	  && ((*actualItem)->getTerms()->isChecked())
	  && ((*actualItem)->getTerms()->isNotOptional())
	  && (*actualItem)->getFirstTerm()){
	
	// force ↓:=[]; si ↓==nil
	if ((*actualItem)->getInheritedSonFeatures()[(*actualItem)->getIndex()]==Features::nil){
	  if (verbose){
	    cerr << "####################### Default: ↓i := [] #######################" << endl;
	    (*actualItem)->print(cerr, this);
	    cerr << endl;
	  }
	  (*actualItem)->getInheritedSonFeatures()[(*actualItem)->getIndex()]=new Features();
	}

	if ((grammar->getTerminals().find((*actualItem)->getFirstTerm()->getCode()) != grammar->getTerminals().end())){
	  
#ifdef OUTPUT_ITEMS_DOT
	  if (outputItemsDotFile.is_open()){
	    outputItemsDotFile << (*actualItem)->getId() << " [style=\"filled\", fillcolor=\"#FFA0A0\"];" << endl;
	  }
#endif

#ifdef TRACESHIFT
	  if (verbose){
	    cerr << "####################### SHIFT (X -> α • ω β) where ω ∈ ℒ #######################" << endl;
	    (*actualItem)->print(cerr, this);
	    cerr << endl;
	  }
#endif
	  
	  class Features *inheritedSonFeatures=(*actualItem)->getInheritedSonFeatures()[(*actualItem)->getIndex()];
	  if (inheritedSonFeatures!=Features::nil){
	    if ((*actualItem)->getEnvironment() && (*actualItem)->getEnvironment()->size() > 0){
	      (*actualItem)->getEnvironment()->replaceVariables(inheritedSonFeatures);
	    }
	    inheritedSonFeatures->deleteNIL();
	    //inheritedSonFeatures->deleteVariables((*actualItem)->getLexicalEnvironment());
	    if (!inheritedSonFeatures->isNil() && !inheritedSonFeatures->isBottom()){
	      unsigned int pred=inheritedSonFeatures->getPred();
	      string *form=inheritedSonFeatures->getForm();
	      map<unsigned int, map<unsigned int, class Entries*, less<unsigned int> >*>::const_iterator foundCode=lexicon.find((*actualItem)->getFirstTerm()->getCode());
	      if (foundCode!=lexicon.end() && (foundCode->second->size()!=0)){
		map<unsigned int, class Entries*> *listPred=foundCode->second;
		if (listPred!=NULL){
		  map<unsigned int, class Entries*>::const_iterator found;
		  // stages:
		  // 1): without PRED or FORM
		  // 2): with FORM
		  // 3): with PRED
		  bool cont=true;
		  for (int stage = 1; cont && (stage <= 3); stage++){
		    if ((stage==3) && (pred==0))
		      continue;
		    if ((stage==2) && (form==NULL))
		      continue;
		  
		    switch(stage){
		    case 1:
		      found=listPred->find(UINT_MAX);	// Without pred: UINT_MAX => ...
		      break;
		    case 2:
		      found=listPred->find(0);		// IDENTITY: 0 => ...
		      break;
		    case 3:
		      found=listPred->find(pred);		// pred => ...
		      if ((found == listPred->end()) && (lex!=NULL)){
			// On cherche avec le lexique compact...
			//cerr << "<DIV>" << intToStr((*actualItem)->getFirstTerm()->getCode()) << "-" << intToStr(pred) << "</DIV>" << endl;
			//FATAL_ERROR;
			unsigned long int info=~0UL;
			string str=intToStr((*actualItem)->getFirstTerm()->getCode())+"#"+intToStr(pred);
			info = lex->searchStatic(lex->init, str);
			//cerr << "<DIV>input:" << str << "</DIV>";
			// in: pos#lemma
			// out: form#fs
			//lex->printResults(info, 1);
		      
			if (info != ~0UL){
			  class Entries *l=new class Entries;
			  while (info != ~0UL){
			    string result = lex->buffer+(lex->info[info].offset);
			    string form = result.substr(0, result.find("#"));
			    string data = result.substr(result.find("#")+1, -1);
			    extern char *lexString;
			    extern bool stringInput;
			    stringInput=true;
			    lexString=strdup(("."+data).c_str());
			    //BUG;
			    //cerr << "<DIV>form:" << form << "</DIV><DIV>" << "data: " << data << "</DIV>";
			    extern unsigned int rulesparse(void);
			    extern unsigned int rulescolno;
			    extern unsigned int ruleslineno;
			    localEntry=NULL;
			    rulescolno=1;
			    ruleslineno=1;
			    rulesparse();
			    if (localEntry){
			      localEntry->putCode((*actualItem)->getFirstTerm()->getCode());
			      localEntry->putForm(form);
			      l->add(localEntry);
			    }
			    if ((lex->info[info].next)!=(unsigned long int)(~(0UL)))
			      info=lex->info[info].next;
			    else
			      info=(unsigned long int)(~(0UL));
			  }
			  pair<map<unsigned int, class Entries*>::iterator, bool> ret;
			  ret = listPred->insert(pair<unsigned int, class Entries*>(pred, l));
			  if (ret.second)
			    found=ret.first;
			}
		      }
		      break;
		    }
		  
		    // Trouvé
		    if (found != listPred->end()){
		      cont=false;
		      class Entries *listEntrys=found->second;
		      if (!listEntrys)
			FATAL_ERROR;
		    
		      for (list<class Entry *>::const_iterator entry=listEntrys->begin();
			   entry!=listEntrys->end();
			   entry++){
		      
			class Features *entryFeatures=((*entry)->getFeatures()!=NULL)?(*entry)->getFeatures()->copy():NULL;
	  
			class Statements *entryStatements=NULL;
			if ((*entry)->getStatements()){
			  entryStatements=(*entry)->getStatements()->copy(0);
			}
		      
			class Environment *env=((*actualItem)->getEnvironment()!=NULL)?(*actualItem)->getEnvironment()->copy():new Environment();
			/*** ***/

			// Filter !!
			// entryFeatures < ↑
			if (stage==2 ||
			    (entryFeatures && entryFeatures->subsumes(inheritedSonFeatures, env))){
			
			  // On construit un nouvel item
			  class Gitem *it=new Gitem((*actualItem)->getRule(),
						    (*actualItem)->getIndex()+1,
						    (*actualItem)->getIndexTerms(),
						    ((*actualItem)->getStatements()!=NULL)?(*actualItem)->getStatements()->copy(Flags::SEEN):NULL,
						    Features::nil);
			  it->putHistory((*actualItem)->getHistory());
			  it->addHistory((*actualItem)->getId());
			  it->putInheritedFeatures((*actualItem)->getInheritedFeatures());
			  it->putEnvironment(env);
			  it->putIndexes((*actualItem)->getIndexes());
			  it->getIndexes()[it->getIndex()-1]=UINT_MAX;
			  it->putRefs((*actualItem)->getRefs());
			  it->addForestIdentifiers((*actualItem)->getForestIdentifiers());
			  it->addRanges((*actualItem)->getRanges());
			  it->addRanges(row);
			  it->addInheritedSonFeatures((*actualItem)->getInheritedSonFeatures());
			  it->putSynthesizeSonFeatures((*actualItem)->getSynthesizeSonFeatures());
			  it->putSynthesizeFeatures((*actualItem)->getSynthesizeFeatures());
			  it->putLexicalEnvironment((*actualItem)->getLexicalEnvironment());
			
			  class Features *resultFeatures=NULL;
			  class Statement s;
			  class Features *inheritedSonFeaturesCopy=inheritedSonFeatures->copy();
			  if (entryFeatures){
			    resultFeatures=s.unif(entryFeatures, inheritedSonFeaturesCopy, it);
			  }
			  else
			    resultFeatures=inheritedSonFeaturesCopy;
			  if (resultFeatures){
			    if (it->getEnvironment() && (it->getEnvironment()->size() > 0)){
			      it->getEnvironment()->replaceVariables(resultFeatures);
			      resultFeatures->deleteNIL();
			    }
			    resultFeatures->customizeVariables((*entry)->getId());
			  }
			 
			  it->addSynthesizeSonFeatures(resultFeatures, it->getIndex()-1);
			
			
			  if (it->getLexicalEnvironment()==NULL)
			    it->putLexicalEnvironment(new Environment());
			  if (resultFeatures)
			    resultFeatures->buildLexicalEnvironment(it->getLexicalEnvironment());
			  if (it->getLexicalEnvironment()->size()==0){
			    delete it->getLexicalEnvironment();
			    it->putLexicalEnvironment(NULL);
			  }

			  if (it->getEnvironment()->size()==0){
			    delete it->getEnvironment();
			    it->putEnvironment(NULL);
			  }
			
			  if (entryStatements){
			    entryStatements->customizeVariables((*entry)->getId());
			    it->addLexicalStatements(entryStatements);
			  }
			
			  class Entry *word;
			  if (stage==2){
			    word=new Entry((*entry)->getCode(), (unsigned int)-1, *form, resultFeatures, (*entry)->getStatements(), (*entry)->getArgs());
			  } else {
			    word=new Entry((*entry)->getCode(), (*entry)->getCodePred(), (*entry)->getCodeForm(), resultFeatures, (*entry)->getStatements(), (*entry)->getArgs());
			  }
			  class ForestIdentifier *fi=new ForestIdentifier((*entry)->getId(), row-1, row, ForestIdentifier::LEAF, resultFeatures->getSign());
			  map <class ForestIdentifier *, class Forest *, ForestIdentifier::less>::const_iterator forestMapIt=forestMap.find(fi);
			  if (forestMapIt!=forestMap.end()){
			    it->addForestIdentifiers((*forestMapIt).first, it->getIndex()-1);
			    delete (fi);
			  } else {
			    forestMap.insert(pair<class ForestIdentifier *, class Forest *>(fi, new Forest(word, row-1, row)));
			    it->addForestIdentifiers(fi, it->getIndex()-1);
			  }
			
#ifdef OUTPUT_ITEMS_DOT
			  if (outputItemsDotFile.is_open()){
			    outputItemsDotFile << (*actualItem)->getId() << " -> " << it->getId() << "[label=\"" << intToStr(word->getCodeForm()) << "\"];" << endl;
			  }
#endif
			
#ifdef TRACESHIFT
			  if (verbose){
			    cerr << "####################### SHIFT (X -> α ω • β) #######################" << endl;
			    it->print(cerr, this);
			    cerr << endl;
			  }
#endif
			
			  bool result=states[row]->insert(it);
			  if (result==false){
			    delete(it);
			  } else {
			    itemMap.insert(pair<int, Gitem*>(it->getId(), it));
			    modification = true;
			    modificationOnce=true;
			  }
			}
		      }
		    } 
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  } while (modification);
  for (set<Gitem*>::const_iterator i=state->begin(); 
       i!=state->end(); 
       i++){
    (*i)->subFlags(Flags::SEEN);
  }
  return modificationOnce;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::generate()
{
#ifdef OUTPUT_XML
  extern xmlNodePtr nodeRoot;
#endif
  ofstream outfile;
  rootForest=new Forest(NULL, 0, 0);
  GitemSet *q=new GitemSet(0);
  list<class Rule *> *rules=grammar->findRules(getStartTerm());
  class Gitem *it;
  for (list<class Rule *>::const_iterator rule=rules->begin() ; rule!=rules->end(); rule++){
    (*rule)->incUsages();
    it = new Gitem(*rule,
		   0, 
		   0, 
		   ((*rule)->getStatements()!=NULL)?(*rule)->getStatements()->copy(0):NULL,
		   getStartFeatures());
    if (it->getStatements()){
      it->getStatements()->order(it, this);
    }
    it->addRanges(0);
    itemMap.insert(pair<int, Gitem*>(it->getId(), it));
    q->insert(it);
  }
  
#ifdef TRACEINIT
  if (verbose){
    cerr << "####################### INIT #######################" << endl;
    q->print(cerr, this, TRUE_HTML);
    cerr << endl;
  }
#endif
  
  states.insert(pair <unsigned int, class GitemSet *>(0, q));
  close(q, 0);
    
  unsigned int i=0;
  while (i<=maxLength){
        
#ifdef TRACESTAGE
    if (verbose){
      cerr << "####################### STAGE #######################" << endl;
      q->print(cerr, this, TRUE_HTML);
      cerr << endl;
    }
#endif
    
    GitemSet *qi=new GitemSet(++i);
    states.insert(pair<unsigned int, class GitemSet* >(i, qi));
    if (!shift(q, i))
      break;
    qi->resetUsages();
    close(qi, i);    
    q=qi;
  }
    
  if (i>maxLength){
    WARNING_MSG("maxLength");
  }
  if (getMaxUsagesMsg()){
    WARNING_MSG("maxUsages");
  }

#ifdef OUTPUT_XML
  if (outXML){
    nodeRoot=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"FORESTS", NULL);
  }
#endif
  rootForest->generate();
#ifdef OUTPUT_XML
  if (outXML){
    rootForest->toXML(nodeRoot);
  }
#endif

#ifdef OUTPUT_FOREST_DOT
  if (outputForestDotFile.is_open())
    for(set<class Node *, Node::less>::const_iterator n=rootForest->nodesBegin() ; 
	n!=rootForest->nodesEnd() ; 
	n++)
      for(forestVector::const_iterator s=(*n)->sonsBegin(); 
	  s!=(*n)->sonsEnd(); 
	  s++){
	(*s)->dot(outputForestDotFile, NULL, 0);
      }
#endif

}

/* ************************************************************
 *                                                            *
 ************************************************************ */
list<string> *
Synthesizer::toStrings()
{
  list<string> *result = new list<string>;
  for(set<class Node *, Node::less>::const_iterator n=rootForest->nodesBegin() ; 
      n!=rootForest->nodesEnd() ; 
      n++){
    for(forestVector::const_iterator s=(*n)->sonsBegin(); 
	s!=(*n)->sonsEnd(); 
	s++){
      for (list<string>::const_iterator sts=(*s)->getOutput().begin();
	   sts!=(*s)->getOutput().end();
	   sts++){
	result->push_back(*sts);
      }
    }
  }
  return result;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::clearStates()
{
  for (map<unsigned int, class GitemSet *>::iterator i=states.begin();i!=states.end();i++){
    delete (*i).second;
  }
  states.clear();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::clearForestMap()
{
  forestMap.clear();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::clearItemMap()
{
  itemMap.clear();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::clearLexicon()
{
  lexicon.clear();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::parse(FILE *file)
{
  extern bool stringInput;
  stringInput=false;
  extern unsigned int rulesparse(void);
  extern unsigned int rulescolno;
  extern unsigned int ruleslineno;
  extern FILE *rulesin;
  rulesin = file;
  rulescolno=1;
  ruleslineno=1;
  rulesparse();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::parseGrammar(string data)
{
  extern bool stringInput;
  stringInput=true;
  extern char *lexString;
  lexString=strdup(("@grammar «"+data+"»\n").c_str());
  extern unsigned int rulesparse(void);
  extern unsigned int rulescolno;
  extern unsigned int ruleslineno;
  rulescolno=1;
  ruleslineno=1;
  if (getGrammar())
    delete getGrammar();
  putGrammar(new Grammar());
  rulesparse();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::parseLexicon(string data)
{
  extern bool stringInput;
  stringInput=true;
  extern char *lexString;
  lexString=strdup(("@lexicon «"+data+"»\n").c_str());
  extern unsigned int rulesparse(void);
  extern unsigned int rulescolno;
  extern unsigned int ruleslineno;
  rulescolno=1;
  ruleslineno=1;
  clearLexicon();
  rulesparse();
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
list<string> *
Synthesizer::parseInput(string data)
{
  list<string> *ret=NULL;
  extern bool stringInput;
  stringInput=true;
  extern char *lexString;
  lexString=strdup(("@input «"+data+"»\n").c_str());
  extern unsigned int rulesparse(void);
  extern unsigned int rulescolno;
  extern unsigned int ruleslineno;
  rulescolno=1;
  ruleslineno=1;
  clearStates();
  clearForestMap();
  clearItemMap();
  rulesparse();
  if (grammar && getStartTerm()){
    generate();
    ret=toStrings();
  }
  return ret;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
list<string> *
Synthesizer::parseInputFile(char *inputFileName)
{
  list<string> *result=NULL;
  clearStates();
  clearForestMap();
  clearItemMap();
  FILE *rulesin = fopen(inputFileName, "r");
  if (rulesin){
    try{
      parse(rulesin);
    } catch (std::string syntax_error) {
      cerr << "xxx";
    }
    fclose(rulesin);
    if (getStartTerm()){
      generate();
      result=toStrings();
    }
  } else {
    WARNING_MSG("No such file");
  }
  return result;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::parseGrammarFile(char *grammarFileName)
{
    FILE *rulesin = fopen(grammarFileName, "r");
    if (rulesin){
      if (getGrammar())
	delete getGrammar();
      putGrammar(new Grammar());
      parse(rulesin);
      fclose(rulesin);
    } else {
      WARNING_MSG("No such file");
    }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::parseLexiconFile(char * lexiconFileName)
{
  clearLexicon();
  FILE *rulesin = fopen(lexiconFileName, "r");
  if (rulesin){
    parse(rulesin);
    fclose(rulesin);
  } else {
    WARNING_MSG("No such file");
  }
}

#ifdef OUTPUT_FOREST_DOT
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::initOutputForestDotFile()
{
  if (outputForestDotFileName){
    outputForestDotFile.open (outputForestDotFileName);
    outputForestDotFile << "graph G {" << endl;
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::concludeOutputForestDotFile()
{
  if (outputForestDotFile){
    outputForestDotFile << "}" << endl;
    outputForestDotFile.close();
  }
}
#endif

#ifdef OUTPUT_ITEMS_DOT
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::initOutputItemsDotFile()
{
  if (outputItemsDotFileName){
    outputItemsDotFile.open (outputItemsDotFileName);
    outputItemsDotFile << "digraph D {" << endl;
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Synthesizer::concludeOutputItemsDotFile()
{
  if (outputItemsDotFile){
    outputItemsDotFile << "}" << endl;
    outputItemsDotFile.close();
  }
}
#endif
