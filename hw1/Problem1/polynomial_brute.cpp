#include <cmath>
#include <cstdio>
double slowPow(double x, int n) {
	double res(1);
	for (int i = 0; i < n; ++ i) {
		res *= x;
	}
	return res;
}
double polynomial(int n, double* a, double x) {
	double result(0);
	for (int i = n - 1; i >= 0; -- i) {
		result += a[i] * slowPow(x, i);
	}
	return result;
}

