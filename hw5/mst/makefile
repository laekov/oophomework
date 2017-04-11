cc = g++ -g
executables = main

default : main

test : main
	./main
	./main 10
	./main 5 3
	./main 20 20

main : main.cpp graph.o mst.o tree.o dset.o
	g++ main.cpp graph.o mst.o tree.o dset.o -o main

mst.o  : graph.h mst.h tree.h dset.h mst.cpp 
	g++ mst.cpp -c -o mst.o

tree.o : dset.h tree.h tree.cpp
	g++ tree.cpp -c -o tree.o

graph.o : graph.h graph.cpp
	g++ graph.cpp -c -o graph.o

dset.o : dset.h dset.cpp
	g++ dset.cpp -c -o dset.o

clean :
	rm *.o $(executables)

