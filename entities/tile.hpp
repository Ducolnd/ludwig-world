#pragma once

#include <vector>

#include "types.hpp"
#include "entities.hpp"

class Tile {
    public:
        Tiletype type;
        int height_above_ground;

        std::vector<Player*> players;
        std::vector<Enemy*> enemies;

        Tile (Tiletype tiletype);

        void place(Enemy &enemy);
        void place(Player &player);
        void removeEntity(Player &player);
        void removeEntity(Enemy &enemy);
};