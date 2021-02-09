#pragma once

#include <stdint.h>
#include <vector>

#include "region.hpp"


// The Map is what stores all biome, weather, season, temerature data and regions
class Map {
    public:
        Map(uint32_t map_width, uint32_t map_height);

        void setSeed(uint64_t _seed);

        void generate();
        void initHeightmap();
        void initHeatmap();
        void initWetmap();

        uint32_t width; // Size of map in regions
        uint32_t height;

        std::vector<std::vector<Region>> regions;

    private:
        uint64_t seed = 69; // Default seed
};