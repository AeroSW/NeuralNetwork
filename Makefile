CC		= g++
EXE		= test

EFLAGS	= $(CC) -std=c++11 -o $(EXE)

INC		= ./include ./include/transfer-functions
LIBPATH	= -L./lib

TPATH	= ./obj/tests

default	: c_all

c_all	:
	cd lib && $(MAKE)
	cd obj && $(MAKE) testfiles
	
clean	:
	cd lib && $(MAKE) clean
	cd obj && $(MAKE) clean
	
tfunc_test	:
	$(EFLAGS) $(TPATH)/FunctionTest.o $(LIBPATH) -lAeroSW
	
matrix_test	:
	$(EFLAGS) $(TPATH)/MatrixTest.o $(LIBPATH) -lAeroSW -fopenmp
	
neuron_test	:
	$(EFLAGS) $(TPATH)/NeuronTest.o $(LIBPATH) -lAeroSW -fopenmp