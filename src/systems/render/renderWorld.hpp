#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "world/world.hpp"
#include "renderSystem.hpp"

// Simply draws the currently buffered chunks
void renderWorld(World &world,  TileMap &renderer, entt::registry &registry, entt::entity &cam);