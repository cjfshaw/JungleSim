/*
Need a default constructor
*/

#include <iostream>
using namespace std;

#include "champ.h"

void champ::CreateCheck() //Print statement to test functionality
{
	cout << "Champ is created.\n";
}

//create a constructor with (name) to populate champs like champ(Ashe)

void champ::TestStats()  //Gives the champ easily usable stats
{ //use this to 'set' later
	hp=3000;
	hp5=50;
	range=600;
	dmg=200;
	as=2.25;
	armor=100;
	mr=100;
	ms=300;
	exp=0;
	level=1;
}

void champ::AutoAttack() // want champ to be able to AA a target (monster)
{
	hp=hp - dmg;
}

void champ::LevelUp() //upgrade the champ's stats to the ones at the next level
{
	level++;
	hp=hp+hp_per_lvl;//need to make current hp and max hp to account for this
	hp5=hp5+hp5_per_lvl;
	dmg=dmg+dmg_per_lvl;
	as=as+as_per_lvl;
	armor=armor+armor_per_lvl;
	mr=mr+mr_per_lvl;
}

void champ::CheckExp() // check if champ's experience is enough to level up
{
	int ExpForNextLevel; 
	bool EnoughExpToLevel;

	if ( level = 1 )
	{
		ExpForNextLevel = 280;
	}
	else
	{
		ExpForNextLevel = 280 + 110*level;
	}

	if ( level < 18)
	{
		if ( exp >= ExpForNextLevel )
		{
			LevelUp();
		}
	}
}