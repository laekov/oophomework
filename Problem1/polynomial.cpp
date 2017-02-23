#include <cstdio>
double polynomial(int n, double* a, double x) {
	double result(0);
	for (int i = n - 1; i >= 0; -- i) {
		result = result * x + a[i];
	}
	return result;
}

