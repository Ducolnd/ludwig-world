#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "../../helper/sprites.hpp"
#include "components/render/isRenderedComponent.hpp"
#include "components/movement/locationComponent.hpp"
#include "renderSystem.hpp"
#include "world/generation/map.hpp"

void RenderSystem(entt::registry &registry, sf::RenderWindow &window, TextureManager &txm) {
    auto view = registry.view<isRenderedComponent, locationComponent>();

    for (auto& ent : view) {
        auto& rendered = registry.get<isRenderedComponent>(ent);
        auto& location = registry.get<locationComponent>(ent);

        sf::Sprite s(txm.getRef(rendered.sprite));
        s.setPosition((int) location.vec.x * txm.texture_size, (int) location.vec.y * txm.texture_size);

        window.draw(s);
    }
}

void RenderGameMap(sf::RenderWindow &window, Map &world, uint32_t pixel_size) {
    float DeepWater = 0.2f;
    float ShallowWater = 0.4f;  
    float Sand = 0.5f;
    float Grass = 0.7f;
    float Forest = 0.8f;
    float Rock = 0.9f;
    float Snow = 1;

    for (uint16_t x = 0; x < world.width ; x++) {
        for (uint16_t y = 0; y < world.height ; y++) {

            sf::RectangleShape sq(sf::Vector2f(pixel_size, pixel_size));

            // print(world.tiles[x][y].height * 255);

            float h = world.tiles[x][y].height;

            if (h < DeepWater) {
                sq.setFillColor(sf::Color(0, 0, 125));
            } else if (h < ShallowWater) {
                sq.setFillColor(sf::Color(50, 50, 175));
            } else if (h < Sand) {
                sq.setFillColor(sf::Color(240, 240, 64));
            } else if (h < Grass) {
                sq.setFillColor(sf::Color(50, 220, 20));
            } else if (h < Forest) {
                sq.setFillColor(sf::Color(16, 160, 0));
            } else if (h < Rock) {
                sq.setFillColor(sf::Color(125, 125, 125));
            } else if (h < Snow) {
                sq.setFillColor(sf::Color(255, 255, 255));
            } 

            sq.setPosition(x * pixel_size, y * pixel_size);
            window.draw(sq);
        }
    }
}