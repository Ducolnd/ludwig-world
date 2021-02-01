#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "helper/includes.hpp"
#include "systems/systemManager.hpp"

int main() {
    SystemManager sys;
    sys.start();
    
    return 0;
}