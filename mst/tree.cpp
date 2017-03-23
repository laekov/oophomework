#include "graph.h"
#include "tree.h"
#include "dset.h"
#include <cmath>

void Tree::add(Graph::Edge e) {
	this->edges.insert(e);
	this->_sz += e.length();
}

void Tree::print() const {
	for (std::set<Graph::Edge>::iterator it = this->edges.begin(); it != this->edges.end(); ++ it) {
		it->print();
	}
	std::cout << "Total length = " << _sz << std::endl;
}

bool Tree::test(int n) {
	int *r = new int[n];
	for (int i = 0; i < n; ++ i) {
		r[i] = i;
	}
	int parts(n), noRedundant(1);
	for (std::set<Graph::Edge>::iterator it = this->edges.begin(); it != this->edges.end(); ++ it) {
		if (it->u->_id() >= n || it->v->_id() >= n) {
			continue;
		}
		if (getRoot(r, it->u->_id()) != getRoot(r, it->v->_id())) {
			r[getRoot(r, it->u->_id())] = getRoot(r, it->v->_id());
			-- parts;
		} else {
			noRedundant = 0;
		}
	}
	delete[] r;
	return parts == 1 && noRedundant;
}

void Tree::expand(const Graph& g, std::set<Tree>& que) {
	int n((int)g.nodes.size());
	for (std::set<Graph::Edge>::iterator it = this->edges.begin(); it != this->edges.end(); ++ it) {
		Tree cutted;
		for (std::set<Graph::Edge>::iterator ic = this->edges.begin(); ic != this->edges.end(); ++ ic) {
			if (ic != it) {
				cutted.add(*ic);
			}
		}
		for (std::set<Graph::Edge>::iterator ig = g.edges.begin(); ig != g.edges.end(); ++ ig) {
			Tree ng(cutted);
			ng.add(*ig);
			if (ng.test(n)) {
				que.insert(ng);
			}
		}
	}
}

bool operator <(const Tree& a, const Tree& b) {
	static const double eps = 1e-7;
	if (fabs(a._sz - b._sz) > eps) {
		return a._sz < b._sz;
	}
	for (std::set<Graph::Edge>::iterator ia = a.edges.begin(), ib = b.edges.begin(); ia != a.edges.end() && ib != b.edges.end(); ++ ia, ++ ib) {
		if (*ia < *ib) {
			return 1;
		}
		if (*ib < *ia) {
			return 0;
		}
	}
	return 0;
}

