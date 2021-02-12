#include "helper.hpp"
#include "helper/includes.hpp"
#include "helper/color.hpp"

const std::vector<uint8_t> grassSprites = {39, 45, 44, 255};

uint16_t getNum(uint8_t sprite, uint8_t color) {
    return ((0x00 | color) << 8) | sprite;
}

uint16_t getGrass() {
    return getNum(grassSprites[rand() % grassSprites.size()], 12);
}