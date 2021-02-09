#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "helper/sprites.hpp"
#include "components/render/isRenderedComponent.hpp"
#include "world/world.hpp"
#include "world/generation/map.hpp"

void RenderSystem(entt::registry &registry, sf::RenderWindow &window, TextureManager &txm);
void RenderGameMap(sf::RenderWindow &window, World &world, uint32_t pixel_size = 2);