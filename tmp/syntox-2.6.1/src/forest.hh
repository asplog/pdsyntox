/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef FOREST_H
#define FOREST_H

#include <list>
#include <set>
#include <map>
#include <string>

#include "flags.hh"
#include "errors.hh"
#include "colors.hh"
#include "entry.hh"
#include "node.hh"

class Forest : 
  public Flags {
  
private:
  static unsigned int uniqId;
  unsigned int id;
  unsigned int from;
  unsigned int to;
  //colors color;
  set<class Node *, Node::less> nodes;
  unsigned int nbrCS;
  unsigned int prof;
  bool empty;
  class Entry *entry;
  list<string> output;

 public:
  Forest (class Entry *entry, unsigned int from, unsigned int to);  
  ~Forest();

  inline unsigned int getId(void){return id;}
  inline unsigned int getCode(void){
    if (entry)
      return entry->getCode();
    else
      return (unsigned int)-1;
  }
  inline set<class Node *, Node::less> &getNodes(void){return nodes;}
  inline unsigned int getNbrCS(void){return nbrCS;}
  inline unsigned int getFrom(void){return from;}
  inline unsigned int getTo(void){return to;}
  //inline colors getColor(void){return color;}
  //inline void putColor(colors color){this->color=color;} 
  inline bool getEmpty(void){return empty;}
  inline void putEmpty(bool empty){this->empty=empty;}
  inline bool isEmpty(void){return empty;}

  inline list<string> &getOutput(void){return this->output;}
  
  void print(ostream&);
  bool addNode(class Node*);
  void notDrawn(void);
  void evalNbreCS(void);
#ifdef OUTPUT_XML
  void toXML(const xmlNodePtr);
#endif
  void eval(bool_root);
#ifdef OUTPUT_FOREST_DOT
  void dot(std::ostream&, class Node*, int);
#endif

  // Return a constant iterator over the nodes (i.e. tree) in the forest
  inline set<class Node *, Node::less>::const_iterator nodesBegin(void){
    return nodes.begin(); }

  // Return a constant iterator over the nodes (i.e. tree) in the forest,
  // pointing after last one
  inline set<class Node *, Node::less>::const_iterator nodesEnd(void){
    return nodes.end(); }
  
  // Return the number of nodes in the forest,
  inline unsigned int nodesSize(void){
    return nodes.size(); }
  
  void generate(void);
  
};

#endif // FOREST_H
