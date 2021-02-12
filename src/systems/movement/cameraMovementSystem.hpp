#pragma once

#include <entt/entt.hpp>
#include "world/world.hpp"
#include "systems/render/levelManager.hpp"

void CameraMovementSystem(entt::registry &registry, float dt);
void CameraLocationUpdateSystem(entt::registry &registry, World &world, sf::Text text, LevelManager &lvm, sf::RenderWindow &window);