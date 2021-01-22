#include "./includes.hpp"


int main() {

    Game game;
    Player player1("Duco", game);
    Player player2("Jelmer", game);

    game.map.placePlayer(player1);
    game.map.placePlayer(player2, 10, 13);

    game.displayMap();

    player1.teleport(8, 6);

    game.displayMap();
}