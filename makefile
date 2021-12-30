CC = gcc
FLAGS = -Wall -g
AR = ar

# make all
all: graph

graph: main.o edge.o node.o
	$(CC) $(FLAGS) -o graph main.o edge.o node.o

# make o
main.o: main.c listnode.h
	$(CC) $(FLAGS) -c main.c


edge.o: edge.c listnode.h
	$(CC) $(FLAGS) -c edge.c


node.o: node.c listnode.h listedge.h
	$(CC) $(FLAGS) -c node.c





.phony: clean

clean:
	rm -f *.o *.a *.so graph
