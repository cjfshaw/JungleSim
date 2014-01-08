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
	string unit_get_name();
	float unit_get_max_health();
	float unit_get_current_health();
	int unit_get_range();
	float unit_get_damage();
	float unit_get_base_attack_speed();
	float unit_get_armor();
	float unit_get_magic_resist();
	float unit_get_movespeed();
	int unit_get_critical_chance();
	int unit_get_counter();

	//setters
	void unit_set_name(string new_name);
	void unit_set_max_health(float new_max_health);
	void unit_set_current_health(float new_current_health);
	void unit_set_range(int new_range);
	void unit_set_damage(float new_damage);
	void unit_set_base_attack_speed(float new_base_attack_speed);
	void unit_set_armor(float new_armor);
	void unit_set_magic_resist(float new_magic_resist);
	void unit_set_movespeed(float new_movespeed);
	void unit_set_critical_chance(int new_critical_chance);
	void unit_set_counter(int new_counter);

	//stats shared by both jungle minions and champions
	//string name;
	//float max_health;
	//float current_health;
	//int range;
	//float damage;
	//float base_attack_speed;
	//float armor;
	//float magic_resist;
	//float movespeed;
	//int critical_chance;
	//int counter;
};

#endif
