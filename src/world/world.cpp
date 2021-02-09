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
    for (auto i : loaded_chunks) i.resize(buffer_size);
}

void World::bufferAt(int x, int y) {
    for (int i = 0; i < buffer_size; i++) {
        for (int b = 0; b < buffer_size; b++) {
            loaded_chunks[i][b] = getChunk(x + i, y + b);
        }
    }
}

Chunk World::getChunk(int x, int y) {
    return getRegion(x, y).generateChunk(x % REGION_SIZE, y % REGION_SIZE);
}

Region &World::getRegion(int x, int y) {
    return map.regions
        [std::floor(REGION_SIZE / (std::floor(x / CHUNK_SIZE)))]
        [std::floor(REGION_SIZE / (std::floor(y / CHUNK_SIZE)))];
}