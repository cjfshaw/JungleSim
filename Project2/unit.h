#ifndef UNIT_H
#define UNIT_H

#include <string>

using namespace std;

class unit
{
protected:
	string name;
	float max_health;
	float current_health;
	int range;
	float damage;
	float base_attack_speed;
	float armor;
	float magic_resist;
	float movespeed;
	int critical_chance;
	int counter;

public:
	//put functions here...
	//getters
	string getName();
	float getMaxHealth();
	float getCurrentHealth();
	int getRange();
	float getDamage();
	float getBaseAttackSpeed();
	float getArmor();
	float getMagicResist();
	float getMovespeed();
	int getCriticalChance();
	int getCounter();

	//setters
	void setName(string new_name);
	void setMaxHealth(float new_max_health);
	void setCurrentHealth(float new_current_health);
	void setRange(int new_range);
	void setDamage(float new_damage);
	void setBaseAttackSpeed(float new_base_attack_speed);
	void setArmor(float new_armor);
	void setMagicResist(float new_magic_resist);
	void setMovespeed(float new_movespeed);
	void setCriticalChance(int new_critical_chance);
	void setCounter(int new_counter);
};

#endif
