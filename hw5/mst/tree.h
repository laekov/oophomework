#ifndef TREE_H
#define TREE_H
#include "graph.h"
#include <cstring>

class Tree: public Graph {
	private:
		double _sz;
	public:
		Tree(): _sz(0) {}
		Tree(const Tree& _t) {
			this->_sz = _t._sz;
			this->edges = _t.edges;
		}
		inline double size() {
			return _sz;
		}
		void add(Edge);
		void print() const;
		
		/* test if it is a tree */
		bool test(int);

		/* expand new trees using edges from a graph */
		void expand(const Graph&, std::set<Tree>&);
		friend bool operator <(const Tree&, const Tree&);
};

bool operator <(const Tree&, const Tree&);
#endif
