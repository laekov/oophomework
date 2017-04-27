#include "OptRouter.h"
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <iostream>

using std::priority_queue;
using std::set;
using std::pair;
using std::vector;
using std::cout;

bool operator <(const SearchStatus& a, const SearchStatus& b) {
	if (a.dis != b.dis) {
		return a.dis > b.dis;
	} else if (a.turn != b.turn) {
		return a.turn > b.turn;
	} else if (a.x != b.x) {
		return a.x > b.x;
	} else {
		return a.y > b.y;
	}
}

bool OptRouter::route() {
	priority_queue<SearchStatus> pq;
	set<pair<int, int> > hash;
	int xo, yo, xc, yc;
	this->compXYIndex(this->m_sourceIndex, xo, yo);
	pq.push(SearchStatus(xo, yo, 0, 0));
	while (!pq.empty()) {
		SearchStatus *cur(new SearchStatus(pq.top()));
		this->pool.push_back(cur);
		/* will be released during object destruction */
		pq.pop();
		pair<int, int> pos(cur->pos());
		if (hash.find(pos) != hash.end()) {
			continue;
		}
		hash.insert(pos);
		if (this->compIndex(pos.first, pos.second) == this->m_targetIndex) {
			this->backtrace(cur);
			return 1;
		}
		for (int i = 0; i < 4; ++ i) {
			SearchStatus tg(cur->move(i, cur));
			if (!tg.inBoard(this->m_row, this->m_col)) {
				continue;
			}
			pair<int, int> newPos(tg.pos());
			if (m_grids[this->compIndex(newPos.first, newPos.second)] == OBS) {
				continue;
			}
			if (hash.find(newPos) != hash.end()) {
				continue;
			}
			pq.push(tg);
		}
	}
	return 0;
}

void OptRouter::backtrace(SearchStatus* pos) {
	stack<SearchStatus*> path;
	for (; pos; pos = pos->getFrom()) {
		path.push(pos);
	}
	cout << "A path with minimal length and number of turnings is found\n";
	for (; !path.empty(); path.pop()) {
		SearchStatus* curp(path.top());
		pair<int, int> pos(curp->pos());
		curp->output(cout);
	}
}

