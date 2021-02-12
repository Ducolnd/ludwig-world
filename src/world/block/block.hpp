#pragma once

#include "helper/font.hpp"

// Block are stored by BlockId and loaded by this id
enum BlockId : uint16_t { // Max 2^16 block types
    air = 0,
    grass = 1, 
    stone = 2, 
    dirt = 3,
    tree_bark = 4,
    high_grass = 5,
};

// Data holder
struct Block {
    Block(BlockId _id);

    BlockId id;
    
    Font sprite;
    bool passable;
    bool solid; // Can walk through
};