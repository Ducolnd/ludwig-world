#include "world.hpp"
#include "chunk.hpp"
#include "helper/includes.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"
#include "helper/typedef.hpp"


World::World(uint32_t _world_width, uint32_t _world_height, uint64_t _seed, uint8_t _buffer_size) : map(_world_width, _world_height, _seed) {
    world_height = _world_height;
    world_width = _world_width;

    buffer_size = _buffer_size;
    seed = _seed; // If not set, we set it random

    map.generate();

    loaded_chunks.resize(buffer_size);
    for (int i = 0; i < buffer_size; i++) {
        loaded_chunks[i].resize(buffer_size);
    }
}

void World::bufferAt(int chunk_x, int chunk_y) {
    if (chunk_x != loaded_chunk_x | chunk_y != loaded_chunk_y) { // If it is not already loaded
        loaded_chunk_x = chunk_x;
        loaded_chunk_y = chunk_y;
        
        getRegion(chunk_y, chunk_y).generate();

        if (chunk_x >= 1 && chunk_y >= 1) {
            fillBuffer(chunk_x - 1, chunk_y - 1);
        } else if (chunk_x == 0 && chunk_y >=1) {
            fillBuffer(0, chunk_y -1);
        } else if (chunk_x >= 1 && chunk_y == 0) {
            fillBuffer(chunk_x - 1, 0);
        } else {
            fillBuffer(0, 0);
        }
    }
}

void World::fillBuffer(int startx, int starty) {
    for (int i = 0; i < buffer_size; i++) {
        for (int b = 0; b < buffer_size; b++) {
            loaded_chunks[i][b] = generateChunk(startx + i, starty + b);
        }
    }
}

Chunk &World::getChunk(int x, int y) {
    return loaded_chunks
        [(x / CHUNK_SIZE) - loaded_chunk_x]
        [(y / CHUNK_SIZE) - loaded_chunk_y];
}

Chunk World::generateChunk(int chunk_x, int chunk_y) {
    return getRegion(chunk_x, chunk_y).generateChunk(
        chunk_x % REGION_SIZE, 
        chunk_y % REGION_SIZE
    );
}

Region &World::getRegion(int chunk_x, int chunk_y) {
    if ((!chunk_x) > 0) { // Clamp value not lower than 1
        chunk_x = 1;
    }

    if ((!chunk_y) > 0) { // Clamp value not lower than 1
        chunk_y = 1;
    }

    return map.regions
        [std::floor(REGION_SIZE / chunk_x)]
        [std::floor(REGION_SIZE / chunk_y)];
}