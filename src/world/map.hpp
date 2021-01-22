#pragma once

#include "chunk.hpp"

class Player;

class Map {
    public:
        std::vector<std::vector<Chunk>> chunks;

        Map ();
        void placePlayer(Player *player, int x, int y);
        void placePlayer(Player *player);
        void updateChunks();
        Tile * get_tile(int x, int y);

};