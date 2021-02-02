#include "helper/sprites.hpp"
#include "helper/math.hpp"

#include "systems/systemManager.hpp"
#include "systems/render/renderSystem.hpp"
#include "systems/movement/transformSystem.hpp"
#include "systems/movement/inputSystem.hpp"
#include "systems/pvp/seekEntitySystem.hpp"

#include "components/movement/locationComponent.hpp"
#include "components/movement/velocityComponent.hpp"
#include "components/player/controllerComponent.hpp"
#include "components/combat/hasCombatantComponent.hpp"
#include "components/ai/seekEntityComponent.hpp"

#include <math.h>

void SystemManager::start() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 800), "Ludwig World", sf::Style::Default);

    txm.loadTexture("Human", "../tileset/DawnLike/Characters/Humanoid0.png", getSpriteAt(0,6));
    txm.loadTexture("Demon", "../tileset/DawnLike/Characters/Demon0.png", getSpriteAt(0,0));
    txm.loadTexture("Arrow", "../tileset/DawnLike/Items/Ammo.png", getSpriteAt(0,2));

    // Create an entity
    for (int i = 0; i < 1; i++) {
        entt::entity player = registry.create();
        registry.emplace<isRenderedComponent>(player, "Human");
        registry.emplace<locationComponent>(player, vec2(randomFloat(200, 600), randomFloat(200, 600)));
        registry.emplace<velocityComponent>(player, vec2(randomFloat(-50, 50), randomFloat(-50, 50)));
    }

    entt::entity player = registry.create();
    registry.emplace<isRenderedComponent>(player, "Demon");
    registry.emplace<locationComponent>(player, vec2(randomFloat(200, 600), randomFloat(200, 600)));
    registry.emplace<controllerComponent>(player);
  

    update(window);
}

void SystemManager::update(sf::RenderWindow& window) {

    sf::Clock clock;

    
    
    while (window.isOpen()) {
        sf::Time dt;
        dt = clock.restart();

        sf::Event Event{};
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));

        // Update systems
        SeekEntitySystem(registry, dt.asSeconds());
        InputSystem(registry, dt.asSeconds());
        TransformSystem(registry, dt.asSeconds());

        // Render systems
        RenderSystem(registry, window, txm);
        

        window.display();

    }
}