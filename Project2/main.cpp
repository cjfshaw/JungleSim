#include "stdlib.h"
#include <iostream>
#include <ctime> //for timer
#include <thread>

#include "Champ.h"
#include "Monster.h"
#include "MonsterFactory.h"

using namespace std;

//SOME CHANGES TO CHECK WHETHER DEV BRANCH WORKS AND HOW

void ChampionAttack(Monster *target, Champ *attacker);

void MonsterAttack(Champ *target, Monster *attacker);

void Fightcamp(Champ *Champion, Monster *big_Monster, Monster *little_Monster1, Monster *little_Monster2, clock_t *timex );

/*void Fightcamp2(Champ *Champion, Monster *big_Monster, Monster *little_Monster1, Monster *little_Monster2, float *elapsed_time )
{ //This function has a Champion fight an entire camp.  He attacks one Monster until it dies and then moves onto the next one
	//until there are no targets left in the camp.
	//The first target attack is the strongest enemy.  This function uses the ChampionAttack and MonsterAttack functions.

	//float elapsed_time;
	//float elapsed_time2;

	float Champ_atk_time = (1/(*Champion).base_attack_speed)*1000;
	float elder_atk_time = (1/(*big_Monster).base_attack_speed)*1000;
	float young_atk_time = (1/(*little_Monster1).base_attack_speed)*1000;
	float ancient_atk_time = (1/(*little_Monster2).base_attack_speed)*1000;

	while( (*Champion).current_health > 0 && ((*big_Monster).current_health > 0 || (*little_Monster1).current_health > 0 || (*little_Monster2).current_health > 0 ) ) 
	{
	//does not account for red buff or current_health/mana sigil yet
		//elapsed_time = clock() - (*timex) / (float) CLOCKS_PER_SEC; 
		//elapsed_time2 = (clock() - (*timex) ) / (float) CLOCKS_PER_SEC; 

		if ( *elapsed_time > Champ_atk_time*(*Champion).counter )
		{
			cout << "Elapsed time: " << elapsed_time << endl;
			if ( (*big_Monster).current_health > 0 ) //if the large Monster is alive attack him
			{	
				ChampionAttack( &(*big_Monster), &(*Champion) );
			}
			else if ( (*little_Monster1).current_health > 0 ) //if the first young lizard is alive attack him
			{			
				ChampionAttack( &(*little_Monster1), &(*Champion) );
			}
			else if ( (*little_Monster2).current_health > 0 ) //if the second young lizard is alive attack him
			{
				ChampionAttack( &(*little_Monster2), &(*Champion) );
			}
		}
		if ( (*elapsed_time > elder_atk_time*(*big_Monster).counter) && (*big_Monster).current_health > 0 ) //if the large Monster is alive, attack the Champion
		{
			MonsterAttack( &(*Champion), &(*big_Monster) );
		}
		if ( (*elapsed_time > young_atk_time*(*little_Monster1).counter) && (*little_Monster1).current_health > 0 ) //if the first small lizard is alive, attack the Champion
		{
			MonsterAttack( &(*Champion), &(*little_Monster1) );
		}
		if ( (*elapsed_time > young_atk_time*(*little_Monster2).counter) && (*little_Monster2).current_health > 0 ) //if the second small lizard is alive, attack the Champion
		{
			MonsterAttack( &(*Champion), &(*little_Monster2) );
		}
	}

	cout << (*big_Monster).name << " camp DEFEATED" << endl;

	cout << "Elapsed time: " << *elapsed_time << endl;
	//cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "Champ level: " << (*Champion).level << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2
}*/

int main()
{
	
	//GENERATE ChampION AND GOLEM/LIZARD camps
	Champ hero;
	
	//Monsterfactory MFactory;

<<<<<<< HEAD
	Monster ElderLizard;
	Monster YoungLizard1;
	Monster YoungLizard2;
=======
	monster * ElderLizard;
	monster YoungLizard1;
	monster YoungLizard2;
>>>>>>> 8a5b312df82212a0b1c189d242676aebf0e25e86

	Monster AncientGolem;
	Monster YoungLizard3;
	Monster YoungLizard4;

<<<<<<< HEAD
	//MFactory.CreateElderLizard(ElderLizard);
=======
	ElderLizard = MFactory.CreateElderLizard();
>>>>>>> 8a5b312df82212a0b1c189d242676aebf0e25e86

	//POPULATE ChampION AND JUNGLE MonsterS WITH PROPER STATS
	hero.PopulateChamp();

	ElderLizard.BecomeElderLizard();
	YoungLizard1.BecomeYoungLizard();
	YoungLizard2.BecomeYoungLizard();

	AncientGolem.BecomeAncientGolem();
	YoungLizard3.BecomeYoungLizard();
	YoungLizard4.BecomeYoungLizard();

	//INITIALIZE THE SIMULATION'S CLOCK
	clock_t time;
	time = clock();

	//FIGHT THE JUNGLE camps
	Fightcamp( &hero, &ElderLizard, &YoungLizard1, &YoungLizard2, &time );

	Fightcamp( &hero, &AncientGolem, &YoungLizard3, &YoungLizard4, &time );

	std::cin.get();//WAIT SO THE PROGRAM DOESN'T EXIT AUTOMATICALLY
	return 0;
}

void ChampionAttack(Monster *target, Champ *attacker)
{ //This function has the Champion attack a given target once.  It makes use of the Checkexperience function.
	(*target).setCurrentHealth( (*target).getCurrentHealth()-( (*attacker).getDamage() * ( 100 / (100 + (*target).getArmor() ) ) ) );
	cout << (*attacker).getName() << " attacks" << endl;
	cout << (*target).getName() << " health " << (*target).getCurrentHealth() << endl;
	(*attacker).setCounter( (*attacker).getCounter() + 1 );
	
	if ( (*target).getCurrentHealth() <= 0 )
	{
		cout << (*target).getName() << " is dead." << endl;
		(*attacker).setExperience( (*attacker).getExperience() + (*target).getExperienceGiven() );
		(*attacker).Checkexperience();
	}
}

void MonsterAttack(Champ *target, Monster *attacker)
{ //This function has a given Monster attack the Champion once.
	(*target).setCurrentHealth( (*target).getCurrentHealth() - ( (*attacker).getDamage() * ( 100 / (100 + (*target).getArmor() ) ) ) );
	cout << (*attacker).getName() << " attacks" << endl;
	cout << (*target).getName() << " health " << (*target).getCurrentHealth() << endl;
	(*attacker).setCounter( (*attacker).getCounter() + 1 );
}

void Fightcamp(Champ *Champion, Monster *big_Monster, Monster *little_Monster1, Monster *little_Monster2, clock_t *timex )
{ //This function has a Champion fight an entire camp.  He attacks one Monster until it dies and then moves onto the next one
	//until there are no targets left in the camp.
	//The first target attack is the strongest enemy.  This function uses the ChampionAttack and MonsterAttack functions.

	float elapsed_time;
	//float elapsed_time2;

	float Champ_atk_time = (1/(*Champion).getBaseAttackSpeed() )*1000;
	float elder_atk_time = (1/(*big_Monster).getBaseAttackSpeed() )*1000;
	float young_atk_time = (1/(*little_Monster1).getBaseAttackSpeed() )*1000;
	float ancient_atk_time = (1/(*little_Monster2).getBaseAttackSpeed() )*1000;

	while( (*Champion).getCurrentHealth() > 0 && ((*big_Monster).getCurrentHealth() > 0 || (*little_Monster1).getCurrentHealth() > 0 || (*little_Monster2).getCurrentHealth() > 0 ) ) 
	{
	//does not account for red buff or current_health/mana sigil yet
		elapsed_time = clock() - (*timex) / (float) CLOCKS_PER_SEC; 
		//elapsed_time2 = (clock() - (*timex) ) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > Champ_atk_time*(*Champion).getCounter() )
		{
			cout << "Elapsed time: " << elapsed_time << endl;
			if ( (*big_Monster).getCurrentHealth() > 0 ) //if the large Monster is alive attack him
			{	
				ChampionAttack( &(*big_Monster), &(*Champion) );
			}
			else if ( (*little_Monster1).getCurrentHealth() > 0 ) //if the first young lizard is alive attack him
			{			
				ChampionAttack( &(*little_Monster1), &(*Champion) );
			}
			else if ( (*little_Monster2).getCurrentHealth() > 0 ) //if the second young lizard is alive attack him
			{
				ChampionAttack( &(*little_Monster2), &(*Champion) );
			}
		}
		if ( (elapsed_time > elder_atk_time*(*big_Monster).getCounter() ) && (*big_Monster).getCurrentHealth() > 0 ) //if the large Monster is alive, attack the Champion
		{
			MonsterAttack( &(*Champion), &(*big_Monster) );
		}
		if ( (elapsed_time > young_atk_time*(*little_Monster1).getCounter() ) && (*little_Monster1).getCurrentHealth() > 0 ) //if the first small lizard is alive, attack the Champion
		{
			MonsterAttack( &(*Champion), &(*little_Monster1) );
		}
		if ( (elapsed_time > young_atk_time*(*little_Monster2).getCounter() ) && (*little_Monster2).getCurrentHealth() > 0 ) //if the second small lizard is alive, attack the Champion
		{
			MonsterAttack( &(*Champion), &(*little_Monster2) );
		}
	}

	cout << (*big_Monster).getName() << " camp DEFEATED" << endl;

	cout << "Elapsed time: " << elapsed_time << endl;
	//cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "Champ level: " << (*Champion).getLevel() << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2
}
