#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include "team_assigner.h"

void TeamAssigner::assign() {
	srand(time(0));
	if (this->list.size() < 2) {
		throw TOO_FEW_STUDENTS;
	}
	std::random_shuffle(this->list.begin(), this->list.end());
	for (unsigned i = 0, j; i < this->list.size();) {
		j = this->list.size();
		if (j - i > 4) { 
			j = i + 3;
		}
		std::set<unsigned> cho;
		for (; i < j; ++ i) {
			cho.insert(i);
		}
		this->res.push_back(cho);
	}
}

void TeamAssigner::output() {
	std::ofstream ouf("team.txt");
	for (unsigned i = 0; i < this->res.size(); ++ i) {
		for (std::set<unsigned>::iterator it = this->res[i].begin(); it != this->res[i].end(); ++ it) {
			ouf << this->list[*it] << "\t";
		}
		ouf << std::endl;
	}
	ouf.close();
}

