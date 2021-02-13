#pragma once

#include <random>
#include <vector>
#include <stdlib.h>

#include "helper/math/math.hpp"
#include "chunk.hpp"
#include "generation/map.hpp"
#include "generation/perlin.hpp"

// Handles chunk management and updates for chunks according to Map
class World {
    public:
        World(uint32_t _world_width, uint32_t _world_height, uint64_t _seed=69, uint8_t _buffer_size=3);

        std::vector<std::vector<Chunk>> loaded_chunks;
        uint32_t world_width, world_height;
        uint8_t buffer_size;
        Map map;

        int loaded_chunk_x, loaded_chunk_y = 0;

        // Will buffer top left at given coordinates
        void bufferAt(int chunk_x, int chunk_y);
        Chunk &getChunk(int x, int y);


    private:
        Perlin perlin;
        uint64_t seed;

        void fillBuffer(int startx, int starty);

        Chunk generateChunk(int chunk_x, int chunk_y);
        Region &getRegion(int x, int y);
};