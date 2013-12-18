%{
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
#include <string>
#include <vector>
#include <list>
#include <map>
#include <bitset>

#include "errors.hh"
#include "bits.hh"
#include "grammar.hh"
#include "enum.hh"
#include "term.hh"
#include "entry.hh"
#include "entries.hh"
#include "synthesizer.hh"
#include "rule.hh"
#include "value.hh"
#include "feature.hh"
#include "features.hh"
#include "list.hh"
#include "statements.hh"
#include "statement.hh"
#include "vartable.hh"
#include "terms.hh"

#if false
#define DBUG(x)x
#else
#define DBUG(x)
#endif
#define DBUGPRT(x) DBUG(cerr << "*** " << x << "<BR>\n")
#define DBUGPRTARG(x,s) DBUG(cerr << "*** " << x << "&nbsp;" << s << "<BR>")

 extern unsigned int ruleslineno;
 extern unsigned int rulescolno;
 extern string fileName;
 
 void ruleserror(char *Chaine, ...){
   try {
     ostringstream oss;
     if (fileName.size())
       oss << "parse error" << fileName << "&nbsp;(" << ruleslineno << "," << rulescolno << ")&nbsp;" << "<BR>" << endl;
     else
       oss << "parse error" << "<BR>" << endl;
     throw oss.str();
   }
   catch (string msg) {
     cout << msg << endl;
   }
 }
 
 extern unsigned int ruleslex();
 
 class Synthesizer synthesizer;
 
 list<string> argsCat;
 list<string> argsPred;
 unsigned int codeString; 

 class Entry *serverEntry;

#define YYERROR_VERBOSE true

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) (char *)msgid
# endif
#endif

%}

%union{
  int int_slot;
  float float_slot;

  class Term *term_slot;
  class Terms *terms_slot; //(A|B)
  vector<class Terms*> *vector_terms_slot; // X Y

  string *string_slot;
  class Entry *entry_slot;
  class Entries *entries_slot;
  bitset<MAXBITS> *bits_slot;
  class Value *value_slot;
  class Feature *feature_slot;
  class Features *features_slot;
  class List *list_slot;
  class Statements *statements_slot;
  class Statement *statement_slot;
  
  list<bitset<MAXBITS> *> *list_args;
 }


// ARROWS
%token TOKEN_RIGHTARROW TOKEN_UPARROW TOKEN_UP2ARROW TOKEN_DOWNARROW TOKEN_DOWN2ARROW 

// DOLLAR
%token TOKEN_DOLLAR

// PAR
%token TOKEN_LPAR TOKEN_RPAR 
%token TOKEN_LBRACE TOKEN_RBRACE TOKEN_LBRACKET TOKEN_RBRACKET TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK

// PONCT
%token TOKEN_SEMI TOKEN_COLON TOKEN_COLON2 TOKEN_DOT TOKEN_COMMA

// KEYWORDS
%token TOKEN_GRAMMAR TOKEN_INPUT TOKEN_LEXICON  
%token TOKEN_PRED TOKEN_FORM TOKEN_IDENTITY
%token TOKEN_TEST TOKEN_TRACE TOKEN_ORDER
%token TOKEN_IF TOKEN_ELSE
%token TOKEN_NIL TOKEN_TRUE
%token TOKEN_SORT TOKEN_WITH
%token TOKEN_FINISHED

// OPERATORS
%token TOKEN_UNION TOKEN_SUBSET TOKEN_AFF TOKEN_PIPE TOKEN_NOT TOKEN_OR TOKEN_AND TOKEN_IMP TOKEN_EQUIV
TOKEN_PLUS TOKEN_MINUS TOKEN_TIMES TOKEN_DIVIDE TOKEN_MODULO
TOKEN_EQUAL TOKEN_DIFF TOKEN_LT TOKEN_LE TOKEN_GT TOKEN_GE

 // LITERALS
%token<string_slot> TOKEN_IDENTIFIER TOKEN_STRING
%token<int_slot> TOKEN_INTEGER
%token<float_slot> TOKEN_FLOAT 

 // VARIABLES
%token<string_slot> TOKEN_VARIABLE

%type<string_slot> stringOrIdentifier
%type<term_slot> term
%type<terms_slot> terms terms_disj
%type<vector_terms_slot> terms_vector
%type<entries_slot> lexical_entries  
%type<entry_slot> lexical_entry

%type<features_slot> features features_components
%type<feature_slot> feature
%type<bits_slot> variable identifier constant
%type<value_slot> feature_value
%type<list_slot> list list_components list_element

%type<statements_slot> static_structure_statement static_list_statement structure_statement list_statement
%type<statement_slot> statement static_statement dynamic_statement left_hand_side_subset_statement right_hand_side_subset_statement left_hand_side_aff_statement right_hand_side_aff_statement up down updouble downdouble dollars simpledollar dollar
%type<statement_slot> expression_statement

%type<list_args> list_args

%left TOKEN_SEMI
%left TOKEN_COLON2
%left TOKEN_COMMA
%left TOKEN_IMP TOKEN_EQUIV
%left TOKEN_AND
%left TOKEN_OR
%right TOKEN_NOT
%left TOKEN_UNION
%nonassoc TOKEN_IFX 
%nonassoc TOKEN_ELSE 
%left TOKEN_LT TOKEN_LE TOKEN_GT TOKEN_GE TOKEN_EQUAL TOKEN_DIFF
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_TIMES TOKEN_DIVIDE
%left TOKEN_MODULO
%left TOKEN_MINUS_U
%left TOKEN_RPAR

%%

axiom:
	declaration
	{
	  DBUGPRT("axiom done...");
	  YYACCEPT;
	}
	;

declaration:
	TOKEN_GRAMMAR TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK rules TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK {
	  DBUGPRT("declaration grammar");
	  synthesizer.getGrammar()->findTerms();
	  //BUG;
	  //synthesizer.getGrammar().print(cerr, NULL);
	  //cerr << endl;
	}

	|TOKEN_INPUT TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK term features TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK {
	  DBUGPRT("declaration input");
	  synthesizer.putStartTerm($3);
	  synthesizer.putStartFeatures($4);
	}

	|TOKEN_INPUT TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK term TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK {
	  DBUGPRT("declaration input");
	  synthesizer.putStartTerm($3);
	  synthesizer.putStartFeatures(new Features());
	 }

	|TOKEN_LEXICON TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK dictionary TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK {      
	  DBUGPRT("declaration lexicon");
	  //BUG;
	  //synthesizer.printLexicon(cerr);
	  // BUG;
	  // cerr << "strToIntTable:<BR>";
	  // extern map<string, unsigned int, less<string> > strToIntTable;
	  // for (map<string, unsigned int, less<string> >::iterator i=strToIntTable.begin(); i!= strToIntTable.end();  i++)
	  //   cerr << (*i).first << ": " << (*i).second << "<BR>" << endl;
	  // BUG;
	  // cerr << "intToStrTable:<BR>";
	  // extern map<unsigned int, string, less<unsigned int> > intToStrTable;
	  // for (map<unsigned int, string, less<unsigned int> >::iterator i=intToStrTable.begin(); i!= intToStrTable.end();  i++)
	  //   cerr << (*i).first << ": " << (*i).second << "<BR>" << endl;
	  // BUG;
	  // cerr << "varTable:<BR>";
	  // extern map<string, bitset<MAXBITS>, less<string> > varTable;
	  // for (map<string, bitset<MAXBITS>, less<string> > ::iterator i=varTable.begin(); i!= varTable.end();  i++)
	  //   cerr << (*i).first << ": " << (*i).second << "<BR>" << endl;
	  // BUG;
	  // cerr << "bitToStrTable:<BR>";
	  // extern map<unsigned long int, string, less<unsigned long int> > bitToStrTable;
	  // for (map<unsigned long int, string, less<unsigned long int> >::iterator i=bitToStrTable.begin(); i!= bitToStrTable.end();  i++)
	  //   cerr << (*i).first << ": " << (*i).second << "<BR>" << endl;

	  //UNEXPECTED;
	}

	|TOKEN_DOT features static_structure_statement
	{
	  DBUGPRT("declaration features");
	  unsigned int pred=$2->getPred();
	  synthesizer.putLocalEntry(new Entry(0, pred, UINT_MAX, $2, $3));
	}
	;

dictionary:
	word dictionary {
	  DBUGPRT("dictionary");
	}

	|word {
	  DBUGPRT("dictionary");
	 };

stringOrIdentifier:
	TOKEN_IDENTIFIER {
	  DBUGPRT("stringOrIdentifier");
	  $$=$1;
	}

	|TOKEN_STRING {
	  DBUGPRT("stringOrIdentifier");
	  $$=$1;
	 };

word:
	// IDENTITY constantNoun ;
	TOKEN_IDENTITY TOKEN_IDENTIFIER TOKEN_SEMI
	{
	  DBUGPRT("word");
	  unsigned int code=strToInt(*$2);
	  // constantNoun => (0 => args)
	  map<unsigned int, map<unsigned int, class Entries * >* >::iterator foundCode=synthesizer.getLexicon().find(code);
	  map<unsigned int, class Entries * > *zeroToEntries;
	  if (foundCode!=synthesizer.getLexicon().end()){
	    zeroToEntries=foundCode->second;
	  } else {
	    zeroToEntries=new map<unsigned int, class Entries * >;
	    synthesizer.getLexicon().insert(pair<unsigned int, map<unsigned int, class Entries * >* > (code, zeroToEntries));
	  }
	  map<unsigned int, class Entries * >::iterator foundPred=zeroToEntries->find(0);
	  class Entries *lp;
	  if (foundPred!=zeroToEntries->end()){
	    lp=foundPred->second;
	  } else {
	    lp=new class Entries;
	    zeroToEntries->insert(pair<unsigned int, class Entries * > (0, lp));
	  }
	  lp->add(new Entry(code, (unsigned int)UINT_MAX, (unsigned int)UINT_MAX, new Features()));
	}

	// // IDENTITY constantNoun [...] on doit unifiaer !!!;
	|TOKEN_IDENTITY TOKEN_IDENTIFIER features static_structure_statement TOKEN_SEMI
	{
	  DBUGPRT("word");
	  unsigned int code=strToInt(*$2);
	  // constantNoun => (0 => args)
	  map<unsigned int, map<unsigned int, class Entries * >* >::iterator foundCode=synthesizer.getLexicon().find(code);
	  map<unsigned int, class Entries * > *zeroToEntries;
	  if (foundCode!=synthesizer.getLexicon().end()){
	    zeroToEntries=foundCode->second;
	  } else {
	    zeroToEntries=new map<unsigned int, class Entries * >;
	    synthesizer.getLexicon().insert(pair<unsigned int, map<unsigned int, class Entries * >* > (code, zeroToEntries));
	  }
	  map<unsigned int, class Entries * >::iterator foundPred=zeroToEntries->find(0);
	  class Entries *lp;
	  if (foundPred!=zeroToEntries->end()){
	    lp=foundPred->second;
	  } else {
	    lp=new class Entries;
	    zeroToEntries->insert(pair<unsigned int, class Entries * > (0, lp));
	  }
	  lp->add(new Entry(code, (unsigned int)UINT_MAX, (unsigned int)UINT_MAX, $3, $4));
	}

	//
	|stringOrIdentifier lexical_entries TOKEN_SEMI
	{
	  DBUGPRT("word");
	  for (list<class Entry*>::iterator entry=$2->begin();
	       entry!=$2->end();
	       entry++){
	    (*entry)->putForm(*$1);
	  }
	  for (list<class Entry*>::iterator entry=$2->begin();
	       entry!=$2->end();
	       entry++){
	    class Entries *lp;
	    map<unsigned int, class Entries * > *predToEntries;
	    map<unsigned int, map<unsigned int, class Entries * >* >::iterator foundCode=synthesizer.getLexicon().find((*entry)->getCode());
	    if (foundCode!=synthesizer.getLexicon().end()){
	      predToEntries=foundCode->second;
	    } else {
	      predToEntries=new map<unsigned int, class Entries * >;
	      synthesizer.getLexicon().insert(pair<unsigned int, map<unsigned int, class Entries * >* > ((*entry)->getCode(), predToEntries));
	    }
	    map<unsigned int, class Entries * >::iterator foundPred=predToEntries->find((*entry)->getCodePred());
	    if (foundPred!=predToEntries->end()){
	      lp=foundPred->second;
	    } else {
	      lp=new class Entries;
	      predToEntries->insert(pair<unsigned int, class Entries * > ((*entry)->getCodePred(), lp));
	    }
	    lp->add(*entry);
	  }
	}

	//
	|stringOrIdentifier TOKEN_LPAR list_args TOKEN_RPAR lexical_entries TOKEN_SEMI
	{
	  DBUGPRT("word");
	  for (list<class Entry*>::iterator entry=$5->begin();
	       entry!=$5->end();
	       entry++){
	    (*entry)->putForm(*$1);
	    (*entry)->putArgs($3);
	  }
	  for (list<class Entry*>::iterator entry=$5->begin();
	       entry!=$5->end();
	       entry++){
	    class Entries *lp;
	    map<unsigned int, class Entries * > *predToEntries;
	    map<unsigned int, map<unsigned int, class Entries * >* >::iterator foundCode=synthesizer.getLexicon().find((*entry)->getCode());
	    if (foundCode!=synthesizer.getLexicon().end()){
	      predToEntries=foundCode->second;
	    } else {
	      predToEntries=new map<unsigned int, class Entries * >;
	      synthesizer.getLexicon().insert(pair<unsigned int, map<unsigned int, class Entries * >* > ((*entry)->getCode(), predToEntries));
	    }
	    map<unsigned int, class Entries * >::iterator foundPred=predToEntries->find((*entry)->getCodePred());
	    if (foundPred!=predToEntries->end()){
	      lp=foundPred->second;
	    } else {
	      lp=new class Entries;
	      predToEntries->insert(pair<unsigned int, class Entries * > ((*entry)->getCodePred(), lp));
	    }
	    lp->add(*entry);
	  }
	}

	|TOKEN_SEMI
	{
	  DBUGPRT("word");
	};

list_args:
	list_args TOKEN_COMMA identifier
	{
	  DBUGPRT("list_args");
	  $$=$1;
	  $$->push_back($3);
	}

	|identifier
	{
	  DBUGPRT("list_args");
	  $$=new list<bitset<MAXBITS> *>;
	  $$->push_back($1);
	}
	;

lexical_entries:
	lexical_entry TOKEN_PIPE lexical_entries {	  
	  DBUGPRT("lexical_entries");
	  $$=$3; 
	  $$->add($1);}
	
	|lexical_entry {
	  DBUGPRT("lexical_entries");
	  $$=new Entries($1);
	 };

lexical_entry:
	// pos
	TOKEN_IDENTIFIER features static_structure_statement
	{
	  DBUGPRT("lexical_entry");
	  unsigned int pred=$2->getPred();
	  $$=new Entry(strToInt(*$1), pred, UINT_MAX, $2, $3);
	}

	|TOKEN_IDENTIFIER 
	{
	  DBUGPRT("lexical_entry");
	  $$=new Entry(strToInt(*$1), UINT_MAX, UINT_MAX, new Features(), NULL);
	}
	;

///////////////////////////////////////////////
// SEMANTIC FOR LEXICON
///////////////////////////////////////////////
static_structure_statement:
	TOKEN_LBRACE static_list_statement TOKEN_RBRACE
	{
	  DBUGPRT("compound_statement");
	  $$=$2;
	}

	|TOKEN_LBRACE TOKEN_RBRACE
	{
	  $$=NULL;
	}

	|/* empty */
	{
	  $$=NULL;
        };

///////////////////////////
// RULES
//////////////////////////
rules:
	rule rules
	{
	  DBUGPRT("rules"); 
	}
	
	|rule
	{
	  DBUGPRT("rules"); 
	};

rule:
	term TOKEN_RIGHTARROW terms_vector structure_statement TOKEN_SEMI
	{
	  DBUGPRT("rule");
	  class Rule *rule=new Rule($1, *$3, $4);
	  rule->addDefaults();
	  synthesizer.getGrammar()->addRule(rule);
	  if (synthesizer.getGrammar()->getStartTerm()==NULL){
	    synthesizer.getGrammar()->putStartTerm($1);
	  }
	}

	|term TOKEN_RIGHTARROW structure_statement TOKEN_SEMI
	{
	  DBUGPRT("Rule");
	  class Rule *rule=new Rule($1, $3);
	  rule->addDefaults();
	  synthesizer.getGrammar()->addRule(rule);
	  if (synthesizer.getGrammar()->getStartTerm()==NULL){
	    synthesizer.getGrammar()->putStartTerm($1);
	  }
	}

	|TOKEN_SEMI
	;

terms_vector:
	terms_vector terms
	{ 
	  DBUGPRT("term_vector");
	  $$=$1;
	  $$->push_back($2);
	}

	|terms 
	{ 
	  DBUGPRT("term_vector"); 
	  $$=new vector<class Terms*>;
	  $$->push_back($1);
	};
	
terms:
	terms_disj
	{ 
	  DBUGPRT("term");
	  $$=$1;
	}

	|TOKEN_LPAR terms_disj TOKEN_RPAR
	{ 
	  DBUGPRT("term");
	  $$=$2;
	  $$->putOptional(true);
	};

terms_disj:
	terms_disj TOKEN_PIPE term
	{ 
	  DBUGPRT("term_disj");
	  $$=$1;
	  $$->push_back($3);
	}

	|term
	{ 
	  DBUGPRT("term_disj"); 
	  $$=new class Terms($1);
	};
	
term:
	TOKEN_IDENTIFIER
	{ 
	  DBUGPRT("term_id");
	  unsigned int code=strToInt(*$1);
	  $$ = new Term(code);
	}

	|TOKEN_VARIABLE
	{ 
	  DBUGPRT("term_id");
	  unsigned int code=strToInt(*$1);
	  $$ = new Term(code);
	};

///////////////////////////////////////////////
// SEMANTIC FOR RULES
///////////////////////////////////////////////
structure_statement:
	TOKEN_LBRACE list_statement TOKEN_RBRACE
	{
	  DBUGPRT("structure_statement");
	  $$=$2;
	}

	|TOKEN_LBRACE TOKEN_RBRACE
	{
	  $$=NULL;
	}

	|/* empty */
	{
	  $$=NULL;
        };

list_statement:
	statement
	{
	  DBUGPRT("list_statement");
	  $$=new Statements();
	  $$->addStatement($1);
	}

	|list_statement statement {
	  DBUGPRT("list_statement");
	  $$=$1;
	  $$->addStatement($2);
	};

static_list_statement:
	static_statement 
	{
	  DBUGPRT("static_list_statement");
	  $$=new Statements();
	  $$->addStatement($1);
	}

	|static_list_statement static_statement {
	  DBUGPRT("static_list_statement");
	  $$=$1;
	  $$->addStatement($2);
	};

statement:
	static_statement{
	  DBUGPRT("statement");
	  $$=$1;
	 }

	|dynamic_statement{
	  DBUGPRT("statement");
	  $$=$1;
	 }

	|TOKEN_LBRACE list_statement TOKEN_RBRACE
	{
	  DBUGPRT("statement");
	  $$=new Statement($2);
	}
	
	|TOKEN_LBRACE TOKEN_RBRACE
	{
	  DBUGPRT("statement");
	  $$=new Statement(new Statements());
	};
	
static_statement:
	TOKEN_TEST expression_statement TOKEN_SEMI {
	  DBUGPRT("static_statement");
	  $$=new Statement(Statement::TEST, $2);
	}

	|TOKEN_TRACE expression_statement TOKEN_SEMI {
	  DBUGPRT("static_statement");
	  $$=new Statement(Statement::TRACE, $2);
	}

	|TOKEN_TRACE TOKEN_STRING TOKEN_SEMI {
	  DBUGPRT("static_statement");
	  $$=new Statement(Statement::TRACE, new Statement(Statement::STR, $2));
	};

dynamic_statement:
	features TOKEN_SEMI {
	  DBUGPRT("dynamic_statement");
	  $$=new Statement(Statement::FILTER, $1);

	}

	|left_hand_side_aff_statement TOKEN_AFF right_hand_side_aff_statement TOKEN_SEMI {
	  DBUGPRT("dynamic_statement");
	  $$=new Statement(Statement::AFF, $1, $3);
	  // <…> := <…>
	  // <…> := sort …
	  // <…> := X
	  if (($1->getOp()==Statement::LIST) && (($3->getOp()==Statement::LIST)||($3->getOp()==Statement::SORT)||($3->getOp()==Statement::VARIABLE)))
	    ;	  
	  // ↓i := X
	  // ↓i := […]
	  // ↓i := ↑
	  // ↓i := … ∪ …
	  // ↓i := ⇓j
	  else if (($1->getOp()==Statement::DOWN) && (($3->getOp()==Statement::VARIABLE)||($3->getOp()==Statement::FEATURES)||($3->getOp()==Statement::UP)||($3->getOp()==Statement::UNIF)||($3->getOp()==Statement::DOWN2)))
	    ;
	  // ⇑ := X
	  // ⇑ := […]
	  // ⇑ := ↑
	  // ⇑ := … ∪ …
	  // ⇑ := ⇓j
	  else if (($1->getOp()==Statement::UP2) && (($3->getOp()==Statement::VARIABLE)||($3->getOp()==Statement::FEATURES)||($3->getOp()==Statement::UP)||($3->getOp()==Statement::UNIF)||($3->getOp()==Statement::DOWN2)))
	    ;
	  // X := Y
	  // X := a
	  // X := <…>
	  // X := sort …
	  // X := […]
	  // X := ↑
	  // X := … ∪ …
	  // X := ⇓j
	  // X := <expr>
	  else if (($1->getOp()==Statement::VARIABLE) 
		   &&(($3->getOp()==Statement::VARIABLE)
		      ||($3->getOp()==Statement::CONSTANT)
		      ||($3->getOp()==Statement::LIST)
		      ||($3->getOp()==Statement::SORT)
		      ||($3->getOp()==Statement::FEATURES)
		      ||($3->getOp()==Statement::UP)
		      ||($3->getOp()==Statement::UNIF)
		      ||($3->getOp()==Statement::DOWN2)
		      ||($3->getOp()==Statement::NUMBER)
		      ||($3->getOp()==Statement::FCT)))
	    ;
	  else {
	    //CERR_LINE;
	    yyerror((char *)"••• syntax error");
	  }
	}

	|left_hand_side_subset_statement TOKEN_SUBSET right_hand_side_subset_statement TOKEN_SEMI {
	  DBUGPRT("dynamic_statement");
	  $$=new Statement(Statement::SUBSET, $1, $3);
	  // […] ⊂ ↑ 
	  // […] ⊂ ⇓j 
	  // […] ⊂ X 
	  if (($1->getOp()==Statement::FEATURES) && (($3->getOp()==Statement::UP)||($3->getOp()==Statement::DOWN2)||($3->getOp()==Statement::VARIABLE)))
	    ;
	  else 
	    yyerror((char *)"syntax error");
	}

	|TOKEN_ORDER dollars TOKEN_SEMI {
	  DBUGPRT("dynamic_statement");
	  $$=new Statement(Statement::ORDER, $2);
	}

	|TOKEN_IF TOKEN_LPAR expression_statement TOKEN_RPAR statement %prec TOKEN_IFX {
	  DBUGPRT("dynamic_statement");
	  $$=new Statement(Statement::IF, $3, new Statement(Statement::THEN, $5, NULL));
	}

	|TOKEN_IF TOKEN_LPAR expression_statement TOKEN_RPAR statement TOKEN_ELSE statement {
	  DBUGPRT("dynamic_statement");
	  $$=new Statement(Statement::IF, $3, new Statement(Statement::THEN, $5, $7));
	};

left_hand_side_subset_statement:
	features {
	  DBUGPRT("left_hand_side_statement");
	  $$=new Statement(Statement::FEATURES, $1);
	};
	
right_hand_side_subset_statement:
	variable {
	  DBUGPRT("right_hand_side_subset_statement");
	  $$=new Statement(Statement::VARIABLE, $1);
	}

	|up {
	  DBUGPRT("right_hand_side_subset_statement");
	  $$=$1;
	}

	|downdouble {
	  DBUGPRT("right_hand_side_subset_statement");
	  $$=$1;
	}

	|features {
	  DBUGPRT("right_hand_side_subset_statement");
	  $$=new Statement(Statement::FEATURES, $1);
	};
	
left_hand_side_aff_statement:
	updouble {
	  DBUGPRT("left_hand_side_statement");
	  $$=$1;
	}

	|down {
	  DBUGPRT("left_hand_side_statement");
	  $$=$1;
	}

	|variable {
	  DBUGPRT("left_hand_side_statement");
	  $$=new Statement(Statement::VARIABLE, $1);
	 };

right_hand_side_aff_statement:
	expression_statement {
	  DBUGPRT("right_hand_side_statement");
	  $$=$1;
	};	

expression_statement:
// logic
	expression_statement TOKEN_OR expression_statement {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::OR, $1, $3);
	}

	|expression_statement TOKEN_AND expression_statement {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::AND, $1, $3);
	}

	|expression_statement TOKEN_IMP expression_statement {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::OR, new Statement(Statement::FCT, Statement::NOT, $1), $3);
	}

	|expression_statement TOKEN_EQUIV expression_statement {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::AND, new Statement(Statement::FCT, Statement::OR, new Statement(Statement::FCT, Statement::NOT, $1), $3), new Statement(Statement::FCT, Statement::OR, $1, new Statement(Statement::FCT, Statement::NOT, $3)));
	}

	|TOKEN_NOT expression_statement {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::NOT, $2);
	}

	|expression_statement TOKEN_EQUAL expression_statement {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::EQUAL, $1, $3);
	}
	
	|expression_statement TOKEN_DIFF expression_statement { 
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::NOT, new Statement(Statement::FCT, Statement::EQUAL, $1, $3)); 
	}
	
	|expression_statement TOKEN_LT expression_statement { 
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::LT, $1, $3); 
	}

	|expression_statement TOKEN_LE expression_statement { 
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::LE, $1, $3); 
	}

	|expression_statement TOKEN_GT expression_statement { 
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::GT, $1, $3); 
	}

	|expression_statement TOKEN_GE expression_statement { 
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::GE, $1, $3); 
	}
	
	|dollar {
	  DBUGPRT("expression_statement");
	  $$=$1;
	 }

	|TOKEN_FINISHED {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FINISHED);
	 }

// arithmetic
	|expression_statement TOKEN_PLUS expression_statement
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::PLUS, $1, $3);
	}

	|expression_statement TOKEN_MINUS expression_statement
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::MINUS, $1, $3);
	}

	|expression_statement TOKEN_TIMES expression_statement
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::TIMES, $1, $3);
	}

	|expression_statement TOKEN_DIVIDE expression_statement
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::DIVIDE, $1, $3);
	}

	|expression_statement TOKEN_MODULO expression_statement
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::MODULO, $1, $3);
	}

	|TOKEN_MINUS expression_statement %prec TOKEN_MINUS_U
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FCT, Statement::MINUS_U, $2, NULL);
	}

	|TOKEN_FLOAT
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement((float)$1);
	}

	|TOKEN_INTEGER
	{
	  DBUGPRT("expression_statement");
 	  $$=new Statement((float)$1);
	}

	|TOKEN_IDENTIFIER TOKEN_LPAR expression_statement TOKEN_RPAR {
	  DBUGPRT("expression_statement");
	  if (*$1=="abs")
	    $$=new Statement(Statement::FCT, Statement::ABS, $3);
	  else {
	    yyerror((char *)"syntax error");
	  }
	}
	
// features
	|expression_statement TOKEN_UNION expression_statement {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::UNIF, $1, $3);
	}
 	
	|up {
	  DBUGPRT("expression_statement");
	  $$=$1;
	}

	|downdouble {
	  DBUGPRT("expression_statement");
	  $$=$1;
	}

	|features {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::FEATURES, $1);
	}

	|TOKEN_NIL
	{
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::NIL);
	}

	|constant {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::CONSTANT, $1);
	}

	|variable {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::VARIABLE, $1);
	}

	|TOKEN_LPAR expression_statement TOKEN_RPAR {
	  DBUGPRT("expression_statement");
	  $$=$2;
	}
	
	|TOKEN_SORT variable TOKEN_WITH identifier {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::SORT, new Statement(Statement::VARIABLE, $2), new Statement(Statement::CONSTANT, $4));
	}
	
	|TOKEN_SORT list TOKEN_WITH identifier {
	  DBUGPRT("expression_statement");
	  $$=new Statement(Statement::SORT, new Statement($2), new Statement(Statement::CONSTANT, $4));
	}

	|list {
	  DBUGPRT("expression_statement");
	  $$=new Statement($1);
	};

up:
	TOKEN_UPARROW {  
	  DBUGPRT("up");
	  $$=new Statement(Statement::UP);
	};

updouble:
	TOKEN_UP2ARROW {  
	  DBUGPRT("updouble");
	  $$=new Statement(Statement::UP2);
	};

dollars:
	simpledollar dollars {  
	  DBUGPRT("dollars");
	  $$ = new Statement(Statement::DOLLARS, $1, $2); 
	}

	|simpledollar { 
	  DBUGPRT("dollars");
	  $$ = new Statement(Statement::DOLLARS, $1, NULL);
	};

down:
	TOKEN_DOWNARROW {  
	  DBUGPRT("downSimple");
	  $$ = new Statement(Statement::DOWN, (unsigned int)0); 
	}

	|TOKEN_DOWNARROW TOKEN_INTEGER
	{ 
	  DBUGPRT("downSimple");
	  $$ = new Statement(Statement::DOWN, $2-1); 
	};

dollar:
	TOKEN_DOLLAR TOKEN_INTEGER TOKEN_COLON TOKEN_INTEGER
	{ 
	  DBUGPRT("dollar");
	  $$ = new Statement(Statement::DOLLAR, $2-1, $4-1); 
	}

	|simpledollar
	{ 
	  DBUGPRT("dollar");
	  $$ = $1; 
	};

simpledollar:
	TOKEN_DOLLAR TOKEN_INTEGER
	{ 
	  DBUGPRT("downComplex");
	  $$ = new Statement(Statement::DOLLAR, $2-1); 
	};

downdouble:
	TOKEN_DOWN2ARROW {  
	  DBUGPRT("downdouble");
	  $$ = new Statement(Statement::DOWN2, (unsigned int)0); 
	}

	|TOKEN_DOWN2ARROW TOKEN_INTEGER
	{ 
	  DBUGPRT("downdouble");
	  $$ = new Statement(Statement::DOWN2, (unsigned int)($2-1)); 
	};

//////////////////////////
// Features
//////////////////////////
features:
	TOKEN_LBRACKET features_components TOKEN_RBRACKET
	{
	  DBUGPRT("features");
 	  $$=$2;
	}

	|TOKEN_LBRACKET TOKEN_RBRACKET
	{
	  DBUGPRT("features");
	  $$=new Features();
	};

features_components:
	features_components TOKEN_COMMA feature
	{
	  DBUGPRT("features_components");
	  $$=$1; 
	  $$->addFeature($3);
	}

	|feature 
	{
	  DBUGPRT("features_components");
	  $$=new Features();
	  $$->addFeature($1);
	};

feature:
	// PRED: predicate
	TOKEN_PRED TOKEN_COLON TOKEN_IDENTIFIER
	{
	  DBUGPRT("feature");
	  $$ = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  $$->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value($3, Value::IDENTIFIER), Feature::CONSTANT));
	}

	// PRED: predicate(variable)
	|TOKEN_PRED TOKEN_COLON TOKEN_IDENTIFIER TOKEN_LPAR variable TOKEN_RPAR
	{
	  DBUGPRT("feature");
	  $$ = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  $$->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value($3, Value::IDENTIFIER), Feature::CONSTANT));
	  $$->getRhs()->getFeatures()->addFeature(new Feature(ARGBITS, new Value($5, Value::VARIABLE), Feature::CONSTANT));
	  //BUG;
	  //$$->print(cerr);
	}

	// PRED: predicate(constant)
	|TOKEN_PRED TOKEN_COLON TOKEN_IDENTIFIER TOKEN_LPAR TOKEN_IDENTIFIER TOKEN_RPAR
	{
	  DBUGPRT("feature");
	  $$ = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  $$->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value($3, Value::IDENTIFIER), Feature::CONSTANT));
	  $$->getRhs()->getFeatures()->addFeature(new Feature(ARGBITS, new Value($5, Value::IDENTIFIER), Feature::CONSTANT));
	  //BUG;
	  //$$->print(cerr);
	}

	// PRED: X
	|TOKEN_PRED TOKEN_COLON variable
	{
	  DBUGPRT("feature");
	  $$ = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  $$->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value($3, Value::VARIABLE), Feature::CONSTANT));
	  //$$ = new Feature(SYSBITS, new Value($3, Value::VARIABLE), Feature::PRED);
	  //BUG;
	  //$$->print(cerr);
	}

	|TOKEN_FORM TOKEN_COLON TOKEN_STRING
	{
	  DBUGPRT("feature");
	  $$ = new Feature(SYSBITS, new Value($3, Value::FORM), Feature::FORM);
	}

	|identifier TOKEN_COLON feature_value
	{
	  DBUGPRT("feature");
	  $$=new Feature(*$1, $3, Feature::CONSTANT);
	  //$$->print(cerr);
	}

	|variable TOKEN_COLON feature_value
	{
	  DBUGPRT("feature");
	  $$=new Feature(*$1, $3, Feature::VARIABLE);
	}

	|variable
	{
	  DBUGPRT("feature");
	  $$ = new Feature(*$1, NULL, Feature::VARIABLE);
	};

feature_value:
	variable
	{
	  DBUGPRT("feature_value");
	  $$=new Value($1, Value::VARIABLE);
	}

	|constant
	{
	  DBUGPRT("feature_value");
	  $$=new Value($1, Value::CONSTANT);
	}

	|TOKEN_FLOAT
	{
	  DBUGPRT("expression_statement");
	  $$=new Value((float)$1);
	}

	|TOKEN_INTEGER
	{
	  DBUGPRT("expression_statement");
 	  $$=new Value((float)$1);
	}

	|list
	{
	  DBUGPRT("feature_value");
	  $$=new Value($1);
	}

	|features
	{
	  DBUGPRT("feature_value");
	  $$=new Value($1);
	}

	|TOKEN_NIL
	{
	  DBUGPRT("feature_value");
	  $$=Value::_nil;
	}

	|TOKEN_TRUE
	{
	  DBUGPRT("feature_value");
	  $$=Value::_true;
	}
	;

constant:
	identifier
	{
	  DBUGPRT("constants");
	  $$=$1;
	}

	|constant TOKEN_PIPE identifier
	{
	  DBUGPRT("constants");
	  $$=$3;
	  *$$ |= *$1;
	};

identifier:
	TOKEN_IDENTIFIER
	{
	  DBUGPRT("identifier");
 	  $$=varTableAdd(*$1);
	};

variable:
	TOKEN_VARIABLE
	{
	  DBUGPRT("variable");
 	  ostringstream oss;
	  oss << *$1;
  	  string str = oss.str();
	  $$=varTableAdd(str);
	};
	
list:
	TOKEN_LT list_components TOKEN_GT
	{
	  DBUGPRT("list");
	  $$=$2;
	  /***
	      BUG;
	      $$->print(cerr, FALSE_HTML);
	      cerr << "<br>" << endl;
	      ofstream dotForestFile;
	      char s[128];
	      sprintf(s, "list-%d.dot", $$->getId());
	      dotForestFile.open (s);
	      dotForestFile << "graph G {" << endl;
	      $$->dot(dotForestFile, 0);
	      dotForestFile << "}";
	      dotForestFile.close();
	  ***/
	}

	|TOKEN_LT TOKEN_GT
	{
	  DBUGPRT("list");
	  $$=List::nil;
	}

	|TOKEN_LT list_element TOKEN_COLON2 list_element TOKEN_GT
	{
	  DBUGPRT("list");
	  $$=new List($2, $4);
	  /***
	      BUG;
	      $$->print(cerr, FALSE_HTML);
	      cerr << "<br>" << endl;
	      ofstream dotForestFile;
	      char s[128];
	      sprintf(s, "list-%d.dot", $$->getId());
	      dotForestFile.open (s);
	      dotForestFile << "graph G {" << endl;
	      $$->dot(dotForestFile, 0);
	      dotForestFile << "}";
	      dotForestFile.close();
	  ***/
	}
	;

list_components:
	list_element TOKEN_COMMA list_components
	{
	  DBUGPRT("list_components");
	  $$=new List($1, $3);
	}

	|list_element
	{
	  DBUGPRT("list_components");
	  $$=new List($1, List::nil);
	}
	;

list_element:
	variable
	{
	  DBUGPRT("list_element");
	  $$=new List(new Value($1, Value::VARIABLE));
	}

	|constant
	{
	  DBUGPRT("list_element");
	  $$=new List(new Value($1, Value::CONSTANT));
	}

	|features
	{
	  DBUGPRT("list_element");
	  $$=new List(new Value($1));
	}

	|list
	{
	  DBUGPRT("list_element");
	  $$=$1;
	}
	;

%%
