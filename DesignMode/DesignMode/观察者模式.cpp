#include <iostream>

using namespace std;

#include "list"
#include "string"

class Notify;

class Player
{
public:
	void update()
	{
		cout<<"我要工作。。。"<<endl;
	}
};

class Notify
{
public:
	Notify(string info)
	{
		l_player.clear();
	}

	void setPlayer(Player *palyer)
	{
		l_player.push_back(palyer);
	}
	void notifyPlayer()
	{
		for(list<Player*>::iterator it=l_player.begin(); it!=l_player.end(); it++)
		{
			(*it)->update();
		}
	}
private:
	list<Player *> l_player; 
};


void main()
{
	Notify *notify = NULL;
	Player *player1 = new Player;
	Player *player2 = new Player;


	notify->setPlayer(player1);
	notify->setPlayer(player2);

	notify->notifyPlayer();

	delete notify;
	delete player1;
	delete player2;

	system("pause");
	return;
}