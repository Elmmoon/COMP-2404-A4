/*Abstract class that defines base functionality for each kind of participant,
i.e. Hero and Snorc*/

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Position.h"
#include "Pit.h"

class Participant{
  public:
    Participant(char = ' ', int = 0, int = 0);
    virtual ~Participant();
    virtual void move(Pit*) = 0;
    virtual void incurDamage(Participant*) = 0;
    virtual int causeDamage() = 0;
    bool collide(Participant*) const;
    char getAvatar() const;
    int getRow() const;
    int getCol() const;
    bool isDead() const;
    bool isSafe() const;
  protected:
    char avatar;
    bool dead;
    Position* pos;
};

#endif
