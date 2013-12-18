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

#include "features.hh"
#include "forest.hh"
#include "grammar.hh"
#include "io.hh"

unsigned int Forest::uniqId=0;
Forest::Forest (class Entry *entry, unsigned int from, unsigned int to) 
{
  NEW("Forest");
  this->id=uniqId++;
  this->entry=entry;
  this->from=from;
  this->to=to;
  if (from==to)
    this->empty=true;
  else
    this->empty=false;
  this->nbrCS=0;
  this->prof=0;
  //this->color=WHITE;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
Forest::~Forest(){  
  DELETE("Forest");
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
bool
Forest::addNode(class Node *n)
{
  pair<set<class Node *, Node::less>::iterator, bool> result = nodes.insert(n);
  empty=false;
  return result.second;
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Forest::print(ostream& out)
{
  if (entry)
    out << intToStr(entry->getCode()) << "[" << from << "-" << to << "]";
  else
    out << "NULL" << "[" << from << "-" << to << "]";
  if (nodesSize()){
    out << "(";
    bool first=true;
    for(set<class Node *, Node::less>::const_iterator n=nodesBegin() ; n!=nodesEnd() ; n++){
      if (first)
	first=false;
      else
	out << ", ";
      (*n)->print(out);
    }
    out << ")";
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Forest::evalNbreCS(void)
{
  if (isUnsetFlags(Flags::COUNT)){
    addFlags(Flags::COUNT);
    if (nodesSize()>0){
      nbrCS=0;
      for(set<class Node *, Node::less>::const_iterator n=nodesBegin() ; n!=nodesEnd() ; n++){
 	(*n)->evalNbreCS();
 	nbrCS += (*n)->getNbrCS();
      }
    } else
      nbrCS=1;
  }
}

#ifdef OUTPUT_FOREST_DOT
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Forest::dot(std::ostream& outStream, class Node *prec, int k)
{
  if (k)
    outStream << "N" << prec->getId() << " -- F" << this->getId() << " [label=\"" << k << "\"];" << endl;
  if (isUnsetFlags(Flags::DOTTED)){
    addFlags(Flags::DOTTED);
    if (entry){
      outStream << "F" << this->getId();
      if (nodesSize()==0){
	outStream << "[shape=\"plaintext\", label=\"" << intToStr(entry->getCode());
	outStream << "\\n";
	//outStream << "[" << from << "," << to << "]";
	//outStream << "(" << nodesSize() << ")";
	if (output.size()>0){
	  for(list<string>::const_iterator s=output.begin() ; s!=output.end() ; ){
	    outStream << (*s);
	    if(s++!=output.end())
	      outStream << "\\n";
	  }
	}    
      } else {
	outStream << "[shape=\"egg\", label=\"" << intToStr(entry->getCode());
	//outStream << "[" << from << "," << to << "]";
	//outStream << "(" << nodesSize() << ")";
      }
      outStream << "\\n";
      
      /***
	  if (output.size()>0){
	  for(list<string>::const_iterator s=output.begin() ; s!=output.end() ; ){
	  outStream << (*s);
	  if(s++!=output.end())
	  outStream << "\\n";
	  }
	  }    
      ***/  
      //outStream << "\\n" << comment;
      outStream << "\"";
      
      //if (color!=WHITE)
      //outStream << ", style=\"filled\", color=\"" << colorToStr[color] << "\"";
      outStream << "]";
    }
    outStream << ";" << endl;
    if (nodesSize()){
      int k=1;
      for(set<class Node *, Node::less>::const_iterator n=nodesBegin() ; n!=nodesEnd() ; n++, k++){
	(*n)->dot(outStream, this);
      }
    }
  }
}
#endif

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Forest::toXML(xmlNodePtr nodeRoot)
{
  xmlNodePtr f=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"FOREST", NULL);
  xmlErrors(f);
  if (isSetFlags(Flags::XML)){
    xmlSetProp(f, (xmlChar*)"idref", (xmlChar*)(toStr(id)).c_str());
    return;
  } else {
    xmlSetProp(f, (xmlChar*)"id", (xmlChar*)(toStr(id)).c_str());
  }
  //if (color)
  //xmlSetProp(f, (xmlChar*)"color", (xmlChar*)colorToStr[color].c_str());
  addFlags(Flags::XML);
  xmlSetProp(f, (xmlChar*)"from", (xmlChar*)toStr(from).c_str());
  xmlSetProp(f, (xmlChar*)"to", (xmlChar*)toStr(to).c_str());
  xmlSetProp(f, (xmlChar*)"nbrCS", (xmlChar*)(toStr(getNbrCS())).c_str());
  xmlSetProp(f, (xmlChar*)"size", (xmlChar*)(toStr(nodesSize())).c_str());
  
  if (empty)
    xmlSetProp(f, (xmlChar*)"empty", (xmlChar*)"yes");
  else
    xmlSetProp(f, (xmlChar*)"empty", (xmlChar*)"no");
  
  
  if (entry)
    entry->toXML(f);
  
  if (output.size()>0){
    xmlNodePtr o=xmlNewChild(f, NULL, (const xmlChar*)"OUTPUT", NULL);
    for(list<string>::const_iterator s=output.begin() ; s!=output.end() ; s++)
      xmlNewChild(o, NULL, (const xmlChar*)"S", (xmlChar*)(*s).c_str());
  }
  for(set<class Node *, Node::less>::const_iterator n=nodesBegin() ; n!=nodesEnd() ; n++){
    (*n)->toXML(nodeRoot, f);
  }
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Forest::eval(bool_root root)
{
  if (isUnsetFlags(Flags::EVAL)){
    addFlags(Flags::EVAL);
    for(set<class Node *, Node::less>::const_iterator n=nodesBegin() ; n!=nodesEnd() ; n++){
      for(vector<class Forest *>::const_iterator f=(*n)->sonsBegin() ; f!=(*n)->sonsEnd() ; f++){
	if ((*f)->from<(*f)->to){
	  (*f)->eval(root);
	}
      }
    }
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Forest::generate()
{
  if (isUnsetFlags(Flags::GEN)){
    addFlags(Flags::GEN);
    if (nodesSize())
      for(set<class Node *, Node::less>::const_iterator n=nodesBegin() ; n!=nodesEnd() ; n++)
	(*n)->generate();
    
    if (entry){
      ostringstream o;
      if (entry->getArgs())
	entry->printArgs(o);
      if (entry->getCodeForm()!=(unsigned int)-1){
	output.push_back(intToStr(entry->getCodeForm()) + o.str());
      }
    }
    if (nodesSize())
      for(set<class Node *, Node::less>::const_iterator n=nodesBegin() ; n!=nodesEnd() ; n++){
	for (list<string>::const_iterator s=(*n)->getOutput().begin();
	     s!=(*n)->getOutput().end();
	     s++)
	  output.push_back(*s);
    }
  }
}
