#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Pit.h"
#include "PartArray.h"
#include "Hero.h"

Pit::Pit(const char layout[MAX_ROW+1][MAX_COL+1]){
    for (int i = 0; i < MAX_ROW + 1; i++){
        for (int j = 0; j < MAX_COL + 1; j++)
            this->layout[i][j] = layout[i][j];
    }
}

Pit::~Pit(){}

bool Pit::validPos(int row, int col){
    return (withinBounds(row, col) && layout[row][col] == ' ');
}

bool Pit::withinBounds(int row, int col){
    return !(row < 1|| col < 1 || row >= MAX_ROW - 1 || col >= MAX_COL - 1);
}

bool Pit::underLedge(Position* p){
    return (layout[p->getRow() - 1][p->getCol()] == '-');
}

void Pit::print(PartArray* part, Hero* h1, Hero* h2){
    char tempLayout[MAX_ROW+1][MAX_COL+1] = {};
    int i = 0;
    for (int i = 0; i < MAX_ROW + 1; i++){
        for (int j = 0; j < MAX_COL + 1; j++)
            tempLayout[i][j] = layout[i][j];
    }

    for (int i = 0; i < part->getSize(); i++){
        Participant* temp = part->get(i);
        if(!temp->isSafe())
            tempLayout[temp->getRow()][temp->getCol()] = temp->getAvatar();
    }

    for (; i < MAX_ROW - 1; i++)
        cout << endl << tempLayout[i];

    cout << left << setfill(' ') << setw(5) << "";
    cout << setw(6) << h1->getName() << ":";
    cout << right << setw(4) << h1->getHealth() << endl;
    
    cout << tempLayout[i];  
    cout << left << setfill(' ') << setw(5) << "";
    cout << setw(6) << h2->getName() << ":";
    cout << right << setw(4) << h2->getHealth() << endl;
}
