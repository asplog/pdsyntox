/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_RIGHTARROW = 258,
     TOKEN_UPARROW = 259,
     TOKEN_UP2ARROW = 260,
     TOKEN_DOWNARROW = 261,
     TOKEN_DOWN2ARROW = 262,
     TOKEN_DOLLAR = 263,
     TOKEN_LPAR = 264,
     TOKEN_RPAR = 265,
     TOKEN_LBRACE = 266,
     TOKEN_RBRACE = 267,
     TOKEN_LBRACKET = 268,
     TOKEN_RBRACKET = 269,
     TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK = 270,
     TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK = 271,
     TOKEN_SEMI = 272,
     TOKEN_COLON = 273,
     TOKEN_COLON2 = 274,
     TOKEN_DOT = 275,
     TOKEN_COMMA = 276,
     TOKEN_GRAMMAR = 277,
     TOKEN_INPUT = 278,
     TOKEN_LEXICON = 279,
     TOKEN_PRED = 280,
     TOKEN_FORM = 281,
     TOKEN_IDENTITY = 282,
     TOKEN_TEST = 283,
     TOKEN_TRACE = 284,
     TOKEN_ORDER = 285,
     TOKEN_IF = 286,
     TOKEN_ELSE = 287,
     TOKEN_NIL = 288,
     TOKEN_TRUE = 289,
     TOKEN_SORT = 290,
     TOKEN_WITH = 291,
     TOKEN_FINISHED = 292,
     TOKEN_UNION = 293,
     TOKEN_SUBSET = 294,
     TOKEN_AFF = 295,
     TOKEN_PIPE = 296,
     TOKEN_NOT = 297,
     TOKEN_OR = 298,
     TOKEN_AND = 299,
     TOKEN_IMP = 300,
     TOKEN_EQUIV = 301,
     TOKEN_PLUS = 302,
     TOKEN_MINUS = 303,
     TOKEN_TIMES = 304,
     TOKEN_DIVIDE = 305,
     TOKEN_MODULO = 306,
     TOKEN_EQUAL = 307,
     TOKEN_DIFF = 308,
     TOKEN_LT = 309,
     TOKEN_LE = 310,
     TOKEN_GT = 311,
     TOKEN_GE = 312,
     TOKEN_IDENTIFIER = 313,
     TOKEN_STRING = 314,
     TOKEN_INTEGER = 315,
     TOKEN_FLOAT = 316,
     TOKEN_VARIABLE = 317,
     TOKEN_IFX = 318,
     TOKEN_MINUS_U = 319
   };
#endif
/* Tokens.  */
#define TOKEN_RIGHTARROW 258
#define TOKEN_UPARROW 259
#define TOKEN_UP2ARROW 260
#define TOKEN_DOWNARROW 261
#define TOKEN_DOWN2ARROW 262
#define TOKEN_DOLLAR 263
#define TOKEN_LPAR 264
#define TOKEN_RPAR 265
#define TOKEN_LBRACE 266
#define TOKEN_RBRACE 267
#define TOKEN_LBRACKET 268
#define TOKEN_RBRACKET 269
#define TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK 270
#define TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK 271
#define TOKEN_SEMI 272
#define TOKEN_COLON 273
#define TOKEN_COLON2 274
#define TOKEN_DOT 275
#define TOKEN_COMMA 276
#define TOKEN_GRAMMAR 277
#define TOKEN_INPUT 278
#define TOKEN_LEXICON 279
#define TOKEN_PRED 280
#define TOKEN_FORM 281
#define TOKEN_IDENTITY 282
#define TOKEN_TEST 283
#define TOKEN_TRACE 284
#define TOKEN_ORDER 285
#define TOKEN_IF 286
#define TOKEN_ELSE 287
#define TOKEN_NIL 288
#define TOKEN_TRUE 289
#define TOKEN_SORT 290
#define TOKEN_WITH 291
#define TOKEN_FINISHED 292
#define TOKEN_UNION 293
#define TOKEN_SUBSET 294
#define TOKEN_AFF 295
#define TOKEN_PIPE 296
#define TOKEN_NOT 297
#define TOKEN_OR 298
#define TOKEN_AND 299
#define TOKEN_IMP 300
#define TOKEN_EQUIV 301
#define TOKEN_PLUS 302
#define TOKEN_MINUS 303
#define TOKEN_TIMES 304
#define TOKEN_DIVIDE 305
#define TOKEN_MODULO 306
#define TOKEN_EQUAL 307
#define TOKEN_DIFF 308
#define TOKEN_LT 309
#define TOKEN_LE 310
#define TOKEN_GT 311
#define TOKEN_GE 312
#define TOKEN_IDENTIFIER 313
#define TOKEN_STRING 314
#define TOKEN_INTEGER 315
#define TOKEN_FLOAT 316
#define TOKEN_VARIABLE 317
#define TOKEN_IFX 318
#define TOKEN_MINUS_U 319




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 92 "rulesyacc.yy"
{
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
/* Line 1529 of yacc.c.  */
#line 199 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE ruleslval;

