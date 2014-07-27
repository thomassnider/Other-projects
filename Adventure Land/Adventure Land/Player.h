#ifndef PLAYER_H
#define	PLAYER_H
#include <string>//same old stuff
#include <iostream>
using namespace std;
class Player
{
protected:
	string name;//your name
	int life;//your life
	bool sword;//a sword
	bool shield;//a shield
	bool win;//did you win yet
public:
	Player();//contructor
	void setwin(bool newwin);//set win
	bool getwin();//returns win
	void printPlayer();//prints id of player for grid
	void setname(string playername);//sets name
	void setlife(int life);//sets life
	string getname();//gets name
	int getlife();//gets life
	void setsword(bool havesword);//sets the sword, used after events
	void setshield(bool haveshield);//sets the shield, same thing
	bool getsword();//gets sword, for dragon event
	bool getshield();//get shield, for dragon event
};
#endif