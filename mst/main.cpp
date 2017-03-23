#include "graph.h"
#include "mst.h"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(0));
	Graph g;
	for (int i = 0; i < 20; ++ i) {
		g.addRandomNodeOnPlan();
	}
	MST::instance()->computeMST(g);
}
