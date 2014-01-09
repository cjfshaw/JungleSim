#include "monsterfactory.h"

monster monsterfactory::CreateElderLizard(monster new_monster)
{
	new_monster.set_name("ElderLizard");
	new_monster.set_max_health(1400);
	new_monster.set_current_health(1400);
	new_monster.set_range(100);
	new_monster.set_damage(65);
	new_monster.set_base_attack_speed(0.625);
	new_monster.set_armor(20);
	new_monster.set_magic_resist(0);
	new_monster.set_experience_given(260);
	new_monster.set_counter(1);
	new_monster.set_movespeed(0);
	new_monster.set_critical_chance(0);

	return new_monster;
} //name goes from "ElderLizard" to "" for some reason when it gets to this line - not sure if this is causing everything else to error out or not