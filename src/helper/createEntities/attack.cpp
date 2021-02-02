#include <entt/entt.hpp>

#include "attack.hpp"
#include "helper/math.hpp"

void newBullet(entt::registry &registry) {
    entt::entity entity = registry.create();
    registry.emplace<isRenderedComponent>(entity, "Arrow");
    registry.emplace<locationComponent>(entity, vec2(randomFloat(200, 600), randomFloat(200, 600)));
    registry.emplace<velocityComponent>(entity, vec2(50.0f, 0.0f));
    registry.emplace<hasCombatantComponent>(entity);
}