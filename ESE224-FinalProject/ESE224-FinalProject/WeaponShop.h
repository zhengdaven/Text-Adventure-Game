#pragma once
#include "Weapon.h"
#include "Player.h"
#include "ShopNode.h"
#include "Scoreboard.h"
#include <vector>
#include <stack>

using namespace std;

class shop
{
private:
	stack<weapon> recent;
	typedef WNode* nodePtr;
	nodePtr head, tail;
	//vector<weapon> weaponitem; //vector that holds all the weapon profiles that the shop is selling

public:
	shop(); //default constructor for the shop with all the weapons
	void print(); //function prints all the items available
	void printOption();
	void buy(player& p, scoreboard& s, int option); //function allows the player to purchase the weapon
	void addtoInv(player& p);
	void addW(WNode* w);
	void loadW1(scoreboard& s);
	void loadW2(scoreboard& s);
	void loadW3(scoreboard& s);
	void loadW4(scoreboard& s);
	void setTail(WNode* tail);
	void clear();
	void clearstack();
	void remove(WNode* w);
	weapon pop();
};