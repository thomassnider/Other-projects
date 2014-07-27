#include "Dragon.h"
using namespace std;
Dragon::Dragon():Location()
{
	health=100;//it has alot of health
	swordshield=false;//starts out as you not have a swordshield
}
void Dragon::print()
{
	cout<<"D";//for grid
}
void Dragon::sethealth(int draghealth)
{
	health=draghealth;
}
int Dragon::gethealth()
{
	return health;
}
void Dragon::setweapons(bool weapons)
{
	swordshield=weapons;
}
bool Dragon::getweapons()
{
	return swordshield;
}
void Dragon::runEvent(Player& p)
{
	if(p.getshield()!=true&&p.getsword()!=true)//if dont have sword and shield you lose
	{
		cout<<"You are unready to fight him, yet brave as you, you try"<<endl;
		cout<<"His firey breath consumes you and you become his next meal..."<<endl;
		p.setlife(p.getlife()-p.getlife());//you die!
	}
	else//if you do
	{
	setweapons(true);
	int choice;//the choice you make
	cout<<"You approach the beast, it notices you with only a brief glance"<<endl;
	cout<<"It slowly climbs down from it mountain to come for its next meal.."<<endl;
	cout<<"Your ready yourself for the final duel!"<<endl;
	while(p.getlife()>0&&health>0)//while both you and him have a greater then 0 life
	{
		int dragattack=rand()%3+1;//he has a chance to change attacks
		cout<<"It has a life of: "<<health<<endl;//display life
		cout<<"You have a life of: "<<p.getlife()<<endl;//display health
		cout<<"Choose your action: <1>Prepare for its breath <2> Thrust your blade <3> Dodge its bite"<<endl;//rock paper scissors with a advantage to you
		cin>>choice;//you win eventhing besides ties!!!
		while(cin.fail()||choice>3||choice<1)//if you mess up
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Try again, please choose 1 to prepare for its fire, 2 to attack, or 3 to dodge the bite"<<endl;
				cin>>choice;
			}
		if(choice==1)//you chose 1
		{
			cout<<"You pull up your shield to block its fire breath..."<<endl;//writing cinematic
				if(dragattack==1)//if it chose one you lose 10 life
				{
					cout<<"It swipes at you with its claws!"<<endl;
					cout<<"You get hit and it tears a gash in you!(-10 life)"<<endl;
					p.setlife(p.getlife()-10);
				}
				else//else you deal 10 damage
				{
					cout<<"His breath reaches hits your shield!"<<endl;
					cout<<"You swing your sword at its feet!"<<endl;
					health=health-10;
				}
		}
		else if(choice==2)//you chose 2
		{
			cout<<"You charge your blade at its chest..."<<endl;
			if(dragattack==2)//it also chose 2
			{
				cout<<"Its head comes to bite your arm inflicting serious wounds!(-15 life)"<<endl;
				p.setlife(p.getlife()-15);//you lose 15
			}
			else
			{
				cout<<"It tries to dodge but is too big of a target."<<endl;
				cout<<"You stab its chest!"<<endl;
				health=health-15;//you deal 15
			}
		}
		else if(choice==3)
		{
			cout<<"You squat to get ready for its teeth..."<<endl;
			if(dragattack==3)
			{
				cout<<"The dragon blares fire from its mouth!"<<endl;
				cout<<"You try to leap away but are severly burned! (-15 life)"<<endl;
				p.setlife(p.getlife()-15);//you take 15
			}
			else
			{
				cout<<"Its jaw comes down quickly, luickly your ready and leap around it."<<endl;
				cout<<"You slice the dragon's neck as it trys to recoil its head!"<<endl;
				health=health-20;//you deal 20
			}
		}
		if(p.getlife()==0)//if you die
		{
			cout<<"You have fallen to the great beast! You lose!"<<endl;
		}
		else if(health==0)//if it dies
		{
			cout<<"You leap upon the beast to reach its heart!  You plunge your sword deep into its chest!"<<endl;
			cout<<"The dragon is slain!"<<endl;
			cout<<"You win!"<<endl;
			p.setwin(true);//you win!
		}
	}
	}
}

