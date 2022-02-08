#include "Enemy.h"

enemy::enemy()
{
    Name = "";
    HealthPoints = 0;
    AttackDamage = 0;
    level = 0;
    Currency = 0;
    Score = 0;
}

enemy::enemy(string Name, int HealthPoints, int AttackDamage, int level, int Currency, int Score)
{
    this->Name = Name;
    this->HealthPoints = HealthPoints;
    this->AttackDamage = AttackDamage;
    this->level = level;
    this->Currency = Currency;
    this->Score = Score;
}

string enemy::getName()
{
    return Name;
}

int enemy::getHP()
{
    return HealthPoints;
}

int enemy::getDMG()
{
    return AttackDamage;
}

int enemy::getLVL()
{
    return level;
}

int enemy::getCurr()
{
    return Currency;
}
int enemy::getScore()
{
    return Score;
}

void enemy::setName(string Name)
{
    this->Name = Name;
}

void enemy::setHP(int HealthPoints)
{
    this->HealthPoints = HealthPoints;
}

void enemy::setDMG(int AttackDamage)
{
    this->AttackDamage = AttackDamage;
}

void enemy::setLVL(int level)
{
    this->level = level;
}

void enemy::setCurr(int Currency)
{
    this->Currency = Currency;
}
void enemy::setScore(int Score)
{
    this->Score = Score;
}

void enemy::ModifyHealth(int Health)
{
    HealthPoints += Health;
}

void enemy::ModifyDamage(int Damage)
{
    AttackDamage += Damage;
}

/*void enemy::print()
{
    cout << "Enemy Information:" << "\nName: " << Name << "\nHP : " << HealthPoints << "\nAverage AD : " << AttackDamage << "\nLevel : " << level << "\nCurrency : " << Currency << "\nScore : " << Score << endl << endl;
}*/

ostream& operator<<(ostream& os, const enemy& e)
{
    // TODO: insert return statement here
    os << "Enemy Information:" << "\nName: " << e.Name << "\nHP : " << e.HealthPoints << "\nAverage AD : " << e.AttackDamage << "\nLevel : " << e.level << "\nCurrency : " << e.Currency << "\nScore : " << e.Score << endl << endl;
    return os;
}