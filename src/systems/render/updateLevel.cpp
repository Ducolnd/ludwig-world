#include <entt/entt.hpp>
#include <iostream>

#include "world/world.hpp"
#include "updateLevel.hpp"
#include "helper/includeComponents.hpp"
#include "helper/includes.hpp"
#include "helper/font.hpp"

void UpdateLevelEntites(entt::registry &registry, TileMap &renderer) {
    auto view = registry.view<isRenderedComponent, locationComponent>();

    for (auto& ent : view) {
        auto& rendered = registry.get<isRenderedComponent>(ent);
        auto& location = registry.get<locationComponent>(ent);

        // renderer.level[] = rendered.sprite;
    }
}

void UpdateLevelGamemap(TileMap &renderer, World &world, uint32_t pixel_size) {
    float DeepWater = 0.345f;
    float ShallowWater = 0.5f;  
    float Sand = 0.6f;
    float Grass = 0.7f;
    float Forest = 0.8f;
    float Rock = 0.85f;
    float Snow = 1;

    float ColdestValue = 0.10f;
    float ColderValue = 0.18f;
    float ColdValue = 0.4f;
    float WarmValue = 0.6f;
    float WarmerValue = 0.8f;
    float WarmestValue = 1.0f;

    for (uint16_t x = 0; x < world.map.width ; x++) {
        for (uint16_t y = 0; y < world.map.height ; y++) {

            float h = world.map.regions[x][y].height;

            Font font;
            font.setCoord(254); 

            if (h < DeepWater) {
                font.setColor(sf::Color(0, 0, 125));
            } else if (h < ShallowWater) {
                font.setColor(sf::Color(50, 50, 175));
            } else if (h < Sand) {
                font.setColor(sf::Color(240, 240, 64));
            } else if (h < Grass) {
                font.setColor(sf::Color(50, 220, 20));
            } else if (h < Forest) {
                font.setColor(sf::Color(16, 160, 0));
            } else if (h < Rock) {
                font.setColor(sf::Color(125, 125, 125));
            } else if (h < Snow) {
                font.setColor(sf::Color(255, 255, 255));
            } else {
                font.setColor(sf::Color(255, 255, 255));
            }

            //  if (h < ColdestValue) {
            //     Font font(254, (sf::Color(255, 255, 255));
            // } else if (h < ColderValue) {
            //     Font font(254, (sf::Color(204, 255, 255));
            // } else if (h < ColdValue) {
            //     Font font(254, (sf::Color(153, 255, 51));
            // } else if (h < WarmValue) {
            //     Font font(254, (sf::Color(255, 255, 0));
            // } else if (h < WarmerValue) {
            //     Font font(254, (sf::Color(255, 153, 0));
            // } else if (h < WarmestValue) {
            //     Font font(254, (sf::Color(255, 0, 0));
            // }

            renderer.level[x][y] = font;
        }
    }
}

void UpdateLevelWorld(World &world,  TileMap &renderer, entt::registry &registry, entt::entity &cam) {

    auto& loc = registry.get<cameraComponent>(cam).cameraLocation;

    for (uint16_t cx = 0; cx < world.buffer_size; cx++) {
        for (uint16_t cy = 0; cy < world.buffer_size; cy++) { // Loops chunks

            for (uint16_t x = 0; x < CHUNK_SIZE; x++) {
                for (uint16_t y = 0; y < CHUNK_SIZE; y++) { // Loops tiles in chunk
                    Chunk &c = world.loaded_chunks[cx][cy];

                    renderer.level[cx * 16 + x][cy * 16 + y] = Font(
                        c.tiles[loc.z][x][y] & 0xFF, // Which sprite

                        c.tiles[loc.z][x][y] >> 8, // R
                        c.tiles[loc.z][x][y] >> 8, // G
                        c.tiles[loc.z][x][y] >> 8  // B
                    );
                }
            }  
        }
    }  
}