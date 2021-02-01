#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "../helper/sprites.hpp"

// Central class from which all systems are updated

class SystemManager {
    public:
        void start();
        void update(sf::RenderWindow& window);

    private:
        // EnTT 
        entt::registry registry;
        TextureManager txm;
};