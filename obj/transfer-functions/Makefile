CC		= g++

HEADERS	= -I../../include -I../../include/transfer-functions

IPATH	= ../../include
ITFPATH	= ../../include/transfer-functions

CFLAGS	= $(CC) -std=c++11 $(HEADERS) -c -fPIC

MPATH	= ../../src/transfer-functions
FILES	= FunctionHandler.o HyperbolicTangentFunction.o SigmoidFunction.o
default	:	$(FILES)

FunctionHandler.o:	$(MPATH)/FunctionHandler.cpp $(ITFPATH)/FunctionHandler.h $(ITFPATH)/TransferFunctionIncludes.h
	$(CFLAGS) -o FunctionHandler.o $(MPATH)/FunctionHandler.cpp

HyperbolicTangentFunction.o:	$(MPATH)/HyperbolicTangentFunction.cpp $(ITFPATH)/HyperbolicTangentFunction.h $(ITFPATH)/TransferFunction.h
	$(CFLAGS) -o HyperbolicTangentFunction.o $(MPATH)/HyperbolicTangentFunction.cpp
	
SigmoidFunction.o:	$(MPATH)/SigmoidFunction.cpp $(ITFPATH)/SigmoidFunction.h $(ITFPATH)/TransferFunction.h
	$(CFLAGS) -o SigmoidFunction.o $(MPATH)/SigmoidFunction.cpp

clean:
	$(RM) *.o