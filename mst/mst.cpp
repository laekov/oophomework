#include "mst.h"
#include <iostream>

MST MST::inst;

int getRoot(int* r, int x) {
	int p, q;
	for (p = x; p ^ r[p]; p = r[p]);
	for (; x ^ p; q = r[x], r[x] = p, x = q);
	return x;
}

void MST::computeMST(const Graph& g) {
	int n((int)g.nodes.size());
	int *r = new int[n];
	for (int i = 0; i < n; ++ i) {
		r[i] = i;
	}
	double sumLen(0);
	this->edges.clear();
	for (std::set<Graph::Edge>::iterator it = g.edges.begin(); it != g.edges.end(); ++ it) {
		if (getRoot(r, it->u->_id()) != getRoot(r, it->v->_id())) {
			r[getRoot(r, it->u->_id())] = getRoot(r, it->v->_id());
			sumLen += it->length();
			this->edges.insert(*it);
		}
	}
	for (std::set<Graph::Edge>::iterator it = this->edges.begin(); it != this->edges.end(); ++ it) {
		it->print();
	}
	std::cout << "Total length = " << sumLen << std::endl;
	delete[] r;
}
