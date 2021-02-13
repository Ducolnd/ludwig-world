#include <entt/entt.hpp>

#include "attack.hpp"
#include "helper/math/math.hpp"

void newBullet(entt::registry &registry) {
    entt::entity entity = registry.create();
    registry.emplace<velocityComponent>(entity, vec2(50.0f, 0.0f));
    registry.emplace<hasCombatantComponent>(entity);
}