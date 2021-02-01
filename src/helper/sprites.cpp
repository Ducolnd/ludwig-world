#include "sprites.hpp"

#include <iostream>
#include <random>

// #include "helper/includes.hpp"

float randomFloat(float start, float end) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(start, end);

    return dis(gen);
}
 
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

sf::IntRect getSpriteAt(uint8_t x, uint8_t y) {
    return sf::IntRect(16 * x, 16 * y, 16, 16);
}