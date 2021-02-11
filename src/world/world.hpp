#pragma once

#include <random>
#include <vector>
#include <stdlib.h>

#include "helper/math.hpp"
#include "chunk.hpp"
#include "generation/map.hpp"
#include "generation/perlin.hpp"

// Handles chunk management and updates for chunks according to Map
class World {
    public:
        World(uint32_t _world_width, uint32_t _world_height, uint64_t _seed=0, uint8_t _buffer_size=3);

        std::vector<std::vector<Chunk>> loaded_chunks;
        uint32_t world_width, world_height;
        uint8_t buffer_size;
        Map map;

        void bufferAt(int x, int y);


    private:
        Perlin perlin;
        uint64_t seed;

        Chunk getChunk(int x, int y);
        Region &getRegion(int x, int y);
};