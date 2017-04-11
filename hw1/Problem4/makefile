cc = g++ -g

main : main.cpp hen.o
	g++ hen.o main.cpp -o main

hen.o : hen.cpp hen.h
	g++ hen.cpp -c -o hen.o

clean : 
	rm -rf *.o main *.dSYM

