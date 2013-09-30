//header for champ.cpp
/*
Need a default constructor
*/

class champ
{
public:
	//include function prototypes and stats here
	//functions
	void CreateCheck(); //Print statement to test functionality
	void TestStats(); //Gives the champ easily usable stats
	void AutoAttack(); //Attack a monster

	//variables
	int hp;
	float hp5;
	//int mp;
	//float mp5;
	int range;
	float dmg;
	float as;
	float armor;
	float mr;
	float ms;
};