#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "helper/sprites.hpp"
#include "components/render/isRenderedComponent.hpp"

void RenderSystem(entt::registry &registry, sf::RenderWindow &window, TextureManager &txm);