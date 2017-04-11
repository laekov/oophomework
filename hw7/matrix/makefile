cc = g++ -g

main : main.cpp matrix.o 
	$(cc) main.cpp Matrix.o -o main

matrix.o : Matrix.cpp Matrix.h
	$(cc) Matrix.cpp -c -o Matrix.o

clean : 
	rm -rf *.o *.dSYM main
