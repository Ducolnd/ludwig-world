#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "world/world.hpp"

#include "helper/includes.hpp"
#include "helper/typedef.hpp"
#include "helper/math.hpp"
#include "systems/systemManager.hpp"
#include "../FastNoiseLite/FastNoiseLite.h"

template <typename T>
void print(T what) {
    std::cout << what << std::endl;
}

int main() {
    SystemManager sys;
    sys.start();

    return 0;
}