#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include <string>

#include "monster.h"

using namespace std;

class monsterfactory
{
public:
	monster CreateElderLizard(monster new_monster);
};

#endif