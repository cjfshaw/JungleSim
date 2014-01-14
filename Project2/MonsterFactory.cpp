#include "Monsterfactory.h"

Monster * Monsterfactory::CreateElderLizard()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("ElderLizard");
	new_monster->setMaxHealth(1500);
	new_monster->setCurrentHealth(1500);
	new_monster->setRange(100);
	new_monster->setDamage(60);
	new_monster->setBaseAttackSpeed(0.625);
	new_monster->setArmor(20);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(260);
	new_monster->setCounter(1);
	new_monster->setMovespeed(330);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateAncientGolem()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("AncientGolem");
	new_monster->setMaxHealth(1500);
	new_monster->setCurrentHealth(1500);
	new_monster->setRange(100);
	new_monster->setDamage(60);
	new_monster->setBaseAttackSpeed(0.613);
	new_monster->setArmor(20);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(260);
	new_monster->setCounter(1);
	new_monster->setMovespeed(200);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateYoungLizard()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("YoungLizard");
	new_monster->setMaxHealth(400);
	new_monster->setCurrentHealth(400);
	new_monster->setRange(500);
	new_monster->setDamage(12);
	new_monster->setBaseAttackSpeed(0.679);
	new_monster->setArmor(8);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(20);
	new_monster->setCounter(1);
	new_monster->setMovespeed(330);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateWraith()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("Wraith");
	new_monster->setMaxHealth(1000);
	new_monster->setCurrentHealth(1000);
	new_monster->setRange(300);
	new_monster->setDamage(35);
	new_monster->setBaseAttackSpeed(0.638);
	new_monster->setArmor(15);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(90);
	new_monster->setCounter(1);
	new_monster->setMovespeed(300);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateLesserWraith()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("LesserWaith");
	new_monster->setMaxHealth(150);
	new_monster->setCurrentHealth(150);
	new_monster->setRange(100);
	new_monster->setDamage(10);
	new_monster->setBaseAttackSpeed(0.63);
	new_monster->setArmor(20);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(20);
	new_monster->setCounter(1);
	new_monster->setMovespeed(330);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateBigGolem()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("BigGolem");
	new_monster->setMaxHealth(1200);
	new_monster->setCurrentHealth(1200);
	new_monster->setRange(150);
	new_monster->setDamage(54);
	new_monster->setBaseAttackSpeed(0.613);
	new_monster->setArmor(12);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(140);
	new_monster->setCounter(1);
	new_monster->setMovespeed(350);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateGolem()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("Golem");
	new_monster->setMaxHealth(450);
	new_monster->setCurrentHealth(450);
	new_monster->setRange(150);
	new_monster->setDamage(30);
	new_monster->setBaseAttackSpeed(0.613);
	new_monster->setArmor(12);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(40);
	new_monster->setCounter(1);
	new_monster->setMovespeed(350);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateWight()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("Wight");
	new_monster->setMaxHealth(1400);
	new_monster->setCurrentHealth(1400);
	new_monster->setRange(100);
	new_monster->setDamage(75);
	new_monster->setBaseAttackSpeed(0.64);
	new_monster->setArmor(15);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(150);
	new_monster->setCounter(1);
	new_monster->setMovespeed(330);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateGiantWolf()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("GiantWolf");
	new_monster->setMaxHealth(1100);
	new_monster->setCurrentHealth(1100);
	new_monster->setRange(100);
	new_monster->setDamage(40);
	new_monster->setBaseAttackSpeed(0.679);
	new_monster->setArmor(9);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(110);
	new_monster->setCounter(1);
	new_monster->setMovespeed(443);
	new_monster->setCriticalChance(0);

	return new_monster;
}

Monster * Monsterfactory::CreateWolf()
{
	Monster * new_monster = new Monster();
	
	new_monster->setName("Wolf");
	new_monster->setMaxHealth(200);
	new_monster->setCurrentHealth(200);
	new_monster->setRange(100);
	new_monster->setDamage(14);
	new_monster->setBaseAttackSpeed(0.679);
	new_monster->setArmor(6);
	new_monster->setMagicResist(0);
	new_monster->setExperienceGiven(25);
	new_monster->setCounter(1);
	new_monster->setMovespeed(443);
	new_monster->setCriticalChance(0);

	return new_monster;
}