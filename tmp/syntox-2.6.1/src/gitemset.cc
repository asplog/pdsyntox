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

#include "gitemset.hh"
#include "io.hh"

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
GitemSet::resetUsages()
{
  for (set<class Gitem *, Gitem::less>::iterator item=items.begin();
       item!=items.end();
       item++){
    (*item)->getRule()->resetUsages();
  }
}

/* ************************************************************
 *                                                            *
 ************************************************************ */
void
GitemSet::print(ostream& oss, class Synthesizer *synthesizer, bool_html html)
{
  //oss << "<TABLE BORDER=\"0\" BGCOLOR=\"lightgray\">";
  oss << "<TABLE border=\"0\">";
  for (set<class Gitem *, Gitem::less>::iterator item=items.begin();
       item!=items.end();
       item++){
    oss << "<TR>";
    oss << "<TD align=\"LEFT\">";
    (*item)->print(oss, synthesizer);
    oss << "</TD>";
    oss << "</TR>";
  }
  oss << "</TABLE>";
}

#ifdef OUTPUT_XML
/* ************************************************************
 *                                                            *
 ************************************************************ */
void
GitemSet::toXML(xmlNodePtr node, class Synthesizer *synthesizer){
  xmlNodePtr s=xmlNewChild(node, NULL, (const xmlChar*)"STATE", NULL);
  xmlSetProp(s, (xmlChar*)"id", (xmlChar*)(toStr(id)).c_str());
  xmlSetProp(s, (xmlChar*)"fillcolor", (xmlChar*)"WHITE");
  xmlSetProp(s, (xmlChar*)"color", (xmlChar*)"BLACK");
  ostringstream oss;
  oss << "<TABLE BORDER=\"0\">";
  oss << "<TR><TD><FONT COLOR=\"BLUE\" FACE=\"Times-Roman\" POINT-SIZE=\"16\">Q" << id << "</FONT></TD></TR>";
  oss << "<TR>";
  oss << "<TD ALIGN=\"LEFT\">";
  print(oss, synthesizer, TRUE_HTML);
  oss << "</TD>";
  oss << "</TR>";
  oss << "</TABLE>";
  xmlSetProp(s, (xmlChar*)"rule", (xmlChar*)(oss.str().c_str()));
}
#endif
