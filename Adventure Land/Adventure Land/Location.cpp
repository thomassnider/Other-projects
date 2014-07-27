#include "Location.h"
using namespace std;
Location::Location()//idk i just left it incase
{
}
void Location::print()//prints for grid
{
	cout<<"E";
}
void Location::runEvent(Player& p)
{
	p.setlife(p.getlife());//I had to put this in or it had some error, anyway it doesnt do anything
	cout<<"There is nothing here..."<<endl;//the action
}
