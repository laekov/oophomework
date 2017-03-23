#ifndef MST_H
#define MST_H
#include "graph.h"
class MST { 
	/* an instance class which only computes
	 * PS: why not a function?
	 */
	private:
		MST() {}
		MST(const MST&) {}
		static MST inst;
		std::set<Graph::Edge> edges;
	public:
		static MST* instance() {
			return &inst;
		}
		void computeMST(const Graph&);
};
#endif
