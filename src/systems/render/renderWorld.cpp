#include <SFML/Graphics.hpp>

#include "helper/sprites.hpp"
#include "world/world.hpp"
#include "renderWorld.hpp"

void renderWorld(World &world, sf::RenderWindow &window, TextureManager &txm) {

    // uint16_t x_tiles = window.getSize().x / txm.texture_size;
    // uint16_t y_tiles = window.getSize().y / txm.texture_size;

    // uint8_t x_chunks = x_tiles / world.chunkwidth;
    // uint8_t y_chunks = y_tiles / world.chunkwidth;

    for (uint8_t x = 0; x < world.chunkwidth; x++) {
        for (uint8_t y = 0; y < world.chunkwidth; y++) {
            sf::Sprite tile(txm.getRef(world.loaded_chunks[1][1].tiles[25][x][y]));

            tile.setPosition(
                window.getSize().x / 2 - txm.texture_size * (world.chunkwidth / 2) + txm.texture_size * x, 
                window.getSize().y / 2 - txm.texture_size * (world.chunkwidth / 2) + txm.texture_size * y
            );

            window.draw(tile);
        }
    }
}