#include "helper/includes.hpp"
#include "region.hpp"

Region::Region() {
}

Chunk Region::generateChunk(int x, int y) {
    return Chunk(CHUNK_SIZE, CHUNK_SIZE, WORLD_HEIGHT, 3466);
}

void Region::generate() {
    initDetailedHeightmap();
    // initDetailedTemperature();
    // initDetailedWetmap();
}

void Region::initDetailedHeightmap() {
    Perlin heightMap;

    for (uint32_t x = 0; x < REGION_SIZE; x++) {
        for (uint32_t y = 0; y < REGION_SIZE; y++) {
            detailedHeightMap[x][y] = height + heightMap.get(x, y) / 2;
        }
    }
}

void Region::initDetailedWetmap() {
    Perlin detailedMap();
}

void Region::initDetailedTemperature() {
    Perlin tempMap();
}