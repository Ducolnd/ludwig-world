#include "../includes.hpp"

// Chunk class

Chunk::Chunk() {
    tiles.resize(CHUNKSIZE, std::vector<Tile>(CHUNKSIZE, Tile(Tiletype::empty)));
}

void Chunk::init(int n, int a) {
    fillChunk(n, a);
}

void Chunk::fillChunk(int itm, int enm) {

    std::cout << "A chunk was created" << std::endl;

    int enemy_count = 0;

    // Engine for generator numbers between 0 and CHUNKSIZE - 1
    std::random_device rseed;
    std::mt19937 engine(rseed());
    std::uniform_int_distribution<int> dist(0,CHUNKSIZE - 1);

    
    Enemy en("Zombie Bob", Enemies::zombie);


    for (int x = 0; x <= CHUNKSIZE - 1; x++ ) {
        for (int y = 0; y <= CHUNKSIZE - 1; y++) {
            Tile tile(Tiletype::empty);
            tiles[x].push_back(tile);
        }
    }

    while (enemy_count < enm) {
        tiles[dist(engine)][dist(engine)].place(en);
        enemy_count++;
    }
}

void Chunk::updateChunk() {
    for (uint16_t i = 0; i < needs_update.size(); i++) {
        Entity *entity = needs_update[i];

        Tile tile = tiles[entity->x][entity->y];
        tile.removeEntity(entity);
    }

    needs_update.clear();
}

