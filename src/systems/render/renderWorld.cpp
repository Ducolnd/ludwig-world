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
            sf::Sprite tile(txm.getRef(world.loaded_chunks[x / world.chunkwidth][y / world.chunkwidth].tiles[25][x % world.chunkwidth][y % world.chunkwidth]));

            tile.setPosition(
                txm.texture_size * x, 
                txm.texture_size * y
            );
            window.draw(tile);
        }
    }

    // for (uint8_t xc = 0; xc < x_chunks; xc++) {
    //     for (uint8_t yc = 0; yc < y_chunks; yc++) {

    //         std::cout << "x y" << std::to_string(xc) << " " << std::to_string(yc) << std::endl;

    //         for (uint8_t x = 0; x < world.chunkwidth; x++) {
    //             for (uint8_t y = 0; y < world.chunkwidth; y++) {
                    
    //                 sf::Sprite tile(txm.getRef(world.loaded_chunks[xc][yc].tiles[25][x][y]));

    //                 tile.setPosition(
    //                     window.getSize().x / 2 - txm.texture_size * (world.chunkwidth / 2) - (1 - xc) * txm.texture_size * world.chunkwidth + txm.texture_size * x, 
    //                     window.getSize().y / 2 - txm.texture_size * (world.chunkwidth / 2) - (1 - yc) * txm.texture_size * world.chunkwidth + txm.texture_size * y
    //                 );

    //                 window.draw(tile);
    //             }
    //         }
    //     }
    // }
    
}