CC = gcc
FLAGS = -Wall -g
AR = ar

# make all
all: graph

graph: main.o my_lib.a
	$(CC) $(FLAGS) -o graph main.o my_lib.a

# make o
again.o: main.c edgelist.h listnode.h
	$(CC) $(FLAGS) -c main.c


edge.o: edge.c edgelist.h listnode.h
	$(CC) $(FLAGS) -c edge.c


node.o: node.c listnode.h edgelist.h
	$(CC) $(FLAGS) -c node.c





# make lib
my_lib.a: main.o 
	$(AR) -rcs my_lib.a main.o 



.phony: clean

clean:
	rm -f *.o *.a *.so graph
