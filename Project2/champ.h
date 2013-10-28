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
	void PopulateChamp(); //Gives the champ eattack_speedily usable stats
	void LevelUp();
	void Checkexperience();

	//variables
	float health_regeneration;
	float mana_regeneration;
	int max_mana;
	int current_mana;
	float mana5;
	int critical_bonus;
	float experience;
	int level;
	
	//level up stats
	float health_regeneration_per_lvl;
	float health5_per_lvl;
	int mana_per_lvl;
	float mana_regeneration_per_lvl;
	float damage_per_lvl;
	float attack_speed_per_lvl;
	float armor_per_lvl;
	float magic_resist_per_lvl;
};
