#include "unit.h"

//getters
string unit::get_name()
{
	return name;
}

float unit::get_max_health()
{
	return max_health;
}

float unit::get_current_health()
{
	return current_health;
}

int unit::get_range()
{
	return range;
}

float unit::get_damage()
{
	return damage;
}

float unit::get_base_attack_speed()
{
	return base_attack_speed;
}

float unit::get_armor()
{
	return armor;
}

float unit::get_magic_resist()
{
	return magic_resist;
}

float unit::get_movespeed()
{
	return movespeed;
}

int unit::get_critical_chance()
{
	return critical_chance;
}

int unit::get_counter()
{
	return counter;
}

//setters
void unit::set_name(string new_name)
{
	name = new_name;
}

void unit::set_max_health(float new_max_health)
{
	max_health = new_max_health;
}

void unit::set_current_health(float new_current_health)
{
	current_health = new_current_health;
}

void unit::set_range(int new_range)
{
	range = new_range;
}

void unit::set_damage(float new_damage)
{
	damage = new_damage;
}

void unit::set_base_attack_speed(float new_base_attack_speed)
{
	base_attack_speed = new_base_attack_speed;
}

void unit::set_armor(float new_armor)
{
	armor = new_armor;
}

void unit::set_magic_resist(float new_magic_resist)
{
	magic_resist = new_magic_resist;
}

void unit::set_movespeed(float new_movespeed)
{
	movespeed = new_movespeed;
}

void unit::set_critical_chance(int new_critical_chance)
{
	critical_chance = new_critical_chance;
}

void unit::set_counter(int new_counter)
{
	counter = new_counter;
}