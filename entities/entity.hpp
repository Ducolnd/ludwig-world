#pragma once

#include <stdint.h>
#include "chunk.hpp"
#include <memory>

class Entity {
    public:
        uint16_t x, y;
        Chunk *in_chunk;

        Entity();
        void move(uint16_t move_x, uint16_t move_y);
        void teleport(uint16_t to_x, uint16_t to_y);
        void changed();
};