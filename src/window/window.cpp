#include "window.hpp"

#include "helper/includes.hpp"

Window::Window(uint16_t x_size, uint16_t y_size, std::string title) { 

    sf::RenderWindow window(sf::VideoMode(x_size, y_size), title, sf::Style::Close | sf::Style::Resize);
}