#include "math.hpp"

#include <math.h>
#include <random>

int randomInt(int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dist(start, end);

    return dist(gen);
}

float randomFloat(float start, float end) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(start, end);

    return dis(gen);
}

RandGenerator::RandGenerator(uint32_t seed) {
    gen = std::mt19937(seed);
}

float RandGenerator::randFloat(float start, float end) {
    std::uniform_real_distribution<float> dis(start, end);
    return dis(gen);
}

// VECTOR 2

vec2::vec2(float _x, float _y) {

    x = _x;
    y = _y;
}

vec2 vec2::operator - (vec2 const &other) {
    return vec2(x - other.x, y - other.y);
}

void vec2::rotate(float radians) {
    float nx = cos(radians) * x - sin(radians) * y;

    y = round((sin(radians) * x + cos(radians) * y) * 10000) / 10000;
    x = round(nx * 10000) / 10000;
}

// VECTOR 3

vec3::vec3(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

vec3::operator vec2() const {
    return vec2(x, y);
}