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
    if (!tex.loadFromFile(filename, rect)) {
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
    txm.loadTexture(0, "../tileset/DawnLike/Items/Ammo.png", getSpriteAt(7,4));

    txm.loadTexture(1, "../tileset/DawnLike/Objects/Ground1.png", getSpriteAt(0,1));
    txm.loadTexture(2, "../tileset/DawnLike/Objects/Ground1.png", getSpriteAt(0,1));
    txm.loadTexture(3, "../tileset/DawnLike/Objects/Ground1.png", getSpriteAt(1,0));
    txm.loadTexture(4, "../tileset/DawnLike/Objects/Ground1.png", getSpriteAt(2, 0));

    txm.loadTexture(5, "../tileset/DawnLike/Items/Food.png", getSpriteAt(0,3));
    txm.loadTexture(6, "../tileset/DawnLike/Items/Chest1.png", getSpriteAt(0,0));



    txm.loadTexture(255, "../tileset/DawnLike/Characters/Humanoid0.png", getSpriteAt(0,6));
    txm.loadTexture(256, "../tileset/DawnLike/Characters/Demon0.png", getSpriteAt(0,0));
    txm.loadTexture(257, "../tileset/DawnLike/Items/Ammo.png", getSpriteAt(0,2));
}
