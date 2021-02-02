#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
    private:
 
        /* Array of textures used */
        std::map<uint16_t, sf::Texture> textures;
 
    public:
 
        /* Add a texture from a file */
        void loadTexture(const uint16_t& name, const std::string &filename);
        void loadTexture(const uint16_t& name, const std::string &filename, sf::IntRect rect);
    
        /* Translate an id into a reference */
        sf::Texture& getRef(const uint16_t& texture);
    
        /* Constructor */
        TextureManager(uint8_t txus=16) {texture_size = txus;}

        uint8_t texture_size;
};

void loadAllTextures(TextureManager &txm);

sf::IntRect getSpriteAt(uint8_t x, uint8_t y, uint16_t width=16, uint16_t height=16);
