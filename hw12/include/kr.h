#ifndef MATCHER_KR_H
#define MATCHER_KR_H
#include <matcher.h>
#include <vector>
#include <queue>

class KRMatcher: public Matcher {
	protected:
		static const int H_BASE = 128;
		static const int H_MOD = 1e9 + 9;
		int hashv_, hash_, powk_;
		std::queue<char> que_;
	public:
		void init(const std::string&);
		void reset();
		bool nextChar(char);
		KRMatcher(const std::string& str) {
			this->init(str);
		}
};
#endif
