//////////////////////////////////////////////////////////////////////////
// Description: this is the base implementation of a simple maze router
// Author: YHL
// Date: 20120323
// Note: Modify this file and add OptRouter.cpp file for the
//       implementation of the additional functionalities
//////////////////////////////////////////////////////////////////////////
#ifndef OPT_ROUTER_H_
#define OPT_ROUTER_H_

#include "BaseRouter.h"
#include <map>
#include <vector>
#include <ostream>

class SearchStatus {
	private:
		int x, y, dir, dis, turn;
		SearchStatus* from;
	public:
		SearchStatus(int _x, int _y, int _dis, int _turn, SearchStatus* _from = 0, int _dir = -1)
			: x(_x), y(_y), dis(_dis), turn(_turn), from(_from), dir(_dir) {}
		~SearchStatus() {}
		/* check if this position is in the board */
		inline bool inBoard(int n, int m) const {
			return x >= 0 && x < n && y >= 0 && y < m;
		}
		/* move in a given direction */
		inline SearchStatus move(int di, SearchStatus* cur)  const {
			static const int movx[4] = { 1, -1, 0, 0 };
			static const int movy[4] = { 0, 0, -1, 1 };
			return SearchStatus(this->x + movx[di], this->y + movy[di], this->dis + 1, (this->dir == -1 || this->dir == di) ? this->turn : this->turn + 1, cur, di);
		}
		/* return position only */
		inline std::pair<int, int> pos() const {
			return std::pair<int, int>(this->x, this->y);
		}
		/* used in priority queue. 
		 * Note that priority queue is a big-rooted heap, so this operator should be reversed
		 */
		friend bool operator <(const SearchStatus&, const SearchStatus&); 
		inline SearchStatus* getFrom() const {
			return this->from;
		}
		inline void output(std::ostream& ouf) {
			ouf << "Pos (" << this->x << "," << this->y << ") Distance = " << this->dis << " Turns = " << this->turn << "\n";
		}
};

class OptRouter:public BaseRouter
{
	private:
		void backtrace(SearchStatus*);
		std::vector<SearchStatus*> pool;
	public:
		OptRouter(int r, int c, const Point &source, const Point &target, const PointVector &obs)
			: BaseRouter(r, c, source, target, obs)
		{
		}
		~OptRouter() {
			for (std::vector<SearchStatus*>::iterator it = pool.begin(); it != pool.end(); ++ it) {
				delete *it;
			}
		}
		bool route();
};

#endif
