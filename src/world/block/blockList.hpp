#pragma once

#include "block.hpp"

extern std::vector<Block> blocks; // Will be filled with block objects

Block &getBlock(uint16_t id);
void initBlocks();