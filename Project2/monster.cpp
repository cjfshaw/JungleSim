#include <iostream>
using namespace std;

#include "Monster.h"

//getters
float Monster::getExperienceGiven()
{
	return experience_given;
}

//setters
void Monster::setExperienceGiven(float new_experience_given)
{
	experience_given = new_experience_given;
}
