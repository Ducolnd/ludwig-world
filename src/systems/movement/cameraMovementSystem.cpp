#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "systems/render/levelManager.hpp"

#include "cameraMovementSystem.hpp"

#include "components/general/cameraComponent.hpp"
#include "components/player/controllerComponent.hpp"
#include "components/render/isRenderedComponent.hpp"


void CameraMovementSystem(entt::registry &registry, World &world, float dt, sf::RenderWindow &window, sf::Text text, LevelManager &lvm) {
    auto view = registry.view<controllerComponent, cameraComponent>();

    for (auto& ent : view) {
        auto& camera = registry.get<cameraComponent>(ent);

        // Horizontal movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            camera.cameraLocation.x -= 20 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            camera.cameraLocation.y -= 20 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            camera.cameraLocation.y += 20 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            camera.cameraLocation.x += 20 * dt;
        }

        // Vertical movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            camera.cameraLocation.z += 4 * dt;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            camera.cameraLocation.z -= 4 * dt;
        }       

        lvm.currentHeight = static_cast<int>(camera.cameraLocation.z); 

        text.setString(std::to_string(camera.cameraLocation.z));
        window.draw(text);      
    }
}