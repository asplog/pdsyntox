#############################################
# Reserved for the developpers
OPTIONS = 
#OPTIONS += -DOUTPUT_ITEMS_DOT
#OPTIONS += -DOUTPUT_FOREST_DOT
#OPTIONS += -DOUTPUT_STATEMENT_DOT
#OPTIONS += -DOUTPUT_XML

#############################################
# Edit THIS ...
#OPTIONS += -DTRACEALLOC
#OPTIONS += -DTRACEINIT
#OPTIONS += -DTRACESTAGE
#OPTIONS += -DTRACESPLIT
#OPTIONS += -DTRACESHIFT
#OPTIONS += -DTRACECLOSE
#OPTIONS += -DTRACEREDUCE
#OPTIONS += -DTRACEACTION

OPTIONS += -DMAXLENGTHDEFAULT=500
OPTIONS += -DMAXUSAGESDEFAULT=500

#############################################
# Do not edit the rest
AUTOMAKE_OPTIONS= foreign

bin_PROGRAMS=syntox buildlexiconmain

NAME=syntox

noinst_PROGRAMS = syntox buildlexiconmain
dist_syntox_SOURCES =\
rulesyacc.cc\
ruleslex.cc\
bits.cc\
colors.cc\
entries.cc\
entry.cc\
enum.cc\
environment.cc\
errors.cc\
feature.cc\
features.cc\
flags.cc\
forest.cc\
forestIdentifier.cc\
gitem.cc\
gitemset.cc\
grammar.cc\
io.cc\
item.cc\
list.cc\
main.cc\
node.cc\
rule.cc\
statement.cc\
statements.cc\
synthesizer.cc\
term.cc\
terms.cc\
value.cc\
vartable.cc\
buildlexicon.cc

dist_buildlexiconmain_SOURCES = buildlexicon.cc buildlexiconmain.cc  

BUILT_SOURCES = 

DIST_COMMON = Makefile.in Makefile.am

EXTRA_DIST = 	

CLEANFILES = token.cc

AM_CXXFLAGS = -DPACKAGE_NAME=\"@PACKAGE_NAME@\" -DPACKAGE_VERSION=\"@PACKAGE_VERSION@\" `@XML2_CONFIG@ --cflags` $(OPTIONS)
AM_LDFLAGS = `xml2-config --libs` 
YFLAGS = -y --defines --verbose
LFLAGS = -8
CXXFLAGS = -Wall -O5
#CXXFLAGS = -Wall -g
#CXXFLAGS = -Wall -pg

rulesyacc.cc: rulesyacc.yy
	$(YACC) $(YFLAGS) -p rules rulesyacc.yy
	mv y.tab.c rulesyacc.cc
	mv y.tab.h rulesyacc.hh 
	mv y.output rulesyacc.output

ruleslex.cc: ruleslex.ll
	flex -8 -Prules ruleslex.ll
	mv lex.rules.c ruleslex.cc

