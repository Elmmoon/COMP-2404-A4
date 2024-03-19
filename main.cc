/* 
Purpose: A randomized simulation of the two heroes' (Timothy and Harold) escape from the pit. 
    Both heroes spawn at the bottom of the pit and will attempt to climb up to the top.
    Snorcs (monsters represented by the char 's'), will randomly spawn.
    The movements of both the heroes and the snorcs are randomized. 
    Only snorcs may move onto ledges ('-').
    If a snorc and a hero land on the same area, the hero will take damage.
    When a hero reaches 0 health they will die.
    If a hero reaches the top, they have escaped and will be removed from the simulation.
    The simulation ends when both heroes have died or escaped.
Usage:
    Enter the project directory
    Enter 'make', then './a4' into the command line
Author: Dylan Yin
ID: 101257186
*/

#include "Escape.h"

int main(){
    Escape escape;
    escape.runEscape();
}