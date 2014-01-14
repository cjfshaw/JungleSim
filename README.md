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



Overall design approach
---------------------------------------------
The general design philosophy for this program is to start with core functionality necessary to make a low-fidelity simulation.  This low-fidelity simulation will be a psuedo-champion that is able to complete red and blue buff.  After the core functionality is implemented, the next goal is to add elements of the game that haven't been accounted for yet that also increase the fidelity of the simulation.  An example of this is adding regeneration.  The next step is to actually create a champion so that the program runs a basic, but accurate simulation of the LoL jungle.  At this point the code will be in alpha.  After that the program must be scripted to run multiple times with various different champion setups and then to compare the results.  Finally, the code will be expanded to account for multiple champions.  First only a few champions will be added, champions that expose the code to as many scenarios as possible.  Second, popular champions will be added.  Third, champions that expose the code to remaining edge cases will be added.  Eventually, advanced mechanics such as wall-jumping and leashing will be accounted for to make the program more accurately reflect how the jungle is played in reality.



The latest version
--------------------------------------------
Currently the simulator runs through the red buff camp and the blue buff camp.  He can kill them and level up.  The code has been refactored and reorganized to keep it from getting out of hand, but much of the functionality remains in main.cpp.

The current code does not account for preseason 4 changes.  Advancement of the code has been slowed so that the code base could be 'cleaned up' before proceeding.



Next to-do
--------------------------------------------
Verify level-up functionality is working.  Place each monster camp into it's own array, use the arrays in later functions (like fightcamp) as opposed to using the individual objects.



Latest problems
--------------------------------------------
Level up functionality needs to be double checked.



Remaining goals
--------------------------------------------

1.) Debug MonsterFactory and affected files: MonsterFactory.h, MonsterFactory.cpp, main.cpp

2.) Add unit testing.

3.) Expand MonsterFactory to include all monsters: Elder Lizard, Young Lizard, Ancient Golem, Big Golem, Little Golem, Large Wraith, Little Wraith, Wight.

4.) Expand MonsterFactory functionality to create monsters in an array.  Useful for multiple-unit spell targeting later.

5.) Create ChampFactory with "Nunu" and allow it to create champs in an array.

6.) Move extraneous functionality from Champ class (Level-up, CheckExperience).  Unsure where to move it to, possibly create another class.

7.) Add sigils and sigil transfer after a large minion is killed (assuming I can find info on how much hp/mp is transferred.)  This may require adding another identifier to minions to determine whether they are a large or small minion.

8.) Add regeneration functionality.  Do not allow current hp/mana to exceed maximum hp/mana.  This may need to be split into subtasks as the regeneration functionality may be larger than expected.

9.) Add a game timer that shifts simulation time to in-game timer.

10.) Account for correct spawning time with in-game timer (start timer at 1:55 not at 0).

11.) Account for the time it takes to move between camps.  This means account for travel time between camps, which is variable based on which camp (distance) and the champion's movespeed (velocity).  May need to update champion to have some kind of 'location' field for dynamic travel-time calculations between camps.  May need to be split into subtasks.

12.) Skip in-game timer ahead to account for times moved between camps, but do not have the simulation 'wait' for this movement to complete.  Example, it takes 10 seconds to get from blue buff to red buff; skip the in-game timer ahead by 10s and allow the champion to regenerate for that time in a 'burst regeneration.'  However, the simulation does not wait for the 10 seconds that it takes to move from red buff to blue buff. 

May require an update to regeneration functionality so that it continues to regen while the simulation 'skips ahead' to the next camp.

Note: MS and times gathered for red to blue buff are below.

335 ms (22s), 360 ms (20.5s), 375 ms (20s), 403 ms (19s)

		ms * time to get distance

13.) Log stats after a run.  May need to include functionality that stops when a champion clears the camp that gives them level 3.

14.) Add monster level ups (assuming I can find enough information of them).

15.) Add blue buff.  Cooldown reduction functionality may need to way until later.  It can possibly be done right away if there is an additional data member added to the champ class (cooldown reduction).

16.) Add red buff. May require that attack functionality is moved out of main.cpp to more easily account for both damage-over-time and different damage types (physical, magical, true).

17.) Add popular/standard runes.

18.) Add popular/standard items.

19.) Add popular/standard masteries.

20.) Add learned abilities. May need to do this in tandem with innate abilities and first real champion.

21.) Add innate abilities. May need to do this in tandem with learned abilities and first real champion.

22.) Add first real champion.

This should be a champion who is relatively easy to code and exposes the code to very few additional paths in order to get a working prototype out faster.  Currently considering Fiora.

23.) Add a script that runs multiple scenarios.

24.) Parse the output log to compare results.



Questions or comments?
--------------------------------------------
Feel free to send a message to the owner of this repository and codebase (cjfshaw) via github or email at cjfshaw@gmail.com.
