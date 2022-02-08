#include "Mission.h"

SideQuest::SideQuest()
{
	description = "";
	points = 0;
}

SideQuest::SideQuest(string description, int points)
{

	this->description = description;
	this->points = points;
}

void SideQuest::setPoints(int points)
{
	this->points = points;
}

void SideQuest::setDes(string description)
{
	this->description = description;
}

string SideQuest::getDes()
{
	return description;
}

int SideQuest::getPoints()
{
	return points;
}