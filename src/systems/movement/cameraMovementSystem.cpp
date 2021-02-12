#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "systems/render/levelManager.hpp"

#include "cameraMovementSystem.hpp"

#include "components/general/cameraComponent.hpp"
#include "components/player/controllerComponent.hpp"
#include "components/render/isRenderedComponent.hpp"


void CameraMovementSystem(entt::registry &registry, float dt) {
    auto view = registry.view<controllerComponent, cameraComponent>();

    for (auto& ent : view) {
        auto& camera = registry.get<cameraComponent>(ent);

        // Horizontal movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            camera.cameraLocation.x -= 5 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            camera.cameraLocation.y -= 5 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            camera.cameraLocation.y += 5 * dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            camera.cameraLocation.x += 5 * dt;
        }

        // Vertical movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::PageUp)) {
            camera.cameraLocation.z += 4 * dt;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::PageDown)) {
            camera.cameraLocation.z -= 4 * dt;
        }
    }
}

void CameraLocationUpdateSystem(entt::registry &registry, World &world, sf::Text text, LevelManager &lvm, sf::RenderWindow &window) {
    auto view = registry.view<cameraComponent>();

    for (auto& ent : view) {
        auto& camera = registry.get<cameraComponent>(ent);

        world.bufferAt(
            static_cast<int>(camera.cameraLocation.x / CHUNK_SIZE),
            static_cast<int>(camera.cameraLocation.y / CHUNK_SIZE)
        );       

        lvm.topLeft = vec2(
            static_cast<int>(camera.cameraLocation.x),
            static_cast<int>(camera.cameraLocation.y)
        );

        lvm.currentHeight = static_cast<int>(camera.cameraLocation.z); 

        text.setString(std::to_string(camera.cameraLocation.z));
        window.draw(text); 
    }
}