#include <kmp.h>

using std::vector;
using std::string;

void KMPMatcher::init(const string& str) {
	this->str_ = str;
	this->len_ = str.length();
	this->next_.clear();
	this->next_.push_back(-1);
	for (int i = 0, j; i + 1 < this->len_; ++ i) {
		for (j = this->next_[i]; j > -1 && str[j + 1] != str[i + 1]; j = this->next_[j]);
		if (str[j + 1] == str[i + 1]) {
			this->next_.push_back(j + 1);
		} else {
			this->next_.push_back(-1);
		}
	}
	this->reset();
}

void KMPMatcher::reset() {
	this->curi_ = 0;
}

bool KMPMatcher::nextChar(char c) {
	for (; this->curi_ > -1 && this->str_[this->curi_ + 1] != c; this->curi_ = this->next_[this->curi_]);
	if (this->str_[this->curi_ + 1] == c) {
		++ this->curi_;
	}
	if (this->curi_ == this->len_ - 1) {
		this->curi_ = this->next_[this->curi_];
		return 1;
	}
	return 0;
}

