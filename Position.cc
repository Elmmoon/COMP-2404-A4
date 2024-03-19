#include <iostream>
using namespace std;
#include <string>
#include "Position.h"

Position::Position(int r, int c)
    :row(r), col(c){}

Position::~Position(){}

bool Position::equals(Position* p){
    return (p->row == row && p->col == col);
}

void Position::set(int row, int col){
    this->row = row;
    this->col = col;
}
int Position::getRow(){
    return row;
}

int Position::getCol(){
    return col;
}