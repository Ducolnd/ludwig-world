#include "perlin.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"

Perlin::Perlin(int seed, float frequency, uint16_t octaves, float lacunarity, float gain) {
    noise.SetSeed(seed);
    noise.SetFrequency(frequency);
    noise.SetNoiseType(FastNoiseLite::NoiseType::NoiseType_OpenSimplex2);
    noise.SetFractalType(FastNoiseLite::FractalType::FractalType_FBm);
    noise.SetFractalOctaves(octaves);
    noise.SetFractalLacunarity(lacunarity);
    noise.SetFractalGain(gain);
}

void Perlin::setRange(float low, float high) {
    rangeLow = low;
    rangeHigh = high;
}

float Perlin::get(float x, float y) {
    return map(noise.GetNoise(x, y));
}

float Perlin::get(float x, float y, float z) {
    return map(noise.GetNoise(x, y, z));
}

float Perlin::map(float value) {
    return (value - -1) * (rangeHigh - rangeLow) / (1 - -1) + rangeLow;
}