/*Class representing the position of the given parrticipant in the pit*/

#ifndef POSITION_H
#define POSITION_H

class Position{
  public:
    Position(int = 0, int = 0);
    ~Position();
    bool equals(Position*) const;
    void set(int, int);
    int getRow() const;
    int getCol() const;
  private:
    int row;
    int col;
};

#endif
