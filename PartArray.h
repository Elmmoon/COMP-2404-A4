#ifndef PARTARRAY_H
#define PARTARRAY_H

#include "defs.h"
#include "Participant.h"

class Participant;
class PartArray{
  public:
    PartArray();
    ~PartArray();
    void add(Participant*);
    Participant* get(int);
    int getSize();
    
  private:
    Participant* elements[MAX_ARR];
    int   size;
};

#endif