#pragma once

#include <entt/entt.hpp>

#include "world/world.hpp"

// Handles collision with the world (walls, hills etc.)
void LevelCollisionSystem(World &world, entt::registry &registry);