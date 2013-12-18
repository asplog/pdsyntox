/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H

#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>

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

using namespace std;

#include "grammar.hh"
#include "features.hh"
#include "forestIdentifier.hh"
#include "buildlexicon.hh"

#ifdef OUTPUT_ITEMS_DOT
extern ofstream outputItemsDotFile;
#endif

#ifdef OUTPUT_FOREST_DOT
extern ofstream outputForestDotFile;
#endif

extern bool compare (class Forest *, class Forest *);

class Synthesizer {
 private:
  class Grammar *grammar;
  map<unsigned int, class GitemSet *> states;
  // pos => (PRED => entries)
  // entries: list<entry>
  
  // verb => (manger => (mangions, mange|mange))
  map<unsigned int, map<unsigned int, class Entries *, less<unsigned int> >*, less<unsigned int> > lexicon;
  
  // Associe un identifieur de foret à une foret
  map<class ForestIdentifier* , class Forest* , ForestIdentifier::less> forestMap;
  map<int, class Gitem* > itemMap;
  class Forest *rootForest;
  class Features *startFeatures;
  class Term *startTerm;
  class Lex *lex;
  class Entry *localEntry; //flying lexical entry

  bool trace;
  bool verbose;
  bool reduceAll;

#ifdef OUTPUT_XML
  char *outXML;
#endif

#ifdef OUTPUT_FOREST_DOT
char *outputForestDotFileName;
ofstream outputForestDotFile;
#endif

#ifdef OUTPUT_FSA_DOT
char *outputFsaDotFileName;
ofstream outputFsaDotFile;
#endif

#ifdef OUTPUT_ITEMS_DOT
char *outputItemsDotFileName;
ofstream outputItemsDotFile;
#endif

  unsigned int maxLength;
  unsigned int maxUsages;
  bool maxLengthMsg;
  bool maxUsagesMsg;

public:
  
  Synthesizer(void){
    NEW("Synthesizer");
    lex=NULL;
    grammar=NULL;
    maxLength=MAXLENGTHDEFAULT;
    maxUsages=MAXUSAGESDEFAULT;
    maxLengthMsg=false;
    maxUsagesMsg=false;
    rootForest=NULL;
    startFeatures=NULL;
    startTerm=NULL;
    localEntry=NULL;
  }
  
  ~Synthesizer(void){
    DELETE("Synthesizer");
    if (grammar){
      delete grammar;
      grammar=NULL;
    }
  }
  
  inline void putMaxLength(unsigned int maxLength){this->maxLength=maxLength;};
  inline void putMaxUsages(unsigned int maxUsages){this->maxUsages=maxUsages;};
  inline void putMaxLengthMsg(bool b){this->maxLengthMsg=b;};
  inline void putMaxUsagesMsg(bool b){this->maxUsagesMsg=b;};
  inline bool getMaxUsagesMsg(void){return this->maxUsagesMsg;};

  inline class Grammar *getGrammar(void){return grammar;};
  inline void putGrammar(class Grammar *grammar){this->grammar=grammar;};
  inline map<unsigned int, class GitemSet *>::const_iterator begin(void){return states.begin();};
  inline map<unsigned int, class GitemSet *>::const_iterator end(void){return states.end();};
  inline int size(void){return states.size();};

  inline class Lex *getLex(void){return lex;};
  inline void putLex(class Lex *lex){this->lex=lex;};

  inline map<class ForestIdentifier*, class Forest* , ForestIdentifier::less> &getForestMap(void){return forestMap;};
  inline void setForestMap(map<class ForestIdentifier*, class Forest* , ForestIdentifier::less> &forestMap){this->forestMap=forestMap;};

  inline void putStartFeatures(class Features *f){this->startFeatures=f;};
  inline class Features *getStartFeatures(void){return this->startFeatures;};
  
  inline class Term *getStartTerm(void){return startTerm;};
  inline void putStartTerm(class Term *startTerm){this->startTerm=startTerm;};

  inline void putVerbose(bool verbose){this->verbose=verbose;};
  inline void putTrace(bool trace){this->trace=trace;};
  inline void putReduceAll(bool reduceAll){this->reduceAll=reduceAll;};
#ifdef OUTPUT_XML
  inline void putOutXML(char *outXML){this->outXML=outXML;};
  inline char *getOutXML(void){return this->outXML;};
#endif

#ifdef OUTPUT_FOREST_DOT
  inline char *getOutputForestDotFileName(void){return outputForestDotFileName;};
  inline void putOutputForestDotFileName(char *outputForestDotFileName){this->outputForestDotFileName=outputForestDotFileName;};
#endif

#ifdef OUTPUT_FSA_DOT
  inline char *getOutputFsaDotFileName(void){return outputFsaDotFileName;};
  inline void putOutputFsaDotFileName(char *outputFsaDotFileName){this->outputFsaDotFileName=outputFsaDotFileName;};
#endif

#ifdef OUTPUT_ITEMS_DOT
  inline char *getOutputItemsDotFileName(void){return outputItemsDotFileName;};
  inline void putOutputItemsDotFileName(char *outputItemsDotFileName){this->outputItemsDotFileName=outputItemsDotFileName;};
  inline ofstream &getOutputItemsDotFile(void){return outputItemsDotFile;};
#endif

  inline map<unsigned int, map<unsigned int, class Entries *, less<unsigned int> >*, less<unsigned int> > &getLexicon(void){return lexicon;};
  inline void putLexicon(map<unsigned int, map<unsigned int, class Entries *, less<unsigned int> >*, less<unsigned int> > &lexicon){this->lexicon=lexicon;};
  inline map<unsigned int, map<unsigned int, class Entries *, less<unsigned int> >*, less<unsigned int> >::iterator findLexicon(unsigned int i){return lexicon.find(i);}
  inline map<unsigned int, map<unsigned int, class Entries *, less<unsigned int> >*, less<unsigned int> >::iterator beginLexicon(void){return lexicon.begin();}
  inline map<unsigned int, map<unsigned int, class Entries *, less<unsigned int> >*, less<unsigned int> >::iterator endLexicon(void){return lexicon.end();}
  
  inline class Entry *getLocalEntry(void){return localEntry;}
  inline void putLocalEntry(class Entry *localEntry){this->localEntry=localEntry;}

  void printLexicon(ostream&);
  
  inline map<int, class Gitem* >& getItemMap(void){return itemMap;};
  
  inline bool getVerbose(void){return verbose;}
  inline bool getTrace(void){return trace;}
  inline bool getReduceAll(void){return reduceAll;}

private:
  void parse(FILE *);
  void generate(void); 
  list<string> *toStrings(void); 
  void clearLexicon(void);
  void clearStates(void);
  void clearItemMap(void);
  void clearForestMap(void);
  void printState(ostream&, class GitemSet*, bool_html);
  void close(class GitemSet *,  int);
  bool shift(class GitemSet *, int);

public:  
  void parseGrammar(string);
  void parseLexicon(string);
  list<string> *parseInput(string);
  void parseGrammarFile(char *);
  void parseLexiconFile(char *);
  list<string> *parseInputFile(char *);
#ifdef OUTPUT_FOREST_DOT
  void initOutputForestDotFile(void);
  void concludeOutputForestDotFile(void);
#endif
#ifdef OUTPUT_FSA_DOT
  void initOutputFsaDotFile(void);
  void concludeOutputFsaDotFile(void);
#endif
#ifdef OUTPUT_ITEMS_DOT
  void initOutputItemsDotFile(void);
  void concludeOutputItemsDotFile(void);
#endif
};

#endif // SYNTHESIZER_H
