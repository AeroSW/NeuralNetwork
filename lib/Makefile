CC		= g++

OPATH	= ../obj
OTFPATH	= ../obj/transfer-functions

LFLAG	= $(CC) -std=c++11 -shared

LFILE	= libtfuncs.so
VFILE	= libtfuncs.so.1.0.1

TFUNCS	= $(OTFPATH)/FunctionHandler.o $(OTFPATH)/HyperbolicTangentFunction.o $(OTFPATH)/SigmoidFunction.o

DEPEND	= $(TFUNCS)

default	: make_lib

make_lib:	$(DEPEND)
	$(LFLAG) -shared -o $(LFILE) $(TFUNCS)
	
$(OTFPATH)/FunctionHandler.o	:
	cd ../obj/transfer-functions && $(MAKE)

$(OTFPATH)/HyperbolicTangentFunction.o	:
	cd ../obj/transfer-functions && $(MAKE)

$(OTFPATH)/SigmoidFunction.o	:
	cd ../obj/transfer-functions && $(MAKE)