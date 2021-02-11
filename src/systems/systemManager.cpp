#include "helper/blocks.hpp"
#include "helper/math.hpp"
#include "helper/includeComponents.hpp"
#include "helper/font.hpp"

#include "systems/systemManager.hpp"
#include "systems/render/renderSystem.hpp"
#include "systems/movement/transformSystem.hpp"
#include "systems/movement/inputSystem.hpp"
#include "systems/pvp/seekEntitySystem.hpp"
#include "systems/render/updateLevel.hpp"
#include "systems/movement/cameraMovementSystem.hpp"

#include "world/generation/map.hpp"

#include <math.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;

void SystemManager::start() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 900), "Ludwig World", sf::Style::Default);

    update(window);
}

void SystemManager::update(sf::RenderWindow& window) {

    entt::entity camera = registry.create();
    registry.emplace<controllerComponent>(camera);
    registry.emplace<cameraComponent>(camera, vec3(0, 0, 20));


    // Setup
    World world(129, 129);
    world.bufferAt(0,0);

    sf::Clock clock;  

    sf::Font font;
    if (!font.loadFromFile("../assets/textfont.ttf")) {print("Error occured while loading font.");}

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::Red);

    TileMap renderer;
    if(!renderer.load("/home/duco/development/cpp/gamedev/ludwig-world/assets/tileset.png", sf::Vector2u(32, 32), 48, 48)) {
        std::cout << "error occured" << std::endl;
        return;
    }

    while (window.isOpen()) {
        sf::Time dt;
        dt = clock.restart();

        fpsText.setString(std::to_string(1.0f / dt.asSeconds()));

        sf::Event Event{};
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0,0,0));
        
        // RenderGameMap(window, world, 1);
        UpdateLevelWorld(world, renderer, registry, camera); 
        renderer.updateMap(1);

        CameraMovementSystem(registry, world, dt.asSeconds());
        
    
        // // Update systems
        // // SeekEntitySystem(registry, dt.asSeconds());
        // InputSystem(registry, dt.asSeconds());
        // // TransformSystem(registry, dt.asSeconds());

        // // Render systems
        // RenderSystem(registry, window, txm);
        
        window.draw(renderer);
        window.draw(fpsText);
        window.display();

    }
}