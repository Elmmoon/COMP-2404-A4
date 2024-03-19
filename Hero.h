/*Class that represents the heroes of the escape.*/
#ifndef HERO_H
#define HERO_H

#include "defs.h"
#include "Participant.h"
#include "Pit.h"

class Hero: public Participant{
    public:
        Hero(char = ' ', int = 0, int = 0, string = " ");
        virtual ~Hero();
        virtual void move(Pit*);
        virtual void incurDamage(Participant*);
        virtual int causeDamage();
        string getName() const;
        int getHealth() const;

    private:
        string name;
        int health;

};

#endif
