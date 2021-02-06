#include "chunk.hpp"
#include "helper/math.hpp"
#include "helper/textures.hpp"
#include "helper/includes.hpp"
#include "helper/typedef.hpp"

Chunk::Chunk(uint16_t w, uint16_t d, uint8_t h) {
    width = w;
    depth = d;
    height = h;
}

void Chunk::fill(tdvf heightmap) {
    tiles.resize(height);

    for (uint8_t i = 0; i < height; i++) {
        tiles[i].resize(width);

        for (uint16_t b = 0; b < width; b++) {
            tiles[i][b].resize(depth, 0);
        }
    }
    
    for (uint16_t x = 0; x < width; x++) {
        for (uint16_t y = 0; y < depth; y++) {
            if (heightmap[(int) x][(int) y] > -5) {
                tiles[heightmap[(int) x][(int) y] + 20][x][y] = textures::blocks::grass;
            }
        }
    }
}

void Chunk::fillEmtpy() {
    tiles.resize(height);

    for (uint8_t i = 0; i < height; i++) {
        tiles[i].resize(width);

        for (uint16_t b = 0; b < width; b++) {
            tiles[i][b].resize(depth, 0);
        }
    }
}