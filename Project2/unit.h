#ifndef UNIT_H
#define UNIT_H

#include <string>

using namespace std;

class unit
{
public:
	//put functions here...
	void placeholder();
	
	//stats shared by both jungle minions and champions
	string name;
	float max_hp;
	float current_hp;
	int range;
	float dmg;
	float as;
	float armor;
	float mr;
	float ms;
	int crit_chance;
	int counter;
};

#endif
