#include <iostream>
#include "team_assigner.h"

int main() {
	TeamAssigner ra;
	try {
		ra.load();
		ra.assign();
		ra.output();
	} catch(int error) {
		std::cerr << "Processing with error " << error;
	}
}
