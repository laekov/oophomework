#include "mst.h"
#include "tree.h"
#include "dset.h"
#include <iostream>
#include <queue>

MST MST::inst;

void MST::_computeMST(const Graph& g) {
	int n((int)g.nodes.size());
	int *r = new int[n];
	for (int i = 0; i < n; ++ i) {
		r[i] = i;
	}
	this->mst = Tree();
	for (std::set<Graph::Edge>::iterator it = g.edges.begin(); it != g.edges.end(); ++ it) {
		if (getRoot(r, it->u->_id()) != getRoot(r, it->v->_id())) {
			r[getRoot(r, it->u->_id())] = getRoot(r, it->v->_id());
			this->mst.add(*it);
		}
	}
	delete[] r;
}

void MST::computeMST(const Graph& g) {
	this->_computeMST(g);
	this->mst.print();
}

/* This function uses the unoptimized algorithm from D.Yu(2014)
 * Initially, the MST is in the answer set.
 * For each step, enum every trees in the answer set, and try to use another edge which is not in the tree but in the graph to replace an edge on this tree, generating a new tree.
 * After generating many trees, pick the one not chosen before with minimal weight and insert it to the answer set.
 */
void MST::computeTopKMST(const Graph& g, int k) {
	static const double INFINITE = 1e111;
	this->_computeMST(g);
	this->msts.clear();
	std::set<Tree> que;
	que.insert(this->mst);
	while (que.size() > 0 && this->msts.size() < k) {
		Tree t(*que.begin());
		que.erase(que.begin());
		if (this->msts.insert(t).second) {
			t.expand(g, que);
		}
	}
	int cnt(0);
	std::set<Tree>::iterator ita(this->msts.begin());
	std::set<Tree>::iterator itb(ita);
	++ itb;
	for (std::set<Tree>::iterator it = this->msts.begin(); it != this->msts.end(); ++ it) {
		std::cout << "The " << ++ cnt << " minimal spanning tree: " << std::endl;
		it->print();
		std::cout << std::endl;
	}
}

