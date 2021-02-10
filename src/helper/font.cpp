#include "font.hpp"
#include "includes.hpp"

Font::Font(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    coord = sf::Vector2u(x, y);
    color = sf::Color(r, g, b);
}

Font::Font(int x, int y, sf::Color _color) {
    coord = sf::Vector2u(x, y);
    color = _color;
}

Font::Font(sf::Vector2u xy, sf::Color _color) {
    coord = xy;
    color = _color;
}