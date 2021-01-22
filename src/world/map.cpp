#include "../includes.hpp"


// Map class

Map::Map () {
    chunks.resize(3, std::vector<Chunk>(3, Chunk()));
    chunks[0][0].init(100, 5);
}

void Map::placePlayer(Player *player, int x, int y) {
    // std::cout << "Placed player on " << x % CHUNKSIZE << "x y" << y % CHUNKSIZE << std::endl;

    chunks[(int) x / CHUNKSIZE][(int) y / CHUNKSIZE].               // Which Chunk
    tiles[x % CHUNKSIZE][y % CHUNKSIZE].placeEntity(player);        // Which tile on chunk?
}

void Map::placePlayer(Player *player) {
    player->x = 0;
    player->y = 0;

    chunks[0][0].tiles[0][0].placeEntity(player);
}

Tile * Map::get_tile(int x, int y) {
    //std::cout << "x " << x << " y " << y << " from get_tile" << std::endl;
    return &chunks[0][0].tiles[x][y];
}