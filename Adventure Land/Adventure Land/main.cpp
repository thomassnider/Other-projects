//Thomas Snider
//Prof Bowring
//Comp 53
//February 11,2013
//
//the data file needs to be named data and be a txt file also please be sure to only put one dragon event labeled D you must have it to win.
//there are instuctions in the game when you start but if you need further instructions please email me and I will imediately describe the game
//to you!
//Also, I got rid of the visited member variable due to my game running a random drop to defeat the boss dragon.  If you were not allowed to go 
//back it may be impossible to win
#include "Board.h"//calls board header file
#include <ctime>//for random
#include <string>//sets up for string names
#include <iostream>//normal library
using namespace std;//same old
int main()
{
	srand((unsigned)time(0));//seeds
	Board b;//the game class
	b.rungame();//runs game
	system("pause");//stops for final text
}