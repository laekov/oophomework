cc1 = clang	# clang iostream is broken on my computer
cc2 = g++

all : cgpp

cgpp : t.h t.cpp
	$(cc2) t.cpp -o main
	./main >output_gpp

cclang : t.h t.cpp
	$(cc1) t.cpp -o main
	./main >output_clang

clean :
	rm -rf main *.dSYM

