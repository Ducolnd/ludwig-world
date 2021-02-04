#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "inputSystem.hpp"

#include "components/movement/locationComponent.hpp"
#include "components/player/controllerComponent.hpp"


void InputSystem(entt::registry &registry, float dt) {
    auto view = registry.view<controllerComponent, locationComponent>();

    for (auto& ent : view) {
        auto& location = registry.get<locationComponent>(ent);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            location.vec.x -= 6 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            location.vec.y -= 6 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            location.vec.y += 6 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            location.vec.x += 6 * dt;
        }
        
    }
}