#pragma once
#include <string>
#include "Player.h"
#include "CombatLog.h"
#include <iostream>
#include <vector>

using namespace std;

class scoreboard
{
private:
    string SB_Name; //Name of the player
    int SB_Score; //Player score
    string SB_Difficulty; //difficulty that the player is playing on
    int SB_DifficultyMod; //Difficulty modifier for score
    int floor;//current floor of the player
    int pos;//current position of the player
    bool missioncomplete;
    vector<int> bought;
public:
    scoreboard(); //default constructor for scoreboard
    void setName(string name);//set the name
    void setScore(int score);//set the score
    void setDiff(string diff);//set the difficulty
    void setDiffMod(int diffmod);//set the difficulty modifier
    void setFloor(int f);//set the floor
    void setPos(int p);//set the position
    void setMission(bool m);
    string getName();//returns the scoreboard name
    int getScore();//return the score
    string getDiff();//return the difficulty
    int getDiffMod();//return the difficulty modifier
    int getFloor();//return the current floor
    int getPos();//return the current position
    bool getMission();
    void modifyScore(int score);//modify the score in the scoreboard based on the player raw score and diffMod
    void modifyPos();//increment the position of the player
    void modifyDiffMod();//change the diffMod based on the game difficulty
    void nextFloor(player& p, Combat& c);//increments the floor of the player
    void SB_out(); //outputs scoreboard to the player
    void clear();
    vector<int> getbought();
    void setbought(int b);
    void sortbought();
};