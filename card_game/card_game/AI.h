//Header ==> Function declaration

#include <iostream>

#include "Player.h"

using namespace std;

#ifndef AI_H
#define AI_H

class AI{
	//Default Constructor
	AI();

	//Overload Constructor
	AI(Player, Card);

	//Destructor
	~AI();
};

#endif