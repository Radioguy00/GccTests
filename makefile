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



serial_port: serial_port_test.o
	g++ -L /usr/lib  -o serial_port.out serial_port_test.cpp

# Multiple threads are created without join
thread: thread_test.o
	g++ -L /usr/lib  -lpthread -o thread_test.out thread_test.cpp

thread_join: thread_join_test.o
	g++ -g -L /usr/lib  -lpthread -o thread_join_test.out thread_join_test.cpp
	
thread_cond: thread_cond_test.o 	
	g++ -g -L /usr/lib  -lpthread -o thread_cond_test.out thread_cond_test.cpp
	
clean:
	rm *.o
