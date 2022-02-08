#pragma once
#include <iostream>
using namespace std;

class Srank
{
private:
	string name;
	int score;
public:
	Srank();
	Srank(string n, int s);
	string getName();
	int getScore();
	void setName(string n);
	void setScore(int n);
	bool operator<(const Srank& s1) const;
	struct NameComparator
	{
		bool operator ()(const Srank& player1, const Srank& player2) {
			return player1.name < player2.name;
		};
	};
};