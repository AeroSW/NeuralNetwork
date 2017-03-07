CC		= g++
EXE		= test

EFLAGS	= $(CC) -std=c++11 -o $(EXE)

INC		= ./include ./include/transfer-functions
LIBPATH	= -L./lib/tfuncs

default	: c_all

c_all	:
	cd lib && $(MAKE)
	cd obj && $(MAKE) tests
	
clean	:
	cd lib && $(MAKE) clean
	cd obj && $(MAKE) clean
	
tfunc_test	:
	$(EFLAGS) $(LIBPATH) -ltfuncs