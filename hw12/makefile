cc = g++ -Iinclude -g
requ = obj/restrict.o
matchero = obj/kmp.o obj/kr.o obj/matcher.o
matchers = kmp kr 
default : mkdir bin/main
test :  default test/test.sh testdatacheck $(requ)
	bash test/test.sh
testdatacheck : test/1.cc
testdata : $(requ)
	bash test/init.sh
bin/main : src/main.cpp $(matchero) obj/creator.o $(requ)
	$(cc) src/main.cpp $(matchero) obj/creator.o -o bin/main
obj/creator.o : src/creator.cpp $(requ)
	$(cc) src/creator.cpp -c -o obj/creator.o
obj/kmp.o : src/kmp.cpp $(requ)
	$(cc) src/kmp.cpp -c -o obj/kmp.o
obj/kr.o : src/kr.cpp $(requ)
	$(cc) src/kr.cpp -c -o obj/kr.o
obj/matcher.o : src/matcher.cpp $(requ)
	$(cc) src/matcher.cpp -c -o obj/matcher.o
$(requ) : src/restrict.cpp 
	$(cc) src/restrict.cpp -c -o obj/restrict.o
mkdir : 
	@ if [ ! -d obj ]; then mkdir obj; fi
	@ if [ ! -d bin ]; then mkdir bin; fi
clean : 
	rm -rf obj bin
