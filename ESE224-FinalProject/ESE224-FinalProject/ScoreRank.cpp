#include "ScoreRank.h"

Srank::Srank()
{
	name = "";
	score = 0;
}

Srank::Srank(string n, int s)
{
	name = n;
	score = s;
}

string Srank::getName()
{
	return name;
}

int Srank::getScore()
{
	return score;
}

void Srank::setName(string n)
{
	name = n;
}

void Srank::setScore(int n)
{
	score = n;
}

bool Srank::operator<(const Srank& s1) const
{
	return (score < s1.score);
}