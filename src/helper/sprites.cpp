#include "sprites.hpp"

#include <iostream>

 
void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    /* Load the texture */
    sf::Texture tex;
    if (!tex.loadFromFile(filename)) {
        std::cout << "Error loading file" << std::endl;
        return;
    }
 
    /* Add it to the list of textures */
    this->textures[name] = tex;
}

void TextureManager::loadTexture(const std::string& name, const std::string& filename, sf::IntRect rect) {
    /* Load the texture */
    sf::Texture tex;
    if (!tex.loadFromFile(filename, rect)) {
        std::cout << "Error loading file" << std::endl;
        return;
    }
 
    /* Add it to the list of textures */
    this->textures[name] = tex;
}
 
sf::Texture& TextureManager::getRef(const std::string& texture) {
    return this->textures.at(texture);
}

sf::IntRect getSpriteAt(uint8_t x, uint8_t y, uint16_t width, uint16_t height) {
    return sf::IntRect(width * x, height * y, width, height);
}