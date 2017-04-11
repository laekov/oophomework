cc = g++ -g

main : main.cpp video.o
	g++ video.o main.cpp -o main

video.o : video.cpp video.h
	g++ video.cpp -c -o video.o

clean : 
	rm -rf *.o main *.dSYM

