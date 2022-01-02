CC = gcc
FLAGS = -Wall -g
AR = ar

# # make all
# all: graph

# graph: main.o
# 	$(CC) $(FLAGS) -o graph main.o


# make o

algo.o: algo.c graph.h
	$(CC) $(FLAGS) -c algo.c


edge.o: edge.c graph.h
	$(CC) $(FLAGS) -c edge.c


node.o: node.c graph.h
	$(CC) $(FLAGS) -c node.c


main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c



# make all
all: graph

graph: main.o
	$(CC) $(FLAGS) -o graph main.o




.phony: clean

clean:
	rm -f *.o *.a *.so graph
