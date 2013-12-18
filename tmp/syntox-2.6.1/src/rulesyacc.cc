/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse rulesparse
#define yylex   ruleslex
#define yyerror ruleserror
#define yylval  ruleslval
#define yychar  ruleschar
#define yydebug rulesdebug
#define yynerrs rulesnerrs


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




/* Copy the first part of user declarations.  */
#line 1 "rulesyacc.yy"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 345 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 358 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   565

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNRULES -- Number of states.  */
#define YYNSTATES  253

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    10,    16,    21,    26,    30,    33,
      35,    37,    39,    43,    49,    53,    60,    62,    66,    68,
      72,    74,    78,    80,    84,    87,    88,    91,    93,    99,
     104,   106,   109,   111,   113,   117,   121,   123,   125,   127,
     131,   134,   135,   137,   140,   142,   145,   147,   149,   153,
     156,   160,   164,   168,   171,   176,   181,   185,   191,   199,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   221,
     225,   229,   233,   236,   240,   244,   248,   252,   256,   260,
     262,   264,   268,   272,   276,   280,   284,   287,   289,   291,
     296,   300,   302,   304,   306,   308,   310,   312,   316,   321,
     326,   328,   330,   332,   335,   337,   339,   342,   347,   349,
     352,   354,   357,   361,   364,   368,   370,   374,   381,   388,
     392,   396,   400,   404,   406,   408,   410,   412,   414,   416,
     418,   420,   422,   424,   428,   430,   432,   436,   439,   445,
     449,   451,   453,   455,   457
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    22,    15,    75,    16,    -1,
      23,    15,    80,    99,    16,    -1,    23,    15,    80,    16,
      -1,    24,    15,    68,    16,    -1,    20,    99,    74,    -1,
      70,    68,    -1,    70,    -1,    58,    -1,    59,    -1,    27,
      58,    17,    -1,    27,    58,    99,    74,    17,    -1,    69,
      72,    17,    -1,    69,     9,    71,    10,    72,    17,    -1,
      17,    -1,    71,    21,   104,    -1,   104,    -1,    73,    41,
      72,    -1,    73,    -1,    58,    99,    74,    -1,    58,    -1,
      11,    83,    12,    -1,    11,    12,    -1,    -1,    76,    75,
      -1,    76,    -1,    80,     3,    77,    81,    17,    -1,    80,
       3,    81,    17,    -1,    17,    -1,    77,    78,    -1,    78,
      -1,    79,    -1,     9,    79,    10,    -1,    79,    41,    80,
      -1,    80,    -1,    58,    -1,    62,    -1,    11,    82,    12,
      -1,    11,    12,    -1,    -1,    84,    -1,    82,    84,    -1,
      85,    -1,    83,    85,    -1,    85,    -1,    86,    -1,    11,
      82,    12,    -1,    11,    12,    -1,    28,    91,    17,    -1,
      29,    91,    17,    -1,    29,    59,    17,    -1,    99,    17,
      -1,    89,    40,    90,    17,    -1,    87,    39,    88,    17,
      -1,    30,    94,    17,    -1,    31,     9,    91,    10,    84,
      -1,    31,     9,    91,    10,    84,    32,    84,    -1,    99,
      -1,   105,    -1,    92,    -1,    98,    -1,    99,    -1,    93,
      -1,    95,    -1,   105,    -1,    91,    -1,    91,    43,    91,
      -1,    91,    44,    91,    -1,    91,    45,    91,    -1,    91,
      46,    91,    -1,    42,    91,    -1,    91,    52,    91,    -1,
      91,    53,    91,    -1,    91,    54,    91,    -1,    91,    55,
      91,    -1,    91,    56,    91,    -1,    91,    57,    91,    -1,
      96,    -1,    37,    -1,    91,    47,    91,    -1,    91,    48,
      91,    -1,    91,    49,    91,    -1,    91,    50,    91,    -1,
      91,    51,    91,    -1,    48,    91,    -1,    61,    -1,    60,
      -1,    58,     9,    91,    10,    -1,    91,    38,    91,    -1,
      92,    -1,    98,    -1,    99,    -1,    33,    -1,   103,    -1,
     105,    -1,     9,    91,    10,    -1,    35,   105,    36,   104,
      -1,    35,   106,    36,   104,    -1,   106,    -1,     4,    -1,
       5,    -1,    97,    94,    -1,    97,    -1,     6,    -1,     6,
      60,    -1,     8,    60,    18,    60,    -1,    97,    -1,     8,
      60,    -1,     7,    -1,     7,    60,    -1,    13,   100,    14,
      -1,    13,    14,    -1,   100,    21,   101,    -1,   101,    -1,
      25,    18,    58,    -1,    25,    18,    58,     9,   105,    10,
      -1,    25,    18,    58,     9,    58,    10,    -1,    25,    18,
     105,    -1,    26,    18,    59,    -1,   104,    18,   102,    -1,
     105,    18,   102,    -1,   105,    -1,   105,    -1,   103,    -1,
      61,    -1,    60,    -1,   106,    -1,    99,    -1,    33,    -1,
      34,    -1,   104,    -1,   103,    41,   104,    -1,    58,    -1,
      62,    -1,    54,   107,    56,    -1,    54,    56,    -1,    54,
     108,    19,   108,    56,    -1,   108,    21,   107,    -1,   108,
      -1,   105,    -1,   103,    -1,    99,    -1,   106,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   189,   189,   197,   205,   211,   217,   245,   254,   258,
     263,   268,   275,   300,   325,   357,   389,   395,   402,   411,
     416,   423,   430,   441,   447,   453,   461,   466,   472,   483,
     494,   498,   505,   513,   519,   527,   534,   541,   548,   559,
     565,   571,   576,   583,   590,   597,   604,   609,   614,   620,
     627,   632,   637,   643,   649,   698,   710,   715,   720,   726,
     732,   737,   742,   747,   753,   758,   763,   769,   776,   781,
     786,   791,   796,   801,   806,   811,   816,   821,   826,   831,
     836,   842,   848,   854,   860,   866,   872,   878,   884,   890,
     900,   905,   910,   915,   920,   926,   931,   936,   941,   946,
     951,   957,   963,   969,   974,   980,   985,   992,   998,  1005,
    1012,  1017,  1027,  1033,  1040,  1047,  1056,  1064,  1075,  1086,
    1096,  1102,  1109,  1115,  1122,  1128,  1134,  1140,  1146,  1152,
    1158,  1164,  1172,  1178,  1186,  1193,  1203,  1222,  1228,  1249,
    1255,  1263,  1269,  1275,  1281
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_RIGHTARROW", "TOKEN_UPARROW",
  "TOKEN_UP2ARROW", "TOKEN_DOWNARROW", "TOKEN_DOWN2ARROW", "TOKEN_DOLLAR",
  "TOKEN_LPAR", "TOKEN_RPAR", "TOKEN_LBRACE", "TOKEN_RBRACE",
  "TOKEN_LBRACKET", "TOKEN_RBRACKET",
  "TOKEN_LEFT_DOUBLE_ANGLE_QUOTATION_MARK",
  "TOKEN_RIGHT_DOUBLE_ANGLE_QUOTATION_MARK", "TOKEN_SEMI", "TOKEN_COLON",
  "TOKEN_COLON2", "TOKEN_DOT", "TOKEN_COMMA", "TOKEN_GRAMMAR",
  "TOKEN_INPUT", "TOKEN_LEXICON", "TOKEN_PRED", "TOKEN_FORM",
  "TOKEN_IDENTITY", "TOKEN_TEST", "TOKEN_TRACE", "TOKEN_ORDER", "TOKEN_IF",
  "TOKEN_ELSE", "TOKEN_NIL", "TOKEN_TRUE", "TOKEN_SORT", "TOKEN_WITH",
  "TOKEN_FINISHED", "TOKEN_UNION", "TOKEN_SUBSET", "TOKEN_AFF",
  "TOKEN_PIPE", "TOKEN_NOT", "TOKEN_OR", "TOKEN_AND", "TOKEN_IMP",
  "TOKEN_EQUIV", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_TIMES",
  "TOKEN_DIVIDE", "TOKEN_MODULO", "TOKEN_EQUAL", "TOKEN_DIFF", "TOKEN_LT",
  "TOKEN_LE", "TOKEN_GT", "TOKEN_GE", "TOKEN_IDENTIFIER", "TOKEN_STRING",
  "TOKEN_INTEGER", "TOKEN_FLOAT", "TOKEN_VARIABLE", "TOKEN_IFX",
  "TOKEN_MINUS_U", "$accept", "axiom", "declaration", "dictionary",
  "stringOrIdentifier", "word", "list_args", "lexical_entries",
  "lexical_entry", "static_structure_statement", "rules", "rule",
  "terms_vector", "terms", "terms_disj", "term", "structure_statement",
  "list_statement", "static_list_statement", "statement",
  "static_statement", "dynamic_statement",
  "left_hand_side_subset_statement", "right_hand_side_subset_statement",
  "left_hand_side_aff_statement", "right_hand_side_aff_statement",
  "expression_statement", "up", "updouble", "dollars", "down", "dollar",
  "simpledollar", "downdouble", "features", "features_components",
  "feature", "feature_value", "constant", "identifier", "variable", "list",
  "list_components", "list_element", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    82,    82,    83,    83,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    87,
      88,    88,    88,    88,    89,    89,    89,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    93,    94,    94,    95,    95,    96,    96,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   104,   105,   106,   106,   106,   107,
     107,   108,   108,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     5,     4,     4,     3,     2,     1,
       1,     1,     3,     5,     3,     6,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     0,     2,     1,     5,     4,
       1,     2,     1,     1,     3,     3,     1,     1,     1,     3,
       2,     0,     1,     2,     1,     2,     1,     1,     3,     2,
       3,     3,     3,     2,     4,     4,     3,     5,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     2,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       1,     1,     1,     2,     1,     1,     2,     4,     1,     2,
       1,     2,     3,     2,     3,     1,     3,     6,     6,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     2,     5,     3,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,    25,     0,
       0,     0,     1,   113,     0,     0,   134,   135,     0,   115,
       0,   123,     0,     7,    30,    37,    38,     0,    27,     0,
       0,    16,     0,    10,    11,     0,     0,     9,     0,     0,
     112,     0,     0,     0,    24,     0,     0,     0,    44,     3,
      26,    41,     5,     0,     0,     6,     0,    22,     0,    20,
       8,   116,   119,   120,   114,   130,   131,     0,   127,   126,
     129,   121,   125,   132,   124,   128,   122,   101,   110,     0,
       0,    94,     0,    80,     0,     0,   134,    88,    87,     0,
      91,    79,   108,    92,    93,    95,    96,   100,     0,     0,
      23,    45,     0,     0,    41,    32,    33,    36,     0,     4,
      12,    25,     0,    18,    25,    14,     0,     0,   137,   143,
     142,   141,   144,     0,   140,     0,   111,   109,     0,     0,
       0,    72,    86,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    51,     0,   102,   105,     0,    40,     0,     0,
       0,    42,    46,    47,     0,     0,    64,    65,    59,    66,
      31,     0,     0,    29,     0,     0,     0,    21,    19,     0,
       0,   136,     0,     0,   133,     0,    97,     0,     0,     0,
      90,    68,    69,    70,    71,    81,    82,    83,    84,    85,
      73,    74,    75,    76,    77,    78,    34,   106,    49,     0,
       0,     0,   104,     0,    39,    43,     0,     0,    53,    28,
      35,    13,     0,    17,   118,   117,     0,   139,   140,   107,
      98,    99,    89,    48,   109,    56,   103,     0,     0,    61,
      62,    63,    60,     0,    67,    15,   138,     0,    55,    54,
      57,     0,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    35,    36,    37,   112,    58,    59,    23,
      27,    28,   104,   105,   106,   107,   108,   160,    47,   161,
     162,   163,   164,   238,   165,   243,    89,    90,   166,   211,
     167,    91,    92,    93,    94,    18,    19,    71,    95,    73,
      96,    97,   123,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -159
static const yytype_int16 yypact[] =
{
     189,     4,    37,    40,    57,    38,  -159,    33,    69,    23,
     -28,    82,  -159,  -159,    64,    78,  -159,  -159,    36,  -159,
      80,   104,    72,  -159,  -159,  -159,  -159,    71,    23,   130,
      11,  -159,    87,  -159,  -159,   131,    13,    82,    30,    92,
    -159,   109,   129,   129,  -159,   229,    70,   144,  -159,  -159,
    -159,     5,  -159,   136,    91,  -159,    88,     4,   140,   112,
    -159,   149,  -159,  -159,  -159,  -159,  -159,     6,  -159,  -159,
    -159,  -159,   119,  -159,  -159,  -159,  -159,  -159,   115,   118,
     229,  -159,   -36,  -159,   229,   229,   155,  -159,  -159,   406,
    -159,  -159,  -159,  -159,  -159,   119,  -159,  -159,   151,   428,
    -159,  -159,   -28,   108,     5,  -159,   138,  -159,   163,  -159,
    -159,    69,    10,  -159,    69,  -159,   126,    48,  -159,  -159,
     119,  -159,  -159,   132,    54,    88,  -159,   186,   337,   169,
     170,   508,  -159,   229,  -159,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,  -159,  -159,     3,  -159,   147,   273,  -159,   224,   225,
     294,  -159,  -159,  -159,   196,   199,  -159,  -159,   223,  -159,
    -159,   226,   -28,  -159,   227,   126,    88,  -159,  -159,   237,
     238,  -159,    32,    32,  -159,   197,  -159,    88,    88,   357,
     145,   508,   488,   468,   468,    66,    66,   198,   198,  -159,
     204,   204,   204,   204,   204,   204,  -159,  -159,  -159,   303,
     200,   239,   224,   229,  -159,  -159,     8,   229,  -159,  -159,
    -159,  -159,   241,  -159,  -159,  -159,   203,  -159,   240,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,   386,   246,  -159,
    -159,  -159,  -159,   248,   448,  -159,  -159,   315,  -159,  -159,
     235,   315,  -159
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   231,  -159,  -159,  -159,  -106,  -159,   -65,
     242,  -159,  -159,   165,   171,    -3,   168,   120,  -159,  -158,
       1,  -159,  -159,  -159,  -159,  -159,    81,    58,  -159,    63,
    -159,  -159,  -147,    65,    -1,  -159,   247,   249,   -34,    -2,
      -6,   -39,    97,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       8,    21,   215,    75,    75,    20,    29,    30,    72,    72,
     178,   212,    77,   206,   102,    78,   103,     7,    67,     7,
     175,     7,    56,    48,     7,    29,    17,    52,   122,    53,
      25,   176,    62,   120,    26,    21,    74,    74,    12,    20,
      24,    70,    70,   130,   172,     7,   174,    13,   101,   177,
      40,   215,     9,   111,   113,    10,   114,    41,    14,    15,
      67,   121,   118,    25,    16,   212,   119,    26,    17,   222,
      17,    57,    11,   182,    77,   183,   129,    78,    79,    80,
      22,    25,    38,     7,    44,    26,    67,    49,    61,   250,
      16,    16,    17,   252,    17,    17,    39,   169,    42,    31,
      45,    46,   168,    81,     7,    82,   179,    83,   110,    32,
      17,   180,    84,   154,   155,   142,   143,   144,    85,   156,
     157,     7,    43,   184,    67,   226,   228,    99,    86,    98,
      87,    88,    17,    51,    14,    15,    45,    46,   158,   159,
      33,    34,     7,   122,   122,    54,    16,    55,   120,   120,
     169,    63,   109,   116,   169,   168,   100,   115,   117,   168,
     125,   128,    65,    66,   133,   131,   132,    16,   151,   220,
      17,    17,    45,    46,   223,   126,   121,   121,   127,   172,
     173,   119,   119,    67,    57,   230,   231,    16,   181,    68,
      69,    17,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   169,   185,   187,   188,   207,   168,     1,
     242,     2,     3,     4,   189,   241,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   210,    77,   213,   216,    78,    79,    80,   217,
     218,   169,     7,   219,   221,   169,   168,   224,   225,   144,
     168,   140,   141,   142,   143,   144,   235,   229,   245,   246,
     234,   183,    81,   248,    82,   249,    83,   251,    60,   170,
      50,    84,   171,   153,   239,   236,   209,    85,   154,   155,
     227,   240,     0,    67,   156,   208,     7,    86,    64,    87,
      88,    17,    76,     0,   237,     0,     0,     0,   244,   154,
     155,    45,    46,   158,   159,   156,   214,     7,   154,   155,
       0,     0,     0,     0,   156,   233,     7,     0,     0,     0,
     154,   155,    45,    46,   158,   159,   156,     0,     7,     0,
       0,    45,    46,   158,   159,    17,     0,     0,     0,     0,
       0,     0,     0,    45,    46,   158,   159,   186,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,   232,     0,     0,
       0,     0,     0,     0,     0,   135,     0,    17,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   135,   247,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   135,   152,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   135,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   135,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   135,     0,     0,     0,
       0,   136,   137,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   135,     0,     0,     0,
       0,   136,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   135,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150
};

static const yytype_int16 yycheck[] =
{
       1,     7,   160,    42,    43,     7,     9,    10,    42,    43,
     116,   158,     4,    10,     9,     7,    11,    13,    54,    13,
      10,    13,     9,    22,    13,    28,    62,    16,    67,    30,
      58,    21,    38,    67,    62,    41,    42,    43,     0,    41,
      17,    42,    43,    82,    41,    13,   111,    14,    47,   114,
      14,   209,    15,    54,    56,    15,    57,    21,    25,    26,
      54,    67,    56,    58,    58,   212,    67,    62,    62,   175,
      62,    58,    15,    19,     4,    21,    82,     7,     8,     9,
      11,    58,    18,    13,    12,    62,    54,    16,    58,   247,
      58,    58,    62,   251,    62,    62,    18,   103,    18,    17,
      28,    29,   103,    33,    13,    35,    58,    37,    17,    27,
      62,   117,    42,     5,     6,    49,    50,    51,    48,    11,
      12,    13,    18,   125,    54,   182,   183,    46,    58,    59,
      60,    61,    62,     3,    25,    26,    28,    29,    30,    31,
      58,    59,    13,   182,   183,    58,    58,    16,   182,   183,
     156,    59,    16,    41,   160,   156,    12,    17,     9,   160,
      41,    80,    33,    34,     9,    84,    85,    58,    17,   172,
      62,    62,    28,    29,   176,    60,   182,   183,    60,    41,
      17,   182,   183,    54,    58,   187,   188,    58,    56,    60,
      61,    62,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   209,    18,    36,    36,    60,   209,    20,
     216,    22,    23,    24,   133,   216,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     8,     4,     9,    39,     7,     8,     9,    40,
      17,   247,    13,    17,    17,   251,   247,    10,    10,    51,
     251,    47,    48,    49,    50,    51,    17,    60,    17,    56,
      60,    21,    33,    17,    35,    17,    37,    32,    37,   104,
      28,    42,   104,   102,   216,   212,   156,    48,     5,     6,
     183,   216,    -1,    54,    11,    12,    13,    58,    41,    60,
      61,    62,    43,    -1,   213,    -1,    -1,    -1,   217,     5,
       6,    28,    29,    30,    31,    11,    12,    13,     5,     6,
      -1,    -1,    -1,    -1,    11,    12,    13,    -1,    -1,    -1,
       5,     6,    28,    29,    30,    31,    11,    -1,    13,    -1,
      -1,    28,    29,    30,    31,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    62,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    38,    10,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    38,    17,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    38,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    22,    23,    24,    66,    67,    13,    99,    15,
      15,    15,     0,    14,    25,    26,    58,    62,   100,   101,
     104,   105,    11,    74,    17,    58,    62,    75,    76,    80,
      80,    17,    27,    58,    59,    68,    69,    70,    18,    18,
      14,    21,    18,    18,    12,    28,    29,    83,    85,    16,
      75,     3,    16,    99,    58,    16,     9,    58,    72,    73,
      68,    58,   105,    59,   101,    33,    34,    54,    60,    61,
      99,   102,   103,   104,   105,   106,   102,     4,     7,     8,
       9,    33,    35,    37,    42,    48,    58,    60,    61,    91,
      92,    96,    97,    98,    99,   103,   105,   106,    59,    91,
      12,    85,     9,    11,    77,    78,    79,    80,    81,    16,
      17,    99,    71,   104,    99,    17,    41,     9,    56,    99,
     103,   105,   106,   107,   108,    41,    60,    60,    91,   105,
     106,    91,    91,     9,    17,    38,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    17,    17,    79,     5,     6,    11,    12,    30,    31,
      82,    84,    85,    86,    87,    89,    93,    95,    99,   105,
      78,    81,    41,    17,    74,    10,    21,    74,    72,    58,
     105,    56,    19,    21,   104,    18,    10,    36,    36,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    10,    60,    12,    82,
       8,    94,    97,     9,    12,    84,    39,    40,    17,    17,
      80,    17,    72,   104,    10,    10,   108,   107,   108,    60,
     104,   104,    10,    12,    60,    17,    94,    91,    88,    92,
      98,    99,   105,    90,    91,    17,    56,    10,    17,    17,
      84,    32,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 190 "rulesyacc.yy"
    {
	  DBUGPRT("axiom done...");
	  YYACCEPT;
	}
    break;

  case 3:
#line 197 "rulesyacc.yy"
    {
	  DBUGPRT("declaration grammar");
	  synthesizer.getGrammar()->findTerms();
	  //BUG;
	  //synthesizer.getGrammar().print(cerr, NULL);
	  //cerr << endl;
	}
    break;

  case 4:
#line 205 "rulesyacc.yy"
    {
	  DBUGPRT("declaration input");
	  synthesizer.putStartTerm((yyvsp[(3) - (5)].term_slot));
	  synthesizer.putStartFeatures((yyvsp[(4) - (5)].features_slot));
	}
    break;

  case 5:
#line 211 "rulesyacc.yy"
    {
	  DBUGPRT("declaration input");
	  synthesizer.putStartTerm((yyvsp[(3) - (4)].term_slot));
	  synthesizer.putStartFeatures(new Features());
	 }
    break;

  case 6:
#line 217 "rulesyacc.yy"
    {      
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
    break;

  case 7:
#line 246 "rulesyacc.yy"
    {
	  DBUGPRT("declaration features");
	  unsigned int pred=(yyvsp[(2) - (3)].features_slot)->getPred();
	  synthesizer.putLocalEntry(new Entry(0, pred, UINT_MAX, (yyvsp[(2) - (3)].features_slot), (yyvsp[(3) - (3)].statements_slot)));
	}
    break;

  case 8:
#line 254 "rulesyacc.yy"
    {
	  DBUGPRT("dictionary");
	}
    break;

  case 9:
#line 258 "rulesyacc.yy"
    {
	  DBUGPRT("dictionary");
	 }
    break;

  case 10:
#line 263 "rulesyacc.yy"
    {
	  DBUGPRT("stringOrIdentifier");
	  (yyval.string_slot)=(yyvsp[(1) - (1)].string_slot);
	}
    break;

  case 11:
#line 268 "rulesyacc.yy"
    {
	  DBUGPRT("stringOrIdentifier");
	  (yyval.string_slot)=(yyvsp[(1) - (1)].string_slot);
	 }
    break;

  case 12:
#line 276 "rulesyacc.yy"
    {
	  DBUGPRT("word");
	  unsigned int code=strToInt(*(yyvsp[(2) - (3)].string_slot));
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
    break;

  case 13:
#line 301 "rulesyacc.yy"
    {
	  DBUGPRT("word");
	  unsigned int code=strToInt(*(yyvsp[(2) - (5)].string_slot));
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
	  lp->add(new Entry(code, (unsigned int)UINT_MAX, (unsigned int)UINT_MAX, (yyvsp[(3) - (5)].features_slot), (yyvsp[(4) - (5)].statements_slot)));
	}
    break;

  case 14:
#line 326 "rulesyacc.yy"
    {
	  DBUGPRT("word");
	  for (list<class Entry*>::iterator entry=(yyvsp[(2) - (3)].entries_slot)->begin();
	       entry!=(yyvsp[(2) - (3)].entries_slot)->end();
	       entry++){
	    (*entry)->putForm(*(yyvsp[(1) - (3)].string_slot));
	  }
	  for (list<class Entry*>::iterator entry=(yyvsp[(2) - (3)].entries_slot)->begin();
	       entry!=(yyvsp[(2) - (3)].entries_slot)->end();
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
    break;

  case 15:
#line 358 "rulesyacc.yy"
    {
	  DBUGPRT("word");
	  for (list<class Entry*>::iterator entry=(yyvsp[(5) - (6)].entries_slot)->begin();
	       entry!=(yyvsp[(5) - (6)].entries_slot)->end();
	       entry++){
	    (*entry)->putForm(*(yyvsp[(1) - (6)].string_slot));
	    (*entry)->putArgs((yyvsp[(3) - (6)].list_args));
	  }
	  for (list<class Entry*>::iterator entry=(yyvsp[(5) - (6)].entries_slot)->begin();
	       entry!=(yyvsp[(5) - (6)].entries_slot)->end();
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
    break;

  case 16:
#line 390 "rulesyacc.yy"
    {
	  DBUGPRT("word");
	}
    break;

  case 17:
#line 396 "rulesyacc.yy"
    {
	  DBUGPRT("list_args");
	  (yyval.list_args)=(yyvsp[(1) - (3)].list_args);
	  (yyval.list_args)->push_back((yyvsp[(3) - (3)].bits_slot));
	}
    break;

  case 18:
#line 403 "rulesyacc.yy"
    {
	  DBUGPRT("list_args");
	  (yyval.list_args)=new list<bitset<MAXBITS> *>;
	  (yyval.list_args)->push_back((yyvsp[(1) - (1)].bits_slot));
	}
    break;

  case 19:
#line 411 "rulesyacc.yy"
    {	  
	  DBUGPRT("lexical_entries");
	  (yyval.entries_slot)=(yyvsp[(3) - (3)].entries_slot); 
	  (yyval.entries_slot)->add((yyvsp[(1) - (3)].entry_slot));}
    break;

  case 20:
#line 416 "rulesyacc.yy"
    {
	  DBUGPRT("lexical_entries");
	  (yyval.entries_slot)=new Entries((yyvsp[(1) - (1)].entry_slot));
	 }
    break;

  case 21:
#line 424 "rulesyacc.yy"
    {
	  DBUGPRT("lexical_entry");
	  unsigned int pred=(yyvsp[(2) - (3)].features_slot)->getPred();
	  (yyval.entry_slot)=new Entry(strToInt(*(yyvsp[(1) - (3)].string_slot)), pred, UINT_MAX, (yyvsp[(2) - (3)].features_slot), (yyvsp[(3) - (3)].statements_slot));
	}
    break;

  case 22:
#line 431 "rulesyacc.yy"
    {
	  DBUGPRT("lexical_entry");
	  (yyval.entry_slot)=new Entry(strToInt(*(yyvsp[(1) - (1)].string_slot)), UINT_MAX, UINT_MAX, new Features(), NULL);
	}
    break;

  case 23:
#line 442 "rulesyacc.yy"
    {
	  DBUGPRT("compound_statement");
	  (yyval.statements_slot)=(yyvsp[(2) - (3)].statements_slot);
	}
    break;

  case 24:
#line 448 "rulesyacc.yy"
    {
	  (yyval.statements_slot)=NULL;
	}
    break;

  case 25:
#line 453 "rulesyacc.yy"
    {
	  (yyval.statements_slot)=NULL;
        }
    break;

  case 26:
#line 462 "rulesyacc.yy"
    {
	  DBUGPRT("rules"); 
	}
    break;

  case 27:
#line 467 "rulesyacc.yy"
    {
	  DBUGPRT("rules"); 
	}
    break;

  case 28:
#line 473 "rulesyacc.yy"
    {
	  DBUGPRT("rule");
	  class Rule *rule=new Rule((yyvsp[(1) - (5)].term_slot), *(yyvsp[(3) - (5)].vector_terms_slot), (yyvsp[(4) - (5)].statements_slot));
	  rule->addDefaults();
	  synthesizer.getGrammar()->addRule(rule);
	  if (synthesizer.getGrammar()->getStartTerm()==NULL){
	    synthesizer.getGrammar()->putStartTerm((yyvsp[(1) - (5)].term_slot));
	  }
	}
    break;

  case 29:
#line 484 "rulesyacc.yy"
    {
	  DBUGPRT("Rule");
	  class Rule *rule=new Rule((yyvsp[(1) - (4)].term_slot), (yyvsp[(3) - (4)].statements_slot));
	  rule->addDefaults();
	  synthesizer.getGrammar()->addRule(rule);
	  if (synthesizer.getGrammar()->getStartTerm()==NULL){
	    synthesizer.getGrammar()->putStartTerm((yyvsp[(1) - (4)].term_slot));
	  }
	}
    break;

  case 31:
#line 499 "rulesyacc.yy"
    { 
	  DBUGPRT("term_vector");
	  (yyval.vector_terms_slot)=(yyvsp[(1) - (2)].vector_terms_slot);
	  (yyval.vector_terms_slot)->push_back((yyvsp[(2) - (2)].terms_slot));
	}
    break;

  case 32:
#line 506 "rulesyacc.yy"
    { 
	  DBUGPRT("term_vector"); 
	  (yyval.vector_terms_slot)=new vector<class Terms*>;
	  (yyval.vector_terms_slot)->push_back((yyvsp[(1) - (1)].terms_slot));
	}
    break;

  case 33:
#line 514 "rulesyacc.yy"
    { 
	  DBUGPRT("term");
	  (yyval.terms_slot)=(yyvsp[(1) - (1)].terms_slot);
	}
    break;

  case 34:
#line 520 "rulesyacc.yy"
    { 
	  DBUGPRT("term");
	  (yyval.terms_slot)=(yyvsp[(2) - (3)].terms_slot);
	  (yyval.terms_slot)->putOptional(true);
	}
    break;

  case 35:
#line 528 "rulesyacc.yy"
    { 
	  DBUGPRT("term_disj");
	  (yyval.terms_slot)=(yyvsp[(1) - (3)].terms_slot);
	  (yyval.terms_slot)->push_back((yyvsp[(3) - (3)].term_slot));
	}
    break;

  case 36:
#line 535 "rulesyacc.yy"
    { 
	  DBUGPRT("term_disj"); 
	  (yyval.terms_slot)=new class Terms((yyvsp[(1) - (1)].term_slot));
	}
    break;

  case 37:
#line 542 "rulesyacc.yy"
    { 
	  DBUGPRT("term_id");
	  unsigned int code=strToInt(*(yyvsp[(1) - (1)].string_slot));
	  (yyval.term_slot) = new Term(code);
	}
    break;

  case 38:
#line 549 "rulesyacc.yy"
    { 
	  DBUGPRT("term_id");
	  unsigned int code=strToInt(*(yyvsp[(1) - (1)].string_slot));
	  (yyval.term_slot) = new Term(code);
	}
    break;

  case 39:
#line 560 "rulesyacc.yy"
    {
	  DBUGPRT("structure_statement");
	  (yyval.statements_slot)=(yyvsp[(2) - (3)].statements_slot);
	}
    break;

  case 40:
#line 566 "rulesyacc.yy"
    {
	  (yyval.statements_slot)=NULL;
	}
    break;

  case 41:
#line 571 "rulesyacc.yy"
    {
	  (yyval.statements_slot)=NULL;
        }
    break;

  case 42:
#line 577 "rulesyacc.yy"
    {
	  DBUGPRT("list_statement");
	  (yyval.statements_slot)=new Statements();
	  (yyval.statements_slot)->addStatement((yyvsp[(1) - (1)].statement_slot));
	}
    break;

  case 43:
#line 583 "rulesyacc.yy"
    {
	  DBUGPRT("list_statement");
	  (yyval.statements_slot)=(yyvsp[(1) - (2)].statements_slot);
	  (yyval.statements_slot)->addStatement((yyvsp[(2) - (2)].statement_slot));
	}
    break;

  case 44:
#line 591 "rulesyacc.yy"
    {
	  DBUGPRT("static_list_statement");
	  (yyval.statements_slot)=new Statements();
	  (yyval.statements_slot)->addStatement((yyvsp[(1) - (1)].statement_slot));
	}
    break;

  case 45:
#line 597 "rulesyacc.yy"
    {
	  DBUGPRT("static_list_statement");
	  (yyval.statements_slot)=(yyvsp[(1) - (2)].statements_slot);
	  (yyval.statements_slot)->addStatement((yyvsp[(2) - (2)].statement_slot));
	}
    break;

  case 46:
#line 604 "rulesyacc.yy"
    {
	  DBUGPRT("statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	 }
    break;

  case 47:
#line 609 "rulesyacc.yy"
    {
	  DBUGPRT("statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	 }
    break;

  case 48:
#line 615 "rulesyacc.yy"
    {
	  DBUGPRT("statement");
	  (yyval.statement_slot)=new Statement((yyvsp[(2) - (3)].statements_slot));
	}
    break;

  case 49:
#line 621 "rulesyacc.yy"
    {
	  DBUGPRT("statement");
	  (yyval.statement_slot)=new Statement(new Statements());
	}
    break;

  case 50:
#line 627 "rulesyacc.yy"
    {
	  DBUGPRT("static_statement");
	  (yyval.statement_slot)=new Statement(Statement::TEST, (yyvsp[(2) - (3)].statement_slot));
	}
    break;

  case 51:
#line 632 "rulesyacc.yy"
    {
	  DBUGPRT("static_statement");
	  (yyval.statement_slot)=new Statement(Statement::TRACE, (yyvsp[(2) - (3)].statement_slot));
	}
    break;

  case 52:
#line 637 "rulesyacc.yy"
    {
	  DBUGPRT("static_statement");
	  (yyval.statement_slot)=new Statement(Statement::TRACE, new Statement(Statement::STR, (yyvsp[(2) - (3)].string_slot)));
	}
    break;

  case 53:
#line 643 "rulesyacc.yy"
    {
	  DBUGPRT("dynamic_statement");
	  (yyval.statement_slot)=new Statement(Statement::FILTER, (yyvsp[(1) - (2)].features_slot));

	}
    break;

  case 54:
#line 649 "rulesyacc.yy"
    {
	  DBUGPRT("dynamic_statement");
	  (yyval.statement_slot)=new Statement(Statement::AFF, (yyvsp[(1) - (4)].statement_slot), (yyvsp[(3) - (4)].statement_slot));
	  // <…> := <…>
	  // <…> := sort …
	  // <…> := X
	  if (((yyvsp[(1) - (4)].statement_slot)->getOp()==Statement::LIST) && (((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::LIST)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::SORT)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::VARIABLE)))
	    ;	  
	  // ↓i := X
	  // ↓i := […]
	  // ↓i := ↑
	  // ↓i := … ∪ …
	  // ↓i := ⇓j
	  else if (((yyvsp[(1) - (4)].statement_slot)->getOp()==Statement::DOWN) && (((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::VARIABLE)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::FEATURES)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::UP)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::UNIF)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::DOWN2)))
	    ;
	  // ⇑ := X
	  // ⇑ := […]
	  // ⇑ := ↑
	  // ⇑ := … ∪ …
	  // ⇑ := ⇓j
	  else if (((yyvsp[(1) - (4)].statement_slot)->getOp()==Statement::UP2) && (((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::VARIABLE)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::FEATURES)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::UP)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::UNIF)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::DOWN2)))
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
	  else if (((yyvsp[(1) - (4)].statement_slot)->getOp()==Statement::VARIABLE) 
		   &&(((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::VARIABLE)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::CONSTANT)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::LIST)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::SORT)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::FEATURES)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::UP)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::UNIF)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::DOWN2)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::NUMBER)
		      ||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::FCT)))
	    ;
	  else {
	    //CERR_LINE;
	    yyerror((char *)"••• syntax error");
	  }
	}
    break;

  case 55:
#line 698 "rulesyacc.yy"
    {
	  DBUGPRT("dynamic_statement");
	  (yyval.statement_slot)=new Statement(Statement::SUBSET, (yyvsp[(1) - (4)].statement_slot), (yyvsp[(3) - (4)].statement_slot));
	  // […] ⊂ ↑ 
	  // […] ⊂ ⇓j 
	  // […] ⊂ X 
	  if (((yyvsp[(1) - (4)].statement_slot)->getOp()==Statement::FEATURES) && (((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::UP)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::DOWN2)||((yyvsp[(3) - (4)].statement_slot)->getOp()==Statement::VARIABLE)))
	    ;
	  else 
	    yyerror((char *)"syntax error");
	}
    break;

  case 56:
#line 710 "rulesyacc.yy"
    {
	  DBUGPRT("dynamic_statement");
	  (yyval.statement_slot)=new Statement(Statement::ORDER, (yyvsp[(2) - (3)].statement_slot));
	}
    break;

  case 57:
#line 715 "rulesyacc.yy"
    {
	  DBUGPRT("dynamic_statement");
	  (yyval.statement_slot)=new Statement(Statement::IF, (yyvsp[(3) - (5)].statement_slot), new Statement(Statement::THEN, (yyvsp[(5) - (5)].statement_slot), NULL));
	}
    break;

  case 58:
#line 720 "rulesyacc.yy"
    {
	  DBUGPRT("dynamic_statement");
	  (yyval.statement_slot)=new Statement(Statement::IF, (yyvsp[(3) - (7)].statement_slot), new Statement(Statement::THEN, (yyvsp[(5) - (7)].statement_slot), (yyvsp[(7) - (7)].statement_slot)));
	}
    break;

  case 59:
#line 726 "rulesyacc.yy"
    {
	  DBUGPRT("left_hand_side_statement");
	  (yyval.statement_slot)=new Statement(Statement::FEATURES, (yyvsp[(1) - (1)].features_slot));
	}
    break;

  case 60:
#line 732 "rulesyacc.yy"
    {
	  DBUGPRT("right_hand_side_subset_statement");
	  (yyval.statement_slot)=new Statement(Statement::VARIABLE, (yyvsp[(1) - (1)].bits_slot));
	}
    break;

  case 61:
#line 737 "rulesyacc.yy"
    {
	  DBUGPRT("right_hand_side_subset_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	}
    break;

  case 62:
#line 742 "rulesyacc.yy"
    {
	  DBUGPRT("right_hand_side_subset_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	}
    break;

  case 63:
#line 747 "rulesyacc.yy"
    {
	  DBUGPRT("right_hand_side_subset_statement");
	  (yyval.statement_slot)=new Statement(Statement::FEATURES, (yyvsp[(1) - (1)].features_slot));
	}
    break;

  case 64:
#line 753 "rulesyacc.yy"
    {
	  DBUGPRT("left_hand_side_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	}
    break;

  case 65:
#line 758 "rulesyacc.yy"
    {
	  DBUGPRT("left_hand_side_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	}
    break;

  case 66:
#line 763 "rulesyacc.yy"
    {
	  DBUGPRT("left_hand_side_statement");
	  (yyval.statement_slot)=new Statement(Statement::VARIABLE, (yyvsp[(1) - (1)].bits_slot));
	 }
    break;

  case 67:
#line 769 "rulesyacc.yy"
    {
	  DBUGPRT("right_hand_side_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	}
    break;

  case 68:
#line 776 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::OR, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 69:
#line 781 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::AND, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 70:
#line 786 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::OR, new Statement(Statement::FCT, Statement::NOT, (yyvsp[(1) - (3)].statement_slot)), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 71:
#line 791 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::AND, new Statement(Statement::FCT, Statement::OR, new Statement(Statement::FCT, Statement::NOT, (yyvsp[(1) - (3)].statement_slot)), (yyvsp[(3) - (3)].statement_slot)), new Statement(Statement::FCT, Statement::OR, (yyvsp[(1) - (3)].statement_slot), new Statement(Statement::FCT, Statement::NOT, (yyvsp[(3) - (3)].statement_slot))));
	}
    break;

  case 72:
#line 796 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::NOT, (yyvsp[(2) - (2)].statement_slot));
	}
    break;

  case 73:
#line 801 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::EQUAL, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 74:
#line 806 "rulesyacc.yy"
    { 
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::NOT, new Statement(Statement::FCT, Statement::EQUAL, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot))); 
	}
    break;

  case 75:
#line 811 "rulesyacc.yy"
    { 
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::LT, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot)); 
	}
    break;

  case 76:
#line 816 "rulesyacc.yy"
    { 
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::LE, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot)); 
	}
    break;

  case 77:
#line 821 "rulesyacc.yy"
    { 
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::GT, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot)); 
	}
    break;

  case 78:
#line 826 "rulesyacc.yy"
    { 
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::GE, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot)); 
	}
    break;

  case 79:
#line 831 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	 }
    break;

  case 80:
#line 836 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FINISHED);
	 }
    break;

  case 81:
#line 843 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::PLUS, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 82:
#line 849 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::MINUS, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 83:
#line 855 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::TIMES, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 84:
#line 861 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::DIVIDE, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 85:
#line 867 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::MODULO, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 86:
#line 873 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FCT, Statement::MINUS_U, (yyvsp[(2) - (2)].statement_slot), NULL);
	}
    break;

  case 87:
#line 879 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement((float)(yyvsp[(1) - (1)].float_slot));
	}
    break;

  case 88:
#line 885 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
 	  (yyval.statement_slot)=new Statement((float)(yyvsp[(1) - (1)].int_slot));
	}
    break;

  case 89:
#line 890 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  if (*(yyvsp[(1) - (4)].string_slot)=="abs")
	    (yyval.statement_slot)=new Statement(Statement::FCT, Statement::ABS, (yyvsp[(3) - (4)].statement_slot));
	  else {
	    yyerror((char *)"syntax error");
	  }
	}
    break;

  case 90:
#line 900 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::UNIF, (yyvsp[(1) - (3)].statement_slot), (yyvsp[(3) - (3)].statement_slot));
	}
    break;

  case 91:
#line 905 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	}
    break;

  case 92:
#line 910 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=(yyvsp[(1) - (1)].statement_slot);
	}
    break;

  case 93:
#line 915 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::FEATURES, (yyvsp[(1) - (1)].features_slot));
	}
    break;

  case 94:
#line 921 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::NIL);
	}
    break;

  case 95:
#line 926 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::CONSTANT, (yyvsp[(1) - (1)].bits_slot));
	}
    break;

  case 96:
#line 931 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::VARIABLE, (yyvsp[(1) - (1)].bits_slot));
	}
    break;

  case 97:
#line 936 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=(yyvsp[(2) - (3)].statement_slot);
	}
    break;

  case 98:
#line 941 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::SORT, new Statement(Statement::VARIABLE, (yyvsp[(2) - (4)].bits_slot)), new Statement(Statement::CONSTANT, (yyvsp[(4) - (4)].bits_slot)));
	}
    break;

  case 99:
#line 946 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement(Statement::SORT, new Statement((yyvsp[(2) - (4)].list_slot)), new Statement(Statement::CONSTANT, (yyvsp[(4) - (4)].bits_slot)));
	}
    break;

  case 100:
#line 951 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.statement_slot)=new Statement((yyvsp[(1) - (1)].list_slot));
	}
    break;

  case 101:
#line 957 "rulesyacc.yy"
    {  
	  DBUGPRT("up");
	  (yyval.statement_slot)=new Statement(Statement::UP);
	}
    break;

  case 102:
#line 963 "rulesyacc.yy"
    {  
	  DBUGPRT("updouble");
	  (yyval.statement_slot)=new Statement(Statement::UP2);
	}
    break;

  case 103:
#line 969 "rulesyacc.yy"
    {  
	  DBUGPRT("dollars");
	  (yyval.statement_slot) = new Statement(Statement::DOLLARS, (yyvsp[(1) - (2)].statement_slot), (yyvsp[(2) - (2)].statement_slot)); 
	}
    break;

  case 104:
#line 974 "rulesyacc.yy"
    { 
	  DBUGPRT("dollars");
	  (yyval.statement_slot) = new Statement(Statement::DOLLARS, (yyvsp[(1) - (1)].statement_slot), NULL);
	}
    break;

  case 105:
#line 980 "rulesyacc.yy"
    {  
	  DBUGPRT("downSimple");
	  (yyval.statement_slot) = new Statement(Statement::DOWN, (unsigned int)0); 
	}
    break;

  case 106:
#line 986 "rulesyacc.yy"
    { 
	  DBUGPRT("downSimple");
	  (yyval.statement_slot) = new Statement(Statement::DOWN, (yyvsp[(2) - (2)].int_slot)-1); 
	}
    break;

  case 107:
#line 993 "rulesyacc.yy"
    { 
	  DBUGPRT("dollar");
	  (yyval.statement_slot) = new Statement(Statement::DOLLAR, (yyvsp[(2) - (4)].int_slot)-1, (yyvsp[(4) - (4)].int_slot)-1); 
	}
    break;

  case 108:
#line 999 "rulesyacc.yy"
    { 
	  DBUGPRT("dollar");
	  (yyval.statement_slot) = (yyvsp[(1) - (1)].statement_slot); 
	}
    break;

  case 109:
#line 1006 "rulesyacc.yy"
    { 
	  DBUGPRT("downComplex");
	  (yyval.statement_slot) = new Statement(Statement::DOLLAR, (yyvsp[(2) - (2)].int_slot)-1); 
	}
    break;

  case 110:
#line 1012 "rulesyacc.yy"
    {  
	  DBUGPRT("downdouble");
	  (yyval.statement_slot) = new Statement(Statement::DOWN2, (unsigned int)0); 
	}
    break;

  case 111:
#line 1018 "rulesyacc.yy"
    { 
	  DBUGPRT("downdouble");
	  (yyval.statement_slot) = new Statement(Statement::DOWN2, (unsigned int)((yyvsp[(2) - (2)].int_slot)-1)); 
	}
    break;

  case 112:
#line 1028 "rulesyacc.yy"
    {
	  DBUGPRT("features");
 	  (yyval.features_slot)=(yyvsp[(2) - (3)].features_slot);
	}
    break;

  case 113:
#line 1034 "rulesyacc.yy"
    {
	  DBUGPRT("features");
	  (yyval.features_slot)=new Features();
	}
    break;

  case 114:
#line 1041 "rulesyacc.yy"
    {
	  DBUGPRT("features_components");
	  (yyval.features_slot)=(yyvsp[(1) - (3)].features_slot); 
	  (yyval.features_slot)->addFeature((yyvsp[(3) - (3)].feature_slot));
	}
    break;

  case 115:
#line 1048 "rulesyacc.yy"
    {
	  DBUGPRT("features_components");
	  (yyval.features_slot)=new Features();
	  (yyval.features_slot)->addFeature((yyvsp[(1) - (1)].feature_slot));
	}
    break;

  case 116:
#line 1057 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot) = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  (yyval.feature_slot)->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value((yyvsp[(3) - (3)].string_slot), Value::IDENTIFIER), Feature::CONSTANT));
	}
    break;

  case 117:
#line 1065 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot) = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  (yyval.feature_slot)->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value((yyvsp[(3) - (6)].string_slot), Value::IDENTIFIER), Feature::CONSTANT));
	  (yyval.feature_slot)->getRhs()->getFeatures()->addFeature(new Feature(ARGBITS, new Value((yyvsp[(5) - (6)].bits_slot), Value::VARIABLE), Feature::CONSTANT));
	  //BUG;
	  //$$->print(cerr);
	}
    break;

  case 118:
#line 1076 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot) = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  (yyval.feature_slot)->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value((yyvsp[(3) - (6)].string_slot), Value::IDENTIFIER), Feature::CONSTANT));
	  (yyval.feature_slot)->getRhs()->getFeatures()->addFeature(new Feature(ARGBITS, new Value((yyvsp[(5) - (6)].string_slot), Value::IDENTIFIER), Feature::CONSTANT));
	  //BUG;
	  //$$->print(cerr);
	}
    break;

  case 119:
#line 1087 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot) = new Feature(SYSBITS, new Value(new Features()), Feature::PRED);
	  (yyval.feature_slot)->getRhs()->getFeatures()->addFeature(new Feature(LEXBITS, new Value((yyvsp[(3) - (3)].bits_slot), Value::VARIABLE), Feature::CONSTANT));
	  //$$ = new Feature(SYSBITS, new Value($3, Value::VARIABLE), Feature::PRED);
	  //BUG;
	  //$$->print(cerr);
	}
    break;

  case 120:
#line 1097 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot) = new Feature(SYSBITS, new Value((yyvsp[(3) - (3)].string_slot), Value::FORM), Feature::FORM);
	}
    break;

  case 121:
#line 1103 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot)=new Feature(*(yyvsp[(1) - (3)].bits_slot), (yyvsp[(3) - (3)].value_slot), Feature::CONSTANT);
	  //$$->print(cerr);
	}
    break;

  case 122:
#line 1110 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot)=new Feature(*(yyvsp[(1) - (3)].bits_slot), (yyvsp[(3) - (3)].value_slot), Feature::VARIABLE);
	}
    break;

  case 123:
#line 1116 "rulesyacc.yy"
    {
	  DBUGPRT("feature");
	  (yyval.feature_slot) = new Feature(*(yyvsp[(1) - (1)].bits_slot), NULL, Feature::VARIABLE);
	}
    break;

  case 124:
#line 1123 "rulesyacc.yy"
    {
	  DBUGPRT("feature_value");
	  (yyval.value_slot)=new Value((yyvsp[(1) - (1)].bits_slot), Value::VARIABLE);
	}
    break;

  case 125:
#line 1129 "rulesyacc.yy"
    {
	  DBUGPRT("feature_value");
	  (yyval.value_slot)=new Value((yyvsp[(1) - (1)].bits_slot), Value::CONSTANT);
	}
    break;

  case 126:
#line 1135 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
	  (yyval.value_slot)=new Value((float)(yyvsp[(1) - (1)].float_slot));
	}
    break;

  case 127:
#line 1141 "rulesyacc.yy"
    {
	  DBUGPRT("expression_statement");
 	  (yyval.value_slot)=new Value((float)(yyvsp[(1) - (1)].int_slot));
	}
    break;

  case 128:
#line 1147 "rulesyacc.yy"
    {
	  DBUGPRT("feature_value");
	  (yyval.value_slot)=new Value((yyvsp[(1) - (1)].list_slot));
	}
    break;

  case 129:
#line 1153 "rulesyacc.yy"
    {
	  DBUGPRT("feature_value");
	  (yyval.value_slot)=new Value((yyvsp[(1) - (1)].features_slot));
	}
    break;

  case 130:
#line 1159 "rulesyacc.yy"
    {
	  DBUGPRT("feature_value");
	  (yyval.value_slot)=Value::_nil;
	}
    break;

  case 131:
#line 1165 "rulesyacc.yy"
    {
	  DBUGPRT("feature_value");
	  (yyval.value_slot)=Value::_true;
	}
    break;

  case 132:
#line 1173 "rulesyacc.yy"
    {
	  DBUGPRT("constants");
	  (yyval.bits_slot)=(yyvsp[(1) - (1)].bits_slot);
	}
    break;

  case 133:
#line 1179 "rulesyacc.yy"
    {
	  DBUGPRT("constants");
	  (yyval.bits_slot)=(yyvsp[(3) - (3)].bits_slot);
	  *(yyval.bits_slot) |= *(yyvsp[(1) - (3)].bits_slot);
	}
    break;

  case 134:
#line 1187 "rulesyacc.yy"
    {
	  DBUGPRT("identifier");
 	  (yyval.bits_slot)=varTableAdd(*(yyvsp[(1) - (1)].string_slot));
	}
    break;

  case 135:
#line 1194 "rulesyacc.yy"
    {
	  DBUGPRT("variable");
 	  ostringstream oss;
	  oss << *(yyvsp[(1) - (1)].string_slot);
  	  string str = oss.str();
	  (yyval.bits_slot)=varTableAdd(str);
	}
    break;

  case 136:
#line 1204 "rulesyacc.yy"
    {
	  DBUGPRT("list");
	  (yyval.list_slot)=(yyvsp[(2) - (3)].list_slot);
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
    break;

  case 137:
#line 1223 "rulesyacc.yy"
    {
	  DBUGPRT("list");
	  (yyval.list_slot)=List::nil;
	}
    break;

  case 138:
#line 1229 "rulesyacc.yy"
    {
	  DBUGPRT("list");
	  (yyval.list_slot)=new List((yyvsp[(2) - (5)].list_slot), (yyvsp[(4) - (5)].list_slot));
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
    break;

  case 139:
#line 1250 "rulesyacc.yy"
    {
	  DBUGPRT("list_components");
	  (yyval.list_slot)=new List((yyvsp[(1) - (3)].list_slot), (yyvsp[(3) - (3)].list_slot));
	}
    break;

  case 140:
#line 1256 "rulesyacc.yy"
    {
	  DBUGPRT("list_components");
	  (yyval.list_slot)=new List((yyvsp[(1) - (1)].list_slot), List::nil);
	}
    break;

  case 141:
#line 1264 "rulesyacc.yy"
    {
	  DBUGPRT("list_element");
	  (yyval.list_slot)=new List(new Value((yyvsp[(1) - (1)].bits_slot), Value::VARIABLE));
	}
    break;

  case 142:
#line 1270 "rulesyacc.yy"
    {
	  DBUGPRT("list_element");
	  (yyval.list_slot)=new List(new Value((yyvsp[(1) - (1)].bits_slot), Value::CONSTANT));
	}
    break;

  case 143:
#line 1276 "rulesyacc.yy"
    {
	  DBUGPRT("list_element");
	  (yyval.list_slot)=new List(new Value((yyvsp[(1) - (1)].features_slot)));
	}
    break;

  case 144:
#line 1282 "rulesyacc.yy"
    {
	  DBUGPRT("list_element");
	  (yyval.list_slot)=(yyvsp[(1) - (1)].list_slot);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 3239 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1288 "rulesyacc.yy"


