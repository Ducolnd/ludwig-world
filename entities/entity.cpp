#include "entity.hpp"
#include "../includes.hpp"

Entity::Entity() {
}

void Entity::move(uint16_t move_x, uint16_t move_y) {
    x += move_x;
    y += move_y;

    changed();
}

void Entity::teleport(uint16_t to_x, uint16_t to_y) {
    x = to_x;
    y = to_y;

    changed();
}

void Entity::changed() {
    in_chunk->needs_update.push_back(this);
}
