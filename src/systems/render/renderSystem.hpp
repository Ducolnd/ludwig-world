#pragma once

#include <SFML/Graphics.hpp>

#include "helper/font.hpp"

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