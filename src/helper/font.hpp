#pragma once

#include <cstdint>
#include <SFML/Graphics.hpp>

struct Font {
    sf::Vector2u coord;
    sf::Color color;

    Font() {}

    Font(uint8_t xy, uint8_t r, uint8_t g, uint8_t b);
    Font(int x, int y, uint8_t r, uint8_t g, uint8_t b);
    Font(int x, int y, sf::Color color);
    Font(sf::Vector2u xy, sf::Color color);
    Font(uint8_t xy, sf::Color color);

    void setColor(sf::Color c);
    void setCoord(uint8_t coord);

};