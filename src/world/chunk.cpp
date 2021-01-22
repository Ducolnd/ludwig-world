#include "../includes.hpp"

// Chunk class

Chunk::Chunk() {
    tiles.resize(CHUNKSIZE, std::vector<Tile>(CHUNKSIZE, Tile(Tiletype::empty)));
}

void Chunk::init(int n, int a) {
    fillChunk(n, a);
}

void Chunk::fillChunk(int itm, int enm) {
    int enemy_count = 0;

    // Engine for generator numbers between 0 and CHUNKSIZE - 1
    std::random_device rseed;
    std::mt19937 engine(rseed());
    std::uniform_int_distribution<int> dist(0,CHUNKSIZE - 1);


    for (int x = 0; x <= CHUNKSIZE - 1; x++ ) {
        for (int y = 0; y <= CHUNKSIZE - 1; y++) {
            Tile tile(Tiletype::empty);
            tiles[x].push_back(tile);
        }
    }
}

