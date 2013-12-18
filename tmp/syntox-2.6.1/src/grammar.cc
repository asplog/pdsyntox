/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include <map>
#include <string>
#include "grammar.hh"
#include "term.hh"
#include "terms.hh"
#include "vartable.hh"

extern map<unsigned int, string> intToStrTable;

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Grammar::addNewStartTerm(bool addENDTerminal)
{
  //cerr << __FILE__ << "(" << __LINE__ << ")" << endl;
  //return;
  class Rule *r;
  vector<class Terms *> rhs;

  if (addENDTerminal){
    intToStrTable[_END_]="_END_";
    terminals.insert(_END_);
  }
  
  intToStrTable[_STARTTERM_]="_STARTTERM_";
  nonTerminals.insert(_STARTTERM_);

  rhs.push_back(new Terms(getStartTerm()));
  if (addENDTerminal){
    rhs.push_back(new Terms(new class Term(_END_)));
  }
  
  class Term *startTerm=new class Term(_STARTTERM_);
  r=new Rule(startTerm, rhs);
  putStartTerm(startTerm);
  rules.insert(r);
  firstRule=r;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Grammar::print(ostream& outStream, class Gitem *gitem)
{
  outStream << "<table><tr><td>";
  outStream << "Terminals={";
  set<unsigned int>::const_iterator iter;
  bool first=true;
  for (iter=terminals.begin(); iter != terminals.end(); iter++){
    if (first)
      first=false;
    else
      outStream << ", ";
    outStream << intToStrTable[*iter] /***<< "(" << *iter << ")"***/;
  }
  outStream << "}" << endl;
  outStream << "</td></tr><tr><td>";
  outStream << "NonTerminals={";
  first=true;
  for (iter=nonTerminals.begin(); iter != nonTerminals.end(); iter++){
    if (first)
      first=false;
    else
      outStream << ", ";
    outStream << intToStrTable[*iter] /***<< "(" << *iter << ")"***/;
  }
  outStream << "}" << endl;
  outStream << "</td></tr><tr><td>";
  outStream << "StartTerm=";
  if (startTerm)
    startTerm->print(outStream);
  else
    outStream << "NULL";
  outStream << endl;
  outStream << "</td></tr><tr><td>";
  outStream << "Rules:\n";
  outStream << "&nbsp;</td><td><table>";
  ruleSet::const_iterator iterRules;
  for (iterRules=rulesBegin(); iterRules != rulesEnd(); iterRules++){
    outStream << "<tr><td>";
    (*iterRules)->print(outStream, -1, true);
    outStream << "</td></tr>";
  }
  outStream << "</table>";
  outStream << "</td></tr></table>";
  outStream << endl;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Grammar::addNonTerminal(unsigned int s)
{
  nonTerminals.insert(s);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Grammar::addTerminal(unsigned int s)
{
  terminals.insert(s);
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool
Grammar::isTerminal(Term *t)
{
  set<unsigned int>::const_iterator iter=terminals.find(t->getCode());
  return (iter != terminals.end());
} 

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool
Grammar::isNonTerminal(Term *t)
{
  set<unsigned int>::const_iterator iter=nonTerminals.find(t->getCode());
  return (iter != nonTerminals.end());
} 

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Grammar::findTerms()
{
  nonTerminals.clear();
  terminals.clear();

  ruleSet::const_iterator iterRules;
  for (iterRules=rulesBegin(); iterRules != rulesEnd(); iterRules++){
    nonTerminals.insert((*iterRules)->getLhs()->getCode());
  }
  for (iterRules=rulesBegin(); iterRules != rulesEnd(); iterRules++){
    unsigned int i;
    for(i=0; i<(*iterRules)->getRhs().size(); i++){
      for (termVector::const_iterator term=((*iterRules)->getRhs()[i])->begin();
	   term != ((*iterRules)->getRhs()[i])->end();
	   term++){
	if (nonTerminals.find((*term)->getCode())==nonTerminals.end()){
	  terminals.insert((*term)->getCode());
	}
      }
    }
  }
}

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Grammar::toXML(xmlNodePtr nodeRoot)
{
  xmlNodePtr g=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"GRAMMAR", NULL);
  xmlNodePtr t=xmlNewChild(g, NULL, (const xmlChar*)"TERMINALS", NULL);
  set<unsigned int>::const_iterator iter;
  for (iter=terminals.begin(); iter != terminals.end(); iter++){
    xmlNewChild(t, NULL, (const xmlChar*)"TERM", (const xmlChar*)(intToStrTable[*iter].c_str()));
  }
  t=xmlNewChild(g, NULL, (const xmlChar*)"NON-TERMINALS", NULL);
  for (iter=nonTerminals.begin(); iter != nonTerminals.end(); iter++){
    xmlNewChild(t, NULL, (const xmlChar*)"TERM", (const xmlChar*)(intToStrTable[*iter].c_str()));
  }
  xmlNodePtr r=xmlNewChild(g, NULL, (const xmlChar*)"RULES", NULL);
  ruleSet::const_iterator iterRules;
  for (iterRules=rulesBegin(); iterRules != rulesEnd(); iterRules++){
    (*iterRules)->toXML(r);
  }
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
list<class Rule *>*
Grammar::findRules(class Term *lhs)
{
  list<class Rule *> *result=new list<class Rule *>;
  ruleSet::const_iterator iterRules;
  for (iterRules=rulesBegin(); iterRules != rulesEnd(); iterRules++){
    if (lhs->getCode()==(*iterRules)->getLhs()->getCode()){
      result->push_back(*iterRules);
    }
  }
  return result;
}
