CC		= g++

OPATH	= ../obj
OTFPATH	= ../obj/transfer-functions

LFLAG	= $(CC) -std=c++11 -shared -fPIC

LFILE	= libAeroSW.so
VFILE	= libAeroSW.so.0.0.2

NNET	= $(OPATH)/Matrix.o
TFUNCS	= $(OTFPATH)/FunctionHandler.o $(OTFPATH)/HyperbolicTangentFunction.o $(OTFPATH)/SigmoidFunction.o

DEPEND	= $(TFUNCS) $(NNET)

default	: make_lib

make_lib:	$(DEPEND)
	$(LFLAG) -o $(LFILE) $(DEPEND)
	
$(OTFPATH)/FunctionHandler.o	:
	cd ../obj && $(MAKE) tfuncs

$(OTFPATH)/HyperbolicTangentFunction.o	:
	cd ../obj && $(MAKE) tfuncs

$(OTFPATH)/SigmoidFunction.o	:
	cd ../obj && $(MAKE) tfuncs

$(OPATH)/Matrix.o	:
	cd ../obj && $(MAKE) objs
	
clean	:
	$(RM) *.so