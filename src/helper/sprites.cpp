#include "sprites.hpp"

#include <iostream>

void TextureManager::loadTexture(const uint16_t& name, const std::string& filename) {
    /* Load the texture */
    sf::Texture tex;
    if (!tex.loadFromFile(filename)) {
        std::cout << "Error loading file" << std::endl;
        return;
    }
 
    /* Add it to the list of textures */
    this->textures[name] = tex;
}

void TextureManager::loadTexture(const uint16_t& name, const std::string& filename, sf::IntRect rect) {
    /* Load the texture */
    sf::Texture tex;
    if (!tex.loadFromFile("../tileset/DawnLike/" + filename, rect)) {
        std::cout << "Error loading file" << std::endl;
        return;
    }
 
    /* Add it to the list of textures */
    this->textures[name] = tex;
}
 
sf::Texture& TextureManager::getRef(const uint16_t& texture) {
    return this->textures.at(texture);
}

sf::IntRect getSpriteAt(uint8_t x, uint8_t y, uint16_t width, uint16_t height) {
    return sf::IntRect(width * x, height * y, width, height);
}

// Helper function to load all textures
void loadAllTextures(TextureManager &txm) {
    txm.loadTexture(0, "Characters/Aquatic1.png", getSpriteAt(7, 4));

    txm.loadTexture(9, "Objects/Tile.png", getSpriteAt(5, 2));
    txm.loadTexture(1, "Objects/Tile.png", getSpriteAt(2, 2));
    txm.loadTexture(2, "Objects/Tile.png", getSpriteAt(0,0));
    txm.loadTexture(3, "Objects/Ground0.png", getSpriteAt(1,0));
    txm.loadTexture(4, "Objects/Ground0.png", getSpriteAt(2, 0));

    txm.loadTexture(5, "Items/Food.png", getSpriteAt(0,3));
    txm.loadTexture(6, "Items/Chest1.png", getSpriteAt(0,0));
    txm.loadTexture(9, "Objects/Wall.png", getSpriteAt(0,0));



    txm.loadTexture(256, "Characters/Demon0.png", getSpriteAt(0,0));
}
