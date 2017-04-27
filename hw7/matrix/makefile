cc = g++ -g -Wall -Wextra -Wconversion

main : main.cpp matrix.o restrictions
	$(cc) main.cpp Matrix.o -o main

matrix.o : Matrix.cpp Matrix.h restrictions
	$(cc) Matrix.cpp -c -o Matrix.o

restrictions : restrictions.cpp
	$(cc) restrictions.cpp -c -o restrictions

clean : 
	rm -rf *.o *.dSYM main restrictions
