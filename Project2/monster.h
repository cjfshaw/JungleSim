#ifndef MONSTER_H
#define MONSTER_H

#include "unit.h"

class monster : public unit
{
private:
	float experience_given;
public:
	//include function prototypes and stats here
	
	//functions
	void BecomeElderLizard(); //Gives the monster object Elder Lizard stats
	void BecomeAncientGolem(); //Gives the monster object Ancient Golem stats
	void BecomeYoungLizard(); //Gives the monster object young lizard stats
	//getters
	float get_experience_given();
	//setters
	void set_experience_given(float new_experience_given);
};

#endif