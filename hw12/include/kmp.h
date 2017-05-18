#ifndef MATCHER_KMP_H
#define MATCHER_KMP_H
#include <matcher.h>
#include <vector>

class KMPMatcher: public Matcher {
	protected:
		std::vector<int> next_;
		int curi_;
	public:
		void init(const std::string&);
		void reset();
		bool nextChar(char);
		KMPMatcher(const std::string& str) {
			this->init(str);
		}
};
#endif
