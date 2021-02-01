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

        location.x += velocity.x * dt;
        location.y += velocity.y * dt;

        if (location.x > 800) {
            velocity.x *= -1;
        }
        else if (location.x < 0) {
            velocity.x *= -1;
        }
        if (location.x > 800) {
            velocity.y *= -1;
        }
        else if (location.x > 0) {
            velocity.y *= -1;
        }
        // location.z += velocity.z * dt;
    }
}