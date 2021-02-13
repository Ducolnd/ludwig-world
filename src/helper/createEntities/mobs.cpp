#include <entt/entt.hpp>

#include "mobs.hpp"
#include "helper/math/math.hpp"

void newSkeleton(entt::registry &registry) {
    entt::entity entity = registry.create();
    registry.emplace<velocityComponent>(entity, vec2(50.0f, 0.0f));
    registry.emplace<hasCombatantComponent>(entity);
}

void newZombie(entt::registry &registry) {

}

void newDwarf(entt::registry &registry) {

}

void newGhost(entt::registry &registry) {

}

void newDragon(entt::registry &registry) {

}