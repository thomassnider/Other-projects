#ifndef BOARD_H
#define BOARD_H//header stuff
#include <iostream>//normal library
#include <string>//strings
#include "Battle.h"//Battle event clas
#include "Dragon.h"//Dragon event class
#include "Location.h"//Location event class
#include "Player.h"//Player class
#include "Riddler.h"//Riddler Event class
#include <fstream>//reading files
using namespace std;
class Board
{
protected:
	Location***grid;//the pointer of a pointer of a pointer with a Location class type
	Player p;//player class
	int rows,cols;//the total number of rows and cols
	int rowp,colp;//the row and col of player
	int winr,winc;//the wining dragon space
	bool winner;//if you win
public:
	Board();//board contructor
	void printBoard();//prints board
	void tryingmove(string move);//sees if the move is valid
	void playermove();//makes the move officially
	void setrows(int rows);//sets total of rows
	void setcols(int cols);//sets total of cols
	int getrows();//gets the total rows
	int getcols();//get the total cols
	void rungame();//runs the game
};
#endif