#include "blockList.hpp"
#include "block.hpp"

std::vector<Block> blocks(256, Block(BlockId::air));

Block &getBlock(uint16_t id) {
    return blocks[static_cast<BlockId>(id)];
}

void initBlocks() {
    Block air = Block(BlockId::air);
    air.passable = true;
    blocks[BlockId::air] = air;

    Block grass = Block(BlockId::grass);
    grass.sprite = Font(39, sf::Color(0, 153, 0));
    grass.solid = false;
    blocks[BlockId::grass] = grass;

    Block high_grass = Block(BlockId::high_grass);
    high_grass.sprite = Font(34, sf::Color(0, 40, 0));
    high_grass.solid = false;
    blocks[BlockId::high_grass] = high_grass;

    Block stone = Block(BlockId::stone);
    stone.sprite = Font(178, sf::Color(125, 125, 125));
    stone.solid = true;
    stone.passable = false;
    blocks[BlockId::stone] = stone;

    Block dirt = Block(BlockId::dirt);
    dirt.sprite = Font(178, sf::Color(151, 83, 38));
    dirt.solid = true;
    dirt.passable = false;
    blocks[BlockId::dirt] = dirt;

    Block tree_bark = Block(BlockId::tree_bark);
    tree_bark.sprite = Font(178, sf::Color(92, 48, 18));
    tree_bark.solid = true;
    tree_bark.passable = false;
    blocks[BlockId::tree_bark] = tree_bark;
}