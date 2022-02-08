#pragma once
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Mission.h"
#include "Player.h"
#include "Enemy.h"
#include "CombatLog.h"
#include "Scoreboard.h"
using namespace std;

class HandleSideQuest
{
private:
    queue<SideQuest> completed;
    queue<SideQuest> current;
    vector<SideQuest> sidearray
    {
        SideQuest("Save up 300 currency", 100), //in modify currency do a check
        SideQuest("Complete the floor without buying a weapon", 200),
        SideQuest("One shot an enemy on this floor", 300),
        SideQuest("Buy Goredrinker from the weapon shop", 400),
    };
public:
    HandleSideQuest(scoreboard s);
    void CheckSideQuest(player& p, Combat c, scoreboard& s); //On eney defeat chekc if sidequest completion
    void loadsidequest(int floor);
    vector<SideQuest> getQuest();
    void clear();
    void printQuest(scoreboard s);
    friend ostream& operator<<(ostream& os, HandleSideQuest& h);
};