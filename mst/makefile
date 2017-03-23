cc = g++ -g
executables = main

default : main

exec : main
	./main

main : main.cpp graph.o mst.o 
	g++ main.cpp graph.o mst.o -o main

mst.o  : graph.h mst.h mst.cpp
	g++ mst.cpp -c -o mst.o

graph.o : graph.cpp graph.h
	g++ graph.cpp -c -o graph.o

clean :
	rm *.o $(executables)

