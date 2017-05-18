#include <matcher.h>

#include <string>

using std::string;

void Matcher::init(const string&) {
	throw -1;
}
void Matcher::reset() {
	throw -1;
}
bool Matcher::nextChar(char) {
	throw -1;
}

bool Matcher::matchString(string str) {
	bool result(0);
	for (string::iterator it = str.begin(); it != str.end(); ++ it) {
		result |= this->nextChar(*it);
	}
	return result;
}
