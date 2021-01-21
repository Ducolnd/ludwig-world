#include "entities.hpp"
#include "../includes.hpp"


Player::Player(std::string player_name) {
    health = 100;
    armour = 100;
    stamina = 100;
    hunger = 0;

    name = player_name;
}

Enemy::Enemy(std::string enemy_name, Enemies enemytype) {
    type = enemytype;
    name = enemy_name;

}

Item::Item(std::string itemname, Itemtype itemtype) {
    name = itemname;
    type = itemtype;
}
