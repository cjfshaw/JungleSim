#include "unit.h"

//header for champ.cpp
/*
Need a default constructor
*/

class champ : public unit
{
public:
	//include function prototypes and stats here
	
	//functions
	void CreateCheck(); //Print statement to test functionality
	void TestStats(); //Gives the champ easily usable stats
	void AutoAttack(); //Attack a monster
	void LevelUp();
	void CheckExp();

	//variables
	float hp5;
	int mp;
	float mp5;
	int crit_bonus;
	float exp;
	int level;
	
	//level up stats
	float hp_per_lvl;
	float hp5_per_lvl;
	int mp_per_lvl;
	float mp5_per_lvl;
	float dmg_per_lvl;
	float as_per_lvl;
	float armor_per_lvl;
	float mr_per_lvl;
};
