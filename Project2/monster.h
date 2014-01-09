#ifndef Monster_H
#define Monster_H

#include "unit.h"

class Monster : public unit
{
private:
	float experience_given;
public:
	//include function prototypes and stats here
	
	//functions
	void BecomeElderLizard(); //Gives the Monster object Elder Lizard stats
	void BecomeAncientGolem(); //Gives the Monster object Ancient Golem stats
	void BecomeYoungLizard(); //Gives the Monster object young lizard stats
	//getters
	float getExperienceGiven();
	//setters
	void setExperienceGiven(float new_experience_given);
};

#endif