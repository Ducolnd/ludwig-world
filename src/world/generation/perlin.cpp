#include "perlin.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"

Perlin::Perlin(uint64_t seed, float frequency, uint16_t octaves, float lacunarity, float gain) {
    noise.SetSeed(seed);
    noise.SetFrequency(frequency);
    noise.SetNoiseType(FastNoiseLite::NoiseType::NoiseType_OpenSimplex2);
    noise.SetFractalType(FastNoiseLite::FractalType::FractalType_FBm);
    noise.SetFractalOctaves(octaves);
    noise.SetFractalLacunarity(lacunarity);
    noise.SetFractalGain(gain);
}

float Perlin::get(float x, float y) {
    return (noise.GetNoise(x, y) + 1) / 2;
}

float Perlin::get(float x, float y, float z) {
    return (noise.GetNoise(x, y, z) + 1) / 2;
}