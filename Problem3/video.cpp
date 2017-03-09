#include "video.h"
#include <iostream>

Video::Video() {
	this->name = "unknown";
	this->author = "unknown";
	this->price = 0;
	this->length = 0;
	this->available = false;
}

Video::Video(std::string name, std::string author, int price, int length) {
	this->name = name;
	this->author = author;
	this->price = price;
	this->length = length;
	this->available = true;
}

void Video::print() {
	std::cout << "Name:\t" << this->name << std::endl;
	std::cout << "Author:\t" << this->author << std::endl;
	std::cout << "Price:\t$" << this->price << std::endl;
	std::cout << "Length:\t" << this->price << " min" << std::endl;
}

bool Video::rent() {
	if (!this->available) {
		return false;
	}
	return this->available = false, true;
}

void Video::release() {
	this->available = true;
}

