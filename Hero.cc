#include <iostream>
using namespace std;
#include <string>

#include "Hero.h"
#include "defs.h"

Hero::Hero(char a, int r, int c, string n)
 : Participant(a, r, c), name(n), health(MAX_HEALTH){}

Hero::~Hero(){}

void Hero::move(Pit* p){
    if (isDead() || isSafe())
        return;
        
    int rowShift = pos->getRow();
    int colShift = pos->getCol();
    if (p->underLedge(pos)){
        if (random(2) == 0)
            colShift--;
        else
            colShift++;
    }
    else {
        int rand = random(10);
        colShift += random(5) - 2;
        if (rand < 5)
            rowShift--;
        else if (rand == 5)
            rowShift -= 2;
        else
            rowShift++;
    }

    if (rowShift < 0)
        rowShift = 0;
    else if (rowShift >= MAX_ROW)
        rowShift = MAX_ROW - 1;
    if (colShift < 0)
        colShift = 0;
    else if (colShift >= MAX_COL)
        colShift = MAX_COL - 1;
    
    if (p->validPos(rowShift, colShift))
        pos->set(rowShift, colShift);
    
}

void Hero::incurDamage(Participant* p){
    if (isDead() || isSafe())
        return;
    health -= p->causeDamage();
    if (health <= 0){
        health = 0;
        avatar = '+';
        dead = true;
    }
}

int Hero::causeDamage(){
    return 0;
}

string Hero::getName() const{
    return name;
}

int Hero::getHealth() const{
    return health;
}