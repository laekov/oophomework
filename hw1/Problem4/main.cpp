#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "hen.h"

int main() {
	srand(time(0));
	try {
		std::vector<Hen> hens;
		for (int i = 0; i < 3; ++ i) {
			Hen hen;
			for (int j = 0; j < 4; ++ j) {
				hen.build();
				hen.lay(j, rand() % 4 + 1);
			}
			hens.push_back(hen);
		}
		for (std::vector<Hen>::iterator it = hens.begin(); it != hens.end(); ++ it) {
			it->display();
		}
	} catch(int error) {
		std::cerr << "Error code = " << error << std::endl;
	}
}
