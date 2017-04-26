cc = g++ -g

all : original fixed

orginal : original.cpp
	$(cc) original.cpp -o original

fixed : fixed.cpp
	$(cc) fixed.cpp -o fixed

version : 
	g++ -v

clean : 
	rm -rf *.dSYM original fixed
