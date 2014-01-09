#include "Monsterfactory.h"

<<<<<<< HEAD
Monster Monsterfactory::CreateElderLizard(Monster new_Monster)
{
	new_Monster.setName("ElderLizard");
	new_Monster.setMaxHealth(1400);
	new_Monster.setCurrentHealth(1400);
	new_Monster.setRange(100);
	new_Monster.setDamage(65);
	new_Monster.setBaseAttackSpeed(0.625);
	new_Monster.setArmor(20);
	new_Monster.setMagicResist(0);
	new_Monster.setExperienceGiven(260);
	new_Monster.setCounter(1);
	new_Monster.setMovespeed(0);
	new_Monster.setCriticalChance(0);

	return new_Monster;
} //name goes from "ElderLizard" to "" for some reason when it gets to this line - not sure if this is causing everything else to error out or not
=======
monster * monsterfactory::CreateElderLizard()
{
	monster * new_monster = new monster();
	
	new_monster.set_name("ElderLizard");
	new_monster.set_max_health(1400);
	new_monster.set_current_health(1400);
	new_monster.set_range(100);
	new_monster.set_damage(65);
	new_monster.set_base_attack_speed(0.625);
	new_monster.set_armor(20);
	new_monster.set_magic_resist(0);
	new_monster.set_experience_given(260);
	new_monster.set_counter(1);
	new_monster.set_movespeed(0);
	new_monster.set_critical_chance(0);

	return new_monster;
} //name goes from "ElderLizard" to "" for some reason when it gets to this line - not sure if this is causing everything else to error out or not
>>>>>>> 8a5b312df82212a0b1c189d242676aebf0e25e86
