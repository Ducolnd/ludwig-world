#include "chunk.hpp"
#include "helper/math.hpp"
#include "helper/blocks.hpp"
#include "helper/includes.hpp"
#include "helper/typedef.hpp"

Chunk::Chunk(uint16_t w, uint16_t d, uint8_t h, uint32_t chunkseed) : generator(d) {
    width = w; 
    depth = d;
    height = h;
}

void Chunk::fill(std::vector<std::vector<float>> heightmap) {
    tiles.resize(height);

    for (uint8_t i = 0; i < height; i++) {
        tiles[i].resize(width);

        for (uint16_t b = 0; b < width; b++) {
            tiles[i][b].resize(depth, 0);
        }
    }
    
    for (uint16_t x = 0; x < width; x++) {
        for (uint16_t y = 0; y < depth; y++) {

            uint8_t grass_height = heightmap[(int) x][(int) y] * 20 + 25;
            uint8_t dirt_height = grass_height - generator.randFloat(1, 4);
            uint8_t stone_height = dirt_height;

            uint8_t z = 0;
            while (z < stone_height) {
                tiles[z][x][y] = blocks::blocks::stone;
                z++;
            }

            z = dirt_height;
            while (z < grass_height) {
                tiles[z][x][y] = blocks::blocks::dirt;
                z++;
            }

            tiles[grass_height][x][y] = blocks::blocks::grass;
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