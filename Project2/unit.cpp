#include "unit.h"

//getters
string unit::getName()
{
	return name;
}

float unit::getMaxHealth()
{
	return max_health;
}

float unit::getCurrentHealth()
{
	return current_health;
}

int unit::getRange()
{
	return range;
}

float unit::getDamage()
{
	return damage;
}

float unit::getBaseAttackSpeed()
{
	return base_attack_speed;
}

float unit::getArmor()
{
	return armor;
}

float unit::getMagicResist()
{
	return magic_resist;
}

float unit::getMovespeed()
{
	return movespeed;
}

int unit::getCriticalChance()
{
	return critical_chance;
}

int unit::getCounter()
{
	return counter;
}

//setters
void unit::setName(string new_name)
{
	name = new_name;
}

void unit::setMaxHealth(float new_max_health)
{
	max_health = new_max_health;
}

void unit::setCurrentHealth(float new_current_health)
{
	current_health = new_current_health;
}

void unit::setRange(int new_range)
{
	range = new_range;
}

void unit::setDamage(float new_damage)
{
	damage = new_damage;
}

void unit::setBaseAttackSpeed(float new_base_attack_speed)
{
	base_attack_speed = new_base_attack_speed;
}

void unit::setArmor(float new_armor)
{
	armor = new_armor;
}

void unit::setMagicResist(float new_magic_resist)
{
	magic_resist = new_magic_resist;
}

void unit::setMovespeed(float new_movespeed)
{
	movespeed = new_movespeed;
}

void unit::setCriticalChance(int new_critical_chance)
{
	critical_chance = new_critical_chance;
}

void unit::setCounter(int new_counter)
{
	counter = new_counter;
}