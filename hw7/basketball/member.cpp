#include <iostream>
#include "member.h"

void Member::printInfo() const {
	std::cout << "Name: " << this->name << "\nAge: " << this->age << std::endl;
}
