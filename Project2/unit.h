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
	string get_name();
	float get_max_health();
	float get_current_health();
	int get_range();
	float get_damage();
	float get_base_attack_speed();
	float get_armor();
	float get_magic_resist();
	float get_movespeed();
	int get_critical_chance();
	int get_counter();

	//setters
	void set_name(string new_name);
	void set_max_health(float new_max_health);
	void set_current_health(float new_current_health);
	void set_range(int new_range);
	void set_damage(float new_damage);
	void set_base_attack_speed(float new_base_attack_speed);
	void set_armor(float new_armor);
	void set_magic_resist(float new_magic_resist);
	void set_movespeed(float new_movespeed);
	void set_critical_chance(int new_critical_chance);
	void set_counter(int new_counter);
};

#endif
