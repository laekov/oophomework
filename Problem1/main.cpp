#include <iostream>
#include <cstdlib>
#include "func.h"

int main(int argc, char* args[]) {
	int n = argc - 2;
	if (n <= 0) {
		std::cerr << "Too few arguments" << std::endl;
		return -1;
	}
	double* a = new double[n];
	for (int i = 0; i < n; ++ i) {
		a[i] = atof(args[i + 1]);
	}
	double x = atof(args[argc - 1]);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	std::cout << "Polynominal value = " << polynomial(n, a, x) << std::endl;
	try {
		std::cout << "Posynominal value = " << posynomial(n, a, x) << std::endl;
	} catch (unsigned error) {
		std::cerr << "Error: x = 0" << std::endl;
	}
}
