CC=gcc
CXX=g++
CFLAGS=-I./inc -I/src -O2 -pipe -march=native -DMAXLENGTHDEFAULT=512 -DMAXUSAGESDEFAULT=512
CXXFLAGS=
LDFLAGS=
LIB=

run: lib/pdsyntox.pd_linux
	pd -path ./lib ./var/example.pd
clean:
	rm obj/*
lib/pdsyntox.pd_linux: obj/pdsyntox.o 
	$(CC) $(CFLAGS) $(LDFLAGS) --shared -o $@ $^ $(LIB)


obj/pdsyntox.o: src/pdsyntox.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<


