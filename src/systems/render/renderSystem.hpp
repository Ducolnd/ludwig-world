#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "components/render/isRenderedComponent.hpp"
#include "world/world.hpp"
#include "world/generation/map.hpp"
#include "helper/font.hpp"

void RenderSystem(entt::registry &registry, sf::RenderWindow &window);
void RenderGameMap(sf::RenderWindow &window, World &world, uint32_t pixel_size = 2);

class TileMap : public sf::Drawable, public sf::Transformable {
    public:
        bool load(const std::string& tileset, sf::Vector2u tileSize, uint16_t _width, uint16_t _height);
        void updateMap(float scale=1);
        void changeMapSize(uint16_t tox, uint16_t toy);

        std::vector<std::vector<Font>> level;

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::VertexArray m_vertices;
        sf::Texture m_tileset;

        uint16_t width, height;
        sf::Vector2u tileSize;
};