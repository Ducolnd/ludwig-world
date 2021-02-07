#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <iostream>

#include "helper/sprites.hpp"
#include "world/world.hpp"
#include "renderWorld.hpp"
#include "components/general/cameraComponent.hpp"

void renderWorld(World &world, sf::RenderWindow &window, TextureManager &txm, entt::registry &registry, entt::entity &cam) {

    uint16_t x_tiles = window.getSize().x / txm.texture_size;
    uint16_t y_tiles = window.getSize().y / txm.texture_size;

    uint8_t x_chunks = x_tiles / world.chunkwidth;
    uint8_t y_chunks = y_tiles / world.chunkwidth;

    // std::cout << world.loaded_chunks.size() << std::endl;
    // std::cout << world.loaded_chunks[0].size() << std::endl;

    auto& loc = registry.get<cameraComponent>(cam);

    for (uint16_t cx = 0; cx < world.loaded_chunks.size(); cx++) {
        for (uint16_t cy = 0; cy < world.loaded_chunks[cx].size(); cy++) { // Loops chunks

            for (uint16_t x = 0; x < world.chunkwidth; x++) {
                for (uint16_t y = 0; y < world.chunkwidth; y++) { // Loops tiles in chunk
                    sf::Sprite tile(txm.getRef(
                        world.loaded_chunks[cx][cy]
                        .tiles[(int) loc.cameraLocation.z][x][y]));

                    tile.setPosition(
                        txm.texture_size * (cx * 16 + x), 
                        txm.texture_size * (cy * 16 + y)
                    );
                    window.draw(tile);
                }
            }  
        }
    }  
}