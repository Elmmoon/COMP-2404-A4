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

bool Participant::collide(Participant* p) const{
    return pos->equals(p->pos);
}

char Participant::getAvatar() const{
    return avatar;
}

int Participant::getRow() const{
    return pos->getRow();
}

int Participant::getCol() const{
    return pos->getCol();
}

bool Participant::isDead() const{
    return dead;
}

bool Participant::isSafe() const{
    return (pos->getRow() == 1);
}
