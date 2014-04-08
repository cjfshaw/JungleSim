#ifndef Rune_H
#define Rune_H

#include <string>

using namespace std;

class Rune
{
public:
	//getters
	string Rune::getStatID();
	float Rune::getFloatStatValue();
	int Rune::getIntStatValue();

	//setters
	void Rune::setStatID( string new_stat_ID );
	void Rune::setFloatStatValue( float new_float_stat_value );
	void Rune::setIntStatValue( int new_int_stat_value );

private:
	string stat_ID;
	float float_stat_value;
	int int_stat_value;
};

#endif