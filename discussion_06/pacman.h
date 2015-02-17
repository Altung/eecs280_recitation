#ifndef PACMAN_H
#define PACMAN_H

#include <string>


class Pacman {
    public:
        // Constructors to create a Pacman
        Pacman();
        Pacman(int _x, int _y, std::string _color, unsigned int _lives);

        // Public methods: anyone can call these
        void eat_pellet();
        void die();

        // const function means we can't change any data members in here
        unsigned int get_score() const;

    private:
        // Private data: only we can access this
        int x, y;
        const std::string color;
        unsigned int lives;
        unsigned int score;

};


#endif
