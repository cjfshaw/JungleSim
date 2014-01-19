/*
Need a default constructor
*/

#include <iostream>
using namespace std;

#include "Champ.h"

//create a constructor with (name) to populate Champttack_speed like Champ(ashe)

void Champ::LevelUp() //upgrade the Champ's stats to the ones at the next level
{
        level++;
        current_health=current_health+health_per_level;
        //if (health + healthPerLevel) < max health then health = health + health_per_level, else health=max_health
        //same for mana
        health_regeneration=health_regeneration+health_regeneration_per_level;
        current_mana=current_mana+mana_per_level;
        mana_regeneration=mana_regeneration+mana_regeneration_per_level;
        damage=damage+damage_per_level;
        base_attack_speed=base_attack_speed * base_attack_speed_per_level;
        armor=armor+armor_per_level;
        magic_resist=magic_resist+magic_resist_per_level;
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

float Champ::getMaxMana()
{
        return max_mana;
}

float Champ::getCurrentMana()
{
        return current_mana;
}

/*float Champ::getMana5()
{
        return mana5;
}*/

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

float Champ::getHealthPerLevel()
{
	return health_per_level;
}

float Champ::getHealthRegenerationPerLevel()
{
        return health_regeneration_per_level;
}

/*float Champ::getHealth5PerLevel()
{
        return health5_per_level;
}*/

float Champ::getManaPerLevel()
{
        return mana_per_level;
}

float Champ::getManaRegenerationPerLevel()
{
        return mana_regeneration_per_level;
}

float Champ::getDamagePerLevel()
{
        return damage_per_level;
}

float Champ::getBaseAttackSpeedPerLevel()
{
        return base_attack_speed_per_level;
}

float Champ::getArmorPerLevel()
{
        return armor_per_level;
}

float Champ::getMagicResistPerLevel()
{
        return magic_resist_per_level;
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

void Champ::setMaxMana(float new_max_mana)
{
        max_mana = new_max_mana;
}

void Champ::setCurrentMana(float new_current_mana)
{
        current_mana = new_current_mana;
}

/*void Champ::setMana5(float new_mana5)
{
        mana5 = new_mana5;
}*/

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

void Champ::setHealthPerLevel(float new_health_per_level)
{
	health_per_level = new_health_per_level;
}

void Champ::setHealthRegenerationPerLevel(float new_health_regeneration_per_level)
{
        health_regeneration_per_level = new_health_regeneration_per_level;
}

/*void Champ::setHealth5PerLevel(float new_health5_per_level)
{
        health5_per_level = new_health5_per_level;
}*/

void Champ::setManaPerLevel(float new_mana_per_level)
{
        mana_per_level = new_mana_per_level;
}

void Champ::setManaRegenerationPerLevel(float new_mana_regeneration_per_level)
{
        mana_regeneration_per_level = new_mana_regeneration_per_level;
}

void Champ::setDamagePerLevel(float new_damage_per_level)
{
        damage_per_level = new_damage_per_level;
}

void Champ::setBaseAttackSpeedPerLevel(float new_base_attack_speed_per_level)
{
        base_attack_speed_per_level = new_base_attack_speed_per_level;
}

void Champ::setArmorPerLevel(float new_armor_per_level)
{
        armor_per_level = new_armor_per_level;
}

void Champ::setMagicResistPerLevel(float new_magic_resist_per_level)
{
        magic_resist_per_level = new_magic_resist_per_level;
}