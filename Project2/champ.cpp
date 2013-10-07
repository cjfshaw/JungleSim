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
}

void champ::AutoAttack() // want champ to be able to AA a target (monster)
{
	hp=hp - dmg;
}