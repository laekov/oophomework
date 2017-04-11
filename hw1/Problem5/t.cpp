#include <iostream>
#include "t.h"

T::T() {
	this->a = 1;
	this->b = 2;
	this->c = 3;
	this->d = 4;
}

template <class O>
void coute(O c) {
	std::cout.width(16);
	std::cout.setf(std::ios::left);
	std::cout << c;
}

void T::showMap() {
	coute("Name");
	coute("Value");
	coute("Address");
	coute("Size");
	std::cout << std::endl;
	coute("this");
	coute("...");
	coute((unsigned long long)this);
	coute(sizeof(*this));
	std::cout << std::endl;
	coute("a");
	coute(this->a);
	coute((unsigned long long)&this->a);
	coute(sizeof(this->a));
	std::cout << std::endl;
	coute("e");
	coute(this->e);
	coute((unsigned long long)&this->e);
	coute(sizeof(this->e));
	std::cout << std::endl;
	coute("b");
	coute(this->b);
	coute((unsigned long long)&this->b);
	coute(sizeof(this->b));
	std::cout << std::endl;
	coute("c");
	coute(this->c);
	coute((unsigned long long)&this->c);
	coute(sizeof(this->c));
	std::cout << std::endl;
	coute("d");
	coute(this->d);
	coute((unsigned long long)&this->d);
	coute(sizeof(this->d));
	std::cout << std::endl;
}

int main() {
	T t;
	t.showMap();
}
