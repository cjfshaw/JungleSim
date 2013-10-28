/*
Need a default constructor
*/

#include <iostream>
using namespace std;

#include "champ.h"

//create a constructor with (name) to populate champttack_speed like champ(attack_speedhe)

void champ::PopulateChamp()  //Currently using beefy attack_speeds nunu stats w red pot + consumed (not killed) golem
{ //use this to 'set' later
	name="Nunu";
	max_health=3000;
	current_health=3000;
	health_regeneration=50;
	max_mana=1000;
	current_mana=1000;
	mana5=50;
	range=600;
	damage=73;
	attack_speed=0.781;
	critical_bonus=200;
	armor=100;
	magic_resist=100;
	movespeed=300;
	experience=0;
	level=1;
	health_regeneration_per_lvl=100;
	health5_per_lvl=5;
	mana_per_lvl=50;
	mana_regeneration_per_lvl=5;
	damage_per_lvl=3.45;
	attack_speed_per_lvl=0.0125;
	armor_per_lvl=30;
	magic_resist_per_lvl=30;
	counter=1;
}

void champ::LevelUp() //upgrade the champ's stats to the ones at the next level
{
	level++;
	current_health=current_health+health_regeneration_per_lvl;//need to make current health and max health to account for this
	//if (health + health_per_lvl) < max health then health = health + health_per_level, else health=max_health
	//same for mana
	health_regeneration=health_regeneration+health_regeneration_per_lvl;
	current_mana=current_mana+mana_per_lvl;
	mana_regeneration=mana_regeneration+mana_regeneration_per_lvl;
	damage=damage+damage_per_lvl;
	attack_speed=attack_speed+attack_speed_per_lvl;//TODO: CHANGE HOW LEVEL UP DOES attack_speed (attack_speed = attack_speed * attack_speed_PER_LVL) attack_speed_PER_LEVEL SHOULD BE A % VALUE (EX: 2)
	armor=armor+armor_per_lvl;
	magic_resist=magic_resist+magic_resist_per_lvl;
	cout << "champion is level: " << level << endl;
}

void champ::Checkexperience() // check if champ's experienceerience is enough to level up, if it is use the level up function
{//TODO: VERIFY THIS WORKS FOR ALL LEVELS
	int i;
	int current_experience=0;
	int cum_experience=0;

	if ( level < 18)
	{
		if ( level == 1)
		{
			current_experience = 280;
			cum_experience = cum_experience + current_experience;
		}
		else
		{
			for ( i=level+1; i>1; i--)
			{
				current_experience = 280 + ( 110 * (i-2) );
				cum_experience = cum_experience + current_experience;
			}
		}
		if ( experience >= cum_experience )
		{
			LevelUp();
		}
	}
}