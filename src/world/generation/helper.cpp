#include "helper.hpp"
#include "helper/includes.hpp"
#include "world/block/block.hpp"

const std::vector<uint16_t> grasses = {1, 5};

BlockId getGrass() {
    return static_cast<BlockId>(grasses[rand() % grasses.size()]);
}