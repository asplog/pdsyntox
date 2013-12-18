/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef LEXICON_H
#define LEXICON_H

#define MAXSTRING 50000
#define SEP_PREF ""
#define SEP_UW "UNKNOWN"
#define SEP_SUFF "\n"
#define SEP_OR "|"

struct Fsa {
public:
  unsigned long int child;
  unsigned long int sibling;
  unsigned long int info;
  char letter;
} ;

struct InfoBuff {
public:
  unsigned long int next;
  unsigned long int offset;
};

class Lex {
public:
  char *buffer;
  struct Fsa *fsa;         // table fsa
  class InfoBuff *info;   //table des info
  unsigned long int init;
  class Tree *lexiconInit;
  
  void printResults (unsigned long int index, bool sep);
  
  unsigned long int searchStatic(unsigned long int index, string);
  bool saveFsa(FILE *file);
  bool loadFsa(FILE *file);
  bool build(char* directory, char* prefix, std::istream *input);
  bool load(char *directory, char *prefix);
  bool consult(string inputFileName);
};

class Tree {
 public:
  class Tree *child;
  class Tree *sibling;
  class Info *info;
  int letter;
  unsigned long int adress;
  
  Tree(Tree *child,
       Tree *sibling,
       Info *info,
       char letter){
    this->adress=0;
    this->child = child;
    this->sibling = sibling;
    this->info = info;
    this->letter = letter;
  };
  
  ~Tree() {};
  
  void add(char *, unsigned long int);
  void setIndexStaticFSA(unsigned long int &);
  void printStaticFSA(FILE *, class Lex *);
  void setIndexStaticInfo(unsigned long int &);
  void printStaticInfo(FILE *);
};

class Info {
  
 private:
  class Info *next;
  unsigned long int offset;
  unsigned long int adress;
  
 public:
  Info(Info *next = NULL, unsigned long int offset = 0){
    adress=0;
    this->next=next;
    this->offset=offset;
  };
  
  ~Info(){};
  
  inline Info *getNext(void){return next;};
  inline unsigned long int getOffset(void){return offset;};
  inline unsigned long int getAdress(void){return adress;};
  inline void setNext(Info *info){this->next=next;};
  inline void setOffset(unsigned long int){this->offset=offset;};
  inline void setAdress(unsigned long int adress){this->adress=adress;};

  void printStatic(FILE *);
};

#endif // LEXICON_H
