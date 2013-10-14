JungleSim
=========

Repository for League Jungle Simulator

What is it?
--------------------------------------------
Jungle Simulator is a program meant to simulate the starting route of the popular junglers in League of Legends.  Specifically, it will simulate how a champion with a given setup (runes, masteries, starting items) can kill one major buff (red or blue) and then move onto the next buff (red or blue, whichever was not killed).  The simulation will then log the champion's stats after he has killed the second buff.  This logging will be used to compare one champion setup against another to determine which is the most efficient.

Why does it exist?
--------------------------------------------
With a game as fluid as LoL, things are always changing.  With jungle updates season to season and even patch to patch, this program exists to keep summoners up to date on which setup is currently the best.

How accurate is it?
--------------------------------------------
The goal of this is to be high fidelity, which means that it is as accurate as possible without actually being the game.  In light of this goal, the simulation will include buffs (red and blue) and all of their bonuses, hp/mp gain upon monster kill, monster strength growing over time, champion leveling, buffs and debuffs caused by skills, champion abilities and passives, and everything else that the game does itself.

The latest version
--------------------------------------------
Currently the simulator runs through the red buff camp and the blue buff camp.  He can kill them and level up.  The code has been refactored, but much of the functionalist remains in main.cpp.

Latest problems
--------------------------------------------
The time it takes to fight both red and blue buff camps seems relatively accurate but it is not 100% accuracy.  The functions need to be updated, and so do the stats.  Names like "as" are not descriptive enough and need to be changed to something like "attack_speed."  Additionally find out how to use Visual Studio's autocomplete.  Goals (from Reamining Goals section) that must be completed for phase 1 to be finished are A, B, C, D, F.

Remaining goals (not in order)
--------------------------------------------

A.) Update comments to detail what each process is doing

B.) Account for start time (1:55) and time between camps (a 'wait' function that allows for hp/mp regen and minion levelups)

C.) Add max hp, set limit on hp5 not going above max hp. (when current hp = max hp hp5 = 0?.  Think this might break levelup functionality)

D.) Still need to account for items, runes, masteries, and abilities, timing, and regen, and proper damage ratios

E.) Minions scaling over time, buff transfer, sigil (hp/mp from big minions) transfer

F.) 335 ms (22s), 360 ms (20.5s), 375 ms (20s), 403 ms (19s)

		ms * time to get distance
		
Overall design approach
---------------------------------------------
NOTE: The general philosophy for this design is to start with the aspects of the simulation that would apply to every champion, and then move onto the parts of the game that only apply to a subset of champions.  What this means is that there will be:

1.) A pseudo-champion that can clear the jungle with all the appropriate calculations (gold, experience, hp5) and modifications (sigils, buffs).  With proper logging on ending stats.

2.) Masteries included.

3.) Runes included.

4.) Items included.

5.) Innate skills and learned abilities included.
