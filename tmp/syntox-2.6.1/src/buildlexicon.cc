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
#include <string>
#include <map>
#include <cmath>
using namespace std;

#include <sys/stat.h>

#include "buildlexicon.hh"
#include "errors.hh"

////////////////////////////////////////////////////////////
// Calcule les offsets du tableau FSA
////////////////////////////////////////////////////////////
void
Tree::setIndexStaticFSA(unsigned long int &index)
{
  class Tree *lexiconSy;
  for (lexiconSy=this;lexiconSy!=NULL;lexiconSy=lexiconSy->sibling){
    lexiconSy->adress = index++;
    if (lexiconSy->child)
      lexiconSy->child->setIndexStaticFSA(index);
  }
}

////////////////////////////////////////////////////////////
// écrit les enregistrements du FSA
// les offsets sont calculés sur 32 (vs 16) bits si long==1
////////////////////////////////////////////////////////////
void
Tree::printStaticFSA(FILE *out, class Lex *lex)
{
  struct Fsa elt;
  Tree *lexiconSy;
  if (this==lex->lexiconInit){
    lex->init=this->adress;
  }
  for (lexiconSy=this;lexiconSy;lexiconSy=lexiconSy->sibling){
    elt.child=(lexiconSy->child==NULL)?(unsigned long int)~0UL:lexiconSy->child->adress;
    elt.sibling=(lexiconSy->sibling==NULL)?(unsigned long int)~0UL:lexiconSy->sibling->adress;
    elt.info=(lexiconSy->info==NULL)?(unsigned long int)~0UL:lexiconSy->info->getAdress();
    elt.letter=lexiconSy->letter;
    if (!fwrite(&elt, sizeof(elt), 1, out))
      FATAL_ERROR;
#ifdef DIFF
    fprintf(stdout, "%lX ch:%lX sb:%lX in:%lX <%c>\n", lexiconSy->adress, elt.child, elt.sibling, elt.info, elt.letter);
#endif //DIFF
    lexiconSy->child->printStaticFSA(out, lex);
  }
}

////////////////////////////////////////////////////////////
// Calcule les offsets du tableau info
////////////////////////////////////////////////////////////
void
Tree::setIndexStaticInfo(unsigned long int &index)
{
  Info *infoSy;
  Tree *lexiconSy;
  for (lexiconSy=this;lexiconSy!=NULL;lexiconSy=lexiconSy->sibling)
    lexiconSy->child->setIndexStaticInfo(index);
  for (lexiconSy=this;lexiconSy!=NULL;lexiconSy=lexiconSy->sibling){
    for (infoSy=lexiconSy->info;infoSy!=NULL;infoSy=infoSy->getNext()){
      infoSy->setAdress(index++);
    }
  }
}

////////////////////////////////////////////////////////////
// écrit les enregistrement du tableau d'infos
// les offsets sont calculés sur 32 (vs 16) bits si long==1
////////////////////////////////////////////////////////////
void
Tree::printStaticInfo(FILE *out){
  class Info *infoSy;
  class Tree *lexiconSy;
  struct InfoBuff elt;
  for (lexiconSy=this;lexiconSy!=NULL;lexiconSy=lexiconSy->sibling)
    lexiconSy->child->printStaticInfo(out);
  for (lexiconSy=this;lexiconSy!=NULL;lexiconSy=lexiconSy->sibling){
    for (infoSy=lexiconSy->info;infoSy!=NULL;infoSy=infoSy->getNext()){
      elt.next=(infoSy->getNext()!=NULL)?infoSy->getNext()->getAdress():(unsigned long int)(~(0UL));
      elt.offset=infoSy->getOffset();
      if (!fwrite(&elt, sizeof(elt), 1, out))
	FATAL_ERROR;
#ifdef DIFF
      fprintf(stdout, "%lX su:%lX of:%lX\n", infoSy->getAdress(), elt.next, elt.offset);
#endif //DIFF
    }
  }
}

////////////////////////////////////////////////////////////
// ajoute un mot dans l'arbre à lettres
////////////////////////////////////////////////////////////
void
Tree::add(char *str,
	       unsigned long int offset){
  //Info *infoSy;
  if (!this->letter){
    this->letter = str[0];
    if (!str[1]){
      if(this->info){
	this->info = new Info(this->info, offset);
      }
      else
	this->info = new Info(NULL, offset);
    }
    else{
      if (!this->child)
	this->child = new Tree(NULL, NULL, NULL, str[1]);
      this->child->add((char *)str+1, offset);
    }
  }
  else if (this->letter == str[0]){
    if (!str[1]){
      if(this->info){
	this->info = new Info(this->info, offset);
      }
      else
	this->info = new Info(NULL, offset);
    }
    else{
      if (!this->child)
	this->child = new Tree(NULL, NULL, NULL, str[1]);
      this->child->add((char *)str+1, offset);
    }
  }
  else if (this->sibling)
    this->sibling->add(str, offset);
  else{
    this->sibling = new Tree(NULL, NULL, NULL, str[0]);
    this->sibling->add(str, offset);
  }
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
void 
Lex::printResults (unsigned long int index,
		   bool sep)
{
  char tag[MAXSTRING]; 
  if (sep)
    fputs(SEP_PREF, stdout);
  if (index == (unsigned long int)(~(0UL))){
    fputs(SEP_UW, stdout);
    if (sep) fputs(SEP_SUFF, stdout);
    return;
  }
  while (index != (unsigned long int)(~(0UL))){
    // an other element will be describe
    strcpy (tag, buffer+(info[index].offset));
    fputs(tag, stdout);
    if (info[index].next!=(unsigned long int)(~(0UL)))
      fputs(SEP_OR, stdout);
    if ((info[index].next)!=(unsigned long int)(~(0UL)))
      index=info[index].next;
    else
      index=(unsigned long int)(~(0UL));
  }
  if (sep) fputs(SEP_SUFF, stdout);
}

////////////////////////////////////////////////////////////
// input: string
// output: info
////////////////////////////////////////////////////////////
unsigned long int 
Lex::searchStatic(unsigned long int index,
		  string s)
{
  char *str = strdup(s.c_str());
  char *str2 = str;
  index=fsa[index].child;
  // for each letter of the suffix
  while (*str){
    // parse the brothers while founding the actual char
    while (*str != fsa[index].letter){
      if (fsa[index].sibling != (unsigned long int)(~(0UL)))
	index=fsa[index].sibling;
      else
	return (unsigned long int)(~(0UL));
    }
    if (*str != fsa[index].letter)
      return ((unsigned long int)(~(0UL)));
    if (*(str+1)){
      if (fsa[index].child != (unsigned long int)(~(0UL)))
	index=fsa[index].child;
      else
	return (unsigned long int)(~(0UL));
    } else
      if (fsa[index].info != (unsigned long int)(~(0UL)))
	return fsa[index].info;
    str++;
  } 
  delete str2;
  return (unsigned long int)(~(0UL));
}

////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////
bool
Lex::saveFsa(FILE *file)
{
  int nbrBytes=sizeof(unsigned long int);;
  // encodage des offsets (16 ou 32 bits)
  if (!fwrite(&nbrBytes, sizeof(nbrBytes), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "nbreBytes: %X\n", nbrBytes);
#endif //DIFF
  unsigned long int maxSize=(unsigned long int)~0UL;
  if (!fwrite(&maxSize, sizeof(maxSize), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "maxSize: %lX\n", maxSize);
#endif //DIFF
  // nombre d'offsets du fsa
  //unsigned long int nbreItem=0;
  unsigned long int sizeFsa=0;
  lexiconInit->setIndexStaticFSA(sizeFsa);
  if (!fwrite(&sizeFsa, sizeof(sizeFsa), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "sizeFsa: %lX\n", sizeFsa);
#endif //DIFF
  if (sizeFsa == (unsigned long int)~0UL){
    fputs ("*** Error: Lexicon too large\n", stderr);
    return false;
  }
  unsigned long int sizeInfo=0; 
  lexiconInit->setIndexStaticInfo(sizeInfo);
  if (!fwrite(&sizeInfo, sizeof(sizeInfo), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "sizeInfo: %lX\n", sizeInfo);
#endif //DIFF
  if(sizeInfo == (unsigned long int)~0UL){
    fputs("*** Error: Data too large\n", stderr);
    return false;
  }

#ifdef DIFF
  fprintf(stdout, "---FSA---\n");
#endif //DIFF
  lexiconInit->printStaticFSA(file, this);

#ifdef DIFF
  fprintf(stdout, "---Info---\n");
#endif //DIFF
  lexiconInit->printStaticInfo(file);
  fputs("*** Writing Data\n", stderr);
  // table
  fflush(file);
  if (!fwrite(&init, sizeof(init), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "Init: %lX\n", init);
#endif //DIFF
  return true;
}

////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////
bool
Lex::loadFsa(FILE *file){
  //fputs("*** Loading Finite State Automata\n", stderr);
  int nbrBytes;
  if (!fread(&nbrBytes, sizeof(nbrBytes), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "nbreBytes: %X\n", nbrBytes);
#endif //DIFF
  unsigned long int maxSize;
  if (!fread(&maxSize, sizeof(maxSize), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "maxSize: %lX\n", maxSize);
#endif //DIFF
  if (nbrBytes!=(sizeof(unsigned long int)) || (maxSize!=(unsigned long int)~0UL)){
    fputs("*** lexicon compiled with an incompatible system\n", stderr);
    return false;
  }
  unsigned long int sizeFsa;
  if (!fread(&sizeFsa, sizeof(sizeFsa), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "sizeFsa: %lX\n", sizeFsa);
#endif //DIFF
  unsigned long int sizeInfo;
  if (!fread(&sizeInfo, sizeof(sizeInfo), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "sizeInfo: %lX\n", sizeInfo);
#endif //DIFF

#ifdef DIFF
  fprintf(stdout, "---FSA---\n");
#endif //DIFF
  fsa = new Fsa[sizeFsa+1];
  if (!fread(fsa, sizeof(Fsa), sizeFsa, file))
    FATAL_ERROR;
#ifdef DIFF
  for(unsigned long int sizeSy=0;sizeSy<sizeFsa;sizeSy++){
    fprintf(stdout, "%lX ch:%lX sb:%lX in:%lX <%c>\n", sizeSy, fsa[sizeSy].child, fsa[sizeSy].sibling, fsa[sizeSy].info, fsa[sizeSy].letter);
  }
#endif //DIFF

#ifdef DIFF
  fprintf(stdout, "---Info---\n");
#endif //DIFF
  info = new InfoBuff [sizeInfo+1];
  if (!fread(info, sizeof(InfoBuff), sizeInfo, file))
    FATAL_ERROR;
#ifdef DIFF
  for(unsigned long int sizeSy=0;sizeSy<sizeInfo;sizeSy++){
    fprintf(stdout, "%lX su:%lX of:%lX\n", sizeSy, info[sizeSy].next, info[sizeSy].offset);
  }
#endif //DIFF
  if (!fread(&init, sizeof(init), 1, file))
    FATAL_ERROR;
#ifdef DIFF
  fprintf(stdout, "Init: %lX\n", init);
#endif //DIFF
  return true;
}

////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////
bool
Lex::build(char* directory, char* prefix, std::istream *input) {
  bool result=true;
  FILE *fsaFile;
  FILE *tableFile;
  char str [MAXSTRING];
  char graphie [MAXSTRING];
  char oldStr [MAXSTRING];
  unsigned int i;
  unsigned int range;
  unsigned long int offset;
  
  offset = 0;
  range = 0;

  ostringstream oss;
  oss << directory << "/" << prefix << ".tbl";
  string osss = oss.str();
  tableFile = fopen(osss.c_str(), "w");//tableFileName.c_str(), "w");
  if (tableFile==NULL) {
    cerr << "Unable to open file " << osss << " for writing" << endl;
    result=false;
  } else {
    
    input->seekg(0, ios::end);
    long int size=(int)input->tellg();
    input->seekg(0, ios::beg);
    
    class Tree *lexicon;
    lexicon=new Tree(NULL, NULL, NULL, '\0');
    lexicon->child=new Tree(NULL, NULL, NULL, '\0');
    lexiconInit=lexicon;
    lexicon=lexicon->child;
    
    int nbrItem=0;
    while (input->getline(str, MAXSTRING)) {
      if (!*str)
	continue;
      for (i = 0; i <= strlen(str) && (!strchr ("\t", str[i])); i++)
	/* empty */;
      strcpy (graphie, str);
      graphie[i] = 0;
      if (i < strlen (str)) {
	graphie[i]=0;
	if (!strcmp(str+i+1, oldStr)) {
	  lexicon->add(graphie, offset);
	} else {
	  // Adds one entry
	  offset = ftell(tableFile);
	  lexicon->add(graphie, offset);
	  fprintf(tableFile, "%s%c", str+i+1, 0);
	}
	strcpy (oldStr, str+i+1); 
      } else {
	// the entry of one word without any information is the same as the previous:
	// aaa info_of_aaa
	// bbb
	//
	// bbb -> info_of_aaa
	lexicon->add(graphie, offset);
      }
      nbrItem+=strlen(str)+1;
      if (!(range++ % 1357)){
	int k = (100*(long int)(input->tellg())) / (long int)size;
	cerr << " " << k << "%\r";
      }
    }
    fclose(tableFile);
  }
  
  oss.str("");
  oss << directory << "/" << prefix << ".fsa";
  osss = oss.str();
  cerr << "*** Writing Finite State Automata " << osss << endl;
  fsaFile = fopen(osss.c_str(), "w");
  if (fsaFile == NULL) {
    cerr << "Unable to open file " << osss << " for writing" << endl;
    result=false;
  } else {
    if (!saveFsa(fsaFile))
      result=false;
    fclose(fsaFile);
  }
  return result;
}

////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////
bool
Lex::load(char *directory, char *prefix)
{
  int ok;
  unsigned long int size;

  ostringstream oss;
  oss << directory << "/" << prefix << ".fsa";
  string osss = oss.str();
  FILE *fsaFile = fopen(osss.c_str(), "r");
  if (fsaFile == NULL) {
    cerr << "File " << osss << " not found" << endl;
    exit (EXIT_FAILURE);
  } else {
    if (!loadFsa(fsaFile)) {
      return false;
    } 
    fclose(fsaFile);
  }

  oss.str("");
  oss << directory << "/" << prefix << ".tbl";
  osss = oss.str();
  FILE *tableFile=fopen(osss.c_str(), "r");
  if (!tableFile) {
    cerr << "File " << osss << " not found" << endl;
    exit (EXIT_FAILURE);
  } else {
    //cerr << "*** Load buffer in memory" << endl;
    
    struct stat *statbuf;
    statbuf = (struct stat *)malloc(sizeof(struct stat));
    stat(osss.c_str(), statbuf);
    size = statbuf->st_size;
    free(statbuf);
    
    buffer = new char [size];
    buffer[0] = 0;
    
    ok = fread (buffer, 1, size, tableFile);
    fclose (tableFile);
  }
  
  return true;
}

////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////
bool
Lex::consult(string inputFileName)
{
  FILE *inputFile=NULL;
  if (inputFileName=="-") {
    cerr << "*** Searching from stdin" << endl;
    inputFile = stdin;
  } 
  else if (inputFileName!="") {
    cerr << "*** Seaching " << inputFileName << endl;
    inputFile = fopen (inputFileName.c_str(), "r");
    if (!inputFile) {
      cerr << "Unable to open file " << inputFileName << " for reading" << endl;
      exit (EXIT_FAILURE);
    }
  }
  unsigned long int info;
  char str[MAXSTRING];
  if (inputFile){
    while (fgets (str, MAXSTRING, inputFile)) {
      str[strlen(str)-1]=0;
      info = searchStatic(init, str);
      printResults(info, 1);
      fflush(stdout);
    }
    fclose (inputFile);
  }
  
  return true;
}

