#include "hen.h"
#include <iostream>
#include <cstdlib>

Hen::Hen() {
	this->id = rand() % MAX_ID;
}

Hen::Nest::Nest() {
	this->id = rand() % MAX_ID;
}

Hen::Nest::Egg::Egg() {
	this->id = rand() % MAX_ID;
}

void Hen::Nest::Egg::display() {
	std::cout << this->id << "\t";
}

void Hen::Nest::lay() {
	this->eggs.push_back(Hen::Nest::Egg());
}

void Hen::Nest::display() {
	std::cout << "\tNest: " << this->id << std::endl;
	std::cout << "\t\tEggs: ";
	for (std::vector<Hen::Nest::Egg>::iterator it = this->eggs.begin(); it != this->eggs.end(); ++ it) {
		it->display();
	}
	std::cout << std::endl;
}

void Hen::build() {
	this->nests.push_back(Hen::Nest());
}

void Hen::lay(int nestId, int count) {
	if (nestId >= this->nests.size()) {
		throw BAD_ID;
	}
	for (int i = 0; i < count; ++ i) {
		this->nests[nestId].lay();
	}
}

void Hen::display() {
	std::cout << "Hen: " << this->id << std::endl;
	for (std::vector<Hen::Nest>::iterator it = this->nests.begin(); it != this->nests.end(); ++ it) {
		it->display();
	}
}
