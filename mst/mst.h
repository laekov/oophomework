#ifndef MST_H
#define MST_H
#include "graph.h"
#include "tree.h"
class MST { 
	/* an instance class which only computes
	 * PS: why not a function?
	 */
	private:
		MST() {}
		MST(const MST&) {}
		static MST inst;
		Tree mst;
		std::set<Tree> msts;
		void print(const std::set<Graph::Edge>&);
		void _computeMST(const Graph&);

	public:
		static MST* instance() {
			return &inst;
		}
		
		/* compute the minimal spanning tree */
		void computeMST(const Graph&);

		/* compute the top k minimal spanning tree */
		void computeTopKMST(const Graph&, int);
};
#endif
