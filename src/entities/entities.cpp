#include "entities.hpp"
#include "../includes.hpp"


Player::Player(std::string player_name, Game &game) : Entity(game) {
    health = 100;
    armour = 100;
    stamina = 100;
    hunger = 0;

    previous_y = 0;
    previous_x = 0;

    name = player_name;
}

void Player::move(int16_t move_x, int16_t move_y) {
    previous_x = x;
    previous_y = y;

    x += move_x;
    y += move_y;

    game_container->notifyChanged(this);
}

void Player::teleport(uint16_t to_x, uint16_t to_y) {   
    previous_x = x;
    previous_y = y;
    
    x = to_x;
    y = to_y;

    game_container->notifyChanged(this);
}







Enemy::Enemy(std::string enemy_name, Enemies enemytype, Game &game) : Entity(game) {
    type = enemytype;
    name = enemy_name;

    //game.notifyChanged(*this);
}

Item::Item(std::string itemname, Itemtype itemtype) {
    name = itemname;
    type = itemtype;
}
