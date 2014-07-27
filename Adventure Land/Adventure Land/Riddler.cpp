#include "Player.h"
#include"Riddler.h"
using namespace std;
Riddler::Riddler():Location()//nothing!
{
}
void Riddler::print()//grid help
{
	cout<<"R";
}
void Riddler::runEvent(Player& p)//run event
{
	string answer;//your answer must be in lower case!!!!
	int chance=rand()%5+1;//the chance of getting something is 2 out of five unless you already have 1 or both items then the chance will lessen
	cout<<"You have run into a riddler!  He will hurt you (-10 life)"<<endl<<"if you answer incorrectly!"<<endl;
	cout<<"Hello " <<p.getname()<<" I have been waiting for you! You must answer this riddle:"<<endl;
	int riddle=rand()%5+1;//there are 5 riddles that are chosen from at random
	if(riddle==1)//the first
	{
		cout<<"It is greater than God and more evil than the devil. The poor have it, the rich need it and if you eat it you'll die. What is it?"<<endl;
		cin>>answer;//IN LOWER CASE!!!  Oh and the anwer is nothing for this one
		if(cin.fail()||answer!="nothing")//you only get one shot at it
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Incorrect! Feel my wrath!"<<endl;
			p.setlife(p.getlife()-10);//you lose 10 life
		}
		else if(answer=="nothing")//if you get it right
		{
			cout<<"Drat! You win this time hero!"<<endl;
			if(chance==1)//he may drop something if chance equal to 1
			{
				cout<<"He left a sword!"<<endl;
				p.setsword(true);
			}
			else if(chance==2)//drops if it is 2
			{
				cout<<"He left a shield!"<<endl;
				p.setshield(true);
			}
		}
	}
	else if(riddle==2)//second riddle
	{
		cout<<"It walks on four legs in the morning, two legs at noon and three legs in the evening. What is it?"<<endl;
		cin>>answer;//anser is man
		if(cin.fail()||answer!="man")
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Incorrect! Feel my wrath!"<<endl;
			p.setlife(p.getlife()-10);
		}
		else if(answer=="man")
		{
			cout<<"Drat! You win this time hero!"<<endl;
			if(chance==1)
			{
				cout<<"He left a sword!"<<endl;
				p.setsword(true);
			}
			else if(chance==2)
			{
				cout<<"He left a shield!"<<endl;
				p.setshield(true);
			}
		}
	}
	else if(riddle==3)//3rd riddle
	{
		cout<<"What is in seasons, seconds, centuries and minutes but not in decades, years or days?"<<endl;
		cin>>answer;//anser is the letter n by itself
		if(cin.fail()||answer!="n")
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Incorrect! Feel my wrath!"<<endl;
			p.setlife(p.getlife()-10);
		}
		else if(answer=="n")
		{
			cout<<"Drat! You win this time hero!"<<endl;
			if(chance==1)
			{
				cout<<"He left a sword!"<<endl;
				p.setsword(true);
			}
			else if(chance==2)
			{
				cout<<"He left a shield!"<<endl;
				p.setshield(true);
			}
		}
	}
	else if(riddle==4)//riddle 4
	{
		cout<<"The more you have of it, the less you see. What is it?"<<endl;
		cin>>answer;//the answer is darkness
		if(cin.fail()||answer!="darkness")
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Incorrect! Feel my wrath!"<<endl;
			p.setlife(p.getlife()-10);
		}
		else if(answer=="darkness")
		{
			cout<<"Drat! You win this time hero!"<<endl;
			if(chance==1)
			{
				cout<<"He left a sword!"<<endl;
				p.setsword(true);
			}
			else if(chance==2)
			{
				cout<<"He left a shield!"<<endl;
				p.setshield(true);
			}
		}
	}
	else if(riddle==5)//the final riddle
	{
		cout<<"I am always hungry, I must always be fed, The finger I touch, Will soon turn red"<<endl;
		cin>>answer;//answer is fire
		if(cin.fail()||answer!="fire")
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Incorrect! Feel my wrath!"<<endl;
			p.setlife(p.getlife()-10);
		}
		else if(answer=="fire")
		{
			cout<<"Drat! You win this time hero!"<<endl;
			if(chance==1)
			{
				cout<<"He left a sword!"<<endl;
				p.setsword(true);
			}
			else if(chance==2)
			{
				cout<<"He left a shield!"<<endl;
				p.setshield(true);
			}
		}
	}
}