#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "../../helper/sprites.hpp"
#include "components/render/isRenderedComponent.hpp"
#include "components/movement/locationComponent.hpp"
#include "renderSystem.hpp"

void RenderSystem(entt::registry &registry, sf::RenderWindow &window, TextureManager &txm) {
    auto view = registry.view<isRenderedComponent, locationComponent>();

    for (auto& ent : view) {
        auto& rendered = registry.get<isRenderedComponent>(ent);
        auto& location = registry.get<locationComponent>(ent);

        sf::Sprite s(txm.getRef(rendered.sprite));
        s.setPosition((int) location.x, (int) location.y);

        window.draw(s);
    }
}