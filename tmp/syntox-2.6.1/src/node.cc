/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <vector>
#include <string>

#include "errors.hh"
#include "node.hh"
#include "forest.hh"
#include "io.hh"

ofstream out;
unsigned int Node::uniqId=0;

/* ************************************************************
 *                                                            *
 ************************************************************ */
Node::Node (void) {
  NEW("Node");
  id=uniqId++;
  //color=WHITE;
  nbrCS=0;
}
  
/* ************************************************************
 *                                                            *
 ************************************************************ */
Node::Node (class Forest *forest) {
  NEW("Node");
  id=uniqId++;
  //color=WHITE;
  addSon(forest);
  nbrCS=0;
  evalNbreCS();
}
  
/* ************************************************************
 *                                                            *
 ************************************************************ */
Node::~Node() {
  DELETE("Node");
}
  
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Node::print(ostream& out)
{
  if (sons.size()){
    out << "#";
    bool first=true;
    for(forestVector::const_iterator j=sons.begin(); j!=sons.end() ; j++){
      if (first)
	first=false;
      else
	out << ", ";
      (*j)->print(out);
    }
    out << "#";
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Node::evalNbreCS(void)
{
  if ((flags & Flags::COUNT).none()){
    flags|=Flags::COUNT;
    nbrCS=1;
    if (sons.size()){
      for(forestVector::const_iterator it=sonsBegin(); it!=sonsEnd(); it++){
	(*it)->evalNbreCS();
	nbrCS *= (*it)->getNbrCS();
      }
    }
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Node::eval(bool_root root)
{
  //color=BLUE;
   if ((flags & Flags::EVAL).none()){
     flags|=Flags::EVAL;
    
     for(forestVector::const_iterator it=sonsBegin(); it!=sonsEnd(); it++){
       (*it)->eval(FALSE_ROOT);
     }
   }
}   

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Node::toXML(xmlNodePtr nodeRoot, xmlNodePtr nodeFather)
{
  xmlNodePtr node=xmlNewChild(nodeFather, NULL, (const xmlChar*)"NODE", NULL);
  xmlSetProp(node, (xmlChar*)"id", (xmlChar*)(toStr(getId())).c_str());
  xmlErrors(node);
  //if (color)
  //xmlSetProp(node, (xmlChar*)"color", (xmlChar*)colorToStr[color].c_str());
  /*
    if (output.size()>0){
    xmlNodePtr o=xmlNewChild(node, NULL, (const xmlChar*)"OUTPUT", NULL);
    for(list<string>::const_iterator s=output.begin() ; s!=output.end() ; s++)
    xmlNewChild(o, NULL, (const xmlChar*)"S", (xmlChar*)(*s).c_str());
    }
  */
  for (vector<class Forest *>::const_iterator s=sons.begin() ; 
       s!=sons.end() ; 
       s++){
    if ((*s)->isUnsetFlags(Flags::XML))
      (*s)->toXML(nodeRoot);
    xmlNodePtr son=xmlNewChild(node, NULL, (const xmlChar*)"SON", NULL);
    xmlSetProp(son, (xmlChar*)"idref", (xmlChar*)(toStr((*s)->getId())).c_str());
    if ((*s)->getEmpty())
      xmlSetProp(son, (xmlChar*)"empty", (xmlChar*)"yes");
    else
      xmlSetProp(son, (xmlChar*)"empty", (xmlChar*)"no");
  }
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Node::generate(vector<class Forest *>::const_iterator son)
{
  list<string> result;
  if (son != sons.end()){
    for (list<string>::const_iterator s=(*son)->getOutput().begin();
	 s!=(*son)->getOutput().end();
	 s++){
      
      if (output.size()==0)
	result.push_back(*s);
      else
	for (list<string>::const_iterator o=output.begin();
	     o!=output.end();
	     o++){
	  result.push_back((*o) + " " + (*s));
	}
    }
    output.clear();
    for (list<string>::const_iterator o=result.begin();
	 o!=result.end();
	 o++){
      output.push_back(*o);
    }
    generate(++son);
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Node::generate()
{
  for(forestVector::const_iterator it=sonsBegin(); it!=sonsEnd(); it++)
    (*it)->generate();
  generate(sonsBegin());
}


#ifdef OUTPUT_FOREST_DOT
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Node::dot(std::ostream& outStream, class Forest *prec)
{
  outStream << "F" << prec->getId() << " -- N" << this->getId() << ";" << endl;
  if (isUnsetFlags(Flags::DOTTED)){
    addFlags(Flags::DOTTED);
    outStream << "N" << this->getId() << " [shape=\"ellipse\"";
    outStream << ", height=\"0.1\", width=\"0.1\"";
    //if (this->getColor()!=WHITE)
    //outStream << "style=\"filled\", fillcolor=\"" << colorToStr[this->getColor()] << "\"";
    outStream << ", label=\"";
    /***
	if (output.size()>0){
	for(list<string>::const_iterator s=output.begin() ; s!=output.end() ; ){
	outStream << (*s);
	if(s++!=output.end())
	outStream << "\\n";
	}
	}      
	//outStream << "\\n" << comment;
	***/
    //outStream << "(" << sonsSize() << ")";
    outStream << "\"";
    outStream << "];" << endl;
    if (sonsSize()){
      int k=1;
      for(vector<class Forest *>::const_iterator f=this->sonsBegin() ; f!=this->sonsEnd() ; f++, k++){
	if ((*f)->getFrom() < (*f)->getTo()){
	  (*f)->dot(outStream, this, k);
	}
      }
    }
  }
}
#endif
