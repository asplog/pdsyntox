/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef ENTRIES_H
#define ENTRIES_H
#include <list>
#ifdef XML
#include <libxml/tree.h>
#endif

#include "entry.hh"

class Entries {
  
private:
  
  // liste d'entrées lexicales
  list<class Entry *> entries;
  
public:
  
  Entries(void){
    NEW("Entries");
  }
  
  Entries(class Entry *entry){
    NEW("Entries");
    this->entries.push_front(entry);
  }
  
  Entries(list<class Entry *> &entries){
    NEW("Entries");
    this->entries=entries;
  }
  
  Entries(int codePos, int codeLemma, int codeForm){
    NEW("Entries");
    this->entries.push_front(new Entry(codePos, codeLemma, codeForm));
  }
	  
  ~Entries(){
    DELETE("Entries");
  }
  
  inline size_t size(void){return this->entries.size();}
  inline list<class Entry*>::iterator begin(void){return this->entries.begin();}
  inline list<class Entry*>::iterator end(void){return this->entries.end();}

  inline void add(class Entry *entry){this->entries.push_back(entry);}
#ifdef OUTPUT_XML
  void toXML(xmlNodePtr);
#endif
  void print(ostream&);
};

#endif // ENTRIES_H
