#ifndef PIT_H
#define PIT_H

#include "defs.h"
#include "Position.h"
#include "PartArray.h"
#include "Hero.h"

class Pit{
  public:
    Pit(const char [MAX_ROW+1] [MAX_COL+1]);
    ~Pit();
    bool validPos(int, int);
    bool withinBounds(int, int);
    bool underLedge(Position*);
    void print(PartArray*, Hero*, Hero*);
  private:
    char layout[MAX_ROW+1][MAX_COL+1];
};

#endif






