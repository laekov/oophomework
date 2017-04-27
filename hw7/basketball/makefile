cc = g++ -g

main : main.cpp member.o restrictions
	$(cc) main.cpp member.o -o main

member.o : member.cpp member.h restrictions
	$(cc) member.cpp -c -o member.o

restrictions : restrictions.cpp
	$(cc) restrictions.cpp -c -o restrictions

clean : 
	rm -rf *.o *.dSYM main restrictions
