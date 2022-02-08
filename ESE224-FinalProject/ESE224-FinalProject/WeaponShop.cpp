#include "WeaponShop.h"

shop::shop()
{
	/*weaponitem.push_back(weapon("dagger", 15, 1, 70));
	weaponitem.push_back(weapon("sword", 20, 1, 120));
	weaponitem.push_back(weapon("spear", 30, 1, 150));
	weaponitem.push_back(weapon("bow", 40, 1, 200));
	weaponitem.push_back(weapon("gun", 100, 1, 400)); //damage usage cost
	//*/
	head = NULL;
	tail = NULL;
}

void shop::print()
{
	/*for (int i = 0; i < weaponitem.size(); i++)
	{
		cout << "(" << i << ")" << endl;
		weaponitem[i].print();
	}*/
	WNode* temp = head;
	int i = 0;
	if (temp == NULL)
	{
		cout << "No weapon in shop at the moment" << endl << endl;
	}
	while (temp != NULL)
	{
		cout << "(" << i << ")" << endl;
		temp->print();
		temp = temp->getNext();
		i++;
	}
}

void shop::printOption()
{
	WNode* temp = head;
	int i = 0;
	if (temp == NULL)
	{
		cout << "No weapon in shop at the moment" << endl << endl;
	}
	while (temp != NULL)
	{
		cout << "(" << i << ") - ";
		cout << temp->getitem().getItem() << endl;
		temp = temp->getNext();
		i++;
	}
	cout << "Select a weapon to buy or press (5) to quit buy: ";
}

void shop::buy(player& p, scoreboard& s, int option)
{
	/*if (p.getCurrency() > weaponitem[option].getCost())
	{
		p.addWeapon(weaponitem[option]);
		cout << "Weapon purchased successfully" << endl << endl;
	}
	else
	{
		cout << "Weapon is too expensive" << endl << endl;
	}*/
	WNode* temp = head;
	for (int i = 0; i < option; i++)
	{
		temp = temp->getNext();
	}
	if (p.getCurrency() > temp->getitem().getCost())
	{
		p.addWeapon(temp->getitem());
		p.setboughtonfloor(1);//nick
		recent.push(temp->getitem());
		cout << "Weapon purchased successfully" << endl << endl;
		s.setbought(temp->getitem().getnum());
		if (temp->getitem().getItem() == "Goredrinker")
		{
			p.setboughtgore(1);
		}
		remove(temp);//clear this node
	}
	else
	{
		cout << "Weapon is too expensive" << endl << endl;
	}
}

void shop::addtoInv(player& p)
{
	cout << "Shop Tracker:" << endl;
	cout << "Recently bought weapons:" << endl;
	while (!recent.empty())
	{
		weapon w = pop();
		cout << w.getItem() << endl;
	}
	cout << endl;
}

void shop::addW(WNode* w)
{
	if (head == NULL)
	{
		head = tail = w;
	}
	else
	{
		tail->setNext(w);
		tail->getNext()->setPrev(tail);
		tail = tail->getNext();
	}
}

void shop::loadW1(scoreboard& s)
{
	if (s.getbought().empty())
	{
		addW(new WNode(weapon("BFsword", 15, 1, 40, 0)));
		addW(new WNode(weapon("BlastingWand", 17, 1, 45, 1)));
		addW(new WNode(weapon("Pickaxe", 19, 1, 50, 2)));
		addW(new WNode(weapon("Sheen", 21, 1, 55, 3)));
		addW(new WNode(weapon("NeedlesslyLargeRod", 31, 1, 80, 4)));
	}
	else
	{
		s.sortbought();
		vector<int> temp{ 0, 1, 2, 3, 4 };
		for (int i = 0; i < s.getbought().size(); i++)
		{
			switch (s.getbought()[i])
			{
				case 0:
					for (int j = 0; j < temp.size(); j++)
					{
						if (temp[j] == 0)
						{
							temp.erase(temp.begin() + j);
						}
					}
					break;
				case 1:
					for (int j = 0; j < temp.size(); j++)
					{
						if (temp[j] == 1)
						{
							temp.erase(temp.begin() + j);
						}
					}
					break;
				case 2:
					for (int j = 0; j < temp.size(); j++)
					{
						if (temp[j] == 2)
						{
							temp.erase(temp.begin() + j);
						}
					}
					break;
				case 3:
					for (int j = 0; j < temp.size(); j++)
					{
						if (temp[j] == 3)
						{
							temp.erase(temp.begin() + j);
						}
					}
					break;
				case 4:
					for (int j = 0; j < temp.size(); j++)
					{
						if (temp[j] == 4)
						{
							temp.erase(temp.begin() + j);
						}
					}
					break;
			}
		}
		//sort the vector create a sorting in scoreboard
		//new vector here that has all elements and remove them based on whats in bought vector
		//iterate through new vector
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 0)
			{
				addW(new WNode(weapon("BFsword", 15, 1, 40, 0)));
			}
			else if (temp[i] == 1)
			{
				addW(new WNode(weapon("BlastingWand", 17, 1, 45, 1)));
			}
			else if (temp[i] == 2)
			{
				addW(new WNode(weapon("Pickaxe", 19, 1, 50, 2)));
			}
			else if (temp[i] == 3)
			{
				addW(new WNode(weapon("Sheen", 21, 1, 55, 3)));
			}
			else if (temp[i] == 4)
			{
				addW(new WNode(weapon("NeedlesslyLargeRod", 31, 1, 80, 4)));
			}
		}
	}
	/*addW(new WNode(weapon("BFsword", 15, 1, 40, 0)));
	addW(new WNode(weapon("BlastingWand", 17, 1, 45, 1)));
	addW(new WNode(weapon("Pickaxe", 19, 1, 50, 2)));
	addW(new WNode(weapon("Sheen", 21, 1, 55, 3)));
	addW(new WNode(weapon("NeedlesslyLargeRod", 31, 1, 80, 4)));*/
}

void shop::loadW2(scoreboard& s)
{
	if (s.getbought().empty())
	{
		addW(new WNode(weapon("FrostFang", 16, 1, 48, 0)));
		addW(new WNode(weapon("Hexdrinker", 18, 1, 53, 1)));
		addW(new WNode(weapon("Tiamat", 20, 1, 57, 2)));
		addW(new WNode(weapon("VampiricSceptor", 22, 1, 64, 3)));
		addW(new WNode(weapon("AetherWisp", 40, 1, 100, 4)));
	}
	else
	{
		s.sortbought();
		vector<int> temp{ 0, 1, 2, 3, 4 };
		for (int i = 0; i < s.getbought().size(); i++)
		{
			switch (s.getbought()[i])
			{
			case 0:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 0)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 1:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 1)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 2:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 2)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 3:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 3)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 4:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 4)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			}
		}
		//sort the vector create a sorting in scoreboard
		//new vector here that has all elements and remove them based on whats in bought vector
		//iterate through new vector
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 0)
			{
				addW(new WNode(weapon("FrostFang", 16, 1, 48, 0)));
			}
			else if (temp[i] == 1)
			{
				addW(new WNode(weapon("Hexdrinker", 18, 1, 53, 1)));
			}
			else if (temp[i] == 2)
			{
				addW(new WNode(weapon("Tiamat", 20, 1, 57, 2)));
			}
			else if (temp[i] == 3)
			{
				addW(new WNode(weapon("VampiricSceptor", 22, 1, 64, 3)));
			}
			else if (temp[i] == 4)
			{
				addW(new WNode(weapon("AetherWisp", 40, 1, 100, 4)));
			}
		}
	}
	/*addW(new WNode(weapon("FrostFang", 16, 1, 48, 0)));
	addW(new WNode(weapon("Hexdrinker", 18, 1, 53, 1)));
	addW(new WNode(weapon("Tiamat", 20, 1, 57, 2)));
	addW(new WNode(weapon("VampiricSceptor", 22, 1, 64, 3)));
	addW(new WNode(weapon("AetherWisp", 40, 1, 100, 4)));*/
}

void shop::loadW3(scoreboard& s)
{
	if (s.getbought().empty())
	{
		addW(new WNode(weapon("InfinityEdge", 21, 1, 60, 0)));
		addW(new WNode(weapon("BloodThirster", 26, 1, 67, 1)));
		addW(new WNode(weapon("StormRazor", 31, 1, 79, 2)));
		addW(new WNode(weapon("TheCollector", 37, 1, 90, 3)));
		addW(new WNode(weapon("Muramana", 50, 1, 120, 4)));
	}
	else
	{
		s.sortbought();
		vector<int> temp{ 0, 1, 2, 3, 4 };
		for (int i = 0; i < s.getbought().size(); i++)
		{
			switch (s.getbought()[i])
			{
			case 0:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 0)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 1:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 1)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 2:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 2)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 3:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 3)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 4:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 4)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			}
		}
		//sort the vector create a sorting in scoreboard
		//new vector here that has all elements and remove them based on whats in bought vector
		//iterate through new vector
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 0)
			{
				addW(new WNode(weapon("InfinityEdge", 21, 1, 60, 0)));
			}
			else if (temp[i] == 1)
			{
				addW(new WNode(weapon("BloodThirster", 26, 1, 67, 1)));
			}
			else if (temp[i] == 2)
			{
				addW(new WNode(weapon("StormRazor", 31, 1, 79, 2)));
			}
			else if (temp[i] == 3)
			{
				addW(new WNode(weapon("TheCollector", 37, 1, 90, 3)));
			}
			else if (temp[i] == 4)
			{
				addW(new WNode(weapon("Muramana", 50, 1, 120, 4)));
			}
		}
	}
	/*addW(new WNode(weapon("InfinityEdge", 21, 1, 60, 0)));
	addW(new WNode(weapon("BloodThirster", 26, 1, 67, 1)));
	addW(new WNode(weapon("StormRazor", 31, 1, 79, 2)));
	addW(new WNode(weapon("TheCollector", 37, 1, 90, 3)));
	addW(new WNode(weapon("Muramana", 50, 1, 120, 4)));*/
}

void shop::loadW4(scoreboard& s)
{
	if (s.getbought().empty())
	{
		addW(new WNode(weapon("DuskBlade", 50, 1, 110, 0)));
		addW(new WNode(weapon("Eclipse", 60, 1, 130, 1)));
		addW(new WNode(weapon("NightHarvester", 70, 1, 140, 2)));
		addW(new WNode(weapon("StrideBreaker", 80, 1, 150, 3)));
		addW(new WNode(weapon("Goredrinker", 1000, 1, 300, 4)));
	}
	else
	{
		s.sortbought();
		vector<int> temp{ 0, 1, 2, 3, 4 };
		for (int i = 0; i < s.getbought().size(); i++)
		{
			switch (s.getbought()[i])
			{
			case 0:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 0)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 1:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 1)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 2:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 2)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 3:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 3)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			case 4:
				for (int j = 0; j < temp.size(); j++)
				{
					if (temp[j] == 4)
					{
						temp.erase(temp.begin() + j);
					}
				}
				break;
			}
		}
		//sort the vector create a sorting in scoreboard
		//new vector here that has all elements and remove them based on whats in bought vector
		//iterate through new vector
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 0)
			{
				addW(new WNode(weapon("DuskBlade", 50, 1, 110, 0)));
			}
			else if (temp[i] == 1)
			{
				addW(new WNode(weapon("Eclipse", 60, 1, 130, 1)));
			}
			else if (temp[i] == 2)
			{
				addW(new WNode(weapon("NightHarvester", 70, 1, 140, 2)));
			}
			else if (temp[i] == 3)
			{
				addW(new WNode(weapon("StrideBreaker", 80, 1, 150, 3)));
			}
			else if (temp[i] == 4)
			{
				addW(new WNode(weapon("Goredrinker", 1000, 1, 300, 4)));
			}
		}
	}
	/*addW(new WNode(weapon("DuskBlade", 50, 1, 110, 0)));
	addW(new WNode(weapon("Eclipse", 60, 1, 130, 1)));
	addW(new WNode(weapon("NightHarvester", 70, 1, 140, 2)));
	addW(new WNode(weapon("StrideBreaker", 80, 1, 150, 3)));
	addW(new WNode(weapon("Goredrinker", 1000, 1, 300, 4)));*/
}

void shop::setTail(WNode* tail)
{
	this->tail = tail;
}

void shop::clear()
{
	WNode* current = new WNode();
	while (head != NULL)
	{
		current = head;
		head = head->getNext();
		free(current);
	}
	
}

void shop::clearstack()
{
	while (!recent.empty())
	{
		recent.pop();
	}
}

void shop::remove(WNode* w)
{
	if (head == NULL || w == NULL)
	{
		return;
	}
	if (head == w)
	{
		head = w->getNext();
	}
	if (w->getNext() != NULL)
	{
		w->getNext()->setPrev(w->getPrev());
	}
	if (w->getPrev() != NULL)
	{
		w->getPrev()->setNext(w->getNext());
	}
	free(w);
	return;
}

weapon shop::pop()
{
	weapon w = recent.top();
	recent.pop();
	return w;
}