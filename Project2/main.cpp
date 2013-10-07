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

	int count=1;
	int count2=1;
	int count3=1;
	int count4=1;

	while( hero.hp > 0 && (ElderLizard.hp > 0 || YoungLizard1.hp > 0 || YoungLizard2.hp > 0 ) ) 
	{
		elapsed_time = clock() - time / (float) CLOCKS_PER_SEC; 
		elapsed_time2 = (clock() - time) / (float) CLOCKS_PER_SEC; 
		//don't know if this is really

		//cout << "CHAMP ATK TIME MODDED" << modf(elapsed_time, &champ_atk_time) << endl;

		/*if ( modf(elapsed_time, &champ_atk_time) == 0 )
		{
			test2.hp = test2.hp - test.dmg;
		}
		else if ( modf(elapsed_time, &monster_atk_time) == 0 )
		{
			test.hp = test.hp - test2.dmg;
		}*/

		if ( elapsed_time > champ_atk_time*count )
		{//need to add experience when something dies
			if ( ElderLizard.hp > 0 )
			{
				ElderLizard.hp = ElderLizard.hp - hero.dmg;
				cout << "champ attacks" << endl;
				cout << "Elder Lizard health " << ElderLizard.hp << endl;
				count++;
			}
			else if ( YoungLizard1.hp > 0 )
			{
				YoungLizard1.hp = YoungLizard1.hp - hero.dmg;
				cout << "champ attacks" << endl;
				cout << "Young Lizard 1 health " << YoungLizard1.hp << endl;
				count++;
			}
			else if ( YoungLizard2.hp > 0 )
			{
				YoungLizard2.hp = YoungLizard2.hp - hero.dmg;
				cout << "champ attacks" << endl;
				cout << "Young Lizard 2 health " << YoungLizard2.hp << endl;
				count++;
			}
		}
		if ( elapsed_time > elder_atk_time*count2 )
		{
			hero.hp = hero.hp - ElderLizard.dmg;
			cout << "Elder Lizard attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			count2++;
		}
		if ( elapsed_time > young_atk_time*count3 )
		{
			hero.hp = hero.hp - (YoungLizard1.dmg);
			cout << "Young Lizard 1 attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			count3++;
		}
		if ( elapsed_time > young_atk_time*count3 )
		{
			hero.hp = hero.hp - (YoungLizard2.dmg);
			cout << "Young Lizard 2 attacks" << endl;
			cout << "champ health " << hero.hp << endl;
			count4++;
		}
		//cout << "Elapsed time: " << elapsed_time << endl;
		//cout << "Elapsed time2: " << elapsed_time2 << endl;
	}

	cout << "Elapsed time: " << elapsed_time << endl;
	cout << "Elapsed time2: " << elapsed_time2 << endl;

	cin.get();
	return 0;
}