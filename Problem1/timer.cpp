#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;

unsigned long measureTime(const string cmdLine) {
	const char *c_cmdLine(cmdLine.c_str());
	unsigned long timeb(time(0));
	unsigned int callres(system(c_cmdLine));
	if (callres) {
		cerr << "Run error " << callres << endl;
	}
	return time(0) - timeb;
}

int main() {
	srand(time(0));
	int n(20000);
	static char tmp[30];
	sprintf(tmp, "%d", n);
	string args;
	args += tmp;
	for (int i = 0; i <= n; ++ i) {
		args += " ";
		sprintf(tmp, "%d", rand() % 10);
		args += tmp;
	}
	cout << "Brute time = " << measureTime(string("./brute ") + args) << " s" << endl;
	cout << "QJS time = " << measureTime(string("./main ") + args) << " s" << endl;
}
