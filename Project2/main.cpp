#include "champ.h"
#include "monster.h"

#include "stdlib.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	champ test;
	monster test2;
	test.CreateCheck();
	test2.CreateCheck();

	test.TestStats();

	test2.BecomeElderLizard();

	clock_t time;
	time = clock();
	
	float elapsed_time;

	cout << "Elder lizard hp:" << test2.hp << endl;

	cout << "Champ hp:" << test.hp << endl;

	float champ_atk_time = (1/test.as)*1000;
	float monster_atk_time = (1/test2.as)*1000;

	int count=1;

	while( test.hp >= 0 || test2.hp >= 0 ) 
	{
		elapsed_time = clock() - time / (float) CLOCKS_PER_SEC;

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
		{
			test2.hp = test2.hp - test.dmg;
			cout << "champ attacks" << endl;
			cout << "monster health " << test2.hp << endl;
		}
		if ( elapsed_time > monster_atk_time*count )
		{
			test.hp = test.hp - test2.dmg;
			cout << "monster attacks" << endl;
			cout << "champ health " << test.hp << endl;
		}


		//cout << "Elapsed time: " << elapsed_time << endl;
	}

	/*test.hp = test.hp - test2.dmg;

	cout << "Champ hp:" << test.hp << endl;*/

	cin.get();
	return 0;
}