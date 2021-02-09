#pragma once

#include <stdint.h>
#include <vector>

#include "helper/typedef.hpp"
#include "helper/math.hpp"
#include "world/generation/biomes.hpp"


class Chunk {
    public:

        std::vector<std::vector<std::vector<uint16_t>>> tiles;
        std::vector<std::vector<biomes::biomes>> biomes;

        uint8_t height;
        uint16_t width, depth;

        Chunk() : generator(45747) {} 
        Chunk(uint16_t  w, uint16_t d, uint8_t h, uint32_t chunkseed);
        void fill(tdvf heightmap);
        void fillEmtpy();

        uint32_t chunk_seed;

        RandGenerator generator;

    // private:
        
};