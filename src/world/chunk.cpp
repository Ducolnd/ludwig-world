#include "chunk.hpp"

#include <algorithm>
#include <random>
#include <vector>

Chunk::Chunk(uint32_t seed, uint16_t w, uint16_t d, uint8_t h) {
    chunk_seed = seed;

    width = w;
    depth = d;
    height = h;
}

void Chunk::fill() {
    tiles.resize(64);
    for (uint8_t i = 0; i < 32; i++) {
        tiles[i].resize(32);

        for (uint16_t b = 0; b < 32; b++) {
            tiles[i][b].resize(32, 1);
        }
    }
    tiles[25][10][10] = 1;
}