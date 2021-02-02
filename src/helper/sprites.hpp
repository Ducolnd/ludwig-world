#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class Sprite {
    public:
        Sprite();
        void initTexture(std::string path);

};

class TextureManager {
    private:
 
        /* Array of textures used */
        std::map<std::string, sf::Texture> textures;
 
    public:
 
        /* Add a texture from a file */
        void loadTexture(const std::string& name, const std::string &filename);
        void loadTexture(const std::string& name, const std::string &filename, sf::IntRect rect);
    
        /* Translate an id into a reference */
        sf::Texture& getRef(const std::string& texture);
    
        /* Constructor */
        TextureManager() {}
};

sf::IntRect getSpriteAt(uint8_t x, uint8_t y, uint16_t width=16, uint16_t height=16);
