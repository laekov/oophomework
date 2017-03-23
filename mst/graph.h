#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <iostream>
class Graph {
	private:
		enum {
			MAX_NODE = 20,
			MAX_COORDINATE = 10000,
			ERROR_TOO_MANY_NODES = 0x3000ffff
		};

		/* a node indicates a point on the plane */
		class Node {
			private:
				double x, y;
				int id;
			public:
				/* cmp used to organize a set */
				friend bool operator <(const Node&, const Node&);
				friend double distance(const Node&, const Node&);
				Node(double _x = 0, double _y = 0, int _id = 0): x(_x), y(_y), id(_id) {};
				inline int _id() const {
					return this->id;
				}
				inline void print(char ending = '\n') const {
					std::cout << "Node " << this->id << "(" << (int)this->x << ", " << (int)this->y << ")" << ending;
				}
				friend class MST;
		};

		/* an edge indicates a link between two edges */
		class Edge {
			private:
				std::set<Node>::iterator u, v;
				double len;
			public:
				/* cmp used to organize a set */
				friend bool operator <(const Edge&, const Edge&);
				Edge(std::set<Node>::iterator, std::set<Node>::iterator);
				inline double length() const {
					return this->len;
				}
				inline void print() const {
					this->u->print('\t');
					std::cout << "-\t";
					this->v->print('\t');
					std::cout.setf(std::ios::fixed);
					std::cout.precision(2);
					std::cout << " length = " << this->len << std::endl;
				}
				friend class MST;
		};

		/* sets of nodes and edges on this plane */
		std::set<Node> nodes;
		std::set<Edge> edges;
	public:
		/* cmp used to organize a set */
		friend bool operator <(const Node&, const Node&);
		friend double distance(const Node&, const Node&);
		friend bool operator <(const Edge&, const Edge&);

		/* add a random point to this plane and add edges from it to all other points */
		void addRandomNodeOnPlan();
		friend class MST;
};

bool operator <(const Graph::Node&, const Graph::Node&);
bool operator <(const Graph::Edge&, const Graph::Edge&);
#endif
