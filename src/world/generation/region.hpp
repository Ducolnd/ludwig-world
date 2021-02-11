#pragma once

#include "perlin.hpp"
#include "world/chunk.hpp"
#include "helper/setup.hpp"

#include <vector>

// A structure for holding some information
// Contains REGION_SIZE chunks
class Region {
    public:
        float height; // Z height
        float temperature; // Lower is colder
        float wetness; // Lower is wetter

        void generate();
        void initDetailedHeightmap();
        void initDetailedWetmap();
        void initDetailedTemperature();

        Chunk generateChunk(int x, int y);

        Region();

        std::vector<std::vector<float>> detailedHeightMap;
        std::vector<std::vector<float>> detailedWetmap;
        std::vector<std::vector<float>> detailedTemperature;
        
    private:
        Perlin perlin;
        bool generated = false; // Don't generate twice

};