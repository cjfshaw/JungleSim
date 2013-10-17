/*
Need a default constructor
*/

#include <iostream>
using namespace std;

#include "monster.h"

void monster::BecomeElderLizard() //Gives the monster object Elder Lizard stats
{
	name="ElderLizard";
	max_health=1400;
	current_health=1400;
	range=100;
	damage=65;
	attack_speed=0.625;
	armor=20;
	magic_resist=0;
	experience_given=260;
	counter=1;
}

void monster::BecomeAncientGolem() //Gives the monster object Ancient Golem stats
{
	name="AncientGolem";
	max_health=1400;
	current_health=1400;
	range=100;
	damage=65;
	attack_speed=0.613;
	armor=20;
	magic_resist=0;
	experience_given=260;
	counter=1;
}

void monster::BecomeYoungLizard() //Gives the monster object young lizard stats
{
	name="YoungLizard";
	max_health=400;
	current_health=400;
	range=500;
	damage=11;
	attack_speed=0.679;
	armor=8;
	magic_resist=0;
	experience_given=50;
	counter=1;
}
