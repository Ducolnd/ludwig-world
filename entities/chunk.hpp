#pragma once

#include <vector>

// #include "tile.hpp"

class Tile;
class Entity;

class Chunk {
    public:
        std::vector<std::vector<Tile>> tiles;
        std::vector<Player*> player_need_update;
        std::vector<Enemy*> needs_update;

        Chunk();
        void init(int n, int a);
        void updateChunk();

        private:
        void fillChunk(int itm, int enm);
};