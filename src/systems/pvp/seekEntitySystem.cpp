#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "seekEntitySystem.hpp"

#include "helper/math.hpp"

#include "components/movement/locationComponent.hpp"
#include "components/movement/velocityComponent.hpp"
#include "components/combat/hasCombatantComponent.hpp"
#include "components/ai/seekEntityComponent.hpp"


void SeekEntitySystem(entt::registry &registry, float lapsed) {
    float max_vel = 50;

    auto view = registry.view<locationComponent, velocityComponent, hasCombatantComponent, seekEntityComponent>();

    for (auto& ent : view) {
        auto& location = registry.get<locationComponent>(ent).vec;
        auto& velocity = registry.get<velocityComponent>(ent).vec;
        auto& seek = registry.get<seekEntityComponent>(ent);

        auto& tvec = registry.get<locationComponent>(seek.entity).vec;

        float ratio = (location.x - tvec.x) / (location.y - tvec.y);

        if (round(ratio) != round(velocity.x / velocity.y)) {
            float ang_per_sec = 180 * (3.141592 / 180) * lapsed;
            velocity.rotate(ang_per_sec);
        }                

        std::cout << " ratio 1 " << ratio  << " ratio 2 " << round(velocity.x / velocity.y) << std::endl;
    }
}