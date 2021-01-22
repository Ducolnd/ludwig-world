#include "../includes.hpp"

Game::Game() {

}

void Game::notifyChanged(Entity &entity) {
    map.get_tile(entity.previous_x, entity.previous_y).removeEntity(entity);
    map.get_tile(entity.x, entity.y).placeEntity(entity);
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
}