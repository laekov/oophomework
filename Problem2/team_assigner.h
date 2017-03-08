#ifndef TEAM_ASSIGNER_H
#define TEAM_ASSIGNER_H
#define	TOO_FEW_STUDENTS	0x38383839
#include "list.h"
class TeamAssigner: public StudentList {
	public:
		void assign();
		void output();
};
#endif

