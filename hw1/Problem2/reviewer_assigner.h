#ifndef REVIEWER_ASSIGNER_H
#define REVIEWER_ASSIGNER_H
#define	TOO_FEW_RESIGNERS	0x38383838
#include "list.h"
class ReviewerAssigner: public StudentList {
	public:
		void choose();
		void output();
};
#endif

