GCC = gcc
CFLAGS = -g -Wall -Wshadow



#set up the executable to update if necessary
runMe: Driver.o 
	$(GCC) $(CFLAGS) factorial.o Test3.o -o runMe

# set up the factorial.o to update if changes were made
Driver.o: Driver.c
	$(GCC) $(CFLAGS) -c Driver.c

# add other dependenceis here

# execute our program
run: runMe
	./runMe
