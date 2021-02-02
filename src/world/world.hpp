#pragma once

#include <random>
#include <vector>

enum Biome {
    rainForest,
    thickForet,
    dutchForest,
    taigaForest,
    beach,
    lavaLands,
    riverLands,
    swamp,

    end
};

class Chunk {
    public:
        Biome biome;
        float danger_level;
        
};

class World {
    public:
        World();

        float randomNum(float start, float end);
        int randomNum(int start, int end);

        std::vector<std::vector<Chunk>> loaded_chunks;

    private:
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
};