#include "Player.h"

player::player()
{
	Name = "";
	HealthPoints = 300;
	AttackDamage = 10;
	Currency = 0;
	rawscore = 0;
	wEquipped = weapon("fist", 10, -1, 0, -1);
	inventory.push_back(weapon("fist", 10, -1, 0, -1));
}

string player::getName()
{
	return Name;
}

int player::getHP()
{
	return HealthPoints;
}

int player::getDMG()
{
	return AttackDamage;
}

int player::getCurrency()
{
	return Currency;
}

int player::getScore()
{
	return rawscore;
}

vector<weapon> player::getInventory()
{
	return inventory;
}

weapon player::getWeapon()
{
	return wEquipped;
}

bool player::getboughtonfloor()
{
	return boughtonfloor;
}

bool player::getboughtgore()
{
	return boughtgore;
}

void player::setName(string n)
{
	Name = n;
}

void player::setHP(int hp)
{
	HealthPoints = hp;
}

void player::setDMG(int dmg)
{
	AttackDamage = dmg;
}

void player::setCurrency(int money)
{
	Currency = money;
}

void player::setInventory(weapon w)
{
	inventory.push_back(w);
}

void player::setScore(int s)
{
	rawscore = s;
}

void player::equipWeapon(weapon w)
{
	wEquipped = w;
}

void player::ModifyHealth(int modH)
{
	HealthPoints += modH;
}

void player::ModifyDamage(int modD)
{
	AttackDamage += modD;
}

void player::ModifyCurrency(int modC)
{
	Currency += modC;
}

void player::ModifyScore(int modS)
{
	rawscore += modS;
}

void player::addWeapon(weapon w)
{
	inventory.push_back(w);
	Currency -= w.getCost();
}

void player::modifyInventory(weapon w)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].getItem() == w.getItem())
		{
			inventory.erase(inventory.begin() + i);
		}
	}
}

void player::printInventory()
{
	cout << "Inventory:" << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << "(" << i << ") " << endl;
		inventory[i].print();
	}
}

void player::setboughtonfloor(bool b)
{
	boughtonfloor = b;
}

void player::setboughtgore(bool g)
{
	boughtgore = g;
}

/*void player::print()
{
	cout << "Player Information:" << "\nName: " << Name << "\nHP : " << HealthPoints << "\nAD : " << AttackDamage << "\nCurrency: " << Currency << "\nWeapon : " << wEquipped.getItem() << endl << endl;
}*/

ostream& operator<<(ostream& os, player& p)
{
	// TODO: insert return statement here
	os << "Player Information:" << "\nName: " << p.Name << "\nHP : " << p.HealthPoints << "\nAD : " << p.AttackDamage << "\nCurrency: " << p.Currency << "\nWeapon : " << p.wEquipped.getItem() << endl << endl;
	return os;
}