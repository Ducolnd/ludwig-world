#include "levelManager.hpp"
#include "helper/includes.hpp"

LevelManager::LevelManager(TileMap *tilemap, vec2 winSize, vec2 startPos) : windowSize(winSize), topLeft(startPos) {
    renderer = tilemap;
}

void LevelManager::drawAt(vec3 where, Font what) {
    if (
        where.x < topLeft.x | where.y < topLeft.y |
        where.x >= topLeft.x + windowSize.x | where.y >= topLeft.y + windowSize.y
        
    ) {
        return;
    }

    if (where.z != currentHeight) {return;}

    vec2 lvlCoord = static_cast<vec2>(where) - topLeft;
    
    renderer->level[std::round(lvlCoord.x)][std::round(lvlCoord.y)] = what;
}