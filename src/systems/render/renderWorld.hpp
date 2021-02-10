#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "world/world.hpp"

// Simply draws the currently buffered chunks
void renderWorld(World &world, sf::RenderWindow &window, entt::registry &registry, entt::entity &cam);