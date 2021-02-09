#include "helper/includes.hpp"
#include "world/generation/perlin.hpp"
#include "map.hpp"
#include "region.hpp"

Map::Map(uint32_t map_width, uint32_t map_heigth) {
    width = map_width;
    height = map_heigth;

    regions.resize(width);
    for (int i = 0; i < width; i++) {
        regions[i].resize(height, Region());
    }
}

void Map::setSeed(uint64_t _seed) {
    seed = _seed;
}

void Map::generate() {
    initHeightmap();
    initHeatmap();
    initWetmap();
}

void Map::initHeightmap() {
    Perlin heightMap(seed, 0.006, 6);
    
    for (uint32_t x = 0; x < width; x++) {
        float distFromXCenter = abs(width / 2 - x);

        for (uint32_t y = 0; y < height; y++) {
            float distFromYCenter = abs(height / 2 - y);

            regions[x][y].height = (
                heightMap.get(x, y) 
                * (1 - std::pow(distFromYCenter / (height / 2), 4)) // No land close to edges
                * (1 - std::pow(distFromXCenter / (width / 2), 4))
            );
        }
    }
}

void Map::initHeatmap() {
    std::vector<float> heatY(height);
    std::vector<std::vector<float>> heatMap(width);

    Perlin heatNoiseMap(seed);

    for (uint32_t y = 0; y < height; y++) {
        // heatY[y] = 1 - (abs(static_cast<float>(height) / 2 - y) / (static_cast<float>(height) / 2)); // Linear alternative
        heatY[y] = -1 * (1 - (pow(((float) height / 2 - abs((float) height / 2 - y)) / ((float) height / 2), 1.78))) + 1;
    }

    for (uint32_t x = 0; x < width; x++) {
        heatMap[x] = heatY;
    }

    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {
            float cTileHeight = regions[x][y].height;

            regions[x][y].temperature = (
                ((heatMap[x][y] * 3 
                + heatNoiseMap.get(x, y)) / 4) // Add some noise
            );

            if (cTileHeight > 0.4) {
                regions[x][y].temperature -= 0.3 * cTileHeight;
            } else if (cTileHeight > 0.6) {
                regions[x][y].temperature -= 0.5 * cTileHeight;
            } else if (cTileHeight > 0.8) {
                regions[x][y].temperature -= 0.6 * cTileHeight;
            }
            
        }
    }
}

void Map::initWetmap() {
    std::vector<std::vector<float>> wetMap(width);
    for (auto i : wetMap) i.resize(height);

    Perlin wetNoiseMap(seed, 0.02);

    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            regions[x][y].wetness = wetNoiseMap.get(x, y);
        }
    }
}