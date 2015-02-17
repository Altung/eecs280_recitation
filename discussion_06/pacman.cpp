#include "pacman.h"
#include <iostream>
#include <string>

using namespace std;


Pacman::Pacman() : color("Yellow") {
    // This works, but we can do better with an initialization list. Color had
    // to be in initialization list because it's defined as a const
    x = 0;
    y = 0;
    lives = 3;
    score = 0;
}

Pacman::Pacman(int _x, int _y, string _color, unsigned int _lives) :
        x(_x), y(_y), color(_color), lives(_lives), score(0) {
    // Initialization list did everything for us
}

void Pacman::eat_pellet() {
    // We can access the score of this Pacman because we're within a function
    // owned by the Pacman class
    score += 10;
    cout << "WAKKA" << endl;
}

void Pacman::die() {
    cout << "ERERERER WOP WOP" << endl;
}

unsigned int Pacman::get_score() const {
    // Standard getter function. Notice that we don't change any data members
    // of this object (it's a const function)
    return score;
}
