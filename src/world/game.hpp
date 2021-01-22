#pragma once

// Container for entire game
// Allows entities to move up the hierarchy tree

#include "map.hpp"

class Game {
    public:
        Map map;

        Game();
        void displayMap();
        void notifyChanged(Player *entity);
};