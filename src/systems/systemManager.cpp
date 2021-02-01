#include "helper/sprites.hpp"

#include "systems/systemManager.hpp"
#include "systems/render/renderSystem.hpp"
#include "systems/movement/transformSystem.hpp"
#include "systems/movement/inputSystem.hpp"

#include "components/movement/locationComponent.hpp"
#include "components/movement/velocityComponent.hpp"
#include "components/player/controllerComponent.hpp"

void SystemManager::start() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 800), "Ludwig World", sf::Style::Default);

    txm.loadTexture("Huamn", "../tileset/DawnLike/Characters/Humanoid0.png", getSpriteAt(0,6));
    txm.loadTexture("Huamn", "../tileset/DawnLike/Characters/Humanoid0.png", getSpriteAt(0,6));

    // Create an entity
    for (int i = 0; i < 4; i++) {
        entt::entity player = registry.create();
        registry.emplace<isRenderedComponent>(player, "Huamn");
        registry.emplace<locationComponent>(player, randomFloat(200, 600), randomFloat(200, 600));
        registry.emplace<velocityComponent>(player, randomFloat(-50, 50), randomFloat(-50, 50));
    }

    entt::entity player = registry.create();
    registry.emplace<isRenderedComponent>(player, "Huamn");
    registry.emplace<locationComponent>(player, randomFloat(200, 600), randomFloat(200, 600));
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
        InputSystem(registry, dt.asSeconds());
        TransformSystem(registry, dt.asSeconds());

        // Render systems
        RenderSystem(registry, window, txm);
        

        window.display();

    }
}