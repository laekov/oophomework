#ifndef MEMBER_H
#define MEMBER_H
#include <string>
class Member {
	private:
		const std::string name;
		const int age;
	public:
		Member(std::string _name = "???", int _age = 0): name(_name), age(_age) {}
		void printInfo() const;
};
#endif
