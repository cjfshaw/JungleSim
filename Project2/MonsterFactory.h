#ifndef MonsterFACTORY_H
#define MonsterFACTORY_H

#include <string>

#include "Monster.h"

using namespace std;

class Monsterfactory
{
public:
	Monster CreateElderLizard(Monster new_Monster);
};

#endif