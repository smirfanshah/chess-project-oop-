#pragma once
#include<string>
#include"bscs22117.h"
using namespace std;
class Player
{
	string name;	
	Color C;
public:
	Player(string n, Color c);
	string getname();
	Color getcolor();
};

