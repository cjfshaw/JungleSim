#include "unit.h"

//header for monster
/*
Need a default constructor
*/

class monster : public unit
{
public:
	//include function prototypes and stats here
	
	//functions
	void CreateCheck(); //Print statement to test functionality
	void BecomeElderLizard(); //Gives the monster object Elder Lizard stats
	void BecomeAncientGolem(); //Gives the monster object Ancient Golem stats
	void BecomeYoungLizard(); //Gives the monster object young lizard stats
	 
	//variables
	float exp_given;
};
