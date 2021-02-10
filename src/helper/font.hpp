#pragma once

#include <cstdint>
#include <SFML/Graphics.hpp>

struct Font {
    sf::Vector2u coord;
    sf::Color color;

    Font(int x, int y, uint8_t r, uint8_t g, uint8_t b);
    Font(int x, int y, sf::Color color);
    Font(sf::Vector2u xy, sf::Color color);
};