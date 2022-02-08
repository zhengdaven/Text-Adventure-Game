#include "EnemyList.h"

enemylist::enemylist(scoreboard s)
{
	if (s.getDiff() == "easy")
	{
		for (int i = s.getPos(); i < 3; i++)
		{
			eq.push(easy[s.getFloor()][i]);
		}
		for (int i = s.getFloor() + 1; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				eq.push(easy[i][j]);
			}
		}
	}
	else if (s.getDiff() == "medium")
	{
		for (int i = s.getPos(); i < 3; i++)
		{
			eq.push(medium[s.getFloor()][i]);
		}
		for (int i = s.getFloor() + 1; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				eq.push(medium[i][j]);
			}
		}
	}
	else
	{
		for (int i = s.getPos(); i < 3; i++)
		{
			eq.push(hard[s.getFloor()][i]);
		}
		for (int i = s.getFloor() + 1; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				eq.push(hard[i][j]);
			}
		}
	}
}

enemy enemylist::getEnemy()
{
	enemy current = eq.front();
	return current;
}

void enemylist::destroyEnemy()
{
	enemy temp = eq.front();
	eq.pop();
	defeated.push(temp);
}

void enemylist::clear()
{
	while (!defeated.empty())
	{
		defeated.pop();
	}
}

ostream& operator<<(ostream& os, enemylist& e)
{
	// TODO: insert return statement here
	os << "Enemies defeated this game:" << endl;
	while (!e.defeated.empty())
	{
		enemy temp = e.defeated.top();
		e.defeated.pop();
		os << temp.getName() << endl;
	}
	os << endl;
	return os;
}