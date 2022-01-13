WALL= -Wall -g
CC=gcc

all:stringProg
stringProg: main.o libclassfunc.a algo.o nodes.o edges.o
	$(CC) $(WALL) -o stringProg main.o algo.o nodes.o edges.o

libclassfunc.a:algo.o
	ar -rcs libclassfunc.a algo.o 
main.o:main.c algo.o graph.h 
	$(CC) $(WALL) -c main.c 
algo.o:algo.c algo.h graph.h 
	$(CC) $(WALL) -c algo.c
edges.o:edges.c edges.h graph.h
	$(CC) $(WALL) -c edges.c 
nodes.o:nodes.c nodes.h graph.h
	$(CC) $(WALL) -c nodes.c

	
clean: 
	rm -f *.o *.a ./stringProg
