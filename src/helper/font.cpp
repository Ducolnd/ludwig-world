#include "font.hpp"
#include "includes.hpp"

Font::Font(uint8_t xy, uint8_t r, uint8_t g, uint8_t b) {
    coord = sf::Vector2u(xy - 16 * static_cast<int>(xy / 16), static_cast<int>(xy / 16));
    color = sf::Color(r, g, b);
}

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

Font::Font(uint8_t xy, sf::Color _color) {
    coord = sf::Vector2u(xy - 16 * static_cast<int>(xy / 16), static_cast<int>(xy / 16));
    color = _color;
}

void Font::setColor(sf::Color c) {
    color = c;
}

void Font::setCoord(uint8_t c) {
    coord = sf::Vector2u(c - 16 * static_cast<int>(c / 16), static_cast<int>(c / 16));
}