/*
Need a default constructor
*/

#include <iostream>
using namespace std;

#include "champ.h"

void champ::CreateCheck() //Print statement to test functionality
{
	cout << "Champ is created.\n";
}

//create a constructor with (name) to populate champs like champ(Ashe)

void champ::TestStats()  //Gives the champ easily usable stats
{ //use this to 'set' later
	hp=3000;
	hp5=50;
	range=600;
	dmg=200;
	as=2.25;
	armor=100;
	mr=100;
	ms=300;
	exp=0;
	level=1;
	hp_per_lvl=100;
	hp5_per_lvl=5;
	mp_per_lvl=50;
	mp5_per_lvl=5;
	dmg_per_lvl=50;
	as_per_lvl=0.25;
	armor_per_lvl=30;
	mr_per_lvl=30;
}

void champ::AutoAttack() // want champ to be able to AA a target (monster)
{
	hp=hp - dmg;
}

void champ::LevelUp() //upgrade the champ's stats to the ones at the next level
{
	level++;
	hp=hp+hp_per_lvl;//need to make current hp and max hp to account for this
	hp5=hp5+hp5_per_lvl;
	dmg=dmg+dmg_per_lvl;
	as=as+as_per_lvl;
	armor=armor+armor_per_lvl;
	mr=mr+mr_per_lvl;
	cout << "Champion is level: " << level << endl;
}

void champ::CheckExp() // check if champ's experience is enough to level up
{
	//int ExpForNextLevel;

	int i;
	int current_exp=0;
	int cum_exp=0;

	//ExpForNextLevel = 280 + 110*(level-2); 

	if ( level < 18)
	{
		if ( level == 1)
		{
			current_exp = 280;
			cum_exp = cum_exp + current_exp;
		}
		else
		{
			for ( i=level+1; i>1; i--)
			{
				current_exp = 280 + ( 110 * (i-2) );
				cum_exp = cum_exp + current_exp;
			}
		}

		/*for ( i=level; i>1; i--)
		{
			if ( i >= 2 )
			{
				current_exp = 280 + ( 110 * (i-2) );
				cum_exp = cum_exp + current_exp;
			}
			else 
			{
				current_exp = 280;
				cum_exp = cum_exp + current_exp;
			}
		}*/

		/*
		if ( level == 1 )
		{
			total_exp=280;
		}
		else
		{
			total_exp=0;
			for ( i=2; i <= level; i++ )
			{
				temp_exp=0;

				temp_exp=280+( 110 * (i-2) );
				total_exp = total_exp + temp_exp;

				cout << "exp to level " << i << ": " << temp_exp << endl;
				cout << "total exp needed for level " << i << ": " << total_exp << endl;
			}
		}
		*/

		if ( exp >= cum_exp ) //Verify: That you hit level 3
		{
			LevelUp();
		}
	}

	///////////////////////////////////////////////////////////////////
	/* Working code for cumulative exp
	int i;
	int cum_exp=0;
	int current_exp=0;

	for ( i=17; i>1; i--)
	{
		if ( i >= 2 )
		{
			current_exp = 280 + ( 110 * (i-2) );
			cum_exp = cum_exp + current_exp;
		}
		else 
		{
			current_exp = 280;
			cum_exp = cum_exp + current_exp;
		}
	}

	cout << "Cumulative exp for level 17: " << cum_exp << endl;
	*/
	///////////////////////////////////////////////////////////////////
}