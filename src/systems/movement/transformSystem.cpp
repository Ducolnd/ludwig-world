#include <entt/entt.hpp>
#include <iostream>

#include "transformSystem.hpp"
#include "components/movement/velocityComponent.hpp"
#include "components/movement/locationComponent.hpp"


void TransformSystem(entt::registry &registry, float dt) {
    auto view = registry.view<velocityComponent, locationComponent>();

    for (auto& ent : view) {
        auto& velocity = registry.get<velocityComponent>(ent);
        auto& location = registry.get<locationComponent>(ent);

        location.vec.x += velocity.vec.x * dt;
        location.vec.y += velocity.vec.y * dt;
    }
}