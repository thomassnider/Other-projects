#include "Board.h"
#include"Location.h"
#include "Battle.h"
#include "Dragon.h"
#include "Player.h"
#include "Riddler.h"
using namespace std;
Board::Board()//board contructor
{
	rowp=0;//sets player starter to 0 0
	colp=0;
	char letter;//the letter in which events will be put into
	ifstream file;//starts a reading type called file 
	file.open("data.txt");//opens a file called data.txt
	file>>rows>>cols;//inputs rows and cols from text file
	grid=new Location**[rows];//this along with the next few lines creates the array for grid
	for(int i=0; i<rows;i++)
	{
		grid[i]=new Location*[cols];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			file>>letter;//inputs the first letter
			if(letter=='E')//if you put E in the file it is now empty event
			{
				grid[i][j]=new Location();//sets the spot to run Location event
			}
			else if(letter=='R')//if R it is now the Riddler event
			{
				grid[i][j]=new Riddler();
			}
			else if(letter=='D')//if D it is the Dragon
			{
				grid[i][j]=new Dragon();
				winr=i;//sets the space to realize it is dragon space
				winc=j;
			}
			else if(letter=='B')//if B it is the Battle
			{
				grid[i][j]=new Battle();
			}
		}
	}
	file.close();//closes file
}
void Board::printBoard()//prints board
{
	cout<<"Your current life is: "<<p.getlife()<<endl;//displays life of player
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(grid[i][j]==grid[rowp][colp])//if the player is on that spot display player
			{
				p.printPlayer();
			}
			else//else just print the figure the file said to
			{
				grid[i][j]->print();
			}
		}
		cout<<endl;
	}
}
void Board::setrows(int newrows)
{
	rows=newrows;//sets the total rows for grid
}
void Board::setcols(int newcols)
{
	cols=newcols;//set total cols
}
int Board::getrows()
{
	return rows;//gets rows
}
int Board::getcols()
{
	return cols;//get cols
}
void Board::tryingmove(string move)//inputs direction of movement
{
		if(move=="u"||move=="U")//if you choose up
		{
			if(rowp-1>=0)//as long as it doesnt go less then 0 you can move
			rowp=rowp-1;
			else//else recursive function!
			{
				cout<<"That space does not exist! Try again"<<endl;
				cin>>move;
				tryingmove(move);
			}
		}
		else if(move=="d"||move=="D"&&rowp+1<rows)//if you go down
		{
			if(rowp+1<rows)//same thing as above only if you go over the total number of rows you cant
				rowp=rowp+1;
			else//same
			{
				cout<<"That space does not exist! Try again"<<endl;
				cin>>move;
				tryingmove(move);
			}
		}
		else if(move=="l"||move=="L"&&colp-1<0)//if you go left
		{
			if(colp-1>=0)//basically the same thing but with columns
				colp=colp-1;
			else//same
			{
				cout<<"That space does not exist! Try again"<<endl;
				cin>>move;
				tryingmove(move);
			}
		}
		else if(move=="r"||move=="R"&&colp+1<rows)
		{
			if (colp+1<cols)//same things
			colp=colp+1;
			else//same 
			{
				cout<<"That space does not exist! Try again"<<endl;
				cin>>move;
				tryingmove(move);
			}
		}
		else//if you chose something that doesnt work out
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"I'm sorry you can only type, <u> up, <d> down, <l> left, or <r> right"<<endl;
			cout<<"Try again!"<<endl;//yea just try again and recursive!
			cin>>move;
			tryingmove(move);
		}

}
void Board::playermove()//starts the move of the player
{
	string move;
	cout<<"Please make a move: <u> up, <d> down, <l> left, or <r> right"<<endl;
	cin>>move;
	tryingmove(move);//tests the validation with the above function
	grid[rowp][colp]->runEvent(p);//runs event at that spot
}
void Board::rungame()
{
	string name;//your name
	cout<<"Hello and welcome to Adventure Land hero!"<<endl//instructions!!!!!
		<<"In this game you will face a series of challenges that will "<<endl
		<<"test your courage!"<<endl
		<<"There will be 3 types of events you must face to"<<endl
		<<"win and become a true hero..."<<endl
		<<"In facing the Riddler (labeled R), you will be asked a question."<<endl
		<<"This question will need to"<<endl
		<<"be answered in all lowercase or you will fail the question!"<<endl
		<<"So be careful young warrior!"<<endl
		<<"In facing monsters (label B), you will be asked to choose a action"<<endl
		<<"to take against that evil"<<endl
		<<"creature. You will be given time to think of your actions"<<endl
		<<"and have a chance to beat"<<endl
		<<"him in combat.  In the final and last challenge you "<<endl
		<<"will be forced to fight the dragon (Labeled D)."<<endl
		<<"You will have needed to collect the sword and shield from"<<endl
		<<"the previous events to defeat"<<endl
		<<"him.  If you fail to do so, you will surely perish..."<<endl
		<<"Anyway hero, What is your name?(Try to not use capitals, it will make finding"<<endl
		<<"events for you quite difficult)"<<endl;
		cin>>name;//put in name
		p.setname(name);//sets name
		cout<<"Good luck "<<p.getname()<<" at slaying the dragon!"<<endl;

	while(p.getwin()!=true&&p.getlife()>0)//keeps going till you die or slay dragon
	{
		printBoard();//print board
		playermove();//move
	}
}
