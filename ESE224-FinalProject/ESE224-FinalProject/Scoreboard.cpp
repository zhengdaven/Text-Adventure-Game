#include "Scoreboard.h"

scoreboard::scoreboard()
{
    SB_Name = "";
    SB_Score = 0;
    SB_Difficulty = "";
    SB_DifficultyMod = 0;
    floor = 0;
    pos = 0;
    missioncomplete = 0;
}

void scoreboard::setName(string name)
{
    SB_Name = name;
}

void scoreboard::setScore(int score)
{
    SB_Score = score;
}

void scoreboard::setDiff(string diff)
{
    SB_Difficulty = diff;
}

void scoreboard::setDiffMod(int diffmod)
{
    SB_DifficultyMod = diffmod;
}

void scoreboard::setFloor(int f)
{
    floor = f;
}

void scoreboard::setPos(int p)
{
    pos = p;
}

void scoreboard::setMission(bool m)
{
    missioncomplete = m;
}

string scoreboard::getName()
{
    return SB_Name;
}

int scoreboard::getScore()
{
    return SB_Score;
}

string scoreboard::getDiff()
{
    return SB_Difficulty;
}

int scoreboard::getDiffMod()
{
    return SB_DifficultyMod;
}

int scoreboard::getFloor()
{
    return floor;
}

int scoreboard::getPos()
{
    return pos;
}

bool scoreboard::getMission()
{
    return missioncomplete;
}

void scoreboard::modifyScore(int score)
{
    SB_Score = score * SB_DifficultyMod;
}

void scoreboard::modifyPos()
{
    pos++;
}

void scoreboard::modifyDiffMod()
{
    if (SB_Difficulty == "easy")
    {
        SB_DifficultyMod = 1;
    }
    else if (SB_Difficulty == "medium")
    {
        SB_DifficultyMod = 2;
    }
    else
    {
        SB_DifficultyMod = 3;
    }
}

void scoreboard::nextFloor(player& p, Combat& c)
{
    if (pos > 2)
    {
        floor++;
        pos = 0;
        missioncomplete = 0;
        p.setboughtonfloor(0);
        c.setoneshot(0);
        clear();
    }
}

void scoreboard::SB_out()
{
    cout << "Scoreboard:" << "\nPlayer Name : " << SB_Name << "\nScore : " << SB_Score << "\nDifficulty : " << SB_Difficulty << "\nDifficulty Modifier : " << SB_DifficultyMod << "\nFloor : " << floor << "\nPosition : " << pos << "\nFloor Quest Completion: " << missioncomplete << endl << endl;
}

void scoreboard::clear()
{
    bought.clear();
}

vector<int> scoreboard::getbought()
{
    return bought;
}

void scoreboard::setbought(int b)
{
    bought.push_back(b);
}

void scoreboard::sortbought()
{
    for (int i = 0; i < bought.size() - 1; i++)
    {
        for (int j = i + 1; j < bought.size(); j++)
        {
            if (bought[i] > bought[j])
            {
                int temp = bought[i];
                bought[i] = bought[j];
                bought[j] = temp;
            }
        }
    }
}