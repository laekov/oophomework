#include "graph.h"
#include <cstdlib>
#include <cmath>
#include <ctime>

bool operator <(const Graph::Node& a, const Graph::Node& b) {
	return (a.x == b.x) ? (a.x < b.x) : (a.y < b.y);
}

inline double sqr(const double& x) {
	return x * x;
}

double distance(const Graph::Node& a, const Graph::Node& b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

Graph::Edge::Edge(std::set<Node>::iterator _u, std::set<Node>::iterator _v) {
	this->u = _u, this->v = _v, this->len = distance(*_u, *_v);
}

bool operator <(const Graph::Edge& a, const Graph::Edge& b) {
	return a.len < b.len;
}

void Graph::addRandomNodeOnPlan() {
	if (this->nodes.size() > MAX_NODE) {
		throw ERROR_TOO_MANY_NODES;
	}
	std::pair<std::set<Node>::iterator, bool> res;

	/* insert a new point which never appeared before */
	while (!(res = this->nodes.insert(Node(rand() % MAX_COORDINATE, rand() % MAX_COORDINATE, this->nodes.size()))).second);

	/* add edges between the new point and the old ones */
	for (std::set<Node>::iterator it = this->nodes.begin(); it != this->nodes.end(); ++ it) {
		if (it != res.first) {
			this->edges.insert(Edge(it, res.first));
		}
	}
}
