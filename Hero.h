#ifndef HERO_H
#define HERO_H

#include "Pit.h"
#include "Participant.h"

class Pit;
class Hero : public Participant{
    public:
        Hero(char = ' ', int = 0, int = 0, string = " ");
        virtual ~Hero();
        virtual void move(Pit*);
        virtual void incurDamage(Participant*);
        virtual int causeDamage();
        string getName();
        int getHealth();

    private:
        string name;
        int health;

};

#endif
