#ifndef LOCATION_H
#define LOCATION_H
#include "Player.h"//calls player so it can be used in runevent
#include <string>
#include <iostream>
using namespace std;
class Location
{
protected:
public:
	Location();//contructor that does nothing!
	virtual void print();//prints for grid
	virtual void runEvent(Player& p);//runs event
};
#endif
