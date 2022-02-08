#pragma once
#include <string>
using namespace std;
class SideQuest
{
private:
    string description;
    int points;
public:
    SideQuest();
    SideQuest(string description, int points); //constructor
    void setDes(string description);
    void setPoints(int points);
    string getDes();
    int getPoints();
};