#include "stdlib.h"
#include <iostream>
#include <ctime> //for timer
#include <Windows.h> //for sleep

#include "champ.h"
#include "monster.h"

using namespace std;

void ChampionAttack(monster *target, champ *attacker)
{
	(*target).current_hp=(*target).current_hp-( (*attacker).dmg * ( 100 / (100 + (*target).armor ) ) );
	cout << (*attacker).name << " attacks" << endl;
	cout << (*target).name << " health " << (*target).current_hp << endl;
	(*attacker).counter++;
	
	if ( (*target).current_hp <= 0 )
	{
		cout << (*target).name << " is dead." << endl;
		(*attacker).exp = (*attacker).exp + (*target).exp_given;
		(*attacker).CheckExp();
	}
}

void MonsterAttack(champ *target, monster *attacker)
{
	(*target).current_hp = (*target).current_hp - ( (*attacker).dmg * ( 100 / (100 + (*target).armor ) ) );
	cout << (*attacker).name << " attacks" << endl;
	cout << (*target).name << " health " << (*target).current_hp << endl;
	(*attacker).counter++;
}

void FightCamp(champ *champion, monster *big_monster, monster *little_monster1, monster *little_monster2, clock_t *timex )
{

	float elapsed_time;
	float elapsed_time2;

	float champ_atk_time = (1/(*champion).as)*1000;
	float elder_atk_time = (1/(*big_monster).as)*1000;
	float young_atk_time = (1/(*little_monster1).as)*1000;
	float ancient_atk_time = (1/(*little_monster2).as)*1000;

	while( (*champion).current_hp > 0 && ((*big_monster).current_hp > 0 || (*little_monster1).current_hp > 0 || (*little_monster2).current_hp > 0 ) ) 
	{//this loop has the champion fighting the Elder Lizard camp
	//does not account for red buff or current_hp/mp sigil yet
		elapsed_time = clock() - (*timex) / (float) CLOCKS_PER_SEC; 
		elapsed_time2 = (clock() - (*timex) ) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > champ_atk_time*(*champion).counter )
		{
			cout << "Elapsed time: " << elapsed_time << endl;
			if ( (*big_monster).current_hp > 0 ) //if the large monster is alive atk him
			{	
				ChampionAttack( &(*big_monster), &(*champion) );
			}
			else if ( (*little_monster1).current_hp > 0 ) //if the first young lizard is alive atk him
			{			
				ChampionAttack( &(*little_monster1), &(*champion) );
			}
			else if ( (*little_monster2).current_hp > 0 ) //if the second young lizard is alive atk him
			{
				ChampionAttack( &(*little_monster2), &(*champion) );
			}
		}
		if ( (elapsed_time > elder_atk_time*(*big_monster).counter) && (*big_monster).current_hp > 0 ) //elder lizard attacking champ
		{//refactor
			MonsterAttack( &(*champion), &(*big_monster) );
		}
		if ( (elapsed_time > young_atk_time*(*little_monster1).counter) && (*little_monster1).current_hp > 0 ) //young lizard 1 attacking champ
		{//refactor
			MonsterAttack( &(*champion), &(*little_monster1) );
		}
		if ( (elapsed_time > young_atk_time*(*little_monster2).counter) && (*little_monster2).current_hp > 0 ) //young lizard 2 attacking champ
		{//refactor
			MonsterAttack( &(*champion), &(*little_monster2) );
		}
	}

	cout << (*big_monster).name << " CAMP DEFEATED" << endl;

	cout << "Elapsed time: " << elapsed_time << endl;
	cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "Champ level: " << (*champion).level << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2
}

int main()
{
	//account for time between camps
	//account for start time (1:55)
	//still need to account for items, runes, masteries, and abilities, timing, and regen, and proper damage ratios
	//minions scaling over time, buff transfer, sigil (hp/mp from big minions) transfer
	//335 ms (22s), 360 ms (20.5s), 375 ms (20s), 403 ms (19s), 325 ms (21s), 416 ms (18.5-19s), 
	//361 ms (19.5-20), 389 ms (18.5s), 387 ms (19s)
		//ms * time to get distance
	
	//GENERATE CHAMPION AND GOLEM/LIZARD CAMPS
	champ hero;
	
	monster ElderLizard;
	monster YoungLizard1;
	monster YoungLizard2;

	monster AncientGolem;
	monster YoungLizard3;
	monster YoungLizard4;

	//POPULATE CHAMPION AND JUNGLE MONSTERS WITH PROPER STATS
	hero.TestStats();

	ElderLizard.BecomeElderLizard();
	YoungLizard1.BecomeYoungLizard();
	YoungLizard2.BecomeYoungLizard();

	AncientGolem.BecomeAncientGolem();
	YoungLizard3.BecomeYoungLizard();
	YoungLizard4.BecomeYoungLizard();

	//INITIALIZE AND START THE SIMULATION'S CLOCK
	clock_t time;
	time = clock();
	
	//FIGHT THE JUNGLE CAMPS
	//TODO: Make this interchangeable based on used input, whether you start blue or red.
	FightCamp( &hero, &ElderLizard, &YoungLizard1, &YoungLizard2, &time );
	//Need to double check that this works after ElderLizard dies, seems to be scrolling by very quickly after
	//Elder and before AncientGolem.  Eliminate some text output or pipe to text file to verify.

	FightCamp( &hero, &AncientGolem, &YoungLizard3, &YoungLizard4, &time );

	std::cin.get();//WAIT SO THE PROGRAM DOESN'T EXIT AUTOMATICALLY
	return 0;
}
