#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Weapon.h"

using namespace std;

class player
{
private:
	string Name; //This should hold the player’s name
	int HealthPoints; //This should hold the current health of the player
	int AttackDamage; //This should hold the attack damage of the player
	int Currency; //This should hold the currency of the player
	int rawscore; //this should hold the raw score of the player that can be later converted to the scaled score in scoreboard using diffMod
	weapon wEquipped; //this should hold the weapon profile of weapon equipped
	vector<weapon> inventory; //vector holds all the weapon profiles of the weapons available
	bool boughtonfloor = 0;
	bool boughtgore = 0;
public:
	player(); //default constructor for player
	string getName(); //returns the name of the player
	int getHP(); //returns the current health
	int getDMG(); //returns the current damage
	int getCurrency(); //returns the current currency;
	int getScore(); //returns the rawscore of the player
	vector<weapon> getInventory(); //returns the inventory
	weapon getWeapon(); //returns the weapon equipped
	bool getboughtonfloor();
	bool getboughtgore();
	void setName(string n); //sets the name for the player
	void setHP(int hp); //sets the current health
	void setDMG(int dmg); //sets the current damage
	void setCurrency(int money); //sets the player currency
	void setInventory(weapon w); //sets the player inventory with weapons
	void setScore(int s); //sets the player raw score
	void equipWeapon(weapon w); //equip player with new weapon
	void ModifyHealth(int modH); //Increments or decrements the player’s health by the input value
	void ModifyDamage(int modD); //Increments or decrements the player’s attack damage by the input value
	void ModifyCurrency(int modC); //Increments or decrements the player’s currency by the input value
	void ModifyScore(int modS); //increments or decrements the player's raw score by the input value
	void addWeapon(weapon w); //add weapons bought from the shop to the inventory vector and decrement the currency base on the cost
	void modifyInventory(weapon w); //remove weapons with use of 0
	void printInventory(); //print all weapons profiles of the weapons in the inventory
	void setboughtonfloor(bool b);
	void setboughtgore(bool g);
	//void print(); //print player information
	friend ostream& operator <<(ostream& os, player& p);
};