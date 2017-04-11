cc = g++ -g

main : main.cpp member.o 
	$(cc) main.cpp member.o -o main

member.o : member.cpp member.h
	$(cc) member.cpp -c -o member.o

clean : 
	rm -rf *.o *.dSYM main
