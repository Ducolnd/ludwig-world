#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <iostream>

#include "world/world.hpp"
#include "renderWorld.hpp"
#include "components/general/cameraComponent.hpp"
#include "helper/includes.hpp"

void renderWorld(World &world, sf::RenderWindow &window, entt::registry &registry, entt::entity &cam) {

    auto& loc = registry.get<cameraComponent>(cam);

    for (uint16_t cx = 0; cx < world.loaded_chunks.size(); cx++) {
        for (uint16_t cy = 0; cy < world.loaded_chunks[cx].size(); cy++) { // Loops chunks

            for (uint16_t x = 0; x < CHUNK_SIZE; x++) {
                for (uint16_t y = 0; y < CHUNK_SIZE; y++) { // Loops tiles in chunk
                    // sf::Sprite tile(txm.getRef(
                    //     world.loaded_chunks[cx][cy].tiles[(int) loc.cameraLocation.z][x][y]));

                    // tile.setPosition(
                    //     txm.texture_size * (cx * 16 + x), 
                    //     txm.texture_size * (cy * 16 + y)
                    // );
                    // window.draw(tile);
                }
            }  
        }
    }  
}