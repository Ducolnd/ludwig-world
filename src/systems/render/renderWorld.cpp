#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <iostream>

#include "world/world.hpp"
#include "renderWorld.hpp"
#include "components/general/cameraComponent.hpp"
#include "helper/includes.hpp"

void renderWorld(World &world,  TileMap &renderer, entt::registry &registry, entt::entity &cam) {

    auto& loc = registry.get<cameraComponent>(cam).cameraLocation;

    for (uint16_t cx = 0; cx < world.buffer_size; cx++) {
        for (uint16_t cy = 0; cy < world.buffer_size; cy++) { // Loops chunks

            for (uint16_t x = 0; x < CHUNK_SIZE; x++) {
                for (uint16_t y = 0; y < CHUNK_SIZE; y++) { // Loops tiles in chunk
                    Chunk &c = world.loaded_chunks[cx][cy];

                    // print(c.tiles[loc.y][x][y] & 0xFF);

                    renderer.level[cx * 16 + x][cy * 16 + y] = Font(
                        c.tiles[loc.z][x][y] & 0xFF, // Which sprite

                        c.tiles[loc.z][x][y] >> 8, // R
                        c.tiles[loc.z][x][y] >> 8, // G
                        c.tiles[loc.z][x][y] >> 8  // B
                    );

                    // print("Tile: ", c.tiles[20][x][y] & 0xFF, " Colour: ", c.tiles[20][x][y] >> 8);
                }
            }  
        }
    }  
}