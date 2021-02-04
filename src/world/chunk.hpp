#pragma once

#include <stdint.h>
#include <vector>

// enum Biome {
//     rainForest,
//     thickForet,
//     dutchForest,
//     taigaForest,
//     beach,
//     lavaLands,
//     riverLands,
//     swamp,

//     end
// };

class Chunk {
    public:

        std::vector<std::vector<std::vector<uint16_t>>> tiles;

        uint8_t height;
        uint16_t width, depth;

        Chunk(uint32_t seed, uint16_t  w, uint16_t d, uint8_t h);
        void fill();

        uint64_t chunk_seed;
};