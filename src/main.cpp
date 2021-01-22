#include "./includes.hpp"

template<typename T>
void print(T what) {
    std::cout << what << std::endl;
}

int main() {

    Game game;
    Player player1("Duco", game);
    Player player2("Jelmer", game);

    game.map.placePlayer(&player1);
    game.map.placePlayer(&player2, 10, 13);

    int i = 0;
    while(i < 5) {
        system("clear");
        game.displayMap();

        player1.move(1,0);

        sleep(1);


        i++;
    }

    // std::cout << std::endl;
}