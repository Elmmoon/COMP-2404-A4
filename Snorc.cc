#include <iostream>
using namespace std;
#include <string>
#include "Snorc.h"

Snorc::Snorc(int r, int c, int s)
 :Participant('s', r, c), strength(s){}

Snorc::~Snorc(){}

void Snorc::move(Pit* p){
    int rowShift = pos->getRow();
    int colShift = pos->getCol();
    
    if (random(2) == 0)
            rowShift--;
        else
            rowShift++;
    colShift += random(3) - 1;

    if (rowShift <= MAX_ROW - 7)
        rowShift = pos->getRow();
    else if (rowShift >= MAX_ROW)
        rowShift = MAX_ROW - 1;
    if (colShift < 0)
        colShift = 0;
    else if (colShift >= MAX_COL)
        colShift = MAX_COL - 1;

    if (p->withinBounds(rowShift, colShift))
        pos->set(rowShift, colShift);
}

void Snorc::incurDamage(Participant* p){}

int Snorc::causeDamage(){
    return strength;
}