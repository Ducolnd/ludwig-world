#pragma once

#include "renderSystem.hpp"
#include "helper/math/math.hpp"

class LevelManager {
    public:
        LevelManager(TileMap *tilemap, vec2 winSize, vec2 startPos = vec2(0, 0));

        void drawAt(vec3 where, Font what);

        // Variables
        vec2 topLeft; // Coord of window-topleft game coordinate
        vec2 windowSize;

        int currentHeight;

    private:
        TileMap *renderer;
};