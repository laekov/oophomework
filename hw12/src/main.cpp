#include <creator.h>

#include <cstdlib>
#include <ctime>
#include <cctype>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cerr;
using std::ifstream;
using std::string;
using std::vector;
using std::min;
using std::max;

string initArgs(int argc, char** argv, string& policy, string& source, vector<string>& targets, int& count, int& length, int& seed) {
	for (int i = 1; i < argc; ++ i) {
		string args(argv[i]);
		if (args == "-c") {
			if (++ i >= argc) {
				return "Count error";
			}
			count = atoi(argv[i]);
		} else if (args == "-l") {
			if (++ i >= argc) {
				return "Length error";
			}
			length = atoi(argv[i]);
		} else if (args == "-s") {
			if (++ i >= argc) {
				return "Seed error";
			}
			seed = atoi(argv[i]);
		} else if (args == "-p") {
			if (++ i >= argc) {
				return "Policy error";
			}
			policy = string(argv[i]);
		} else if (source == "") {
			source = args;
		} else {
			targets.push_back(args);
		}
	}
	if (source == "") {
		return "No source file";
	}
	return "OK";
}

string initSource(string fileName) {
	ifstream fin(fileName);
	char c;
	string res;
	while ((c = fin.get()) != EOF) {
		if (!isspace(c)) {
			res.push_back(c);
		}
	}
	fin.close();
	return res;
}

int matchFile(Matcher* matcher, string fileName) {
	ifstream fin(fileName);
	matcher->reset();
	int res(0);
	char c;
	while ((c = fin.get()) != EOF) {
		if (!isspace(c)) {
			res += matcher->nextChar(c);
		}
	}
	return res;
}

int main(int argc, char** argv) {
	string policy = "KMP";
	string source;
	vector<string> targets;
	int count(5), length(10), seed(0);
	string initRes = initArgs(argc, argv, policy, source, targets, count, length, seed);
	if (initRes != "OK") {
		cerr << initRes;
		cerr << "Usage: ./main -p <policy> -c <sample count> -l <sample length> -s <random seed> source target1 target2 ...\n";
		return -1;
	}
	string pattern(initSource(source));
	Matcher* matcher(createMatcher(policy));
	if (matcher == NULL) {
		cerr << "No such policy\n";
		cerr << "Supported policy: KMP, KR\n";
		return -2;
	}
	srand(seed);
	for (int iTime = 0; iTime < count; ++ iTime) {
		int begPos(rand() % pattern.length());
		int endPos(min(begPos + max(rand() % length + 1, 5), (int)pattern.length()));
		string mpattern(pattern.substr(begPos, endPos - begPos));
		matcher->init(mpattern);
		cout << "The #" << + iTime << " checking\n  Pattern: " << mpattern << "\n";
		for (vector<string>::iterator it = targets.begin(); it != targets.end(); ++ it) {
			cout << "  File: " << *it << " appear: " << matchFile(matcher, *it) << "\n";
		}
	}
}

