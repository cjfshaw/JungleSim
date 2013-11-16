#include "stdlib.h"
#include <iostream>
#include <ctime> //for timer
#include <thread>

#include "champ.h"
#include "monster.h"

using namespace std;

void championAttack(monster *target, champ *attacker)
{ //This function has the champion attack a given target once.  It makes use of the Checkexperience function.
	(*target).current_health=(*target).current_health-( (*attacker).damage * ( 100 / (100 + (*target).armor ) ) );
	cout << (*attacker).name << " attacks" << endl;
	cout << (*target).name << " health " << (*target).current_health << endl;
	(*attacker).counter++;
	
	if ( (*target).current_health <= 0 )
	{
		cout << (*target).name << " is dead." << endl;
		(*attacker).experience = (*attacker).experience + (*target).experience_given;
		(*attacker).Checkexperience();
	}
}

void MonsterAttack(champ *target, monster *attacker)
{ //This function has a given monster attack the champion once.
	(*target).current_health = (*target).current_health - ( (*attacker).damage * ( 100 / (100 + (*target).armor ) ) );
	cout << (*attacker).name << " attacks" << endl;
	cout << (*target).name << " health " << (*target).current_health << endl;
	(*attacker).counter++;
}

void Fightcamp(champ *champion, monster *big_monster, monster *little_monster1, monster *little_monster2, clock_t *timex )
{ //This function has a champion fight an entire camp.  He attacks one monster until it dies and then moves onto the next one
	//until there are no targets left in the camp.
	//The first target attack is the strongest enemy.  This function uses the championAttack and MonsterAttack functions.

	float elapsed_time;
	//float elapsed_time2;

	float champ_atk_time = (1/(*champion).base_attack_speed)*1000;
	float elder_atk_time = (1/(*big_monster).base_attack_speed)*1000;
	float young_atk_time = (1/(*little_monster1).base_attack_speed)*1000;
	float ancient_atk_time = (1/(*little_monster2).base_attack_speed)*1000;

	while( (*champion).current_health > 0 && ((*big_monster).current_health > 0 || (*little_monster1).current_health > 0 || (*little_monster2).current_health > 0 ) ) 
	{
	//does not account for red buff or current_health/mana sigil yet
		elapsed_time = clock() - (*timex) / (float) CLOCKS_PER_SEC; 
		//elapsed_time2 = (clock() - (*timex) ) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > champ_atk_time*(*champion).counter )
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
		if ( (elapsed_time > elder_atk_time*(*big_monster).counter) && (*big_monster).current_health > 0 ) //if the large monster is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*big_monster) );
		}
		if ( (elapsed_time > young_atk_time*(*little_monster1).counter) && (*little_monster1).current_health > 0 ) //if the first small lizard is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*little_monster1) );
		}
		if ( (elapsed_time > young_atk_time*(*little_monster2).counter) && (*little_monster2).current_health > 0 ) //if the second small lizard is alive, attack the champion
		{
			MonsterAttack( &(*champion), &(*little_monster2) );
		}
	}

	cout << (*big_monster).name << " camp DEFEATED" << endl;

	cout << "Elapsed time: " << elapsed_time << endl;
	//cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "champ level: " << (*champion).level << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2
}

void Fightcamp2(champ *champion, monster *big_monster, monster *little_monster1, monster *little_monster2, float *elapsed_time )
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
}

void Regeneration(champ *champion, float *elapsed_time)
{
	//while 5s passes...

	if( (*champion).current_health < (*champion).max_health)
	{
		(*champion).current_health = (*champion).current_health + (*champion).health_regeneration;
			if( (*champion).current_health > (*champion).max_health)
			{
				(*champion).current_health = (*champion).max_health;
			}
	}
	
	if( (*champion).current_mana < (*champion).max_mana)
	{
		(*champion).current_mana = (*champion).current_mana + (*champion).mana_regeneration;
		if( (*champion).current_mana > (*champion).max_mana)
		{
			(*champion).current_mana = (*champion).max_mana;
		}
	}
}

void KeepTime( clock_t time, float time_difference )
{
	time_difference = clock() - (time) / (float) CLOCKS_PER_SEC;
}

int main()
{
	//move 'timer' outside of FightCamp, make it an input - not working right now
	//account for time between campttack
	//account for start time (1:55)
	//still need to account for items, runes, masteries, and abilities, timing, and regen
	//minions scaling over time, buff transfer, sigil (health/mana from big minions) transfer
	//335 movespeed (22s), 360 movespeed (20.5s), 375 movespeed (20s), 403 movespeed (19s), 325 movespeed (21s), 416 movespeed (18.5-19s), 
	//361 movespeed (19.5-20), 389 movespeed (18.5s), 387 movespeed (19s)
		//movespeed * time to get distance
	
	//GENERATE CHAMPION AND GOLEM/LIZARD camps
	champ hero;
	
	monster ElderLizard;
	monster YoungLizard1;
	monster YoungLizard2;

	monster AncientGolem;
	monster YoungLizard3;
	monster YoungLizard4;

	//POPULATE champION AND JUNGLE MONSTERS WITH PROPER STATS
	hero.PopulateChamp();

	ElderLizard.BecomeElderLizard();
	YoungLizard1.BecomeYoungLizard();
	YoungLizard2.BecomeYoungLizard();

	AncientGolem.BecomeAncientGolem();
	YoungLizard3.BecomeYoungLizard();
	YoungLizard4.BecomeYoungLizard();

	//bool MonstersAlive = true;

	//INITIALIZE THE SIMULATION'S CLOCK
	clock_t time;
	time = clock();

	float new_elapsed_time;
	//new_elapsed_time = clock() - (time) / (float) CLOCKS_PER_SEC;
	
	//thread time_thread( KeepTime, time, new_elapsed_time );

	//FIGHT THE JUNGLE camps
	//TODO: Make this interchangeable based on user input, whether you start blue or red.
	Fightcamp( &hero, &ElderLizard, &YoungLizard1, &YoungLizard2, &time );

	//Fightcamp2( &hero, &ElderLizard, &YoungLizard1, &YoungLizard2, &new_elapsed_time );
	//Fightcamp2( &hero, &AncientGolem, &YoungLizard3, &YoungLizard4, &new_elapsed_time );
	
	//Need to double check that this works after ElderLizard dies, seems to be scrolling by very quickly after
	//Elder and before AncientGolem.  Eliminate some text output or pipe to text file to verify.

	Fightcamp( &hero, &AncientGolem, &YoungLizard3, &YoungLizard4, &time );

	/*while( MonstersAlive )
	{//need to have the timer constantly updating in here and have the Fightcamp threads run off this timer...

		time_thread( KeepTime, time, new_elapsed_time );

		if ( YoungLizard4.current_health > 0 )
		{
			MonstersAlive = false;
		}
		else
		{
			MonstersAlive = true;
		}
	}*/









	time_thread.join();

	std::cin.get();//WAIT SO THE PROGRAM DOESN'T EXIT AUTOMATICALLY
	return 0;
}
