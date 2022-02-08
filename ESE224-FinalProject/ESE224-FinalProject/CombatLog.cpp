#include "CombatLog.h"

Combat::Combat()
{

}

void Combat::setoneshot(bool o)
{
	oneshot = o;
}

bool Combat::getoneshot()
{
	return oneshot;
}

void Combat::addLog(player p, enemy e)
{
	int php = p.getHP();
	int ehp = e.getHP();
	if (php < 0)
	{
		php = 0;
	}
	if (ehp < 0)
	{
		ehp = 0;
	}
	string ph = p.getName() + " Health: " + to_string(php);
	string eh = e.getName() + " Health: " + to_string(ehp);
	log.push(ph);
	log.push(eh);
}

ostream& operator<<(ostream& os, Combat& c)
{
	// TODO: insert return statement here
	stack<string> temp1;
	int count = 0;
	os << "Combat Log:" << endl;
	while (!c.log.empty())
	{
		string temp = c.log.top();
		c.log.pop();
		temp1.push(temp);
		count++;
	}
	if (count / 2 - 1 == 1)
	{
		c.oneshot = 1;
	}
	while (!temp1.empty())
	{
		string temp = temp1.top();
		temp1.pop();
		os << temp << endl;
	}
	os << endl;
	return os;
}