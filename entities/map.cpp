#include "../includes.hpp"


// Map class

Map::Map () {
    chunks.resize(3, std::vector<Chunk>(3, Chunk()));
    chunks[0][0].init(100, 5);
}

void Map::placePlayer(Player &player, int x, int y) {
    std::cout << "Placed player on " << x % CHUNKSIZE << "x y" << y % CHUNKSIZE << std::endl;

    chunks[(int) x / CHUNKSIZE][(int) y / CHUNKSIZE].       // Which Chunk
    tiles[x % CHUNKSIZE][y % CHUNKSIZE].place(player);      // Which tile on chunk?
}

void Map::placePlayer(Player &player) {
    chunks[0][0].tiles[0][0].place(player);
}

Tile Map::get_tile(int x, int y) {
    return chunks[0][0].tiles[x][y];
}

void Map::updateChunks() {
    for (uint16_t x = 0; x < chunks.size(); x++) { // Loop loaded chunks
        for (uint16_t y = 0; y < chunks[x].size(); y++) {
            Chunk chunk = chunks[x][y];

            if (chunk.needs_update.size() > 0) { // There is entities to be updated

            }
        }
    }
}