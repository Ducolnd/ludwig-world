#pragma once

#include <vector>

class Tile {
    public:
        Tiletype type;
        int height_above_ground;

        std::vector<Entity*> entities;

        Tile (Tiletype tiletype);

        void placeEntity(Entity &entity);
        void removeEntity(Entity &entity);
};