//header for monster
/*
Need a default constructor
*/

class monster
{
public:
	//include function prototypes and stats here
	//functions
	void CreateCheck(); //Print statement to test functionality
	void BecomeElderLizard(); //Gives the monster object Elder Lizard stats
	void BecomeAncientGolem(); //Gives the monster object Ancient Golem stats
	void BecomeYoungLizard(); //Gives the monster object young lizard stats
	 
	//variables
	float hp;
	int range; //add unsigned etc?
	float dmg;
	float as;
	float armor;
	float mr;
};

/*monster::monster ()
{
	hp=1;
	range=100;
	dmg=1;
	as=0.5;
	armor=0;
	mr=0;
}*/