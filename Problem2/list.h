#ifndef LIST_H
#define LIST_H
#include <vector>
#include <string>
#include <set>

const size_t MAX_LINE_LEN = 1 << 16;

std::vector<std::string> readEmailList();

class StudentList {
	public:
		void load();
	protected:
		std::vector<std::string> list;
		std::vector<std::set<unsigned> > res;
};
#endif
