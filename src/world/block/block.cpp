#include "block.hpp"

Block::Block(BlockId _id) {
    id = _id;

    // Default init
    sprite = Font(0, sf::Color::White); // Not visible
    passable = true;
    solid = false;
}