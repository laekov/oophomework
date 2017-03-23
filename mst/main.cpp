#include "graph.h"
#include "mst.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
	srand(time(0));
	int n(5), k(1);
	if (argc > 1) {
		n = atoi(argv[1]);
	}
	if (argc > 2) {
		k = atoi(argv[2]);
	}
	Graph g;
	for (int i = 0; i < n; ++ i) {
		g.addRandomNodeOnPlan();
	}
	if (k == 1) {
		MST::instance()->computeMST(g);
	} else if (k > 1 && k <= 20) {
		MST::instance()->computeTopKMST(g, k);
	}
}
