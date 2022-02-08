#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Scoreboard.h"
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class enemylist
{
private:
	vector<vector<enemy>> easy
	{
		{enemy("goblin1", 10, 3, 1, 100, 50), enemy("goblin2", 12, 4, 1, 110, 60), enemy("goblin3", 25, 5, 1, 120, 120)},
		{enemy("ork1", 13, 4, 2, 65, 65), enemy("ork2", 15, 5, 2, 75, 75), enemy("ork3", 30, 7, 2, 200, 140)},
		{enemy("elf1", 15, 5, 3, 130, 80), enemy("elf2", 17, 5, 3, 140, 90), enemy("elf3", 35, 8, 3, 100, 160)},
		{enemy("devil1", 16, 6, 4, 100, 95), enemy("devil2", 20, 7, 4, 100, 105), enemy("devil3", 40, 9, 4, 100, 180)}
	}; //vector holds all the enemies to be returned if the player is in easy mode
	vector<vector<enemy>> medium
	{
		{enemy("goblin1", 20, 5, 1, 100, 50), enemy("goblin2", 25, 7, 1, 110, 60), enemy("goblin3", 50, 10, 1, 120, 120)},
		{enemy("ork1", 25, 7, 2, 120, 65), enemy("ork2", 30, 10, 2, 130, 75), enemy("ork3", 60, 13, 2, 200, 140)},
		{enemy("elf1", 30, 13, 3, 130, 80), enemy("elf2", 35, 10, 3, 140, 90), enemy("elf3", 70, 17, 3, 100, 160)},
		{enemy("devil1", 35, 13, 4, 100, 95), enemy("devil2", 40, 15, 4, 100, 105), enemy("devil3", 80, 18, 4, 100, 180)}
	}; //vector holds all the enemies to be returned if the player is in medium mode
	vector<vector<enemy>> hard
	{
		{enemy("goblin1", 30, 7, 1,100, 50), enemy("goblin2", 35, 10, 1, 110, 60), enemy("goblin3", 70, 15, 1, 120, 120)},
		{enemy("ork1", 35, 10, 2, 120, 65), enemy("ork2", 45, 15, 2, 130, 75), enemy("ork3", 90, 20, 2, 200, 140)},
		{enemy("elf1", 45, 20, 3, 130, 80), enemy("elf2", 50, 15, 3, 140, 90), enemy("elf3", 105, 25, 3, 100, 160)},
		{enemy("devil1", 55, 20, 4, 100, 95), enemy("devil2", 60, 22, 4, 100, 105), enemy("devil3", 120, 27, 4, 100, 180)}
	}; //vector holds all the enemies to be returned if the player is in hard mode
	queue<enemy> eq;
	stack<enemy> defeated;
public:
	enemylist(scoreboard s);
	enemy getEnemy(); //returns the enemy based on the current floor and position of the player
	void destroyEnemy(); //destroy enemy after hp = 0
	void clear();
	friend ostream& operator<<(ostream& os, enemylist& e);
};