#pragma once
#include <string>
#include <iostream>

using namespace std;

class weapon
{
private:
	string W_item; //Name of the weapon item
	int W_damage; //Attack damage to the item. This can be added or removed by the player
	int use; //number of uses available for the weeapon
	int cost; //cost of the weapon
	int num;
public:
	weapon(); //default constructor for the weapon
	weapon(string i, int d, int u, int c, int n); //parameterized constructor for the weapon
	void setItem(string i);//set the item name
	void setDMG(int d);//set the item damage
	void setUse(int u);//set the number of uses on the weapon
	void setCost(int c);//set the cost of the weapon
	void setnum(int n);
	string getItem();//return the name of the weapon
	int getDMG();//return the damage of the weapon
	int getUse();//return the uses left of the weapon
	int getCost();//return the cost of the weapon
	int getnum();
	void modifyUse();//decrements the number of uses left for the weapon
	void print();//print weapon information to the terminal
};