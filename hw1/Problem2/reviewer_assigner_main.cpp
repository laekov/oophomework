#include <iostream>
#include "reviewer_assigner.h"

int main() {
	ReviewerAssigner ra;
	try {
		ra.load();
		ra.choose();
		ra.output();
	} catch(int error) {
		std::cerr << "Processing with error " << error;
	}
}
