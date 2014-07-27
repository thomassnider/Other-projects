#include "Battle.h"
#include "Player.h"
using namespace std;
Battle::Battle():Location()
{
	health=rand()%50+1;//random life from 1 to 50
}
void Battle::print()
{
	cout<<"B";//for grid
}
void Battle::sethealth(int newhealth)
{
	health=newhealth;
}
int Battle::gethealth()
{
	return health;
}
void Battle::runEvent(Player& p)
{
	int chance=rand()%4+1;//the chance to get item is greater here, then riddle
	int choice;
	int battle;
	cout<<"You have run into a monster!"<<endl;
	while(health>0)
	{
		cout<<"Its health is: " <<health<<endl;
		cout<<"Your health is: " <<p.getlife()<<endl;
		cout<<"What do you want to do?"<<endl;
		cout<<"<1>fight <2>run(-5 health)"<<endl;//you can run or you can fight
		cin>>choice;
		while(cin.fail()||choice>2||choice<1)//if you mess up
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Please choose 1 to fight or 2 to run."<<endl;
			cin>>choice;
		}
		if(choice==2)//if you run you lose five life but the event ends
		{
			p.setlife(p.getlife()-5);
			cout<<"You manange to get away with a couple of scratches"<<endl;
			health=0;
		}
		else if(choice==1)//if you stay
		{
			int monster=rand()%3+1;//he has 3 actions and you win ties
			cout<<"Please choose a action:"<<endl;
			cout<<"<1>grab <2>block <3>attack"<<endl;
			cin>>battle;//make a choice
			while(cin.fail()||battle>3||battle<1)//if you mess up
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Try again, please choose 1 to grab, 2 to block, or 3 to attack"<<endl;
				cin>>battle;
			}
			if(battle==1)//you grab
			{
				if(monster==3)//monster attacks
				{
					cout<<"Monster attacked! You take a hit (-10 life)"<<endl;//you lose 10 life
					p.setlife(p.getlife()-10);
					if(p.getlife()==0)//if you die game ends
					{
						cout<<"You died!"<<endl;
						health=0;
					}
				}
				else
				{
					cout<<"You grabbed the monster and tossed him!"<<endl;
					health=health-10;//if you win you deal 10 damage
				}
			}
			else if(battle==2)//you block
			{
				if(monster==1)
				{
					cout<<"The monster grabs you! He throws you(-5 life)"<<endl;
					p.setlife(p.getlife()-5);//he throws you deals 5 damage to you
					if(p.getlife()==0)
					{
						cout<<"You died!"<<endl;
						health=0;//you die
					}
				}
				else
				{
					cout<<"You block the monster's attack, his recoil leaves him open for your attack"<<endl;
					health=health-10;//you block him you deal 10 damage
				}
			}
			else if(battle==3)//if you attack
			{
				if (monster==2)//he blocks
				{
					cout<<"The creature blocks your attack, and attack when you are left open(-10 life)"<<endl;
					p.setlife(p.getlife()-10);//you take 10 damage
					if(p.getlife()==0)
					{
						cout<<"You died!"<<endl;
						health=0;
					}
				}
				else
				{
					cout<<"You slice the creature while he is open!"<<endl;
					health=health-10;//you deal 10 damage
				}
			}
		}
	}
		if(health<=0)//if it dies
			{
				cout<<"The monster is defeated!"<<endl;//chance to drop a needed item
				if(chance==1&&p.getsword()==false)
				{
					cout<<"It dropped a sword!"<<endl;
					p.setsword(true);
				}
				else if(chance==2&&p.getshield()==false)
				{
					cout<<"It dropped a shield!"<<endl;
					p.setshield(true);
				}
			}
	health=rand()%50+1;//resets the life so the event can go again
}

