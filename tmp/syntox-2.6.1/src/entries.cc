/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#include "errors.hh"
#include "entries.hh"

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Entries::toXML(xmlNodePtr nodeRoot)
{
  xmlNodePtr node=xmlNewChild(nodeRoot, NULL, (const xmlChar*)"ENTRIES", NULL);
  for (list<class Entry *>::const_iterator i=entries.begin();
       i!=entries.end();
       i++)
    (*i)->toXML(node);
}
#endif

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
Entries::print(ostream &out){
  for (list<class Entry *>::const_iterator i=entries.begin();
       i!=entries.end();
       i++)
    (*i)->print(out);
}
