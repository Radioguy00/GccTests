#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# g++ -L /usr/lib -l uhd -o e100test test_routines.cpp
# g++ -g -L /usr/lib -l uhd -o rxtest  receiver_test.cpp uhd_utilities.cpp
# g++ -g -L /usr/lib -l uhd -o serial_port_test serial_port_test.cpp
# g++ -pthread -o thread_test thread_test.cpp

# g : Indicates debug mode
# c : Indicates compilation only

IDIR =.
CC =g++
CXXFLAGS = -std=gnu++0x -I$(IDIR)
LINKFLAGS =

OBJDIR = obj
LIBDIR = /usr/lib

LIBS= -lpthread

$(OBJDIR)/%.o:%.cpp 
	$(CC) -c -o $@ $< $(CXXFLAGS)

############### INTEGER FLOAT SPEED COMPARISON

_OBJ_IFSC = float_integer_speed.o
OBJ_IFSC = $(patsubst %, $(OBJDIR)/%, $(_OBJ_IFSC))

float_integer_speed:$(OBJ_IFSC) 	
	$(CC) -g -L $(LIBDIR)  -o $@ $^  $(LINKFLAGS) $(LIBS)

################ SERIAL PORT TEST

_OBJ_SP = serial_port_test.o
OBJ_SP = $(patsubst %, $(OBJDIR)/%, $(_OBJ_SP))

serial_port: $(OBJ_SP)
	$(CC) -g -L $(LIBDIR)  -o $@ $^  $(LINKFLAGS) $(LIBS)

############### BASIC THREAD TEST

_OBJ_BT = thread_test.o
OBJ_BT = $(patsubst %, $(OBJDIR)/%, $(_OBJ_BT))

thread: $(OBJ_BT)
	$(CC) -g -L $(LIBDIR)  -o $@ $^  $(LINKFLAGS) $(LIBS)

############## THREAD JOIN TEST

_OBJ_TJ = thread_join_test.o
OBJ_TJ = $(patsubst %, $(OBJDIR)/%, $(_OBJ_TJ))

thread_join: $(OBJ_TJ)
	$(CC) -g -L $(LIBDIR)  -o $@ $^  $(LINKFLAGS) $(LIBS)

############# THREAD CONDITION TEST

_OBJ_TC = thread_cond_test.o
OBJ_TC= $(patsubst %, $(OBJDIR)/%, $(_OBJ_TC))

thread_cond: $(OBJ_TC) 	
	$(CC) -g -L $(LIBDIR)  -o $@ $^  $(LINKFLAGS) $(LIBS)
	
############# COMPLEX_INTEGER

_OBJ_CI = complex_integer.o
OBJ_CI = $(patsubst %, $(OBJDIR)/%, $(_OBJ_CI))

complex_integer: $(OBJ_CI) 	
	$(CC) -g -L $(LIBDIR)  -o $@ $^  $(LINKFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o *~
