#pragma once

#include <stdint.h>

#include "../FastNoiseLite/FastNoiseLite.h"

class Perlin {
    public:
        Perlin(uint64_t seed = 32467, float frequency = 0.01, uint16_t octaves = 8, float lacunarity = 2.0, float gain = 0.5);
        float get(float x, float y);
        float get(float x, float y, float z);

        FastNoiseLite noise;
};