CC		= g++

HEADERS	= -I../../include -I../../include/transfer-functions

CFLAGS	= $(CC) -std=c++11 $(HEADERS) -c

MPATH	= ../../src/tests
IPATH	= ../../include
ITFPATH	= ../../include/transfer-functions
TFPATH	= ../../src/transfer-functions
FILES	= FunctionTest.o MatrixTest.o NeuronTest.o
default	:	$(FILES)

FunctionTest.o	: $(ITFPATH)/FunctionHandler.h $(MPATH)/FunctionTest.cpp
	$(CFLAGS) $(MPATH)/FunctionTest.cpp
	
MatrixTest.o	: $(IPATH)/Matrix.h $(IPATH)/TypeDefs.h $(MPATH)/MatrixTest.cpp
	$(CFLAGS) $(MPATH)/MatrixTest.cpp
	
NeuronTest.o	: $(IPATH)/Neuron.h $(IPATH)/Matrix.h $(MPATH)/NeuronTest.cpp
	$(CFLAGS) $(MPATH)/NeuronTest.cpp
	
clean	:
	$(RM) *.o