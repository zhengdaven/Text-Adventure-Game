#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;
class enemy : public player
{
private:
    string Name;//This should hold the enemy’s name
    int HealthPoints;//This should hold the current health of the enemy
    int AttackDamage;//This should hold the attack damage of the enemy
    int level = 0;//this should hold the level of the enemy
    int Currency;//this should hold the currency worth of the enemy if defeated
    int Score;//this should hold the number of points the enemy is worth
public:
    enemy();//default constructor for enemies
    enemy(string Name, int HealthPoints, int AttackDamage, int level, int Currency, int Score);//parameterized constructor for enemies
    string getName();//returns the name of the enemy
    int getHP();//returns the current health of the enemy
    int getDMG();//returns the average damage of the enemy
    int getLVL(); //returns the level of the enemy
    int getCurr(); //returns the currency of the enemy
    int getScore(); //returns the score of the enemy
    void setName(string Name); //sets the name
    void setHP(int HealthPoints);//sets the current health
    void setDMG(int AttackDamage);//sets the current damage
    void setLVL(int level);//sets the level
    void setCurr(int Currency);//sets the currency
    void setScore(int Score);//sets the score
    void ModifyHealth(int Health);//Increments or decrements the enemies’s health by the input value
    void ModifyDamage(int Damage);//Increments or decrements the enemies’s attack damage by the input value
    //void print();//function prints the enemy information
    friend ostream& operator <<(ostream& os, const enemy& e);
};