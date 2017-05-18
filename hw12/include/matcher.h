/* matcher.h
 * matcher base class
 */
#ifndef MATCHER_H
#define MATCHER_H
#include <string>

class Matcher {
	protected:
		std::string str_;
		int len_;
	public:
		/* initialize the matching pattern
		 * calculating next array for example
		 */
		virtual void init(const std::string&);

		/* reset matching status */
		virtual void reset();

		/* process matching nextchar */
		virtual bool nextChar(char);

		/* process a whole string 
		 * will NOT reset matching status
		 */
		bool matchString(std::string);

		Matcher(const std::string& str) {}
		Matcher() {}
};
#endif

