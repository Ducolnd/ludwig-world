#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "components/render/isRenderedComponent.hpp"
#include "helper/font.hpp"
#include "components/movement/locationComponent.hpp"
#include "renderSystem.hpp"
#include "world/generation/map.hpp"

void RenderSystem(entt::registry &registry, sf::RenderWindow &window) {
    auto view = registry.view<isRenderedComponent, locationComponent>();

    for (auto& ent : view) {
        auto& rendered = registry.get<isRenderedComponent>(ent);
        auto& location = registry.get<locationComponent>(ent);

        // ToDo implement entity drawing
        sf::Sprite s;

        window.draw(s);
    }
}

void RenderGameMap(sf::RenderWindow &window, World &world, uint32_t pixel_size) {
    float DeepWater = 0.345f;
    float ShallowWater = 0.5f;  
    float Sand = 0.6f;
    float Grass = 0.7f;
    float Forest = 0.8f;
    float Rock = 0.85f;
    float Snow = 1;

    float ColdestValue = 0.10f;
    float ColderValue = 0.18f;
    float ColdValue = 0.4f;
    float WarmValue = 0.6f;
    float WarmerValue = 0.8f;
    float WarmestValue = 1.0f;

    for (uint16_t x = 0; x < world.map.width ; x++) {
        for (uint16_t y = 0; y < world.map.height ; y++) {

            sf::RectangleShape sq(sf::Vector2f(pixel_size, pixel_size));

            float h = world.map.regions[x][y].height;

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

            //  if (h < ColdestValue) {
            //     sq.setFillColor(sf::Color(255, 255, 255));
            // } else if (h < ColderValue) {
            //     sq.setFillColor(sf::Color(204, 255, 255));
            // } else if (h < ColdValue) {
            //     sq.setFillColor(sf::Color(153, 255, 51));
            // } else if (h < WarmValue) {
            //     sq.setFillColor(sf::Color(255, 255, 0));
            // } else if (h < WarmerValue) {
            //     sq.setFillColor(sf::Color(255, 153, 0));
            // } else if (h < WarmestValue) {
            //     sq.setFillColor(sf::Color(255, 0, 0));
            // }

            sq.setPosition(x * pixel_size, y * pixel_size);
            window.draw(sq);
        }
    }
}


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