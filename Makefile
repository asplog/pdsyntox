CC=gcc
CXX=g++
CFLAGS=-I./inc -Itmp/syntox-2.6.1/src -O2 -pipe -march=native -DMAXLENGTHDEFAULT=512 -DMAXUSAGESDEFAULT=512
CXXFLAGS=
LDFLAGS=
LIB=

run: lib/pdsyntox.pd_linux
	pd -path ./lib ./var/test.pd
clean:
	rm obj/*
lib/pdsyntox.pd_linux: obj/pdsyntox.opp tmp/syntox-2.6.1/src/bits.o tmp/syntox-2.6.1/src/buildlexiconmain.o tmp/syntox-2.6.1/src/buildlexicon.o tmp/syntox-2.6.1/src/colors.o tmp/syntox-2.6.1/src/entries.o tmp/syntox-2.6.1/src/entry.o tmp/syntox-2.6.1/src/enum.o tmp/syntox-2.6.1/src/environment.o tmp/syntox-2.6.1/src/errors.o tmp/syntox-2.6.1/src/feature.o tmp/syntox-2.6.1/src/features.o tmp/syntox-2.6.1/src/flags.o tmp/syntox-2.6.1/src/forestIdentifier.o tmp/syntox-2.6.1/src/forest.o tmp/syntox-2.6.1/src/gitem.o tmp/syntox-2.6.1/src/gitemset.o tmp/syntox-2.6.1/src/grammar.o tmp/syntox-2.6.1/src/io.o tmp/syntox-2.6.1/src/item.o tmp/syntox-2.6.1/src/list.o tmp/syntox-2.6.1/src/node.o tmp/syntox-2.6.1/src/rule.o tmp/syntox-2.6.1/src/ruleslex.o tmp/syntox-2.6.1/src/rulesyacc.o tmp/syntox-2.6.1/src/statement.o tmp/syntox-2.6.1/src/statements.o tmp/syntox-2.6.1/src/synthesizer.o tmp/syntox-2.6.1/src/term.o tmp/syntox-2.6.1/src/terms.o tmp/syntox-2.6.1/src/value.o tmp/syntox-2.6.1/src/vartable.o 
	$(CC) $(CFLAGS) $(LDFLAGS) --shared -o $@ $^ $(LIB)


obj/pdsyntox.opp: src/pdsyntox.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<


