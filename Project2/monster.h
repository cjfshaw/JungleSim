#ifndef Monster_H
#define Monster_H

#include "unit.h"

class Monster : public unit
{
private:
	float experience_given;
public:
	//include function prototypes and stats here
	
	//getters
	float getExperienceGiven();
	//setters
	void setExperienceGiven(float new_experience_given);
};

#endif