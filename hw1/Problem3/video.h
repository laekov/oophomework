#ifndef VIDEO_H
#define VIDEO_H
#include <string>
class Video {
	public:
		Video();
		Video(std::string, std::string, int, int);
		void print();
		bool rent();
		void release();
	private:
		std::string name, author;
		int price, length, available;
};
#endif
