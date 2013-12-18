/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef NODE_H
#define NODE_H

#include <vector>

#include "colors.hh"
#include "term.hh"

typedef vector<class Forest *> forestVector;
typedef vector<struct Term*> termVector;
  
class Node : 
  public Flags {
 
 private:
  static unsigned int uniqId;
  unsigned int id;
  int nbrCS;
  forestVector sons;
  list<string> output;

 public:

  Node (void);  
  Node (class Forest*);  
  ~Node();
  
  inline unsigned int getId(void){return id;}
  inline vector<class Forest *> &getSons(void){return sons;}
  inline  int getNbrCS(void){return nbrCS;}
  //inline colors getColor(void){return color;}
  //inline void putColor(colors color){this->color=color;} 
  inline list<string> &getOutput(void){return this->output;};

  inline forestVector::const_iterator sonsBegin(void){return sons.begin();}
  inline forestVector::const_iterator sonsEnd(void){return sons.end();}
  inline int sonsSize(){return sons.size();}
  inline void addSon(class Forest *forest){sons.push_back(forest);}

  void print(ostream&);
  void evalNbreCS(void);
  void eval(bool_root);

  // Return the forest associated to the nth son of this node
  inline Forest *getSons(int i){
    return sons[i]; }


  void hideEquations( int k);

#ifdef OUTPUT_XML
  void toXML(const xmlNodePtr, const xmlNodePtr);
#endif
  void generate(vector<class Forest *>::const_iterator);
  void generate(void);
#ifdef OUTPUT_FOREST_DOT
  void dot(std::ostream&, class Forest*);
#endif
  
  // compare deux items
  struct less {
    bool operator() (class Node *n1, class Node *n2) 
    {
      if (n1->getSons().size() < n2->getSons().size())
	return true;
      if (n1->getSons().size() > n2->getSons().size())
	return false;
      
      forestVector::const_iterator s1=n1->sonsBegin();
      forestVector::const_iterator s2=n2->sonsBegin();
      while (s1!=n1->sonsEnd()){
	if ((*s1) < (*s2))
	  return true;
	if ((*s1) > (*s2))
	  return false;
	s1++; s2++;
      }
      return false;
    }
  };

};
  
#endif // NODE_H
