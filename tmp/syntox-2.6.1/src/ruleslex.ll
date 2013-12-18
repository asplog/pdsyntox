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

// ↑
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <list>
using namespace std;

#include "enum.hh"
#include "bits.hh"
#include "term.hh"
#include "rulesyacc.hh"

#if false
#define DBUG(x)x
#else
#define DBUG(x)
#endif
#define DBUGPRT(x) DBUG(cerr << "*** " << x << "<BR>\n");
#define DBUGPRTARG(x,s) DBUG(cerr << "*** " << x << "&nbsp;" << s << "<BR>\n");

int rulescolno;
std::string *str;
int comments;
 
char *lexString;
bool stringInput;
string fileName="";

#define YY_INPUT(buf,result,max_size){	\
   if (stringInput){					\
     char c = *lexString++;				\
     result = !c ? YY_NULL : (buf[0] = c, 1);		\
   } else {							\
     if ( YY_CURRENT_BUFFER_LVALUE->yy_is_interactive )		\
       {								\
	 int c = '*';							\
	 yy_size_t n;							\
	 for ( n = 0; n < max_size &&					\
		 (c = getc( yyin )) != EOF && c != '\n'; ++n )		\
	   buf[n] = (char) c;						\
	 if ( c == '\n' )						\
	   buf[n++] = (char) c;						\
	 if ( c == EOF && ferror( yyin ) )				\
	   YY_FATAL_ERROR( "input in flex scanner failed" );		\
	 result = n;							\
       }								\
     else								\
       {								\
	 errno=0;							\
	 while ( (result = fread(buf, 1, max_size, yyin))==0 && ferror(yyin)) \
	   {								\
	     if( errno != EINTR)					\
	       {							\
		 YY_FATAL_ERROR( "input in flex scanner failed" );	\
		 break;							\
	       }							\
	     errno=0;							\
	     clearerr(yyin);						\
	   }								\
       }								\
   }									\
 }  
 
%}

alphaMin ([a-z]|(à)|(á)|(â)|(ã)|(ä)|(å)|(æ)|(ç)|(è)|(é)|(ê)|(ë)|(ì)|(í)|(î)|(ï)|(ð)|(ñ)|(ò)|(ó)|(ô)|(õ)|(ö)|(÷)|(ø)|(ù)|(ú)|(û)|(ü)|(ý)|(ÿ)|(þ)|(_))
alphaCap ([A-Z]|(À)|(Á)|(Â)|(Ã)|(Ä)|(Å)|(Æ)|(Ç)|(È)|(É)|(Ë)|(Ì)|(Í)|(Î)|(Ï)|(Ð)|(Ñ)|(Ò)|(Ó)|(Ô)|(Õ)|(Ö)|(×)|(Ø)|(Ù)|(Ú)|(Û)|(Ü)|(Ý)|(Ÿ)|(Þ)|(ß))
alpha ({alphaMin}|{alphaCap})
alphaNum ([[:digit:]]|{alpha})
identifier (({alphaMin}){alphaNum}*)
variable (({alphaCap}){alphaNum}*)
integer (([1-9][[:digit:]]*)|0)
floatNumber ([[:digit:]]+(\.[[:digit:]]+)?([Ee][+-]?[[:digit:]]+)?)
string (\"([^\n\"]|\\\")*\")
blanks ([[:blank:]\15])+
rightArrow (→)
upArrow (↑)
downArrow (↓)
upDoubleArrow (⇑)
downDoubleArrow (⇓)

%option nounput noyywrap
%x COMMENT LINE FILENAME
 
%%

^.+$ {
  DBUGPRTARG("••••••••••••••• ", yytext);
  REJECT;
}

"//".*\n {
  /* Passe les commentaires de type C++*/
  rulescolno = 1;
  ruleslineno++;
}

"/*" {comments=0; BEGIN COMMENT;}
<COMMENT>"/*" {comments++;}
<COMMENT>\n {ruleslineno++; rulescolno=1;}
<COMMENT>"*"*"*/" {if (!(comments--)) BEGIN INITIAL;} 
<COMMENT>. ;
 
^\#line {BEGIN LINE;}
<LINE>[0-9]+ {ruleslineno=atoi(yytext);}
<LINE>\n {  
  DBUGPRT("TOKEN_#LINE\n");
  BEGIN INITIAL;};
<LINE>. ;

^\#file {BEGIN FILENAME;}

<FILENAME>.+ {
  fileName=yytext;
 }

<FILENAME>\n {
  DBUGPRT("TOKEN_#FILE\n");
  BEGIN INITIAL;
 };

<FILENAME>. ;

{rightArrow} {
  DBUGPRT("TOKEN_RIGHTARROW\n");
  rulescolno+=strlen(yytext);
  return TOKEN_RIGHTARROW;
}

{upArrow} {
  DBUGPRT("TOKEN_UPARROW\n");
  rulescolno+=strlen(yytext);
  return TOKEN_UPARROW;
}

{upDoubleArrow} {
  DBUGPRT("TOKEN_UP2ARROW\n");
  rulescolno+=strlen(yytext);
  return TOKEN_UP2ARROW;
}

{downArrow} {
  DBUGPRT("TOKEN_DOWNARROW\n");
  ruleslval.int_slot = 1;
  rulescolno+=strlen(yytext);
  return TOKEN_DOWNARROW;
}

{downDoubleArrow} {
  DBUGPRT("TOKEN_DOWN2ARROW\n");
  rulescolno+=strlen(yytext);
  return TOKEN_DOWN2ARROW;
}

"<" {
  DBUGPRT("TOKEN_LT\n");
  rulescolno += yyleng;
  return TOKEN_LT;
}

">" {
  DBUGPRT("TOKEN_GT\n");
  rulescolno += yyleng;
  return TOKEN_GT;
}

"≤" {
  DBUGPRT("TOKEN_LE\n");
  rulescolno += yyleng;
  return TOKEN_LT;
}

"≥" {
  DBUGPRT("TOKEN_GE\n");
  rulescolno += yyleng;
  return TOKEN_GE;
}

"(" {
  DBUGPRT("TOKEN_LPAR\n");
  rulescolno += yyleng;
  return TOKEN_LPAR;
}

")" {
  DBUGPRT("TOKEN_RPAR\n");
  rulescolno += yyleng;
  return TOKEN_RPAR;
}

"[" {
  DBUGPRT("TOKEN_LBRACKET\n");
  rulescolno += yyleng;
  return TOKEN_LBRACKET;
}

"]" {
  DBUGPRT("TOKEN_RBRACKET\n");
  rulescolno += yyleng;
  return TOKEN_RBRACKET;
}

"{" {
  DBUGPRT("TOKEN_LBRACE\n");
  rulescolno += yyleng;
  return TOKEN_LBRACE;
}

"}" {
  DBUGPRT("TOKEN_RBRACE\n");
  rulescolno += yyleng;
  return TOKEN_RBRACE;
}

"«" {
  DBUGPRT("TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK");
  rulescolno += yyleng;
  return TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK;
}

"»" {
  DBUGPRT("TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK");
  rulescolno += yyleng;
  return TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK;
}

";" {
  DBUGPRT("TOKEN_SEMI\n");
  rulescolno += yyleng;
  return TOKEN_SEMI;
}

"::" {
  DBUGPRT("TOKEN_COLON2\n");
  rulescolno += yyleng;
  return TOKEN_COLON2;
}

":" {
  DBUGPRT("TOKEN_COLON\n");
  rulescolno += yyleng;
  return TOKEN_COLON;
}

"$" {
  DBUGPRT("TOKEN_DOLLAR");
  rulescolno += yyleng;
  return TOKEN_DOLLAR;
}

"∪" {
  DBUGPRT("TOKEN_UNION\n");
  rulescolno += yyleng;
  return TOKEN_UNION;
}

"⊂" {
  DBUGPRT("TOKEN_SUBSET\n");
  rulescolno += yyleng;
  return TOKEN_SUBSET;
}



"=" {
  DBUGPRT("TOKEN_EQUAL\n");
  rulescolno += yyleng;
  return TOKEN_EQUAL;
}

":=" {
  DBUGPRT("TOKEN_AFF\n");
  rulescolno += yyleng;
  return TOKEN_AFF;
}

"≠" {
  DBUGPRT("TOKEN_DIFF\n");
  rulescolno += yyleng;
  return TOKEN_DIFF;
}

"+" {
  DBUGPRT("TOKEN_PLUS\n");
  rulescolno += yyleng;
  return TOKEN_PLUS;
}

"-" {
  DBUGPRT("TOKEN_MINUS\n");
  rulescolno += yyleng;
  return TOKEN_MINUS;
}

"*" {
  DBUGPRT("TOKEN_TIMES\n");
  rulescolno += yyleng;
  return TOKEN_TIMES;
}

"/" {
  DBUGPRT("TOKEN_DIVIDE\n");
  rulescolno += yyleng;
  return TOKEN_DIVIDE;
}

@input {
  DBUGPRT("TOKEN_INPUT\n");
  rulescolno+=strlen(yytext);
  return TOKEN_INPUT;
}

@grammar {
  DBUGPRT("TOKEN_RULES\n");
  rulescolno+=strlen(yytext);
  return TOKEN_GRAMMAR;
}

@lexicon {
  DBUGPRT("TOKEN_INPUTLEXICON\n");
  rulescolno+=strlen(yytext);
  return TOKEN_LEXICON;
}

order {
  DBUGPRT("TOKEN_ORDER\n");
  rulescolno+=strlen(yytext);
  return TOKEN_ORDER;
}

if {
  DBUGPRT("TOKEN_IF\n");
  rulescolno+=strlen(yytext);
  return TOKEN_IF;
}

else {
  DBUGPRT("TOKEN_ELSE\n");
  rulescolno+=strlen(yytext);
  return TOKEN_ELSE;
}

test {
  DBUGPRT("TOKEN_TEST\n");
  rulescolno+=yyleng;
  return TOKEN_TEST;
}

trace {
  DBUGPRT("TOKEN_TRACE\n");
  rulescolno+=yyleng;
  return TOKEN_TRACE;
}

sort {
  DBUGPRT("TOKEN_SORT\n");
  rulescolno+=yyleng;
  return TOKEN_SORT;
}

with {
  DBUGPRT("TOKEN_WITH\n");
  rulescolno+=yyleng;
  return TOKEN_WITH;
}

finished {
  DBUGPRT("TOKEN_FINISHED\n");
  rulescolno+=yyleng;
  return TOKEN_FINISHED;
}

"|" {
  DBUGPRT("TOKEN_PIPE\n");
  rulescolno += yyleng;
  return TOKEN_PIPE;
}

"∨" {
  DBUGPRT("TOKEN_OR\n");
  rulescolno += yyleng;
  return TOKEN_OR;
}

"∧" {
  DBUGPRT("TOKEN_AND\n");
  rulescolno += yyleng;
  return TOKEN_AND;
}

"⇒" {
  DBUGPRT("TOKEN_IMP\n");
  rulescolno += yyleng;
  return TOKEN_IMP;
}

"⇔" {
  DBUGPRT("TOKEN_EQUIV\n");
  rulescolno += yyleng;
  return TOKEN_EQUIV;
}

"¬" {
  DBUGPRT("TOKEN_NOT\n");
  rulescolno += yyleng;
  return TOKEN_NOT;
}

"," {
  DBUGPRT("TOKEN_COMMA\n");
  rulescolno += yyleng;
  return TOKEN_COMMA;
}

"." {
  DBUGPRT("TOKEN_DOT\n");
  rulescolno += yyleng;
  return TOKEN_DOT;
}

"+" {
  DBUGPRT("TOKEN_PLUS\n");
  rulescolno += yyleng;
  return TOKEN_PLUS;
}

"-" {
  DBUGPRT("TOKEN_MINUS\n");
  rulescolno += yyleng;
  return TOKEN_MINUS;
}

"%" {
  DBUGPRT("TOKEN_MODULO\n");
  rulescolno += yyleng;
  return TOKEN_MODULO;
}

"PRED" {
  DBUGPRT("TOKEN_PRED\n");
  rulescolno+=yyleng;
  return TOKEN_PRED;
}

"FORM" {
  DBUGPRT("TOKEN_FORM\n");
  rulescolno+=yyleng;
  return TOKEN_FORM;
}

"TRUE" {
  DBUGPRT("TOKEN_TRUE\n");
  rulescolno+=strlen(yytext);
  return TOKEN_TRUE;
}

"NIL" {
  DBUGPRT("TOKEN_NILL\n");
  rulescolno+=strlen(yytext);
  return TOKEN_NIL;
}

"IDENTITY" {
  DBUGPRT("TOKEN_IDENTITY\n");
  rulescolno+=yyleng;
  return TOKEN_IDENTITY;
}

{identifier} {
  DBUGPRTARG("TOKEN_IDENTIFIER ", yytext);
  rulescolno+=strlen(yytext);
  ruleslval.string_slot = new string(yytext);
  return TOKEN_IDENTIFIER;
}

{variable} {
  DBUGPRTARG("TOKEN_VARIABLE ", yytext);
  rulescolno+=strlen(yytext);
  ruleslval.string_slot = new string(yytext);
  return TOKEN_VARIABLE;
}

{integer} {
  DBUGPRTARG("TOKEN_INTEGER ", yytext);
  rulescolno+=strlen(yytext);
  //ruleslval.string_slot = new string(yytext);
  sscanf(yytext, "%d", &ruleslval.int_slot);
  return TOKEN_INTEGER;
}

{floatNumber} {
  DBUGPRTARG("TOKEN_FLOAT ", yytext);
  rulescolno+=strlen(yytext);
  //ruleslval.string_slot = new string(yytext);
  sscanf(yytext, "%f", &ruleslval.float_slot);
  return TOKEN_FLOAT;
}

{string} {
  DBUGPRTARG("TOKEN_STRING ", yytext);
  rulescolno+=strlen(yytext);
  string s = yytext;
  ruleslval.string_slot = new string(s.substr(1, s.length()-2));
  return TOKEN_STRING;
}

{blanks} {
  rulescolno+=strlen(yytext);
}

\n {
  ruleslineno++;
  rulescolno=1;
}

. {
  DBUGPRTARG("OTHER TOKEN ", yytext);
  rulescolno+=strlen(yytext);
  return (yytext [0]);
}

%%
