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
//
////////////////////////////////////////////////////////////
void 
usage() {
  cerr <<
    "Usage: buildlexiconmain [global-option] <build|consult|test> <input>\n"
    "Global options:\n"
    "-h|--help                              print this\n"
    "-v|--version                           print version\n"
    "-f <name>                              file\n"
    "-d <directory>                         directory" << endl;
  exit (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////
int main(unsigned int argn,
	 char **argv)
{
  class Lex lex;
  int mode=0;
  string inputFileName="-";
  char prefix[MAXSTRING];
  char directory[MAXSTRING];
  if (argn > 1) {
    // generic options
    for (unsigned int i = 1; argv[i]; i++) {
      if (argv[i][0] == '-') {
	if (!strcmp(argv[i]+1, "f")) {
	  if ((i+1 >= argn) || argv[i+1][0] == '-') {
	    usage();
	  } else {
	    strcpy (prefix, argv[++i]);
	  }
	} else if (!strcmp(argv[i]+1, "d")) {
	  if ((i+1 >= argn) || argv[i+1][0] == '-') {
	    usage();
	  } else {
	    strcpy (directory, argv[++i]);
	  }
	} else if (!strcmp(argv[i]+1, "v") || !strcmp(argv[i]+1, "-version")) {
	  cerr << PACKAGE << VERSION << endl;
	  return EXIT_SUCCESS;
	} else if (!strcmp(argv[i]+1, "h") || !strcmp(argv[i]+1, "-help")) {
	  usage();
	} else {
	  usage();
	}
      } else {
	if (!strcmp(argv[i], "build")) {
	  mode=1;
	} 
	else if (!strcmp(argv[i], "consult")) {
	  mode=2;
	} 
	else if (!strcmp(argv[i], "test")) {
	  mode=3;
	} 
	else {
	  inputFileName=argv[i];
	}
      }
    }
  }
  switch (mode){
  case 1:
    {
      std::ifstream inputFile;
      if (inputFileName!=""){
	inputFile.open(inputFileName.c_str());
	if (inputFile.is_open()) {
	  if (!lex.build(directory, prefix, &inputFile))
	    return EXIT_FAILURE;
	  inputFile.close();
	} else {
	  cerr << "Unable to open file";
	  return EXIT_FAILURE;
	}
      } else {
	if (!lex.build(directory, prefix, &cin))
	  return EXIT_FAILURE;
      }
      return EXIT_SUCCESS; 
    }
    break;
  case 2:
    if (!lex.load(directory, prefix))
      return EXIT_FAILURE;
    if (!lex.consult(inputFileName))
      return EXIT_FAILURE;
    return EXIT_SUCCESS; 
    break;
  case 3:
    if (!lex.load(directory, prefix))
      return EXIT_FAILURE;
    return EXIT_SUCCESS; 
    break;
  }
  usage();
  return EXIT_SUCCESS; 
}
