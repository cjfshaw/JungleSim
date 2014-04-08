#ifndef Champ_H
#define Champ_H

#include "unit.h"

class Champ : public unit
{
private:
        //stats
        float health_regeneration;
        float mana_regeneration;
        float max_mana;
        float current_mana;
        float mana5;
        float attack_speed_bonus;
        float modified_attack_speed;
        int critical_bonus;
        float experience;
        int level;
        
        //level up stats
		float health_per_level;
        float health_regeneration_per_level;
        float health5_per_level;
        float mana_per_level;
        float mana_regeneration_per_level;
        float damage_per_level;
        float base_attack_speed_per_level;
        float armor_per_level;
        float magic_resist_per_level;
public:
        //include function prototypes and stats here
        
        //functions
        void LevelUp();
        void Checkexperience();

        //getters
	float getHealthPerLevel();
        float getHealthRegeneration();
        float getManaRegeneration();
    float getMaxMana();
    float getCurrentMana();
    float getMana5();
    float getAttackSpeedBonus();
    float getModifiedAttackSpeed();
    int getCriticalBonus();
    float getExperience();
    int getLevel();
        float getHealthRegenerationPerLevel();
    float getHealth5PerLevel();
    float getManaPerLevel();
    float getManaRegenerationPerLevel();
    float getDamagePerLevel();
    float getBaseAttackSpeedPerLevel();
    float getArmorPerLevel();
    float getMagicResistPerLevel();

        //setters
	void setHealthPerLevel(float new_health_per_level);
        void setHealthRegeneration(float new_health_regeneration);
        void setManaRegeneration(float new_mana_regeneration);
    void setMaxMana(float new_max_mana);
    void setCurrentMana(float new_current_mana);
    void setMana5(float new_mana5);
    void setAttackSpeedBonus(float new_attack_speed_bonus);
    void setModifiedAttackSpeed(float new_modified_attack_speed);
    void setCriticalBonus(int new_critical_bonus);
    void setExperience(float new_experience);
    void setLevel(int new_level);        
        void setHealthRegenerationPerLevel(float new_health_regeneration_per_level);
    void setHealth5PerLevel(float new_health5_per_level);
    void setManaPerLevel(float new_mana_per_level);
    void setManaRegenerationPerLevel(float new_mana_per_level);
    void setDamagePerLevel(float new_damage_per_level);
    void setBaseAttackSpeedPerLevel(float new_base_attack_speed_per_level);
    void setArmorPerLevel(float new_armor_per_level);
    void setMagicResistPerLevel(float new_magic_resist_per_level);
};

#endif