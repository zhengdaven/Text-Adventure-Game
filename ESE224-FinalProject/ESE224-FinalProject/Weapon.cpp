#include "Weapon.h"

weapon::weapon()
{
	W_item = "";
	W_damage = 0;
	use = 0;
	cost = 0;
	num = 0;
}

weapon::weapon(string i, int d, int u, int c, int n)
{
	W_item = i;
	W_damage = d;
	use = u;
	cost = c;
	num = n;
}

void weapon::setItem(string i)
{
	W_item = i;
}

void weapon::setDMG(int d)
{
	W_damage = d;
}

void weapon::setUse(int u)
{
	use = u;
}

void weapon::setCost(int c)
{
	cost = c;
}

void weapon::setnum(int n)
{
	num = n;
}

string weapon::getItem()
{
	return W_item;
}

int weapon::getDMG()
{
	return W_damage;
}

int weapon::getUse()
{
	return use;
}

int weapon::getCost()
{
	return cost;
}

int weapon::getnum()
{
	return num;
}

void weapon::modifyUse()
{
	use--;
}

void weapon::print()
{
	cout << "Weapon: " << W_item << "\nDamage: " << W_damage << "\nCost: " << cost << endl << endl;
}