#include "levelCollisionSystem.hpp"
#include "helper/includeComponents.hpp"
#include "world/block/blockList.hpp"

#include <math.h>

bool isPassable(std::vector<std::vector<uint16_t>> what, float x, float y) {
    if (x < 0 | x >= CHUNK_SIZE | y < 0 | y >= CHUNK_SIZE) {
        return true;
    }

    return getBlock(what[static_cast<int>(x)][static_cast<int>(y)]).passable;
}

void LevelCollisionSystem(World &world, entt::registry &registry) {
    auto view = registry.view<locationComponent, collisionComponent>();

    for (auto& ent : view) {
        auto& hit = registry.get<collisionComponent>(ent).hitbox;
        auto& location = registry.get<locationComponent>(ent).vec;

        // Slice of chunk at current z 
        std::vector<std::vector<uint16_t>> &slice = world.getChunk(location.x, location.y).tiles[static_cast<int>(location.z)];

        float xChunk = fmod(location.x, CHUNK_SIZE); // Location in chunk
        float yChunk = fmod(location.y, CHUNK_SIZE); // Location in chunk

        // Check all 4 corners for collision
        bool leftTop = !isPassable(slice, xChunk - hit.width, yChunk - hit.height);
        bool leftBot = !isPassable(slice, xChunk - hit.width, yChunk + hit.height);
        bool rightTop = !isPassable(slice, xChunk + hit.width, yChunk - hit.height);
        bool rightBot = !isPassable(slice, xChunk + hit.width, yChunk + hit.height);

        if (rightTop && rightBot) {
            location.x -= hit.width - (xChunk - static_cast<int>(xChunk));
        } else if (leftTop && leftBot) {
            location.x += hit.width - (xChunk - static_cast<int>(xChunk) - 0.5);
        }

        if (leftBot && rightBot) {
            location.y -= hit.height - (yChunk - static_cast<int>(yChunk));
        } else if (leftTop && rightTop) {
            location.y += hit.width - (1 - xChunk - static_cast<int>(xChunk));
        }
    }
}