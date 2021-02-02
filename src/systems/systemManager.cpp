#include "helper/sprites.hpp"
#include "helper/math.hpp"

#include "systems/systemManager.hpp"
#include "systems/render/renderSystem.hpp"
#include "systems/movement/transformSystem.hpp"
#include "systems/movement/inputSystem.hpp"
#include "systems/pvp/seekEntitySystem.hpp"
#include "systems/render/renderWorld.hpp"


#include "components/movement/locationComponent.hpp"
#include "components/movement/velocityComponent.hpp"
#include "components/player/controllerComponent.hpp"
#include "components/combat/hasCombatantComponent.hpp"
#include "components/ai/seekEntityComponent.hpp"

#include <math.h>
#include <iostream>

void SystemManager::start() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 800), "Ludwig World", sf::Style::Default);

    loadAllTextures(txm); // Load all textures needed
    update(window);
}

void SystemManager::update(sf::RenderWindow& window) {

    sf::Clock clock;   

    World world(5, 5);
    world.bufferChunk(33425, 235);
    
    while (window.isOpen()) {
        sf::Time dt;
        dt = clock.restart();


        sf::Event Event{};
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0, 0, 0));

        renderWorld(world, window, txm); 

        
        // Update systems
        // SeekEntitySystem(registry, dt.asSeconds());
        // InputSystem(registry, dt.asSeconds());
        // TransformSystem(registry, dt.asSeconds());

        // Render systems
        // RenderSystem(registry, window, txm);
        
        

        window.display();

    }
}