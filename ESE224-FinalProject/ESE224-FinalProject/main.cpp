#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Scoreboard.h"
#include "Enemy.h"
#include "Weapon.h"
#include "FileOperations.h"
#include "WeaponShop.h"
#include "EnemyList.h"
#include "CombatLog.h"
#include "HandleMission.h"
#include "Mission.h"

using namespace std;

void EnterGame()
{
	FileOperations f1;
	player p1;
	shop w1;
	scoreboard s1;
	enemy monster;
	weapon d1;
	Combat c1;
	int a;
	double random;
	int damage;
	do
	{
		cout << "Do you have an existing file?" << endl << "[0]Yes or [1]No" << endl << "> ";
		cin >> a;
	} while (a != 0 && a != 1);
	if (a == 0)
	{
		f1.ChooseFile(s1, p1);
		f1.ChooseFile1();
	}
	else
	{
		f1.ChooseFile1();
		string name;
		cout << "Enter player name: ";
		cin >> name;
		p1.setName(name);
		s1.setName(name);
		do
		{
			cout << "What difficulty level do you want to play on?" << endl;
			cout << "Pick from: [0]Easy, [1]Medium, [2]Hard" << endl << "> ";
			cin >> a;
		} while (a != 0 && a != 1 && a != 2);
		if (a == 0)
		{
			s1.setDiff("easy");
			s1.modifyDiffMod();
		}
		else if (a == 1)
		{
			s1.setDiff("medium");
			s1.modifyDiffMod();
		}
		else
		{
			s1.setDiff("hard");
			s1.modifyDiffMod();
		}
	}
	HandleSideQuest h1(s1);
	enemylist l1(s1);
	switch (s1.getFloor())
	{
	case 0:
		w1.loadW1(s1);
		break;
	case 1:
		w1.loadW2(s1);
		break;
	case 2:
		w1.loadW3(s1);
		break;
	case 3:
		w1.loadW4(s1);
		break;
	}
	int choice = -1;
	while (s1.getFloor() != 4 && p1.getHP() > 0)
	{
		if (choice == 4)
		{
			break;
		}
		h1.printQuest(s1);
		d1 = p1.getWeapon();
		do
		{
			cout << "What would you like to do?" << endl << "[0]Examine Self, [1]Fight, [2]Buy from Shop, [3]Scoreboard, [4]Return" << endl << "> ";
			cin >> choice;
		} while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4);
		switch (choice)
		{
		case 0:
			cout << p1;
			p1.printInventory();
			break;
		case 1:
			monster = l1.getEnemy();
			cout << "You have encountered " << monster.getName() << " on floor " << s1.getFloor() << endl;
			do
			{
				cout << p1;//change this for the operator
				cout << monster;//change this for the operator
				do
				{
					cout << "What would you like to do?" << endl << "[0]Attack, [1]Switch Weapons" << endl << "> ";
					cin >> choice;
				} while (choice != 0 && choice != 1);
				switch (choice)
				{
				case 0:
					c1.addLog(p1, monster);//log
					monster.ModifyHealth(-(p1.getDMG()));
					cout << "You have done " << p1.getDMG() << " damage to the enemy" << endl;
					srand(time(0));
					random = ((rand() % 51) + 75) / 100.0;
					damage = monster.getDMG() * random;
					p1.ModifyHealth(-damage);
					cout << "The enemy has done " << damage << " damage to you" << endl << endl;
					d1.modifyUse();
					if (d1.getUse() == 0)
					{
						p1.modifyInventory(p1.getWeapon());
						p1.equipWeapon(p1.getInventory()[0]);
						d1 = p1.getWeapon();
						p1.setDMG(p1.getWeapon().getDMG());
					}
					break;

				case 1:
					p1.printInventory();
					do
					{
						cout << "Select the number that corresponds to the weapon you want to equip: ";
						cin >> choice;
					} while (choice >= p1.getInventory().size());
					p1.equipWeapon(p1.getInventory()[choice]);
					d1 = p1.getWeapon();
					p1.setDMG(p1.getWeapon().getDMG());
					break;
				}
			} while (p1.getHP() > 0 && monster.getHP() > 0);
			if (p1.getHP() < 0)
			{
				c1.addLog(p1, monster);
				cout << "You have been defeated" << endl << endl;
				cout << c1;
				cout << l1;
				cout << h1;
				s1.SB_out();
				f1.Save2File(p1);
				f1.Save2File1(s1);
				f1.Save2File2(s1);
				f1.clear();
				w1.clear();
				w1.clearstack();
				l1.clear();
				return;
			}
			else
			{
				c1.addLog(p1, monster);
				cout << "You have defeated the enemy" << endl << endl;
				cout << c1;
				l1.destroyEnemy();
				p1.ModifyCurrency(monster.getCurr());
				p1.ModifyScore(monster.getScore());
				h1.CheckSideQuest(p1, c1, s1);
				s1.modifyPos();
				int floor = s1.getFloor();
				s1.nextFloor(p1, c1);
				if (floor != s1.getFloor()) {
					h1.clear();
					h1.loadsidequest(s1.getFloor());
					w1.clear();
					switch (s1.getFloor())
					{
					case 0:
						w1.loadW1(s1);
						break;
					case 1:
						w1.loadW2(s1);
						break;
					case 2:
						w1.loadW3(s1);
						break;
					case 3:
						w1.loadW4(s1);
						break;
					}
				}
				s1.modifyScore(p1.getScore());
			}
			break;

		case 2:
			/*switch (s1.getFloor())
			{
			case 0:
				w1.loadW1();
				break;
			case 1:
				w1.loadW2();
				break;
			case 2:
				w1.loadW3();
				break;
			case 3:
				w1.loadW4();
				break;
			}*/
			w1.print();
			while (true)
			{
				cout << "Currency: " << p1.getCurrency() << endl;
				do
				{
					w1.printOption();
					cin >> choice;
				} while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
				if (choice >= 0 && choice <= 4)
				{
					w1.buy(p1, s1, choice);
				}
				else
				{
					cout << "Exited Weapon Shop!" << endl << endl;
					w1.addtoInv(p1);
					//w1.clear();
					h1.CheckSideQuest(p1, c1, s1);
					break;
				}
			}
			break;

		case 3:
			s1.SB_out();
			break;

		case 4:
			cout << l1;
			cout << h1;
			f1.Save2File(p1);
			f1.Save2File1(s1);
			f1.Save2File2(s1);
			f1.clear();
			w1.clear();
			w1.clearstack();
			l1.clear();
			break;
		}
	}
	if (s1.getFloor() == 4)
	{
		cout << "You Win! Returning to main menu..." << endl << endl;
		cout << l1;
		cout << h1;
		f1.Save2File(p1);
		f1.Save2File1(s1);
		f1.Save2File2(s1);
		f1.clear();
		w1.clear();
		w1.clearstack();
		l1.clear();
	}
	else if (p1.getHP() <= 0)
	{
		cout << "You're dead. Returning to main menu..." << endl << endl;
	}
	else
	{
		cout << "Returning to main menu..." << endl << endl;
	}
	return;
}

int main()
{
	while (true)
	{
		int choice1;
		FileOperations f1;
		f1.ChooseFile1();
		do
		{
			cout << "Main Menu:" << endl;
			cout << "(0) Scroreboard sorted by score" << endl;
			cout << "(1) Scroreboard sorted by name" << endl;
			cout << "(2) Averaged scoreboard" << endl;
			cout << "(3) Search by name" << endl;
			cout << "(4) Enter game" << endl;
			cout << "(5) Quit" << endl;
			cout << "> ";
			cin >> choice1;     
		} while (choice1 != 0 && choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5);
		switch (choice1)
		{
			case 0:
				f1.sortscore();
				f1.savesort();
				cout << f1;
				break;

			case 1:
				f1.sortname();
				f1.savesort();
				cout << f1;
				break;

			case 2:
				f1.AverageScore();
				f1.savesort();
				cout << f1;
				break;

			case 3:
				f1.ScoreSearch();
				break;

			case 4:
				EnterGame();
				break;

			case 5:
				exit(1);
				break;
		}
	}
}