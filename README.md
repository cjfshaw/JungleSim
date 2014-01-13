JungleSim
=========

Repository for League Jungle Simulator

What is it?
--------------------------------------------
Jungle Simulator is a program meant to simulate the starting route of junglers in League of Legends.  Specifically, it will simulate how a champion with a given setup (runes, masteries, starting items, etc) can reach ganking level (level 3).  The simulation will then log the champion's stats after he has finished the camp that gets him to level 3.  This logging will be used to compare one champion setup against another to determine which is the most efficient.

Why does it exist?
--------------------------------------------
There are two major reasons for this program.

1.) With a game as fluid as LoL, things are always changing.  With jungle updates season to season and even patch to patch, this program exists to keep summoners up to date on which setup is currently the most efficient for their needs.  For example, if a player wants to know if Hunter's Machete + 5 pot gives a faster clear than starting Doran's Blade + 1 pot on Elise, they can run this simulation rather than playing two games and recording the results.  Now extend this out to every champion and every change in champion setup.

2.) This can be used as a tool for Riot Games.  A fully fleshed out simulation can help the Live team with balance.  The simulation can be used to determine the strength of all facets in a jungler's setup.  This contains but is not limited to: champions, runes, masteries, routes (individual camps), and items.

How accurate is it?
--------------------------------------------
The goal of this is to be high fidelity, which means that it is as accurate as possible within reason.  In light of this goal, the simulation will include buffs (red and blue), sigils (hp/mp gain upon monster kill), monster strength growing over time, champion leveling, champion abilities and passives, masteries, runes, items, and every camp.  Essentially, it will contain all of the core mechanics of the game.

The simulation will not account for advanced mechanics, like wall-jumping with Jarvan IV's EQ combo.

For questions about any specific mechanics, please send a message to the owner of this repository, cjfshaw.

The latest version
--------------------------------------------
Currently the simulator runs through the red buff camp and the blue buff camp.  He can kill them and level up.  The code has been refactored and reorganized to keep it from getting out of hand, but much of the functionality remains in main.cpp.

The current code does not account for preseason 4 changes.  Advancement of the code has been slowed so that the code base could be 'cleaned up' before proceeding.

Latest problems
--------------------------------------------
The MonsterFactory class needs to be fixed and updated and the ChampFactory class needs to be created.

Remaining goals (not in order)
--------------------------------------------

1.) FINISH UPDATING THE README.MD

A.) CLEAN UP THE CODE.

	a. DONE ) Bring unit, monster, and champion classes in line with good coding practice.  Change data types and functions from public to private or protected; combined with this, create the appropriate get() and set() functions and replace the current data modifications with them.
	b.) Clearly define functionality between classes and functions.  Remove "create younglizard" etc and move it into a factory class.  Move out other functionality, like level up() and checkExperience() functionality, as well.
	*NOTE: Factory class is created but needs to be debugged.  Other functionality need to be separated from the unit class and subclasses afterwards.*
	c. DONE ) Use prototyping to make main easier to understand.

B.) Account for start time (1:55) and time between camps (a 'wait' function that allows for hp/mp regen and minion levelups)

C.) Set limit on hp5 not going above max hp. (when current hp = max hp hp5 = 0?.  Think this might break levelup functionality)

D.) Still need to account for items, runes, masteries, and abilities, timing, and regen.

E.) Minions scaling over time, buff transfer, sigil (hp/mp from big minions) transfer

F.) 335 ms (22s), 360 ms (20.5s), 375 ms (20s), 403 ms (19s)

		ms * time to get distance
		
Overall design approach
---------------------------------------------
NOTE: The general philosophy for this design is to start with the aspects of the simulation that would apply to every champion, and then move onto the parts of the game that only apply to a subset of champions.  What this means is that there will be:

1.) A pseudo-champion that can clear the jungle with all the appropriate calculations (gold, experience, hp5) and modifications (sigils, buffs).  With proper logging on ending stats.

2.) Runes included.

3.) Items included.

4.) Masteries included.

5.) Innate skills and learned abilities included.
