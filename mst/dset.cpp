int getRoot(int* r, int x) {
	int p, q;
	for (p = x; p ^ r[p]; p = r[p]);
	for (; x ^ p; q = r[x], r[x] = p, x = q);
	return x;
}
