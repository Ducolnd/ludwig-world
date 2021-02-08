#pragma once

#include <stdint.h>
#include <vector>

// A structure for holding some information on that specific location
// Not a chunk or a real game square 
struct Tile {
    float height; // Z height
    float temperature; // Lower is colder
    float wetness;

    Tile *left, *top, *right, *bottom = nullptr;
};

// The Map is what stores all biome, weather, season, temerature data
// Chunks will be constructed from this data
class Map {
    public:
        Map(uint32_t map_width, uint32_t map_height);
        void initHeightmap();
        void initHeatmap();

        uint32_t width; // Size of map
        uint32_t height;

        std::vector<std::vector<Tile>> tiles;
};