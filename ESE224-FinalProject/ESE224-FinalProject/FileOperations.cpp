#include "FileOperations.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Player.h"
#include "Scoreboard.h"

using namespace std;

void FileOperations::Save2File(player in)
{
	cout << "Name the player file (please remember for future use): ";
	cin >> P_file_name;
	P_myFile.open(P_file_name, ios::out);
	if (P_myFile.fail()) {
		cerr << "File cannot be opened.";
		exit(1);
	}
	P_myFile << in.getName() << endl;
	P_myFile << in.getScore() << endl;
	P_myFile << in.getHP() << endl;
	P_myFile << in.getDMG() << endl;
	P_myFile << in.getCurrency() << endl;
	P_myFile << in.getWeapon().getItem() << endl;
	P_myFile << in.getWeapon().getDMG() << endl;
	P_myFile << in.getWeapon().getUse() << endl;
	P_myFile << in.getWeapon().getCost() << endl;
	P_myFile << in.getWeapon().getnum() << endl;
	P_myFile << in.getInventory().size() << endl;
	for (int i = 1; i < in.getInventory().size(); i++)
	{
		P_myFile << in.getInventory()[i].getItem() << endl;
		P_myFile << in.getInventory()[i].getDMG() << endl;
		P_myFile << in.getInventory()[i].getUse() << endl;
		P_myFile << in.getInventory()[i].getCost() << endl;
		P_myFile << in.getInventory()[i].getnum() << endl;
	}
	P_myFile << in.getboughtonfloor() << endl;
	CloseFile();
}

void FileOperations::Save2File1(scoreboard in)
{
	cout << "Name the scoreboard file (please remember for future use): ";
	cin >> SB_file_name;
	SB_myFile.open(SB_file_name, ios::out);
	if (P_myFile.fail())
	{
		cerr << "File cannot be opened.";
		exit(1);
	}
	SB_myFile << in.getName() << endl;
	SB_myFile << in.getScore() << endl;
	SB_myFile << in.getDiff() << endl;
	SB_myFile << in.getDiffMod() << endl;
	SB_myFile << in.getFloor() << endl;
	SB_myFile << in.getPos() << endl;
	SB_myFile << in.getMission() << endl;
	SB_myFile << in.getbought().size() << endl;
	for (int i = 0; i < in.getbought().size(); i++)
	{
		SB_myFile << in.getbought()[i] << endl;
	}
	CloseFile();
}

void FileOperations::Save2File2(scoreboard s)
{
	sbrankfile.open(sbrank, ios::out);
	if (sbrankfile.fail())
	{
		cerr << "File cannot be opened.";
		exit(1);
	}
	list<Srank>::iterator it1;
	for (it1 = rank.begin(); it1 != rank.end(); it1++)
	{
		sbrankfile << it1->getName() << " " << it1->getScore() << endl;
	}
	sbrankfile << s.getName() << " " << s.getScore() << endl;
	sbrankfile.close();
	/*list<string>::iterator it1;
	list<int>::iterator it2;
	for (it1 = rankname.begin(), it2 = rankscore.begin(); it1 != rankname.end() && it2 != rankscore.end(); it1++, it2++)
	{
		sbrankfile << *it1 << " " << *it2 << endl;
	}
	sbrankfile << s.getName() << " " << s.getScore() << endl;
	sbrankfile.close();*/

	/*sbrankfile.open(sbrank, ios::out);
	if (sbrankfile.fail())
	{
		cerr << "File cannot be opened.";
		exit(1);
	}
	for (int i = 0; i < rankscore.size(); i++)
	{
		sbrankfile << rankname[i] << " " << rankscore[i] << endl;
	}
	sbrankfile << s.getName() << " " << s.getScore() << endl;
	sbrankfile.close();*/
}

void FileOperations::ChooseFile(scoreboard& s, player& p)
{
	cout << "Please enter the file name of existing player file: ";
	cin >> P_file_name;
	P_myFile.open(P_file_name, ios::in);
	if (P_myFile.fail()) {
		cerr << "File cannot be found" << endl;
		exit(1);
	}
	else
	{
		cerr << "Successfully opens the target file!" << endl;
	}
	string input, w1;
	int stats, w2, w3, w4, w5, isize, bsize;
	bool miss, bought;
	P_myFile >> input;
	p.setName(input);
	P_myFile >> stats;
	p.setScore(stats);
	P_myFile >> stats;
	p.setHP(stats);
	P_myFile >> stats;
	p.setDMG(stats);
	P_myFile >> stats;
	p.setCurrency(stats);
	P_myFile >> w1;
	P_myFile >> w2;
	P_myFile >> w3;
	P_myFile >> w4;
	P_myFile >> w5;
	p.equipWeapon(weapon(w1, w2, w3, w4, w5));
	P_myFile >> isize;
	for (int i = 1; i < isize; i++)
	{
		P_myFile >> w1;
		P_myFile >> w2;
		P_myFile >> w3;
		P_myFile >> w4;
		P_myFile >> w5;
		p.setInventory(weapon(w1, w2, w3, w4, w5));
	}
	P_myFile >> bought;
	p.setboughtonfloor(bought);

	cout << "Please enter the file name of existing scoreboard file: ";
	cin >> SB_file_name;
	SB_myFile.open(SB_file_name, ios::in);
	if (SB_myFile.fail())
	{
		cerr << "File cannot be found" << endl;
		exit(1);
	}
	else
	{
		cerr << "Successfully opens the target file!" << endl;
	}
	SB_myFile >> input;
	s.setName(input);
	SB_myFile >> stats;
	s.setScore(stats);
	SB_myFile >> input;
	s.setDiff(input);
	SB_myFile >> stats;
	s.setDiffMod(stats);
	SB_myFile >> stats;
	s.setFloor(stats);
	SB_myFile >> stats;
	s.setPos(stats);
	SB_myFile >> miss;
	s.setMission(miss);
	SB_myFile >> bsize;
	for (int i = 0; i < bsize; i++)
	{
		SB_myFile >> stats;
		s.setbought(stats);
	}
	CloseFile();
}

void FileOperations::ChooseFile1()
{
	/*rankname.clear();
	rankscore.clear();*/
	rank.clear();
	string name1;
	int score1, buffer;
	sbrankfile.open(sbrank, ios::in);
	if (sbrankfile.fail())
	{
		cerr << "File cannot be found" << endl;
		exit(1);
	}
	if (sbrankfile.peek() < 0)
	{
		sbrankfile >> buffer;
	}
	while (!sbrankfile.eof())
	{
		sbrankfile >> name1 >> score1;
		/*rankname.push_back(name1);
		rankscore.push_back(score1);*/
		rank.push_back(Srank(name1, score1));
	}
	if (rank.size() != 0)
	{
		rank.pop_back();
	}
	sbrankfile.close();
	/*if (rankname.size() != 0)
	{
		rankname.pop_back();
		rankscore.pop_back();
	}*/
}

void FileOperations::CloseFile()
{
	SB_myFile.close();
	P_myFile.close();
}

void FileOperations::ScoreSearch()
{
	if (rank.size() == 0)
	{
		cout << "No players in scoreboard rank" << endl << endl;
		return;
	}
	string name;
	cout << "Name to Search: ";
	cin >> name;
	/*list<string>::iterator it1;
	list<int>::iterator it2;*/
	list<Srank>::iterator it3;
	cout << "Search Result:" << endl;
	for (it3 = rank.begin(); it3 != rank.end(); it3++)
	{
		if (it3->getName() == name)
		{
			cout << it3->getName() << " " << it3->getScore() << endl;
		}
	}
	cout << endl;
	/*for (it1 = rankname.begin(), it2 = rankscore.begin(); it1 != rankname.end() && it2 != rankscore.end(); it1++, it2++)
	{
		if (*it1 == name)
		{
			cout << *it1 << " " << *it2 << endl;
		}
	}*/
}

void FileOperations::AverageScore()
{
	if (rank.empty())
	{
		cout << "No players in scoreboard rank" << endl << endl;
		return;
	}
	rank.sort(Srank::NameComparator());
	vector<Srank> temp;
	int sum = 0, count = 0;
	int average;
	for (auto v : rank)
	{
		temp.push_back(v);
	}
	for (int i = 0; i < temp.size() - 1; i++)
	{
		sum += temp[i].getScore();
		count++;
		while (i < temp.size() - 1 && temp[i].getName() == temp[i + 1].getName())
		{
			sum += temp[i + 1].getScore();
			count++;
			temp.erase(temp.begin() + (i + 1));
		}
		average = sum / count;
		temp[i].setScore(average);
		sum = 0;
		count = 0;
	}
	rank.clear();
	for (int i = 0; i < temp.size(); i++)
	{
		rank.push_back(temp[i]);
	}
}

void FileOperations::clear()
{
	while (!rank.empty())
	{
		rank.pop_back();
	}
	/*while (!rankscore.empty())
	{
		rankscore.pop_back();
		rankname.pop_back();
	}*/
}

 void FileOperations::sortname(){
 	rank.sort(Srank::NameComparator());
 }

 void FileOperations::sortscore()
 {
	rank.sort();
 }

 void FileOperations::savesort()
 {
	 sbrankfile.open(sbrank, ios::out);
	 if (sbrankfile.fail())
	 {
		 cerr << "File cannot be opened.";
		 exit(1);
	 }
	 list<Srank>::iterator it1;
	 for (it1 = rank.begin(); it1 != rank.end(); it1++)
	 {
		 sbrankfile << it1->getName() << " " << it1->getScore() << endl;
	 }
	 sbrankfile.close();
 }

/*void FileOperations::ScoreRank()
{
	if (rankscore.size() == 0)
	{
		cout << "No players in scoreboard rank" << endl << endl;
		return;
	}
	string temp;
	int temp1, sum = 0, count = 0;
	int average;
	for (int i = 0; i < rankscore.size() - 1; i++)
	{
		for (int j = i + 1; j < rankscore.size(); j++)
		{
			if (rankname[i].compare(rankname[j]) > 0)
			{
				temp = rankname[i];
				temp1 = rankscore[i];
				rankname[i] = rankname[j];
				rankscore[i] = rankscore[j];
				rankname[j] = temp;
				rankscore[j] = temp1;
			}
		}
	}
	for (int i = 0; i < rankscore.size() - 1; i++)
	{
		sum += rankscore[i];
		count++;
		while (i < rankscore.size() - 1 && rankname[i] == rankname[i + 1])
		{
			sum += rankscore[i + 1];
			count++;
			rankscore.erase(rankscore.begin() + (i + 1));
			rankname.erase(rankname.begin() + (i + 1));
		}
		average = sum / count;
		rankscore[i] = average;
		sum = 0;
		count = 0;
	}

	int choice;
	do
	{
		cout << "How would you like to see the Score Rank?" << endl;
		cout << "[0] - Alphabetical Order (A-Z), [1] - Alphabetical Order (Z-A), [2] - Numerical Order (0-9), [3] - Numerical Order (9-0)" << endl << "> ";
		cin >> choice;
	} while (choice != 0 && choice != 1 && choice != 2 && choice != 3);
	switch (choice)
	{
	case 0:
		for (int i = 0; i < rankscore.size() - 1; i++)
		{
			for (int j = i + 1; j < rankscore.size(); j++)
			{
				if (rankname[i].compare(rankname[j]) > 0)
				{
					temp = rankname[i];
					temp1 = rankscore[i];
					rankname[i] = rankname[j];
					rankscore[i] = rankscore[j];
					rankname[j] = temp;
					rankscore[j] = temp1;
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < rankscore.size() - 1; i++)
		{
			for (int j = i + 1; j < rankscore.size(); j++)
			{
				if (rankname[i].compare(rankname[j]) < 0)
				{
					temp = rankname[i];
					temp1 = rankscore[i];
					rankname[i] = rankname[j];
					rankscore[i] = rankscore[j];
					rankname[j] = temp;
					rankscore[j] = temp1;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < rankscore.size() - 1; i++)
		{
			for (int j = i + 1; j < rankscore.size(); j++)
			{
				if (rankscore[i] > rankscore[j])
				{
					temp = rankname[i];
					temp1 = rankscore[i];
					rankname[i] = rankname[j];
					rankscore[i] = rankscore[j];
					rankname[j] = temp;
					rankscore[j] = temp1;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < rankscore.size() - 1; i++)
		{
			for (int j = i + 1; j < rankscore.size(); j++)
			{
				if (rankscore[i] < rankscore[j])
				{
					temp = rankname[i];
					temp1 = rankscore[i];
					rankname[i] = rankname[j];
					rankscore[i] = rankscore[j];
					rankname[j] = temp;
					rankscore[j] = temp1;
				}
			}
		}
		break;
	}
	sbrankfile.open(sbrank, ios::out);
	if (sbrankfile.fail())
	{
		cerr << "File cannot be opened.";
		exit(1);
	}
	for (int i = 0; i < rankscore.size(); i++)
	{
		sbrankfile << rankname[i] << " " << rankscore[i] << endl;
		cout << rankname[i] << " " << rankscore[i] << endl;
	}
	cout << endl;
	sbrankfile.close();
}*/

ostream & operator<<(ostream & os, FileOperations & f)
{
	// TODO: insert return statement here
	/*list<string>::iterator it1;
	list<int>::iterator it2;*/
	list<Srank>::iterator it3;
	os << "Score Rank:" << endl;
	for (it3 = f.rank.begin(); it3 != f.rank.end(); it3++)
	{
		os << it3->getName() << " " << it3->getScore() << endl;
	}
	/*for (it1 = f.rankname.begin(), it2 = f.rankscore.begin(); it1 != f.rankname.end() && it2 != f.rankscore.end(); it1++, it2++)
	{
		os << *it1 << " " << *it2 << endl;
	}*/
	os << endl;
	return os;
}