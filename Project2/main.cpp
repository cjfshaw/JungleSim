#include "champ.h"
#include "monster.h"

#include "stdlib.h"
#include <iostream>
using namespace std;

int main()
{
	champ test;
	monster test2;
	test.CreateCheck();
	test2.CreateCheck();

	test2.BecomeElderLizard();

	cout << "Elder lizard hp:" << test2.hp << endl;

	cin.get();
	return 0;
}