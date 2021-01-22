#include "entity.hpp"
#include "../includes.hpp"

Entity::Entity(Game &game, uint16_t start_x, uint16_t start_y) {
    game_container = &game;

    x = start_x;
    y = start_y;
}

// void Entity::move(uint16_t move_x, uint16_t move_y) {
//     x += move_x;
//     y += move_y;
// }

// void Entity::teleport(uint16_t to_x, uint16_t to_y) {
//     x = to_x;
//     y = to_y;
// }

// void Entity::changed() {
//     game_container->notifyChanged(*this);
// }