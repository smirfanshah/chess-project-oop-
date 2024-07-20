#include "Player.h"
Player::Player(string n, Color c)
{
	this->name = n;
	this->C = c;
}
string Player::getname()
{
	return this->name;	
}
Color Player::getcolor()
{
	return this->C;
}