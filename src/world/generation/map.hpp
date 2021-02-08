#pragma once

#include <stdint.h>
#include <vector>

// A structure for holding some information on that specific location
// Not a chunk or a real game square 
struct Tile {
    float height; // Z height

    Tile() {}
    Tile(float _height);
};

// The Map is what stores all biome, weather, season, temerature data
// Chunks will be constructed from this data
class Map {
    public:
        Map(uint32_t map_width, uint32_t map_height);
        void initTiles();

        uint32_t width; // Size of map
        uint32_t height;

        std::vector<std::vector<Tile>> tiles;
};