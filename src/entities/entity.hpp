#pragma once

#include <stdint.h>
#include <memory>

#include "../world/game.hpp"

class Entity {
    public:
        uint16_t x, y, previous_x, previous_y;
        Game *game_container;

        Entity(Game &game);
        void move(uint16_t move_x, uint16_t move_y);
        void teleport(uint16_t to_x, uint16_t to_y);
        void changed();
};