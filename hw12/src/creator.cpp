#include <common.h>
#include <creator.h>
#include <kmp.h>
#include <kr.h>

using std::string;
using std::map;

map<string, matcherCreator> creatorMap;

Matcher* createKMPMatcher(const string& pattern) {
	return new KMPMatcher(pattern);
}
INSTANCECLASS(CreateKMPMatcher, { creatorMap["KMP"] = createKMPMatcher; });

Matcher* createKRMatcher(const string& pattern) {
	return new KRMatcher(pattern);
}
INSTANCECLASS(CreateKRMatcher, { creatorMap["KR"] = createKRMatcher; });

Matcher* createMatcher(const string& name, const string& pattern) {
	map<string, matcherCreator>::iterator it = creatorMap.find(name);
	if (it != creatorMap.end()) {
		return it->second(pattern);
	} else {
		return 0;
	}
}

