#pragma once

#include "stdint.h"

namespace blocks {
    enum blocks : uint16_t {
        air = 0,
        stone = 1,
        dirt = 2, 
        grass = 3,
        log = 4,
        leaves = 5,
        sulfur_ore = 6,
        wood = 7,
        glass = 8,
        stone_wall = 9,
    };

    enum entities : uint16_t {
        player = 256,
    };
}