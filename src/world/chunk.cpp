#include "chunk.hpp"
#include "helper/math.hpp"

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
            tiles[i][b].resize(32, 0);
        }
    }
    

    for (uint8_t i = 0; i < 32; i++) {
        for (uint16_t b = 0; b < 32; b++) {
            float chance = randomFloat(0, 1);

            if (chance > 0.95) {
                tiles[25][i][b] = 5;
            } else if (chance > 0.92) {
                tiles[25][i][b] = 6;
            } else if (chance > 0.7) {
                tiles[25][i][b] = (int) randomFloat(1, 5);
            } else {
                tiles[25][i][b] = 0;
            }
        }
    }
}