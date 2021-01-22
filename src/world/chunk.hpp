#pragma once

#include <vector>

// #include "tile.hpp"

class Tile;
class Entity;

class Chunk {
    public:
        std::vector<std::vector<Tile>> tiles;

        Chunk();
        void init(int n, int a);

        private:
        void fillChunk(int itm, int enm);
};