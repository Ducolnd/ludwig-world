#pragma once

#include <iostream>
#include <string>

#include "types.hpp"
#include "entity.hpp"


class Player : public Entity {
    public:
        int health, armour, stamina, hunger;
        std::string name;

        Player(std::string player_name, Game &game);
        void move(uint16_t move_x, uint16_t move_y);
        void teleport(uint16_t to_x, uint16_t to_y);
};

class Enemy : public Entity {
    public:
        int health, armour, stamina;
        std::string name;
        Enemies type;

        Enemy(std::string enemy_name, Enemies enemytype, Game &game);
};

class Item {
    public:
        std::string name;
        Itemtype type;

        Item(std::string itemname, Itemtype itemtype);
};