#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "world/world.hpp"
#include "levelManager.hpp"

// level = vector of what is currently being displayed

// Simply draws the currently buffered chunks
void UpdateLevelWorld(World &world,  TileMap &renderer, entt::registry &registry, entt::entity &cam);

// Update entities on level
void UpdateLevelEntites(entt::registry &registry, LevelManager &manager);

// Update level according to world, for when creating new world
void UpdateLevelGamemap(TileMap &renderer, World &world, uint32_t pixel_size = 2);