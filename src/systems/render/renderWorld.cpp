#include <SFML/Graphics.hpp>
#include <iostream>

#include "helper/sprites.hpp"
#include "world/world.hpp"
#include "renderWorld.hpp"

void renderWorld(World &world, sf::RenderWindow &window, TextureManager &txm) {

    uint16_t x_tiles = window.getSize().x / txm.texture_size;
    uint16_t y_tiles = window.getSize().y / txm.texture_size;

    uint8_t x_chunks = x_tiles / world.chunkwidth;
    uint8_t y_chunks = y_tiles / world.chunkwidth;

    // std::cout << world.loaded_chunks.size() << std::endl;
    // std::cout << world.loaded_chunks[0].size() << std::endl;


    for (uint16_t x = 0; x < x_chunks * world.chunkwidth; x++) {
        for (uint16_t y = 0; y < y_chunks * world.chunkwidth; y++) {
            sf::Sprite tile(txm.getRef(world.loaded_chunks[x / world.chunkwidth][y / world.chunkwidth].tiles[20][x % world.chunkwidth][y % world.chunkwidth]));

            tile.setPosition(
                txm.texture_size * x, 
                txm.texture_size * y
            );
            window.draw(tile);
        }
    }   
}