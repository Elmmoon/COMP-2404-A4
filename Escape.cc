#include <iostream>
using namespace std;
#include <string>

#include "Escape.h"
#include "Snorc.h"
#include "defs.h"

Escape::Escape() : numSnorcs(0){
  srand((unsigned)time(NULL));

  int rand = random(10) + 7;
  h1 = new Hero('T', MAX_ROW - 2, rand, "Timmy");
  while (rand == h1->getCol())
    rand = random(10) + 7;
  h2 = new Hero('H', MAX_ROW - 2, rand, "Harold");
  arr.add(h1);
  arr.add(h2);

  const char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "-             --        -",
      "-                      --",
      "-       --              -",
      "                  --    -",
      "--       -              -",
      "---                    --",
      "---       --          ---",
      "--                     --",
      "-            --        --",
      "---               --     ",
      "--        --    ---    --",
      "--  --                  -",
      "--        --       -     ",
      "--                  -    ",
      "--     --         --    -",
      "---                    --",
      "--       ---    --      -",
      "--                     --",
      "-------------------------"
  };
  pit = new Pit(templateGrid);
}

Escape::~Escape(){ 
  delete pit;
}

void Escape::runEscape(){ 
  while (!isOver()){
    if (random(100) < SNORC_SPAWN)
      spawnSnorc();
    moveParticipants();
    pit->print(&arr, h1, h2);
    usleep(300000); 
  }
  pit->print(&arr, h1, h2);
  printOutcome();
}

void Escape::spawnSnorc(){ 
  if (numSnorcs >= MAX_SNORCS)
    return;
  arr.add(new Snorc(MAX_ROW - random(5) - 2, random(MAX_COL - 2) + 1, random(3) + 2));
  numSnorcs++;
}

void Escape::moveParticipants(){ 
  for (int i = 0; i < arr.getSize(); i++){
    arr.get(i)->move(pit);
    Participant* collision = checkForCollision(arr.get(i));
    if (collision){
      collision->incurDamage(arr.get(i));
      arr.get(i)->incurDamage(collision);
    }
  }
}

Participant* Escape::checkForCollision(Participant* p){ 
  for (int i = 0; i < arr.getSize(); i++){
    if (p->collide(arr.get(i)) && p != arr.get(i))
      return arr.get(i);
  }
  return NULL;
}

bool Escape::isOver() const{ 
  return ((h1->isDead()|| h1->isSafe()) && (h2->isDead()|| h2->isSafe()));
}

void Escape::printOutcome() const{
  if (h1->isDead()){
    if (h2->isDead())
      cout << "Both heroes have died..." << endl;
    else  
      cout << h2->getName() << " escapes, but " << h1->getName() << " dies..."<< endl;
  }
  else {
    if (h2->isDead())
      cout << h1->getName() << " escapes, but " << h2->getName() << " dies..."<< endl;
    else
      cout << "BOTH HEROES ESCAPED !!!" << endl;
  }
}


