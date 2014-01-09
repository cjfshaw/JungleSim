#include "Monsterfactory.h"

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