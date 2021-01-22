#include "../includes.hpp"

Game::Game() {

}

void Game::notifyChanged(Player *player) {
    map.get_tile(player->previous_x, player->previous_y)->removeEntity(player);
    map.get_tile(player->x, player->y)->placeEntity(player);
}

void Game::displayMap() {
    for (int x = 0; x < CHUNKSIZE; x++) {
        for (int y = 0; y < CHUNKSIZE; y++) {
            if (map.chunks[0][0].tiles[x][y].entities.size() > 0) {
                std::cout << "x" << " ";
            } 
            else {
                std::cout << "-" << " ";
            }  
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}