#include "Player.h"
#include <iostream>
#include <string>
using namespace std;
Player::Player()
{
	name="N/A";//you dont have a name
	life=100;//you life is set and stays at 100 unless you the tester want to type in somewhere set life so you wont die
	sword=false;
	shield=false;
	win=false;
}
void Player::setwin(bool newwin)
{
	win=newwin;
}
bool Player::getwin()
{
	return win;
}
void Player::printPlayer()
{
	cout<<name[0];
}
void Player::setname(string playername)
{
	name=playername;
}
void Player::setlife(int newlife)
{
	life=newlife;
}
string Player::getname()
{
	return name;
}
int Player::getlife()
{
	return life;
}
void Player::setshield(bool newshield)
{
	shield=newshield;
}
void Player::setsword(bool newsword)
{
	sword=newsword;
}
bool Player::getsword()
{
	return sword;
}
bool Player::getshield()
{
	return shield;
}
