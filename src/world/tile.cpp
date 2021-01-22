#include "../includes.hpp"

// Tile class


Tile::Tile (Tiletype tiletype) {
    type = tiletype;
}   

void Tile::placeEntity(Entity *entity) {
    
    entities.push_back(entity);
}

void Tile::removeEntity(Entity *entity) {
    for (u_int16_t i = 0; i < entities.size(); i++) {
        if (entities[i] == entity) {
            entities.erase(entities.begin() + i);
        }
    }

    // std::cout << entities.size() << " Size and tyletype: " << (int) type << std::endl;
}