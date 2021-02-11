#pragma once

#include <stdint.h>

#include "../FastNoiseLite/FastNoiseLite.h"

class Perlin {
    public:
        Perlin(int seed = 32467, float frequency = 0.01f, uint16_t octaves = 8, float lacunarity = 2.0, float gain = 0.5);
        void setRange(float low, float high);
        float get(float x, float y);
        float get(float x, float y, float z);

        FastNoiseLite noise;

    private:
        float rangeLow = 0;
        float rangeHigh = 1;

        float map(float value);
};