#include <kr.h>

using std::string;

#define _l (long long int)

void KRMatcher::init(const string& str) {
	this->str_ = str;
	this->len_ = str.length();
	this->hashv_ = 0, this->powk_ = 1;
	for (int i = 0; i < this->len_; ++ i) {
		this->hashv_ = (_l this->hashv_ * this->H_BASE + this->str_[i])% this->H_MOD;
		this->powk_ = _l this->powk_ * this->H_BASE % this->H_MOD;
	}
	this->reset();
}

void KRMatcher::reset() {
	for (; !this->que_.empty(); this->que_.pop());
	this->hash_ = 0;
}

bool KRMatcher::nextChar(char c) {
	this->hash_ = (_l this->hash_ * this->H_BASE + c)% this->H_MOD;
	this->que_.push(c);
	if (this->que_.size() > this->len_) {
		char d(this->que_.front());
		this->que_.pop();
		this->hash_ -= _l this->powk_ * d % this->H_MOD;
		if (this->hash_ < 0) {
			this->hash_ += this->H_MOD;
		}
	}
	return this->que_.size() == this->len_ && this->hash_ == this->hashv_;
}

