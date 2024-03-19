/*Collections class that holds all the participants of the escape*/
#ifndef PARTARRAY_H
#define PARTARRAY_H

#include "defs.h"
#include "Participant.h"

class PartArray{
  public:
    PartArray();
    ~PartArray();
    void add(Participant*);
    Participant* get(int) const;
    int getSize() const;
    
  private:
    Participant* elements[MAX_ARR];
    int   size;
};

#endif