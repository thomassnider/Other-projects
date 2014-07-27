#ifndef DRAGON_H
#define DRAGON_H
#include "Location.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Dragon:public Location//inherits from Location
{
protected:
	int health;//dragons health
	bool swordshield;//do you have the winning set
public:
	Dragon();//contructor
	void print();//for grid
	void runEvent(Player& p);//the event
	void sethealth(int draghealth);//if you want to set health
	int gethealth();//to display health in event
	void setweapons(bool weapons);//do you have both weapons
	bool getweapons();//show if you have both weapons
};
#endif
