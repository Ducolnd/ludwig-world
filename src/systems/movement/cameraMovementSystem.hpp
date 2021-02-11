#pragma once

#include <entt/entt.hpp>
#include "world/world.hpp"

void CameraMovementSystem(entt::registry &registry, World &world, float dt, sf::RenderWindow &window, sf::Text text, LevelManager &lvm);