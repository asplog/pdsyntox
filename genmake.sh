#!/usr/bin/env bash
rm *~
for DIR in `ls`
do
	if [ -d $DIR ];
	then
		rm $DIR/*~
	fi
done
SYNTOX=$1

TARGET='run: lib/pdsyntox.pd_linux\n\tpd -path ./lib ./var/example.pd\n'
SOURCE=`ls src`
OBJECT=''

COMPILE='$(CXX) $(CFLAGS) -c -o $@ $<\n'
LINK='$(CC) $(CFLAGS) $(LDFLAGS) --shared -o $@ $^ $(LIB)\n'

HEAD=''
BODY=''

HEAD+="CC=gcc\n"
HEAD+="CXX=g++\n"
HEAD+="CFLAGS=-I./inc -I${SYNTOX}/src -O2 -pipe -march=native -DMAXLENGTHDEFAULT=512 -DMAXUSAGESDEFAULT=512\n"
HEAD+="CXXFLAGS=${CXXFLAGS}\n"
HEAD+="LDFLAGS=\n"
HEAD+="LIB=\n"

TARGET+='clean:\n\trm obj/*\nlib/pdsyntox.pd_linux: '
for FILE in ${SOURCE}
do
	SRC="src/${FILE}"
	OBJ="obj/${FILE/.cpp/.o}"
	TARGET+="${OBJ} "
	BODY+="${OBJ}: ${SRC}\n\t${COMPILE}\n" 
done
for FILE in `ls ${SYNTOX}/src/*o`
do
	if [ `basename ${FILE}` != "main.o" ];
	then
		TARGET+="${FILE} "
	fi
done
TARGET+="\n\t${LINK}\n"
echo -e "${HEAD}\n${TARGET}\n${BODY}"
