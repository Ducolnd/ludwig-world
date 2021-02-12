#include "helper/includes.hpp"
#include "helper/includeComponents.hpp"

#include "systems/systemManager.hpp"
#include "systems/render/renderSystem.hpp"
#include "systems/movement/transformSystem.hpp"
#include "systems/movement/inputSystem.hpp"
#include "systems/pvp/seekEntitySystem.hpp"
#include "systems/render/updateLevel.hpp"
#include "systems/movement/cameraMovementSystem.hpp"

#include "world/generation/map.hpp"

using namespace std::chrono;

void SystemManager::start() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1080, 1080), "Ludwig World", sf::Style::Default);

    update(window);
}

void SystemManager::update(sf::RenderWindow& window) {

    entt::entity camera = registry.create();
    registry.emplace<controllerComponent>(camera);
    registry.emplace<cameraComponent>(camera, vec3(0, 0, 29));

    entt::entity player = registry.create();
    registry.emplace<controllerComponent>(player);
    registry.emplace<locationComponent>(player, vec3(0, 0, 29));
    registry.emplace<isRenderedComponent>(player, Font(0, 4, 66, 200, 245));


    // Setup
    World world(129, 129, 235, 4);
    world.bufferAt(0,0);

    sf::Clock clock;  

    sf::Font font;
    if (!font.loadFromFile("../assets/textfont.ttf")) {print("Error occured while loading font.");}

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::Red);

    sf::Text zText;
    zText.setFont(font);
    zText.setCharacterSize(24);
    zText.setFillColor(sf::Color::Red);
    zText.setPosition(0, 30);

    TileMap renderer;
    if(!renderer.load("/home/duco/development/cpp/gamedev/ludwig-world/assets/tileset.png", sf::Vector2u(32, 32), 48, 48)) {std::cout << "error occured" << std::endl;return;}

    LevelManager levelManager(&renderer, vec2(48, 48));


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
        
        CameraMovementSystem(registry, dt.asSeconds());
        CameraLocationUpdateSystem(registry, world, zText, levelManager, window);
        InputSystem(registry, dt.asSeconds());
        
        UpdateLevelWorld(world, levelManager, registry, camera); 
        UpdateLevelEntites(registry, levelManager);

        renderer.updateMap(0.75);

        window.draw(renderer);
        window.draw(fpsText);
        window.display();

    }
}