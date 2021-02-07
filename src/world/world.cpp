#include "world.hpp"
#include "chunk.hpp"
#include "helper/includes.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"
#include "helper/typedef.hpp"


World::World(uint16_t chunks_x, uint16_t chunks_y, uint16_t chunk_size, uint8_t worldheight, uint8_t buffer_size) {
    seed = 2436346;
    noise.SetSeed(seed);

    max_x = chunks_x * chunk_size;
    max_y = chunks_y * chunk_size;

    chunkwidth = chunk_size;
    chunkheight = worldheight;

    loaded_chunks.resize(buffer_size);
    for (uint8_t i = 0; i < buffer_size; i++) { // Initially fill buffer
        loaded_chunks[i].resize(buffer_size, Chunk(chunk_size, chunk_size, worldheight, seed));
    }
} 

std::vector<std::vector<float>> World::getHeightMap(uint16_t x, uint16_t y, uint16_t scale) {
    std::vector<std::vector<float>> heights(chunkwidth, std::vector<float>(chunkwidth, 0));

    noise.SetSeed(69);
    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
    noise.SetFractalType(FastNoiseLite::FractalType_FBm);
    noise.SetFractalOctaves(12);
    noise.SetFrequency(0.001);

    for (uint16_t xw = 0; xw < chunkwidth; xw++) {
        for (uint16_t yw = 0; yw < chunkwidth; yw++) {
            heights[xw][yw] = noise.GetNoise((float) x * chunkwidth + xw, (float) y * chunkwidth + yw) * scale;
        }
    }

    return heights;
}

Chunk &World::bufferChunk(uint16_t x, uint16_t y, uint8_t buffx, uint8_t buffy) {
    loaded_chunks[buffx][buffy].fill(getHeightMap(x, y));

    return loaded_chunks[buffx][buffy];
}

void World::rotateChunks(uint8_t by, bool axis) { // Axix 1: x direction else y direction
    if (axis) {
        std::rotate(loaded_chunks.begin(), loaded_chunks.begin() + by, loaded_chunks.end());
    } else {
        for (uint8_t i = 0; i < loaded_chunks.size(); i++) {
            std::rotate(loaded_chunks[i].begin(), loaded_chunks[i].begin() + by, loaded_chunks[i].end());
        }
    }
}

void World::fillBuffer(uint16_t x, uint16_t y) {
    for (int i = 0; i < loaded_chunks.size(); i++) {
        for (int b = 0; b < loaded_chunks.size(); b++) {
            loaded_chunks[i][b] = Chunk(chunkwidth, chunkwidth, chunkheight, seed);
            bufferChunk(i + x, b + y, i, b);
        }
    }
}

void World::centerAround(uint16_t x, uint16_t y) {
    if (x != centeringx or y != centeringy) {
        fillBuffer(x, y);
        centeringx = x;
        centeringy = y;
    }
}