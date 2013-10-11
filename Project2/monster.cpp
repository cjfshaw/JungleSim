/*
Need a default constructor
*/

#include <iostream>
using namespace std;

#include "monster.h"

void monster::CreateCheck() //Print statement to test functionality
{
	cout << "Monster is created.\n";
}

void monster::BecomeElderLizard() //Gives the monster object Elder Lizard stats
{
	name="ElderLizard";
	hp=1400;
	range=100;
	dmg=65;
	as=0.625;
	armor=20;
	mr=0;
	exp_given=260;
}

void monster::BecomeAncientGolem() //Gives the monster object Ancient Golem stats
{
	name="AncientGolem";
	hp=1400;
	range=100;
	dmg=65;
	as=0.613;
	armor=20;
	mr=0;
	exp_given=260;
}

void monster::BecomeYoungLizard() //Gives the monster object young lizard stats
{
	name="YoungLizard";
	hp=400;
	range=500;
	dmg=11;
	as=0.679;
	armor=8;
	mr=0;
	exp_given=50;
}