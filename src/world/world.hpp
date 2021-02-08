#pragma once

#include <random>
#include <vector>
#include <stdlib.h>

#include "helper/math.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"
#include "chunk.hpp"

class World {
    public:
        World(uint16_t chunks_x, uint16_t chunks_y, uint16_t chunk_size=16, uint8_t worldheight=64, uint8_t buffer_size=3);

        Chunk &bufferChunk(uint16_t x, uint16_t y, uint8_t buffx, uint8_t buffy);
        void rotateChunks(uint8_t by, bool axis);
        void centerAround(uint16_t x, uint16_t y);
        void fillBuffer(uint16_t x, uint16_t y);
        void unloadChunk(uint8_t x, uint8_t y); // In loaded chunks

        Chunk& getChunk(uint16_t x, uint16_t y);

        std::vector<std::vector<Chunk>> loaded_chunks;

        uint32_t chunkwidth;
        uint8_t chunkheight;


    private:
        uint32_t seed;
        uint16_t centeringx, centeringy;
        uint16_t max_x, max_y;
        uint8_t buffer_size;
        std::random_device rd;  // Will be used to obtain a seed for the random number engine

        FastNoiseLite noise;

        std::vector<std::vector<float>> getHeightMap(uint16_t x, uint16_t y, uint16_t scale = 16);

};