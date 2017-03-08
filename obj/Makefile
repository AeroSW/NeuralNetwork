CC		= g++

IPATH	= ../include
ITFPATH	= ../include/transfer-functions

HEADERS	= -I$(IPATH) -I$(ITFPATH)

CFLAGS	= $(CC) -std=c++11 $(HEADERS) -fopenmp -c -fPIC

MPATH	= ../src
TFPATH	= ../src/transfer-functions

FILES	= Matrix.o

default	: tfuncs tests objs

tfuncs	:
	cd transfer-functions && $(MAKE)

testfiles	:
	cd tests && $(MAKE)

objs	: $(FILES)

Matrix.o	:	$(MPATH)/Matrix.cpp $(IPATH)/TypeDefs.h
	$(CFLAGS) -o Matrix.o $(MPATH)/Matrix.cpp
	
clean		:
	$(RM) *.o
	cd ./transfer-functions && $(MAKE) clean
	cd ./tests && $(MAKE) clean