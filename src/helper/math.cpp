#include "math.hpp"

#include <math.h>
#include <random>

int randomInt(float start, float end) {
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

vec2::vec2(float _x, float _y) {
    x = _x;
    y = _y;
}

void vec2::rotate(float radians) {
    float nx = cos(radians) * x - sin(radians) * y;

    y = round((sin(radians) * x + cos(radians) * y) * 10000) / 10000;
    x = round(nx * 10000) / 10000;
}