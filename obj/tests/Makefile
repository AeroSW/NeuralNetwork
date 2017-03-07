CC		= g++

HEADERS	= -I../../include -I../../include/transfer-functions

CFLAGS	= $(CC) -std=c++11 $(HEADERS) -c

MPATH	= ../../src/tests
IPATH	= ../../include
ITFPATH	= ../../include/transfer-functions
TFPATH	= ../../src/transfer-functions
FILES	= FunctionTest.o
default	:	$(FILES)

FunctionTest.o	: $(ITFPATH)/FunctionHandler.h $(MPATH)/FunctionTest.cpp
	$(CFLAGS) $(MPATH)/FunctionTest.cpp