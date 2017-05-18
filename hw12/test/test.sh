ln -s $(pwd)/bin/main $(pwd)/test/main
cd test
for ((seed=0;seed<10;++seed))
do
	echo Testing seed = $seed
	echo Running KMP
	time ./main -p KMP -c 10 -l 20 -s $seed 1.cc 2.cc 3.cc 4.cc. 5.cc 6.cc 7.cc 8.cc [>kmp.out
	echo Running KR
	time ./main -p KR -c 10 -l 20 -s $seed 1.cc 2.cc 3.cc 4.cc. 5.cc 6.cc 7.cc 8.cc [>kr.out
	diff kmp.out kr.out
	if [ $? != 0 ]; then
		echo Error when processing $seed
	else
		echo Result checked
	fi
	rm kmp.out kr.out
done
cd ..
rm test/main

