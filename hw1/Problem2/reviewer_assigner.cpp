#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include "reviewer_assigner.h"

void ReviewerAssigner::choose() {
	srand(time(0));
	if (this->list.size() < 4) {
		throw TOO_FEW_RESIGNERS;
	}
	for (unsigned i = 0; i < this->list.size(); ++ i) {
		std::set<unsigned> cho;
		for (unsigned j = 0; j < 3; ++ j) {
			unsigned id;
			do {
				id = (unsigned)rand() % this->list.size();
			} while (id == i || cho.find(id) != cho.end());
			cho.insert(id);
		}
		this->res.push_back(cho);
	}
}

void ReviewerAssigner::output() {
	std::ofstream ouf("reviewer.txt");
	for (unsigned i = 0; i < this->list.size(); ++ i) {
		ouf << this->list[i] << ": " << std::endl;
		for (std::set<unsigned>::iterator it = this->res[i].begin(); it != this->res[i].end(); ++ it) {
			ouf << "\t" << this->list[*it] << std::endl;
		}
	}
	ouf.close();
}

