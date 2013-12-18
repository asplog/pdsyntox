/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef GITEMSET_H
#define GITEMSET_H

#include <set>
using namespace std;

#include "gitem.hh"

class GitemSet {

private:
  unsigned int id;
  set<class Gitem *>items;

public:
  //
  GitemSet (int id){
    NEW ("GitemSet");
    this->id=id;
  }
  
  ~GitemSet(){
    for (set<class Gitem *, Gitem::less>::iterator i=items.begin();
	 i!=items.end();
	 i++)
      delete *i;
    items.clear();
    DELETE ("GitemSet");
  }
  
  inline unsigned int getId(void){return id;}
  inline set<class Gitem *> &getItems(void){return items;}
  
  inline set<class Gitem*>::const_iterator begin(void){return items.begin();}
  inline set<class Gitem*>::const_iterator end(void){return items.end();}
  inline set<class Gitem*>::const_iterator find(class Gitem *gitem){return items.find(gitem);}
  inline bool insert(class Gitem *gitem){
    pair<set<class Gitem*>::iterator, bool> result=items.insert(gitem);
    return result.second;
  }
  inline void erase(class Gitem *gitem){
    items.erase(gitem);
  }
  inline void erase(set<class Gitem*>::iterator gitem){
    items.erase(gitem);
  }
  inline unsigned int size(void){return items.size();}
  void resetUsages(void);

  void print(ostream&, class Synthesizer *, bool_html=TRUE_HTML);
#ifdef OUTPUT_XML
  void toXML(xmlNodePtr, class Synthesizer *);
#endif
  
};  

#endif // GITEM_H
