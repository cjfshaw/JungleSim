#include "champ.h"
#include "monster.h"

#include "stdlib.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	champ hero;
	monster ElderLizard;
	monster YoungLizard1;
	monster YoungLizard2;

	hero.TestStats();//populate the empty champ/minion objects w this line and the next 3
	ElderLizard.BecomeElderLizard();//there has to be a better way to do this i just dont know it
	YoungLizard1.BecomeYoungLizard();
	YoungLizard2.BecomeYoungLizard();

	clock_t time;
	time = clock();
	
	float elapsed_time;
	float elapsed_time2;

	float champ_atk_time = (1/hero.as)*1000;
	float elder_atk_time = (1/ElderLizard.as)*1000;
	float young_atk_time = (1/YoungLizard1.as)*1000;

	int ChampCount=1;
	int ElderLizardCount=1;
	int YoungLizard1Count=1;
	int YoungLizard2Count=1;

	while( hero.hp > 0 && (ElderLizard.hp > 0 || YoungLizard1.hp > 0 || YoungLizard2.hp > 0 ) ) 
	{//this loop has the champion fighting the Elder Lizard camp
		//does not account for red buff or hp/mp sigil yet
		elapsed_time = clock() - time / (float) CLOCKS_PER_SEC; 
		elapsed_time2 = (clock() - time) / (float) CLOCKS_PER_SEC; 

		if ( elapsed_time > champ_atk_time*ChampCount )
		{
			if ( ElderLizard.hp > 0 ) //if elder lizard is alive atk him
			{
				ElderLizard.hp = ElderLizard.hp - hero.dmg;
				cout << "champ attacks" << endl;
				cout << "Elder Lizard health " << ElderLizard.hp << endl;
				ChampCount++;
				if ( ElderLizard.hp <= 0 )
				{
					cout << "Elder Lizard is dead." << endl;
					hero.exp = hero.exp + 260;
					hero.CheckExp();
				}
			}
			else if ( YoungLizard1.hp > 0 ) //if young lizard 1 is alive atk him
			{
				YoungLizard1.hp = YoungLizard1.hp - hero.dmg;
				cout << "champ attacks" << endl;
				cout << "Young Lizard 1 health " << YoungLizard1.hp << endl;
				ChampCount++;
				if ( YoungLizard1.hp <= 0 )
				{
					cout << "Young Lizard 1 is dead." << endl;
					hero.exp = hero.exp + 50;
					hero.CheckExp();
				}
			}
			else if ( YoungLizard2.hp > 0 ) //if young lizard 2 is alive atk him
			{
				YoungLizard2.hp = YoungLizard2.hp - hero.dmg;
				cout << "champ attacks" << endl;
				cout << "Young Lizard 2 health " << YoungLizard2.hp << endl;
				ChampCount++;
				if ( YoungLizard2.hp <= 0 )
				{
					cout << "Young Lizard 2 is dead." << endl;
					hero.exp = hero.exp + 50;
					hero.CheckExp();
				}
			}
		}
		if ( elapsed_time > elder_atk_time*ElderLizardCount ) //elder lizard attacking champ
		{
			hero.hp = hero.hp - ElderLizard.dmg;
			cout << "Elder Lizard attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			ElderLizardCount++;
		}
		if ( elapsed_time > young_atk_time*YoungLizard1Count ) //young lizard 1 attacking champ
		{
			hero.hp = hero.hp - (YoungLizard1.dmg);
			cout << "Young Lizard 1 attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			YoungLizard1Count++;
		}
		if ( elapsed_time > young_atk_time*YoungLizard1Count ) //young lizard 2 attacking champ
		{
			hero.hp = hero.hp - (YoungLizard2.dmg);
			cout << "Young Lizard 2 attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			YoungLizard2Count++;
		}
	}

	cout << "Elapsed time: " << elapsed_time << endl;
	cout << "Elapsed time2: " << elapsed_time2 << endl;
	cout << "Champ level: " << hero.level << endl;

	cin.get();
	return 0;
}