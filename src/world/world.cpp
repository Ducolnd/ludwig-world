#include "world.hpp"
#include "chunk.hpp"
#include "helper/includes.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"
#include "helper/typedef.hpp"


World::World(uint32_t _world_width, uint32_t _world_height, uint64_t _seed, uint8_t _buffer_size) : map(_world_width, _world_height) {
    world_height = _world_height;
    world_width = _world_width;

    buffer_size = _buffer_size;
    seed = (!_seed) ? randomInt(0, 3463367) : _seed; // If not set, we set it random

    map.setSeed(seed);
    map.generate();

    loaded_chunks.resize(buffer_size);
    for (int i = 0; i < buffer_size; i++) {
        loaded_chunks[i].resize(buffer_size);
    }
}

void World::bufferAt(int chunk_x, int chunk_y) {
    getRegion(chunk_y, chunk_y).generate();

    for (int i = 0; i < buffer_size; i++) {
        for (int b = 0; b < buffer_size; b++) {
            loaded_chunks[i][b] = getChunk(chunk_x + i, chunk_y + b);
        }
    }
}

Chunk World::getChunk(int chunk_x, int chunk_y) {
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