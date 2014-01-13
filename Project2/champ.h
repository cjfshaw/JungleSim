#ifndef Champ_H
#define Champ_H

#include "unit.h"

class Champ : public unit
{
private:
	//stats
	float health_regeneration;
	float mana_regeneration;
	int max_mana;
	int current_mana;
	float mana5;
	float attack_speed_bonus;
	float modified_attack_speed;
	int critical_bonus;
	float experience;
	int level;
	
	//level up stats
	float health_regeneration_per_lvl;
	float health5_per_lvl;
	int mana_per_lvl;
	float mana_regeneration_per_lvl;
	float damage_per_lvl;
	float base_attack_speed_per_lvl;
	float armor_per_lvl;
	float magic_resist_per_lvl;
public:
	//include function prototypes and stats here
	
	//functions
	void PopulateChamp(); //Gives the Champ easily usable stats
	void LevelUp();
	void Checkexperience();

	//getters
	float getHealthRegeneration();
	float getManaRegeneration();
    int getMaxMana();
    int getCurrentMana();
    float getMana5();
    float getAttackSpeedBonus();
    float getModifiedAttackSpeed();
    int getCriticalBonus();
    float getExperience();
    int getLevel();
	float getHealthRegenerationPerLvl();
    float getHealth5PerLvl();
    int getManaPerLvl();
    float getManaRegenerationPerLvl();
    float getDamagePerLvl();
    float getBaseAttackSpeedPerLvl();
    float getArmorPerLvl();
    float getMagicResistPerLvl();

	//setters
	void setHealthRegeneration(float new_health_regeneration);
	void setManaRegeneration(float new_mana_regeneration);
    void setMaxMana(int new_max_mana);
    void setCurrentMana(int new_current_mana);
    void setMana5(float new_mana5);
    void setAttackSpeedBonus(float new_attack_speed_bonus);
    void setModifiedAttackSpeed(float new_modified_attack_speed);
    void setCriticalBonus(int new_critical_bonus);
    void setExperience(float new_experience);
    void setLevel(int new_level);	
	void setHealthRegenerationPerLvl(float new_health_regeneration_per_lvl);
    void setHealth5PerLvl(float new_health5_per_lvl);
    void setManaPerLvl(int new_mana_per_lvl);
    void setManaRegenerationPerLvl(float new_mana_per_lvl);
    void setDamagePerLvl(float new_damage_per_lvl);
    void setBaseAttackSpeedPerLvl(float new_base_attack_speed_per_lvl);
    void setArmorPerLvl(float new_armor_per_lvl);
    void setMagicResistPerLvl(float new_magic_resist_per_lvl);
};

#endif