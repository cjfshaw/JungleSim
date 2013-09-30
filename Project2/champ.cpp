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
	hp=1000;
	hp5=10;
	range=600;
	dmg=100;
	as=1.0;
	armor=100;
	mr=100;
	ms=300;
}

void champ::AutoAttack() // want champ to be able to AA a target (monster)
{
	hp=hp - dmg;
}