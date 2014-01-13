/*
Need a default constructor
*/

#include <iostream>
using namespace std;

#include "Champ.h"

//create a constructor with (name) to populate Champttack_speed like Champ(base_attack_speedhe)

void Champ::PopulateChamp()  //Currently using beefy base_attack_speeds nunu stats w red pot + consumed (not killed) golem
{ //use this to 'set' later
	name="Nunu";
	max_health=5000;
	current_health=5000;
	health_regeneration=50;
	max_mana=1000;
	current_mana=1000;
	mana5=50;
	range=600;
	damage=73;
	base_attack_speed=0.625;
	attack_speed_bonus = 0;
	modified_attack_speed= base_attack_speed + ( base_attack_speed * ( ( base_attack_speed_per_lvl * (level-1) ) + attack_speed_bonus ) - base_attack_speed );
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
	base_attack_speed_per_lvl=1.0225;
	armor_per_lvl=30;
	magic_resist_per_lvl=30;
	counter=1;
}

void Champ::LevelUp() //upgrade the Champ's stats to the ones at the next level
{
	level++;
	current_health=current_health+health_regeneration_per_lvl;//need to make current health and max health to account for this
	//if (health + healthPerLvl) < max health then health = health + health_per_level, else health=max_health
	//same for mana
	health_regeneration=health_regeneration+health_regeneration_per_lvl;
	current_mana=current_mana+mana_per_lvl;
	mana_regeneration=mana_regeneration+mana_regeneration_per_lvl;
	damage=damage+damage_per_lvl;
	base_attack_speed=base_attack_speed * base_attack_speed_per_lvl;
	armor=armor+armor_per_lvl;
	magic_resist=magic_resist+magic_resist_per_lvl;
	cout << "Champion is level: " << level << endl;
}

void Champ::Checkexperience() // check if Champ's experienceerience is enough to level up, if it is use the level up function
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

//getters
float Champ::getHealthRegeneration()
{
	return health_regeneration;
}

float Champ::getManaRegeneration()
{
	return mana_regeneration;
}

int Champ::getMaxMana()
{
	return max_mana;
}

int Champ::getCurrentMana()
{
	return current_mana;
}

float Champ::getMana5()
{
	return mana5;
}

float Champ::getAttackSpeedBonus()
{
	return attack_speed_bonus;
}

float Champ::getModifiedAttackSpeed()
{
	return modified_attack_speed;
}

int Champ::getCriticalBonus()
{
	return critical_bonus;
}

float Champ::getExperience()
{
	return experience;
}

int Champ::getLevel()
{
	return level;
}

float Champ::getHealthRegenerationPerLvl()
{
	return health_regeneration_per_lvl;
}

float Champ::getHealth5PerLvl()
{
	return health5_per_lvl;
}

int Champ::getManaPerLvl()
{
	return mana_per_lvl;
}

float Champ::getManaRegenerationPerLvl()
{
	return mana_regeneration_per_lvl;
}

float Champ::getDamagePerLvl()
{
	return damage_per_lvl;
}

float Champ::getBaseAttackSpeedPerLvl()
{
	return base_attack_speed_per_lvl;
}

float Champ::getArmorPerLvl()
{
	return armor_per_lvl;
}

float Champ::getMagicResistPerLvl()
{
	return magic_resist_per_lvl;
}

//setters
void Champ::setHealthRegeneration(float new_health_regeneration)
{
	health_regeneration = new_health_regeneration;
}

void Champ::setManaRegeneration(float new_mana_regeneration)
{
	mana_regeneration = new_mana_regeneration;
}

void Champ::setMaxMana(int new_max_mana)
{
	max_mana = new_max_mana;
}

void Champ::setCurrentMana(int new_current_mana)
{
	current_mana = new_current_mana;
}

void Champ::setMana5(float new_mana5)
{
	mana5 = new_mana5;
}

void Champ::setAttackSpeedBonus(float new_attack_speed_bonus)
{
	attack_speed_bonus = new_attack_speed_bonus;
}

void Champ::setModifiedAttackSpeed(float new_modified_attack_speed)
{
	modified_attack_speed = new_modified_attack_speed;
}

void Champ::setCriticalBonus(int new_critical_bonus)
{
	critical_bonus = new_critical_bonus;
}

void Champ::setExperience(float new_experience)
{
	experience = new_experience;
}

void Champ::setLevel(int new_level)
{
	level = new_level;
}	

void Champ::setHealthRegenerationPerLvl(float new_health_regeneration_per_lvl)
{
	health_regeneration_per_lvl = new_health_regeneration_per_lvl;
}

void Champ::setHealth5PerLvl(float new_health5_per_lvl)
{
	health5_per_lvl = new_health5_per_lvl;
}

void Champ::setManaPerLvl(int new_mana_per_lvl)
{
	mana_per_lvl = new_mana_per_lvl;
}

void Champ::setManaRegenerationPerLvl(float new_mana_regeneration_per_lvl)
{
	mana_regeneration_per_lvl = new_mana_regeneration_per_lvl;
}

void Champ::setDamagePerLvl(float new_damage_per_lvl)
{
	damage_per_lvl = new_damage_per_lvl;
}

void Champ::setBaseAttackSpeedPerLvl(float new_base_attack_speed_per_lvl)
{
	base_attack_speed_per_lvl = new_base_attack_speed_per_lvl;
}

void Champ::setArmorPerLvl(float new_armor_per_lvl)
{
	armor_per_lvl = new_armor_per_lvl;
}

void Champ::setMagicResistPerLvl(float new_magic_resist_per_lvl)
{
	magic_resist_per_lvl = new_magic_resist_per_lvl;
}