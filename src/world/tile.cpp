#include "../includes.hpp"

// Tile class


Tile::Tile (Tiletype tiletype) {
    type = tiletype;
    // height_above_ground = height;
}   

void Tile::placeEntity(Entity &entity) {
    entities.push_back(&entity);
}

void Tile::removeEntity(Entity &entity) {
    for (u_int16_t i = 0; i < entities.size(); i++) {
        if (entities[i] == &entity) {
            entities.erase(entities.begin() + i);
        }
    }
}