#include <iostream>
using namespace std;
#include <string>

#include "Participant.h"
#include "defs.h"

Participant::Participant(char a, int r, int c)
 :avatar(a), dead(false) {
    pos = new Position(r,c);
 }

Participant::~Participant(){
    delete pos;
}

bool Participant::collide(Participant* p){
    return pos->equals(p->pos);
}

char Participant::getAvatar(){
    return avatar;
}

int Participant::getRow(){
    return pos->getRow();
}

int Participant::getCol(){
    return pos->getCol();
}

bool Participant::isDead(){
    return dead;
}

bool Participant::isSafe(){
    return (pos->getCol() == 1);
}
