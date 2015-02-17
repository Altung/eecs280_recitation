/*
To compile: g++ demo3_classes.cpp pacman.cpp -o demo
To run:     ./demo
*/

#include <iostream>
#include <string>
#include "pacman.h"

using namespace std;


int main(int argc, char **argv) {
    Pacman p(50, 50, "Yellow", 3);

    for(int i = 0; i != 5; i++) {
        p.eat_pellet();
    }

    // p.score += 10;   <-------- this would fail; Pacman::score is private

    cout << "Score: " << p.get_score() << endl;

    p.die();

    return 0;
}
