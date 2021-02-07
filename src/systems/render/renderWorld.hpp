#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "helper/sprites.hpp"
#include "world/world.hpp"

void renderWorld(World &world, sf::RenderWindow &window, TextureManager &txm, entt::registry &registry, entt::entity &cam);