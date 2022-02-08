#pragma once
#include "Player.h"
#include "Weapon.h"
#include <iomanip>
#include <iostream>
using namespace std;

class WNode {
private:
    weapon item;
    WNode* next;
    WNode* prev;
public:
    WNode();
    WNode(weapon item);
    void setNext(WNode* next);
    void setPrev(WNode* next);
    WNode* getNext();
    WNode* getPrev();
    weapon getitem();
    void print();
};