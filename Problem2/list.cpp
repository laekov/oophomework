#include <fstream>
#include <string>
#include <vector>
#include "list.h"

void StudentList::load() {
	std::ifstream fin("ContactEmail.txt");
	std::string id, email;
	while (fin >> id >> email) {
		this->list.push_back(id + " " + email);
	}
	fin.close();
}
