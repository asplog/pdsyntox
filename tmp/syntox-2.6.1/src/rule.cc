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
#include "rule.hh"
#include "io.hh"
#include "term.hh"
#include "terms.hh"
#include "statements.hh"

unsigned int Rule::uniqId = 0;

/* ************************************************************
 *
 ************************************************************ */
Rule::~Rule(){
  DELETE("Rule");
  for (vector <class Terms *>::iterator term=rhs.begin();
       term != rhs.end();
       term++)
    if (*term)
      delete *term;
  rhs.clear();
  if(lhs){
    delete lhs;
    lhs=NULL;
  }
  if (statements){
    delete statements;
    statements=NULL;
  }
}
  
/* ************************************************************
 *
 ************************************************************ */
void
Rule::print(ostream& out, unsigned int index, bool withSemantic, bool_html html)
{
  string s;
  if (html)
    s="&nbsp;";
  else
    s=" ";
  lhs->print(out, html);
  out << s << "→" << s; 
  if ((index==0) && (rhs.size()==0)){
    out << "•";
  }
  for(unsigned int i=0; i<rhs.size(); i++){
    if (i!=0)
      out << s;
    if (index==i)
      out << "•" << s;
    rhs[i]->print(out, html);
  }
  if ((index==rhs.size()) && (rhs.size()!=0))
    out << s << "•";
  if (withSemantic){
    class Statements *stms=getStatements();
    if (stms)
      stms->print(out);
    if (html)
      out << "<BR>"; 
  }
}

/***************************
 *
 ***************************/
class Rule *
Rule::copy(){
  vector<class Terms *> rhsCopy;
  for(unsigned int i=0; i<rhs.size(); i++)
    rhsCopy.push_back(rhs[i]->copy());
  class Rule *rule=new Rule(lhs, rhsCopy, statements);
  rule->usages=usages;
  return rule;
}
  
#ifdef OUTPUT_XML
  /* ************************************************************
 *                                                            *
 ************************************************************ */
void
Rule::toXML(xmlNodePtr nodeRoot)
{
  // xmlNodePtr r=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"RULE", NULL);
  // xmlSetProp(r, (xmlChar*)"id", (xmlChar*)(toStr(id)).c_str());
  //xmlNodePtr hs=xmlNewChild(r, NULL, (const xmlChar*)"LHS", NULL);
  //lhs->toXML(hs);
  // hs=xmlNewChild(r, NULL, (const xmlChar*)"RHS", NULL);
  // for(unsigned int i=0; i<rhs.size(); i++){
  //   for (vector <class Terms *>::const_iterator term=rhs[i]->begin();
  // 	 term != rhs[i]->end();
  // 	 term++){
  //     (*term)->toXML(hs);
  //   }
  // }
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Rule::addDefaults()
{
  vector<unsigned int> downs;
  for(unsigned int i=0; i<rhs.size(); i++){
    downs.push_back(0);
  }
}
