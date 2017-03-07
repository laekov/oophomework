cc = g++ -g

all : bin/main bin/brute bin/timer

bin/timer : timer.cpp bin
	$(cc) timer.cpp -o bin/timer

bin/brute : main.cpp func.h bin/posynomial.o bin/polynomial_brute.o bin
	$(cc) main.cpp bin/posynomial.o bin/polynomial_brute.o -o bin/brute

bin/main : main.cpp func.h bin/posynomial.o bin/polynomial.o bin
	$(cc) main.cpp bin/posynomial.o bin/polynomial.o -o bin/main

bin/polynomial.o : func.h polynomial.cpp bin
	$(cc) polynomial.cpp -c -o bin/polynomial.o

bin/polynomial_brute.o : func.h polynomial_brute.cpp bin
	$(cc) polynomial_brute.cpp -c -o bin/polynomial_brute.o

bin/posynomial.o : func.h posynomial.cpp bin
	$(cc) posynomial.cpp -c -o bin/posynomial.o

bin : 
	mkdir -p bin

clean :
	rm -rf bin
