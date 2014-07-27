#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include "Location.h"
#include "Player.h"
#include <string>
#include <ctime>
using namespace std;
class Battle:public Location//inherits location
{
protected:
	int health;//the monsters health
public:
	Battle();//constructor to set health
	void print();//for grid
	void sethealth(int newhealth);//sets health incase you want to change
	int gethealth();//shows health
	void runEvent(Player& p);//runs event 
};
#endif