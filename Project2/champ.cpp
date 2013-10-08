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
	hp_per_lvl=100;
	hp5_per_lvl=5;
	mp_per_lvl=50;
	mp5_per_lvl=5;
	dmg_per_lvl=50;
	as_per_lvl=0.25;
	armor_per_lvl=30;
	mr_per_lvl=30;
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
	cout << "Champion is level: " << level << endl;
}

void champ::CheckExp() // check if champ's experience is enough to level up, if it is use the level up function
{//TODO: VERIFY THIS WORKS FOR ALL LEVELS
	int i;
	int current_exp=0;
	int cum_exp=0;

	if ( level < 18)
	{
		if ( level == 1)
		{
			current_exp = 280;
			cum_exp = cum_exp + current_exp;
		}
		else
		{
			for ( i=level+1; i>1; i--)
			{
				current_exp = 280 + ( 110 * (i-2) );
				cum_exp = cum_exp + current_exp;
			}
		}
		if ( exp >= cum_exp )
		{
			LevelUp();
		}
	}
}