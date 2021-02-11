#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "components/render/isRenderedComponent.hpp"
#include "helper/font.hpp"
#include "components/movement/locationComponent.hpp"
#include "renderSystem.hpp"
#include "world/generation/map.hpp"


bool TileMap::load(const std::string& tileset, sf::Vector2u tilesize, uint16_t _width, uint16_t _height) {
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(_width * _height * 4);

    level.resize(_width);
    for (int i = 0; i < _width; i++) {level[i].resize(_height, Font(0, 0, 0, 0));}

    width = _width;
    height = _height;
    tileSize = tilesize;

    return true;
}

void TileMap::updateMap(float scale) {
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {

            Font tile = level[i][j];

            // std::cout << tile.coord.x + tile.coord.y * 16 << " ";

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y) * scale;
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y) * scale;
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y) * scale;
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y) * scale;

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tile.coord.x * tileSize.x, tile.coord.y * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tile.coord.x + 1) * tileSize.x, tile.coord.y * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tile.coord.x + 1) * tileSize.x, (tile.coord.y + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tile.coord.x * tileSize.x, (tile.coord.y + 1) * tileSize.y);

            quad[0].color = tile.color;
            quad[1].color = tile.color;
            quad[2].color = tile.color;
            quad[3].color = tile.color;
        }
    }
}

void TileMap::changeMapSize(uint16_t tox, uint16_t toy) {
    width = tox;
    height = toy;

    m_vertices.resize(tox + toy * 4);
}


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}