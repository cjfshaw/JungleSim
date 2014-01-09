#include <iostream>
using namespace std;

#include "Monster.h"

//getters
float Monster::getExperienceGiven()
{
	return experience_given;
}

//setters
void Monster::setExperienceGiven(float new_experience_given)
{
	experience_given = new_experience_given;
}

void Monster::BecomeElderLizard() //Gives the Monster object Elder Lizard stats
{
	name="ElderLizard";
	max_health=1400;
	current_health=1400;
	range=100;
	damage=65;
	base_attack_speed=0.625;
	armor=20;
	magic_resist=0;
	experience_given=260;
	counter=1;
}

void Monster::BecomeAncientGolem() //Gives the Monster object Ancient Golem stats
{
	name="AncientGolem";
	max_health=1400;
	current_health=1400;
	range=100;
	damage=65;
	base_attack_speed=0.613;
	armor=20;
	magic_resist=0;
	experience_given=260;
	counter=1;
}

void Monster::BecomeYoungLizard() //Gives the Monster object young lizard stats
{
	name="YoungLizard";
	max_health=400;
	current_health=400;
	range=500;
	damage=11;
	base_attack_speed=0.679;
	armor=8;
	magic_resist=0;
	experience_given=50;
	counter=1;
}
