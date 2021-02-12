#pragma once

#include "block.hpp"

extern std::vector<Block> blocks; // Will be filled with block objects

Block &getBlock(BlockId id);
void initBlocks();