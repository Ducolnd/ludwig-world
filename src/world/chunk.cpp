#include "chunk.hpp"
#include "helper/math.hpp"
#include "helper/textures.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

Chunk::Chunk(uint32_t seed, uint16_t w, uint16_t d, uint8_t h) {
    chunk_seed = seed;

    width = w;
    depth = d;
    height = h;
}

void Chunk::fill() {
    tiles.resize(height);

    for (uint8_t i = 0; i < height; i++) {
        tiles[i].resize(width);

        for (uint16_t b = 0; b < width; b++) {
            tiles[i][b].resize(depth, 0);
        }
    }
    
    for (uint16_t i = 0; i < width; i++) {
        for (uint16_t b = 0; b < depth; b++) {
            float chance = randomFloat(0, 1);
            if (chance > 0.85) {
                tiles[25][i][b] = textures::blocks::grass;
            } 
        }
    }
}