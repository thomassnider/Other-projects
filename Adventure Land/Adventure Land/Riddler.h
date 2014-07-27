#ifndef RIDDLER_H
#define RIDDLER_H
#include "Location.h"//calls parent function
#include <string>
#include <ctime>
using namespace std;
class Riddler: public Location//set up inheritance
{
protected:

public:
	Riddler();//contructor that does nothing for this one
	void print();//prints for grid
	void runEvent(Player& p);//runs event
};
#endif