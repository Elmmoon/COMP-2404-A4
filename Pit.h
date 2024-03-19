/*Class that represents the pit (stage map) of the escape.
Forward declarations included to prevent circular dependency errors*/

#ifndef PIT_H
#define PIT_H

#include "defs.h"
#include "Position.h"

class Hero;
class PartArray;

class Pit{
  public:
    Pit(const char [MAX_ROW+1] [MAX_COL+1]);
    ~Pit();
    bool validPos(int, int) const;
    bool withinBounds(int, int) const;
    bool underLedge(Position*) const;
    void print(PartArray*, Hero*, Hero*) const;
  private:
    char layout[MAX_ROW+1][MAX_COL+1];
};

#endif






