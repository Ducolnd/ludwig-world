#include "helper/sprites.hpp"
#include "helper/textures.hpp"
#include "helper/math.hpp"
#include "helper/includeComponents.hpp"

#include "systems/systemManager.hpp"
#include "systems/render/renderSystem.hpp"
#include "systems/movement/transformSystem.hpp"
#include "systems/movement/inputSystem.hpp"
#include "systems/pvp/seekEntitySystem.hpp"
#include "systems/render/renderWorld.hpp"
#include "systems/movement/cameraMovementSystem.hpp"

#include "world/generation/map.hpp"

#include <math.h>
#include <iostream>

void SystemManager::start() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 800), "Ludwig World", sf::Style::Default);

    loadAllTextures(txm); // Load all textures needed

    entt::entity entity = registry.create();
    registry.emplace<locationComponent>(entity, vec2(0,0));
    registry.emplace<controllerComponent>(entity);
    registry.emplace<isRenderedComponent>(entity, textures::entities::player);

    update(window);
}

void SystemManager::update(sf::RenderWindow& window) {

    // entt::entity camera = registry.create();
    // registry.emplace<controllerComponent>(camera);
    // registry.emplace<cameraComponent>(camera, vec3(0, 0, 20));

    Map map(800, 800);
    map.initTiles();

    sf::Clock clock;   

    // World world(5, 5);
    // world.fillBuffer(0,0);
    
    while (window.isOpen()) {
        sf::Time dt;
        dt = clock.restart();


        sf::Event Event{};
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));

        RenderGameMap(window, map, 1);

        // CameraMovementSystem(registry, world, dt.asSeconds());
        // renderWorld(world, window, txm, registry, camera); 

        
        // // Update systems
        // // SeekEntitySystem(registry, dt.asSeconds());
        // InputSystem(registry, dt.asSeconds());
        // // TransformSystem(registry, dt.asSeconds());

        // // Render systems
        // RenderSystem(registry, window, txm);
        
        

        window.display();

    }
}