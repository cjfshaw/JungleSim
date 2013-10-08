JungleSim
=========

Repository for League Jungle Simulator

What is it?
------------------------------------
Jungle Simulator is a program meant to simulate the starting route of the popular junglers in League of Legends.  Specifically, it will simulate how a champion with a given setup (runes, masteries, starting items) can kill one major buff (red or blue) and then move onto the next buff (red or blue, whichever was not killed).  The simulation will then log the champion's stats after he has killed the second buff.  This logging will be used to compare one champion setup against another to determine which is the most efficient.

Why does it exist?
------------------------------------
With a game as fluid as LoL, things are always changing.  With jungle updates season to season and even patch to patch, this program exists to keep summoners up to date on which setup is currently the best.

How accurate is it?
------------------------------------
The goal of this is to be high fidelity, which means that it is as accurate as possible without actually being the game.  In light of this goal, the simulation will include buffs (red and blue) and all of their bonuses, hp/mp gain upon monster kill, monster strength growing over time, champion leveling, buffs and debuffs caused by skills, champion abilities and passives, and everything else that the game does itself.

The latest version
------------------------------------
Currently the simulator runs through the red buff camp and the blue buff camp.  He can kill them and level up.  However, the rate at which the champion levels up is currently incorrect due to an error in the CheckExp function, found in champ.cpp and champ.h.  I am unsure how to include the champion's current level in the calculations for this function.
