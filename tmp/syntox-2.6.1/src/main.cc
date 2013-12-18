/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

using namespace std;

#include <deque>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <queue>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/resource.h>

#include "rule.hh"
#include "grammar.hh"
#include "synthesizer.hh"
#include "errors.hh"
#include "bits.hh"
#include "vartable.hh"
#include "value.hh"

time_t start, end;
#ifdef OUTPUT_XML
xmlNodePtr nodeRoot;
xmlDocPtr document;
#endif

/***************************************************
 *
 **************************************************/
void
Usage(char **argv)
{
  fprintf(stderr, "Usage: %s [option] -grammar &lt;file&gt; -lexicon &lt;file&gt; -input &lt;file&gt;\n", PACKAGE_NAME);
  fputs("\
options<BR>\n\
\t--help                        print this<BR>\n\
\t--version                     print version<BR>\n\
\t--verbose                       verbose mode<BR>\n\
\t--trace                       trace mode<BR>\n\
\t--reduceAll                   reduce all rules<BR>\n\
\t-compactLexiconFile &lt;file&gt;<BR>\n\
\t-compactLexiconDirectory &lt;file&gt;<BR>\n\
\t-maxLength &lt;n&gt;                max number of length<BR>\n\
\t-maxUsages &lt;n&gt;                 max number of rule usage<BR>\n\
", stderr);
#ifdef OUTPUT_XML
  fputs("\t-xml &lt;file&gt;                   the XML file<BR>\n\
", stderr);
#endif
#ifdef OUTPUT_FOREST_DOT
  fputs("\t-dotforest &lt;file&gt;                   the DOT file<BR>\n\
", stderr);
#endif
#ifdef OUTPUT_ITEMS_DOT
  fputs("\t-dotitems &lt;file&gt;                   the OUTPUT_ITEMS_DOT file<BR>\n\
", stderr);
#endif
}

/***************************************************
 *
 **************************************************/
void
seq(int i)
{
  cerr << endl << "ALARM SIGNAL: OUT OF TIME" << endl;
  exit (EXIT_SUCCESS);
}


/***************************************************
 *
 **************************************************/
int
main(int argn,
     char **argv)
{
  extern class Synthesizer synthesizer;
  
  bitsInit();
  varTableInit();

  char *grammarFileName=NULL;
  char *lexiconFileName=NULL;
  char *inputFileName=NULL;
  char *grammarString=NULL;
  char *lexiconString=NULL;
  char *inputString=NULL;
  char *compactLexiconFileName=NULL;
  char *compactLexiconDirectory=NULL;
#ifdef OUTPUT_XML
  synthesizer.putOutXML(NULL);
#endif
#ifdef OUTPUT_FOREST_DOT
  synthesizer.putOutputForestDotFileName(NULL);
#endif
#ifdef OUTPUT_ITEMS_DOT
  synthesizer.putOutputItemsDotFileName(NULL);
#endif
  if (argn > 1){
    for (unsigned int arg=1;argv[arg];arg++){
      if (argv[arg][0] == '-'){
	if (!strcmp (argv[arg]+1, "-version")){
	  std::cout << PACKAGE_VERSION;
	  return EXIT_SUCCESS;
	}
	else if (!strcmp (argv[arg]+1, "-help")){
	  Usage(argv);
	  return EXIT_SUCCESS;
	}
	else if (!strcmp (argv[arg]+1, "-verbose")){
	  synthesizer.putVerbose(true);
	}
	else if (!strcmp (argv[arg]+1, "-trace")){
	  synthesizer.putTrace(true);
	}
	else if (!strcmp (argv[arg]+1, "-reduceAll")){
	  synthesizer.putReduceAll(true);
	}
	else if (!strcmp (argv[arg]+1, "h")){
	  Usage(argv);
	  return EXIT_SUCCESS;
	}
#ifdef OUTPUT_XML
	else if (!strcmp (argv[arg]+1, "xml")){
	  if (argv[arg+1]!=NULL){
	    synthesizer.putOutXML(strdup(argv[++arg]));
	  } else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 
#endif
#ifdef OUTPUT_FOREST_DOT
	else if (!strcmp (argv[arg]+1, "dotforest")){
	  if (argv[arg+1]!=NULL)
	    synthesizer.putOutputForestDotFileName(strdup(argv[++arg]));
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 
#endif
#ifdef OUTPUT_ITEMS_DOT
	else if (!strcmp (argv[arg]+1, "dotitems")){
	  if (argv[arg+1]!=NULL)
	    synthesizer.putOutputItemsDotFileName(strdup(argv[++arg]));
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 
#endif
	else if (!strcmp (argv[arg]+1, "compactLexiconDirectory")){
	  if (argv[arg+1]!=NULL){
	    compactLexiconDirectory=strdup(argv[++arg]);
	  } else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "compactLexiconFile")){
	  if (argv[arg+1]!=NULL){
	    compactLexiconFileName=strdup(argv[++arg]);
	  } else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "grammarFile")){
	  if (argv[arg+1]!=NULL)
	    grammarFileName=strdup(argv[++arg]);
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "lexiconFile")){
	  if (argv[arg+1]!=NULL)
	    lexiconFileName=strdup(argv[++arg]);
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "inputFile")){
	  if (argv[arg+1]!=NULL)
	    inputFileName=strdup(argv[++arg]);
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "grammar")){
	  if (argv[arg+1]!=NULL)
	    grammarString=strdup(argv[++arg]);
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "lexicon")){
	  if (argv[arg+1]!=NULL)
	    lexiconString=strdup(argv[++arg]);
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "input")){
	  if (argv[arg+1]!=NULL)
	    inputString=strdup(argv[++arg]);
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "maxLength")){
	  if (argv[arg+1]!=NULL)
	    synthesizer.putMaxLength(atoi(argv[++arg]));
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "maxUsages")){
	  if (argv[arg+1]!=NULL)
	    synthesizer.putMaxUsages(atoi(argv[++arg]));
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 

	else if (!strcmp (argv[arg]+1, "maxTime")){
	  if (argv[arg+1]!=NULL){
	    signal(SIGALRM, seq);
	    alarm(atoi(argv[++arg]));
	    time (&start);
	  }
	  else {
	    Usage(argv);
	    return EXIT_SUCCESS;
	  }
	} 



	else {
	  cerr << argv[arg]+1 << endl;
	  Usage(argv);
	  return EXIT_SUCCESS;
	}
      }
    }
  }
  
  if (compactLexiconFileName){
    synthesizer.putLex(new class Lex);
    if (!synthesizer.getLex()->load(compactLexiconDirectory, compactLexiconFileName))
      return EXIT_FAILURE;
    //unsigned long int info;
    //info = lex->searchStatic(lex->init, "v#faire");
    //lex->printResults(info, 1);
    //FATAL;
  }
  
  if (grammarFileName){
    if (synthesizer.getVerbose())
      cerr << "load grammar: " << grammarFileName << "<BR>" << endl;
    synthesizer.parseGrammarFile(grammarFileName);
  }
  
  if (grammarString)
    synthesizer.parseGrammar(grammarString);
  
  if (lexiconFileName){
    if (synthesizer.getVerbose())
      cerr << "load lexicon" << "<BR>" << endl;
    synthesizer.parseLexiconFile(lexiconFileName);
  }
  
  if (lexiconString)
    synthesizer.parseLexicon(lexiconString);
  
  if (inputFileName || inputString){
#ifdef OUTPUT_XML
    if (synthesizer.getOutXML()){
      document=xmlNewDoc ((xmlChar*)"1.0");
      xmlDocSetRootElement(document, xmlNewNode(NULL, (xmlChar*)"ROOT"));
      nodeRoot=xmlDocGetRootElement(document);
    }
#endif
#ifdef OUTPUT_FOREST_DOT
    synthesizer.initOutputForestDotFile();
#endif
#ifdef OUTPUT_ITEMS_DOT
    synthesizer.initOutputItemsDotFile();
#endif
    list<string> *result=NULL;
    if (inputFileName){
      if (synthesizer.getVerbose())
	cerr << "load input" << "<BR>" << endl;
      result=synthesizer.parseInputFile(inputFileName);
    }
    else if (inputString)
      result=synthesizer.parseInput(inputString);
    if (result)
      for (list<string>::const_iterator i=result->begin(); i!=result->end(); i++)
	cout << *i << endl;
    
#ifdef OUTPUT_XML
    if (synthesizer.getOutXML()){
      string encoding="UTF-8";
      xmlSaveFormatFileEnc(synthesizer.getOutXML(), document, encoding.c_str(), 1);
    }
#endif
#ifdef OUTPUT_FOREST_DOT
    synthesizer.concludeOutputForestDotFile();
#endif
#ifdef OUTPUT_ITEMS_DOT
    synthesizer.concludeOutputItemsDotFile();
#endif
  }
  if (synthesizer.getVerbose())
    cerr << endl << "EXIT_SUCCESS" << "<BR>" << endl;
  return EXIT_SUCCESS; 
}
