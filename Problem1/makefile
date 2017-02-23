cc = g++ -g

bin/main : main.cpp func.h bin/posynomial.o bin/polynomial.o bin
	$(cc) main.cpp bin/posynomial.o bin/polynomial.o -o bin/main

bin/polynomial.o : func.h polynomial.cpp bin
	$(cc) polynomial.cpp -c -o bin/polynomial.o

bin/posynomial.o : func.h posynomial.cpp bin
	$(cc) posynomial.cpp -c -o bin/posynomial.o

bin : 
	mkdir -p bin

clean :
	rm -rf bin
