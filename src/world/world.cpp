#include "world.hpp"

#include <random>

World::World() {

}

float World::randomNum(float start, float end) {
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<double> dist(start, end);

    return dist(gen);
}

int World::randomNum(int start, int end) {
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dist(start, end);

    return dist(gen);
}