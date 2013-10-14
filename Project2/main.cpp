#include "stdlib.h"
#include <iostream>
#include <ctime> //for timer
//#include <Windows.h> //for sleep

#include "champ.h"
#include "monster.h"

using namespace std;

void ChampionAttack(monster *target, champ *attacker)
{
	(*target).hp=(*target).hp-( (*attacker).dmg * ( 100 / (100 + (*target).armor ) ) );
	cout << (*attacker).name << " attacks" << endl;
	cout << (*target).name << " health " << (*target).hp << endl;
	(*attacker).counter++;
	
	if ( (*target).hp <= 0 )
	{
		cout << (*target).name << " is dead." << endl;
		(*attacker).exp = (*attacker).exp + (*target).exp_given;
		(*attacker).CheckExp();
	}
}

void MonsterAttack(champ *target, monster *attacker)
{
	(*target).hp = (*target).hp - ( (*attacker).dmg * ( 100 / (100 + (*target).armor ) ) );
	cout << (*attacker).name << " attacks" << endl;
	cout << (*target).name << " health " << (*target).hp << endl;
	(*attacker).counter++;
}

int main()
{//change young lizard naming convention to something that shows what camp they belong to
	//condense fighting these camps into functions and subfunctions, a lot of repeated code
	//account for time between camps
	//account for start time (1:55)
	//still need to account for items, runes, masteries, and abilities, timing, and regen, and proper damage ratios
	//minions scaling over time, buff transfer, sigil (hp/mp from big minions) transfer
	//335 ms (22s), 360 ms (20.5s), 375 ms (20s), 403 ms (19s), 325 ms (21s), 416 ms (18.5-19s), 
	//361 ms (19.5-20), 389 ms (18.5s), 387 ms (19s)
		//ms * time to get distance
	champ hero;
	monster ElderLizard;
	monster YoungLizard1;
	monster YoungLizard2;

	monster AncientGolem;
	monster YoungLizard3;
	monster YoungLizard4;

	hero.TestStats();//populate the empty champ/minion objects w this line and the next few lines
	ElderLizard.BecomeElderLizard();//there has to be a better way to do this i just dont know it
	YoungLizard1.BecomeYoungLizard();
	YoungLizard2.BecomeYoungLizard();

	AncientGolem.BecomeAncientGolem();
	YoungLizard3.BecomeYoungLizard();
	YoungLizard4.BecomeYoungLizard();

	clock_t time;
	time = clock();
	
	float elapsed_time;
	float elapsed_time2;

	float champ_atk_time = (1/hero.as)*1000;
	float elder_atk_time = (1/ElderLizard.as)*1000;
	float young_atk_time = (1/YoungLizard1.as)*1000;
	float ancient_atk_time = (1/AncientGolem.as)*1000;

	//int ChampCount=1;
	int AncientGolemCount=1;
	int YoungLizard3Count=1;
	int YoungLizard4Count=1;

	while( hero.hp > 0 && (ElderLizard.hp > 0 || YoungLizard1.hp > 0 || YoungLizard2.hp > 0 ) ) 
	{//this loop has the champion fighting the Elder Lizard camp
		//does not account for red buff or hp/mp sigil yet
		elapsed_time = clock() - time / (float) CLOCKS_PER_SEC; 
		elapsed_time2 = (clock() - time) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > champ_atk_time*hero.counter )
		{
			cout << "Elapsed time: " << elapsed_time << endl;
			if ( ElderLizard.hp > 0 ) //if elder lizard is alive atk him
			{	
				ChampionAttack(&ElderLizard, &hero);
			}
			else if ( YoungLizard1.hp > 0 ) //if young lizard 1 is alive atk him
			{			
				ChampionAttack( &YoungLizard1, &hero );
			}
			else if ( YoungLizard2.hp > 0 ) //if young lizard 2 is alive atk him
			{
				ChampionAttack( &YoungLizard2, &hero );
			}
		}
		if ( (elapsed_time > elder_atk_time*ElderLizard.counter) && ElderLizard.hp > 0 ) //elder lizard attacking champ
		{//refactor
			MonsterAttack(&hero, &ElderLizard);
		}
		if ( (elapsed_time > young_atk_time*YoungLizard1.counter) && YoungLizard1.hp > 0 ) //young lizard 1 attacking champ
		{//refactor
			MonsterAttack(&hero, &YoungLizard1);
		}
		if ( (elapsed_time > young_atk_time*YoungLizard2.counter) && YoungLizard2.hp > 0 ) //young lizard 2 attacking champ
		{//refactor
			MonsterAttack(&hero, &YoungLizard2);
		}
	}

	cout << "RED BUFF CAMP DEFEATED" << endl;

	cout << "Elapsed time: " << elapsed_time << endl;
	cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "Champ level: " << hero.level << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2
	

	while( hero.hp > 0 && (AncientGolem.hp > 0 || YoungLizard3.hp > 0 || YoungLizard4.hp > 0 ) ) 
	{//this loop has the champion fighting the Elder Lizard camp
		//does not account for red buff or hp/mp sigil yet
		//blue buff not working properly, don't know why!
		elapsed_time = clock() - time / (float) CLOCKS_PER_SEC; 
		elapsed_time2 = (clock() - time) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > champ_atk_time*hero.counter )
		{
			cout << "Elapsed time: " << elapsed_time << endl;
			if ( AncientGolem.hp > 0 ) //if elder lizard is alive atk him
			{	
				ChampionAttack(&AncientGolem, &hero);
			}
			else if ( YoungLizard3.hp > 0 ) //if young lizard 1 is alive atk him
			{			
				ChampionAttack( &YoungLizard3, &hero );
			}
			else if ( YoungLizard4.hp > 0 ) //if young lizard 2 is alive atk him
			{
				ChampionAttack( &YoungLizard4, &hero );
			}
		}
		if ( (elapsed_time > elder_atk_time*AncientGolem.counter) && AncientGolem.hp > 0 ) //elder lizard attacking champ
		{//refactor
			MonsterAttack(&hero, &AncientGolem);
		}
		if ( (elapsed_time > young_atk_time*YoungLizard3.counter) && YoungLizard3.hp > 0 ) //young lizard 1 attacking champ
		{//refactor
			MonsterAttack(&hero, &YoungLizard3);
		}
		if ( (elapsed_time > young_atk_time*YoungLizard4.counter) && YoungLizard4.hp > 0 ) //young lizard 2 attacking champ
		{//refactor
			MonsterAttack(&hero, &YoungLizard4);
		}
	}

	cout << "BLUE BUFF CAMP DEFEATED" << endl;

	cout << "Elapsed time: " << elapsed_time << endl;
	cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "Champ level: " << hero.level << endl; //TODO: LOOK AT THIS SHOWING 1 WHEN LEVEL IS 2


	/*while( hero.hp > 0 && (AncientGolem.hp > 0 || YoungLizard3.hp > 0 || YoungLizard4.hp > 0 ) ) 
	{//this loop has the champion fighting the Ancient Golem camp
		//does not account for blue buff or hp/mp sigil yet
		elapsed_time = clock() - time / (float) CLOCKS_PER_SEC; 
		elapsed_time2 = (clock() - time) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > champ_atk_time*ChampCount )
		{
			if ( AncientGolem.hp > 0 ) //if elder lizard is alive atk him
			{//refactor
				AncientGolem.hp = AncientGolem.hp - ( hero.dmg * ( 100 / (100 + AncientGolem.armor ) ) );
				cout << "champ attacks" << endl;
				cout << "Ancient Golem health " << AncientGolem.hp << endl;
				ChampCount++;
				if ( AncientGolem.hp <= 0 )
				{
					cout << "Ancient Golem is dead." << endl;
					hero.exp = hero.exp + AncientGolem.exp_given;
					hero.CheckExp();
				}
			}
			else if ( YoungLizard3.hp > 0 ) //if Young Lizard 3 is alive atk him
			{//refactor
				YoungLizard3.hp = YoungLizard3.hp - ( hero.dmg * ( 100 / (100 + YoungLizard3.armor ) ) );
				cout << "champ attacks" << endl;
				cout << "Young Lizard 3 health " << YoungLizard3.hp << endl;
				ChampCount++;
				if ( YoungLizard3.hp <= 0 )
				{
					cout << "Young Lizard 3 is dead." << endl;
					hero.exp = hero.exp + YoungLizard3.exp_given;
					hero.CheckExp();
				}
			}
			else if ( YoungLizard4.hp > 0 ) //if Young Lizard 4 is alive atk him
			{//refactor
				YoungLizard4.hp = YoungLizard4.hp - ( hero.dmg * ( 100 / (100 + YoungLizard4.armor ) ) );
				cout << "champ attacks" << endl;
				cout << "Young Lizard 4 health " << YoungLizard4.hp << endl;
				ChampCount++;
				if ( YoungLizard4.hp <= 0 )
				{
					cout << "Young Lizard 4 is dead." << endl;
					hero.exp = hero.exp + YoungLizard4.exp_given;
					hero.CheckExp();
				}
			}
		}
		if ( (elapsed_time > ancient_atk_time*AncientGolemCount) && AncientGolem.hp > 0 ) //elder lizard attacking champ
		{//refactor
			hero.hp = hero.hp - AncientGolem.dmg;
			cout << "Ancient Golem attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			AncientGolemCount++;
		}
		if ( (elapsed_time > young_atk_time*YoungLizard3Count) && YoungLizard3.hp > 0 ) //Young Lizard 3 attacking champ
		{//refactor
			hero.hp = hero.hp - YoungLizard3.dmg;
			cout << "Young Lizard 3 attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			YoungLizard3Count++;
		}
		if ( (elapsed_time > young_atk_time*YoungLizard4Count) && YoungLizard4.hp > 0 ) //Young Lizard 4 attacking champ
		{//refactor
			hero.hp = hero.hp - YoungLizard4.dmg;
			cout << "Young Lizard 4 attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			YoungLizard4Count++;
		}
	}

	cout << "BLUE BUFF CAMP DEFEATED" << endl;

	cout << "Elapsed time: " << elapsed_time << endl;
	cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "Champ level: " << hero.level << endl;*/

	cin.get();
	return 0;
}