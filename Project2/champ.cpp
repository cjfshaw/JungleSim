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

void champ::TestStats()  //Currently using beefy ass nunu stats w red pot + consumed (not killed) golem
{ //use this to 'set' later
	name="Nunu";
	hp=3000;
	hp5=50;
	mp=1000;
	mp5=50;
	range=600;
	dmg=73;
	as=0.781;
	crit_bonus=200;
	armor=100;
	mr=100;
	ms=300;
	exp=0;
	level=1;
	hp_per_lvl=100;
	hp5_per_lvl=5;
	mp_per_lvl=50;
	mp5_per_lvl=5;
	dmg_per_lvl=3.45;
	as_per_lvl=0.0125;
	armor_per_lvl=30;
	mr_per_lvl=30;
	counter=1;
}

void champ::LevelUp() //upgrade the champ's stats to the ones at the next level
{
	level++;
	hp=hp+hp_per_lvl;//need to make current hp and max hp to account for this
	//if (hp + hp_per_lvl) < max hp then hp = hp + hp_per_level, else hp=max_hp
	//same for mp
	hp5=hp5+hp5_per_lvl;
	mp=mp+mp_per_lvl;
	mp5=mp5+mp5_per_lvl;
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