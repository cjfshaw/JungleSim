#include "Rune.h"

using namespace std;

//getters
string Rune::getStatID()
{
	return stat_ID;
}

float Rune::getFloatStatValue()
{
	return float_stat_value;
}

int Rune::getIntStatValue()
{
	return int_stat_value;
}

//setters
void Rune::setStatID( string new_stat_ID )
{
	new_stat_ID = stat_ID;
}

void Rune::setFloatStatValue( float new_float_stat_value )
{
	new_float_stat_value = float_stat_value;
}

void Rune::setIntStatValue( int new_int_stat_value )
{
	new_int_stat_value = int_stat_value;
}