#include "stdlib.h"
#include <iostream>
#include <ctime> //for timer
#include <thread>

#include "champ.h"
#include "monster.h"
#include "MonsterFactory.h"

using namespace std;

//SOME CHANGES TO CHECK WHETHER DEV BRANCH WORKS AND HOW

void championAttack(monster *target, champ *attacker);

void MonsterAttack(champ *target, monster *attacker);

void Fightcamp(champ *champion, monster *big_monster, monster *little_monster1, monster *little_monster2, clock_t *timex );

/*void Fightcamp2(champ *champion, monster *big_monster, monster *little_monster1, monster *little_monster2, float *elapsed_time )
{ //This function has a champion fight an entire camp.  He attacks one monster until it dies and then moves onto the next one
	//until there are no targets left in the camp.
	//The first target attack is the strongest enemy.  This function uses the championAttack and MonsterAttack functions.

	//float elapsed_time;
	//float elapsed_time2;

	float champ_atk_time = (1/(*champion).base_attack_speed)*1000;
	float elder_atk_time = (1/(*big_monster).base_attack_speed)*1000;
	float young_atk_time = (1/(*little_monster1).base_attack_speed)*1000;
	float ancient_atk_time = (1/(*little_monster2).base_attack_speed)*1000;

	while( (*champion).current_health > 0 && ((*big_monster).current_health > 0 || (*little_monster1).current_health > 0 || (*little_monster2).current_health > 0 ) ) 
	{
	//does not account for red buff or current_health/mana sigil yet
		//elapsed_time = clock() - (*timex) / (float) CLOCKS_PER_SEC; 
		//elapsed_time2 = (clock() - (*timex) ) / (float) CLOCKS_PER_SEC; 

		if ( *elapsed_time > champ_atk_time*(*champion).counter )
		{
			cout << "Elapsed time: " << elapsed_time << endl;
			if ( (*big_monster).current_health > 0 ) //if the large monster is alive attack him
			{	
				championAttack( &(*big_monster), &(*champion) );
			}
			else if ( (*little_monster1).current_health > 0 ) //if the first young lizard is alive attack him
			{			
				championAttack( &(*little_monster1), &(*champion) );
			}
			else if ( (*little_monster2).current_health > 0 ) //if the second young lizard is alive attack him
			{
				championAttack( &(*little_monster2), &(*champion) );
			}
		}
		if ( (*elapsed_time > elder_atk_time*(*big_monster).counter) && (*big_monster).current_health > 0 ) //if the large monster is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*big_monster) );
		}
		if ( (*elapsed_time > young_atk_time*(*little_monster1).counter) && (*little_monster1).current_health > 0 ) //if the first small lizard is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*little_monster1) );
		}
		if ( (*elapsed_time > young_atk_time*(*little_monster2).counter) && (*little_monster2).current_health > 0 ) //if the second small lizard is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*little_monster2) );
		}
	}

	cout << (*big_monster).name << " camp DEFEATED" << endl;

	cout << "Elapsed time: " << *elapsed_time << endl;
	//cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "champ level: " << (*champion).level << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2
}*/

int main()
{
	
	//GENERATE CHAMPION AND GOLEM/LIZARD camps
	champ hero;
	
	monsterfactory MFactory;

	monster * ElderLizard;
	monster YoungLizard1;
	monster YoungLizard2;

	monster AncientGolem;
	monster YoungLizard3;
	monster YoungLizard4;

	ElderLizard = MFactory.CreateElderLizard();

	//POPULATE champION AND JUNGLE MONSTERS WITH PROPER STATS
	hero.PopulateChamp();

	//ElderLizard.BecomeElderLizard();
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

void championAttack(monster *target, champ *attacker)
{ //This function has the champion attack a given target once.  It makes use of the Checkexperience function.
	(*target).set_current_health( (*target).get_current_health()-( (*attacker).get_damage() * ( 100 / (100 + (*target).get_armor() ) ) ) );
	cout << (*attacker).get_name() << " attacks" << endl;
	cout << (*target).get_name() << " health " << (*target).get_current_health() << endl;
	(*attacker).set_counter( (*attacker).get_counter() + 1 );
	
	if ( (*target).get_current_health() <= 0 )
	{
		cout << (*target).get_name() << " is dead." << endl;
		(*attacker).experience = (*attacker).experience + (*target).get_experience_given();
		(*attacker).Checkexperience();
	}
}

void MonsterAttack(champ *target, monster *attacker)
{ //This function has a given monster attack the champion once.
	(*target).set_current_health( (*target).get_current_health() - ( (*attacker).get_damage() * ( 100 / (100 + (*target).get_armor() ) ) ) );
	cout << (*attacker).get_name() << " attacks" << endl;
	cout << (*target).get_name() << " health " << (*target).get_current_health() << endl;
	(*attacker).set_counter( (*attacker).get_counter() + 1 );
}

void Fightcamp(champ *champion, monster *big_monster, monster *little_monster1, monster *little_monster2, clock_t *timex )
{ //This function has a champion fight an entire camp.  He attacks one monster until it dies and then moves onto the next one
	//until there are no targets left in the camp.
	//The first target attack is the strongest enemy.  This function uses the championAttack and MonsterAttack functions.

	float elapsed_time;
	//float elapsed_time2;

	float champ_atk_time = (1/(*champion).get_base_attack_speed() )*1000;
	float elder_atk_time = (1/(*big_monster).get_base_attack_speed() )*1000;
	float young_atk_time = (1/(*little_monster1).get_base_attack_speed() )*1000;
	float ancient_atk_time = (1/(*little_monster2).get_base_attack_speed() )*1000;

	while( (*champion).get_current_health() > 0 && ((*big_monster).get_current_health() > 0 || (*little_monster1).get_current_health() > 0 || (*little_monster2).get_current_health() > 0 ) ) 
	{
	//does not account for red buff or current_health/mana sigil yet
		elapsed_time = clock() - (*timex) / (float) CLOCKS_PER_SEC; 
		//elapsed_time2 = (clock() - (*timex) ) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > champ_atk_time*(*champion).get_counter() )
		{
			cout << "Elapsed time: " << elapsed_time << endl;
			if ( (*big_monster).get_current_health() > 0 ) //if the large monster is alive attack him
			{	
				championAttack( &(*big_monster), &(*champion) );
			}
			else if ( (*little_monster1).get_current_health() > 0 ) //if the first young lizard is alive attack him
			{			
				championAttack( &(*little_monster1), &(*champion) );
			}
			else if ( (*little_monster2).get_current_health() > 0 ) //if the second young lizard is alive attack him
			{
				championAttack( &(*little_monster2), &(*champion) );
			}
		}
		if ( (elapsed_time > elder_atk_time*(*big_monster).get_counter() ) && (*big_monster).get_current_health() > 0 ) //if the large monster is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*big_monster) );
		}
		if ( (elapsed_time > young_atk_time*(*little_monster1).get_counter() ) && (*little_monster1).get_current_health() > 0 ) //if the first small lizard is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*little_monster1) );
		}
		if ( (elapsed_time > young_atk_time*(*little_monster2).get_counter() ) && (*little_monster2).get_current_health() > 0 ) //if the second small lizard is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*little_monster2) );
		}
	}

	cout << (*big_monster).get_name() << " camp DEFEATED" << endl;

	cout << "Elapsed time: " << elapsed_time << endl;
	//cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "champ level: " << (*champion).level << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2
}
