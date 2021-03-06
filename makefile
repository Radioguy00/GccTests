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
CXXFLAGS = -O2 -std=gnu++0x -I$(IDIR)
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

thread_test: $(OBJ_BT)
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

############ Standard C++ threads

_OBJ_ST = stl_thread.o
OBJ_ST = $(patsubst %, $(OBJDIR)/%, $(_OBJ_ST))

stl_thread: $(OBJ_ST)
	$(CC) -g -L $(LIBDIR) -o $@ $^ $(LINKFLAGS) $(LIBS)  
	
	
############ Standard C++ clocks

_OBJ_CL = clock_test.o
OBJ_CL = $(patsubst %, $(OBJDIR)/%, $(_OBJ_CL))

clock_test: $(OBJ_CL)
	$(CC) -g -L $(LIBDIR) -o $@ $^ $(LINKFLAGS) $(LIBS)  -lrt
	
	
############ Ncurses

_OBJ_CUR = ncurses_test.o
OBJ_CUR = $(patsubst %, $(OBJDIR)/%, $(_OBJ_CUR))

ncurses_test: $(OBJ_CUR)
	$(CC) -g -L $(LIBDIR) -o $@ $^ $(LINKFLAGS) $(LIBS)  -lncurses	

############ Menu

_OBJ_MEN = menu_test.o
OBJ_MEN = $(patsubst %, $(OBJDIR)/%, $(_OBJ_MEN))

menu_test: $(OBJ_MEN)
	$(CC) -g -L $(LIBDIR) -o $@ $^ $(LINKFLAGS) $(LIBS)  -lncurses	-lmenu

############ Menu2 (menu in a specified window)

_OBJ_MEN2 = menu_test2.o
OBJ_MEN2 = $(patsubst %, $(OBJDIR)/%, $(_OBJ_MEN2))

menu_test2: $(OBJ_MEN2)
	$(CC) -g -L $(LIBDIR) -o $@ $^ $(LINKFLAGS) $(LIBS)  -lncurses	-lmenu

############ Menu3 (menu in a specified window)

_OBJ_MEN3 = menu_test3.o
OBJ_MEN3 = $(patsubst %, $(OBJDIR)/%, $(_OBJ_MEN3))

menu_test3: $(OBJ_MEN3)
	$(CC) -g -L $(LIBDIR) -o $@ $^ $(LINKFLAGS) $(LIBS)  -lncurses	-lmenu

############ Menu4 (menu in a specified window)

_OBJ_MEN4 = menu_test4.o
OBJ_MEN4 = $(patsubst %, $(OBJDIR)/%, $(_OBJ_MEN4))

menu_test4: $(OBJ_MEN4)
	$(CC) -g -L $(LIBDIR) -o $@ $^ $(LINKFLAGS) $(LIBS)  -lncurses	-lmenu



.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o *~
