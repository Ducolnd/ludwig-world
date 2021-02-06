#include "world.hpp"
#include "chunk.hpp"
#include "helper/includes.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"
#include "helper/typedef.hpp"


World::World(uint16_t chunks_x, uint16_t chunks_y, uint16_t chunk_size, uint8_t worldheight, uint8_t buffer_size) {
    noise.SetSeed(rd());

    max_x = chunks_x * chunk_size;
    max_y = chunks_y * chunk_size;

    chunkwidth = chunk_size;
    chunkheight = worldheight;

    loaded_chunks.resize(buffer_size);
    for (uint8_t i = 0; i < buffer_size; i++) { // Initially fill buffer
        loaded_chunks[i].resize(buffer_size, Chunk(chunk_size, chunk_size, worldheight));
    }
} 

std::vector<std::vector<float>> World::getHeightMap(uint16_t x, uint16_t y, uint16_t scale) {
    std::vector<std::vector<float>> heights(chunkwidth, std::vector<float>(chunkwidth, 0));

    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
    noise.SetFractalType(FastNoiseLite::FractalType_FBm);
    noise.SetFractalOctaves(8);
    noise.SetFrequency(0.010);

    for (uint16_t xw = 0; xw < chunkwidth; xw++) {
        for (uint16_t yw = 0; yw < chunkwidth; yw++) {
            heights[xw][yw] = noise.GetNoise((float) x * chunkwidth + xw, (float) y * chunkwidth + yw) * scale;
        }
    }

    return heights;
}

Chunk &World::bufferChunk(uint16_t x, uint16_t y) {
    loaded_chunks[x][y].fill(getHeightMap(x, y));

    return loaded_chunks[x][y];
}