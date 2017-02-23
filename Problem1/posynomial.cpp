#include "func.h"
#include <cmath>

double posynomial(int n, double* a, double x) {
	if (fabs(x) < eps && n > 1) {
		throw ERROR_X;
	}
	return polynomial(n, a, 1.0 / x);
}
