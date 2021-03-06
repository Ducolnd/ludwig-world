#include "helper/includes.hpp"
#include "region.hpp"

Region::Region(uint64_t _seed) {
    seed = _seed;
}

Chunk Region::generateChunk(int chunk_x, int chunk_y) {
    Chunk chunk(CHUNK_SIZE, CHUNK_SIZE, WORLD_HEIGHT, 3466);

    std::vector<std::vector<float>> heights(CHUNK_SIZE, std::vector<float>(CHUNK_SIZE, height ));

    chunk.fill(heights);

    return chunk;
}

void Region::generate() {
    if (!generated) {
        initDetailedHeightmap();
        // initDetailedTemperature();
        // initDetailedWetmap();

        generated = true;
    }
}

void Region::initDetailedHeightmap() {
    Perlin heightMap(randomInt(0, seed));

    detailedHeightMap.resize(REGION_SIZE);
    for (int i = 0; i < REGION_SIZE; i++) {
        detailedHeightMap[i].resize(REGION_SIZE);
    }

    for (uint32_t x = 0; x < REGION_SIZE; x++) {
        for (uint32_t y = 0; y < REGION_SIZE; y++) {
            detailedHeightMap[x][y] = height + heightMap.get(x, y) / 2;
        }
    }
}

void Region::initDetailedWetmap() {
    Perlin wetMap();
}

void Region::initDetailedTemperature() {
    Perlin tempMap();
}