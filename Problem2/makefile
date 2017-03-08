cc = g++ -g
executables = reviewer_assigner team_assigner

all : $(executables)

team_assigner : team_assigner.h team_assigner.cpp team_assigner_main.cpp list.o
	$(cc) team_assigner.cpp team_assigner_main.cpp list.o -o team_assigner

reviewer_assigner : reviewer_assigner.h reviewer_assigner.cpp reviewer_assigner_main.cpp list.o
	$(cc) reviewer_assigner.cpp reviewer_assigner_main.cpp list.o -o reviewer_assigner

list.o : list.h list.cpp
	$(cc) list.cpp -c -o list.o

clean : 
	rm -rf *.o $(executables) *.dSYM
