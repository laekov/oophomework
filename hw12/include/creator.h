/* matcher generator here */
#ifndef CREATOR_H
#define CREATOR_H
#include <matcher.h>
#include <map>

typedef Matcher* (*matcherCreator)(const std::string&);

Matcher* createMatcher(const std::string&, const std::string& = "");
#endif
