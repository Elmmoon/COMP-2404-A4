#ifndef ESCAPE_H
#define ESCAPE_H

#include "Participant.h"
#include "PartArray.h"
#include "Hero.h"
#include "Pit.h"

class Escape
{
  public:
    Escape();
    ~Escape();
    void runEscape();

  private:
    PartArray arr;
    Hero* h1;
    Hero* h2;
    Pit* pit;
    int numSnorcs;
    void spawnSnorc();
    void moveParticipants();
    Participant* checkForCollision(Participant*);
    bool isOver();
    void printOutcome();
};

#endif

