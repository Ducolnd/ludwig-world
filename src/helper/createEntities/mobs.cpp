#include <entt/entt.hpp>

#include "mobs.hpp"
#include "helper/math.hpp"

void newSkeleton(entt::registry &registry) {
    entt::entity entity = registry.create();
    registry.emplace<isRenderedComponent>(entity, "Skeleton");
    registry.emplace<locationComponent>(entity, vec2(randomFloat(200, 600), randomFloat(200, 600)));
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