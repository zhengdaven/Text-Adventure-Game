#include "HandleMission.h"

HandleSideQuest::HandleSideQuest(scoreboard s)
{
    if (s.getMission() == 0)
    {
        current.push(sidearray[s.getFloor()]);
    }
}

void HandleSideQuest::CheckSideQuest(player& p, Combat c, scoreboard& s)
{
    if (!current.empty())
    {
        SideQuest temp = current.front();
        switch (temp.getPoints())
        {
            case 100:
                if (p.getCurrency() >= 300 && s.getPos() == 2)
                {
                    p.ModifyScore(temp.getPoints());
                    s.modifyScore(p.getScore());
                    s.setMission(1);
                    completed.push(temp);
                    current.pop();
                }
                break;
            case 200:
                if (p.getboughtonfloor() == 0 && s.getPos() == 2)
                {
                    p.ModifyScore(temp.getPoints());
                    s.modifyScore(p.getScore());
                    s.setMission(1);
                    completed.push(temp);
                    current.pop();
                }
                break;
            case 300:
                if (c.getoneshot() == 1)
                {
                    p.ModifyScore(temp.getPoints());
                    s.modifyScore(p.getScore());
                    s.setMission(1);
                    completed.push(temp);
                    current.pop();
                }
                break;
            case 400:
                if (p.getboughtgore() == 1)
                {
                    p.ModifyScore(temp.getPoints());
                    s.modifyScore(p.getScore());
                    s.setMission(1);
                    completed.push(temp);
                    current.pop();
                }
        }
    }
}

void HandleSideQuest::loadsidequest(int floor)
{
    current.push(sidearray[floor]);
}

vector<SideQuest> HandleSideQuest::getQuest()
{
    return sidearray;
}

void HandleSideQuest::clear()
{
    while (!current.empty())
    {
        current.pop();
    }
}

void HandleSideQuest::printQuest(scoreboard s)
{
    if (!current.empty())
    {
        cout << "Floor " << s.getFloor() << " SideQuest: " << current.front().getDes() << endl;
    }
    else
    {
        cout << "Floor " << s.getFloor() << " SideQuest: " << sidearray[s.getFloor()].getDes() << endl;
    }
}

ostream& operator<<(ostream& os, HandleSideQuest& h)
{
    // TODO: insert return statement here
    os << "Completed SideQuest:" << endl;
    while (!h.completed.empty())
    {
        SideQuest temp = h.completed.front();
        h.completed.pop();
        os << temp.getDes() << endl;
    }
    os << endl;
    return os;
}