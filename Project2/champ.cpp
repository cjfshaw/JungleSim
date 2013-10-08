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
	level=10;
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
}

void champ::CheckExp() // check if champ's experience is enough to level up
{
	int ExpForNextLevel; 

	ExpForNextLevel = 280 + 110(level-2); //ERROR HERE errorC2064, also
	//	2	IntelliSense: expression preceding parentheses of apparent call must have (pointer-to-) function type	c:\Users\Chris\Documents\Visual Studio 2012\Projects\Project2\Project2\champ.cpp	59	26	JungleSim


	if ( level < 18)
	{
		if ( exp >= ExpForNextLevel ) //this only works with cumulative exp
		{
			LevelUp();
		}
	}

	/*this works for finding cumulative exp, will implement once I figure out current error in CheckExp function
		int i;
	int temp_exp;
	int total_exp=0;

	for ( i=2; i < level; i++ )
	{
		temp_exp=0;

		temp_exp=280+( 110 * (i-2) );
		total_exp = total_exp + temp_exp;

		cout << "exp to level " << i << ": " << temp_exp << endl;
		cout << "total exp needed for level " << i << ": " << total_exp << endl;
	}
	*/
}