#include "world.hpp"
#include "chunk.hpp"

#include <random>

World::World(uint16_t chunks_x, uint16_t chunks_y, uint16_t chunk_size, uint8_t worldheight, uint8_t buffer_size) {
    max_x = chunks_x * chunk_size;
    max_y = chunks_y * chunk_size;

    chunkwidth = chunk_size;
    chunkheight = worldheight;

    loaded_chunks.resize(3);
    for (uint8_t i = 0; i < buffer_size; i++) {
        loaded_chunks[i].resize(3, Chunk(346, 64, 32, 32));
    }
}

Chunk &World::bufferChunk(uint16_t x, uint16_t y) {
    loaded_chunks[1][1].fill();

    return loaded_chunks[1][1];
}

float World::randomNum(float start, float end, uint32_t seed) {
    std::mt19937 gen(seed); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dist(start, end);

    return dist(gen);
}

int World::randomNum(int start, int end, uint32_t seed) {
    std::mt19937 gen(seed); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dist(start, end);

    return dist(gen);
}