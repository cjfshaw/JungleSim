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
	float max_health;
	float current_health;
	int range;
	float damage;
	float base_attack_speed;
	float armor;
	float magic_resist;
	float movespeed;
	int critical_chance;
	int counter;
};

#endif
