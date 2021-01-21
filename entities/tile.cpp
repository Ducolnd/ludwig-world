#include "../includes.hpp"

// Tile class


Tile::Tile (Tiletype tiletype) {
    type = tiletype;
    // height_above_ground = height;
}   

void Tile::place(Enemy &enemy) {
    enemies.push_back(&enemy);
}

void Tile::place(Player &player) {
    players.push_back(&player);
}

void Tile::removeEntity(Player &entity) {

}

void Tile::removeEntity(Enemy &enemy) {

}