#pragma once
#include <stack>
#include "Player.h"
#include "Enemy.h"
#include <string>

class Combat
{
private:
	stack<string> log;
	bool oneshot = 0;
public:
	Combat();
	void addLog(player p, enemy e);
	void setoneshot(bool o);
	bool getoneshot();
	friend ostream& operator<<(ostream& os, Combat& c);
};