#include "helper/includes.hpp"
#include "world/generation/perlin.hpp"
#include "map.hpp"

#include <chrono>

Map::Map(uint32_t map_width, uint32_t map_heigth){
    width = map_width;
    height = map_heigth;
}

void Map::initTiles() {
    tiles.resize(width);
    for (int i = 0; i < width; i++) {
        tiles[i].resize(height);
    }

    Perlin heightMap(randomFloat(0, 3463675), 0.0056, 6, 2);

    // Calculate our 3D coordinates
    
    auto t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {

            //Noise range
            float x1 = 0, x2 = 1;
            float y1 = 0, y2 = 1;               
            float dx = x2 - x1;
            float dy = y2 - y1;
 
            //Sample noise at smaller intervals
            float s = x / (float) width;
            float t = y / (float) height;
 
            // Calculate our 3D coordinates
            float nx = x1 + std::sin (s * 2 * 3.14159265) * dx / (2 * 3.14159265);
            float ny = x1 + std::cos (s * 2 * 3.14159265) * dx / (2 * 3.14159265);
            float nz = t;

            tiles[x][y] = Tile(heightMap.get(nx * width, ny * height, nz * height));
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    print("Duration ", std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count());
}

Tile::Tile(float _height) {
    height = _height;
}