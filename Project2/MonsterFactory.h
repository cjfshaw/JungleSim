#ifndef MonsterFACTORY_H
#define MonsterFACTORY_H

#include <string>

#include "Monster.h"

using namespace std;

class Monsterfactory
{
public:
	Monster * CreateElderLizard();
	Monster * CreateAncientGolem();
	Monster * CreateYoungLizard();
	Monster * CreateWraith();
	Monster * CreateLesserWraith();
	Monster * CreateBigGolem();
	Monster * CreateGolem();
	Monster * CreateWight();
	Monster * CreateGiantWolf();
	Monster * CreateWolf();
};

#endif
