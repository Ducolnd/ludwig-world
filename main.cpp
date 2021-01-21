#include "includes.hpp"

void print_map(Map map) {
    for (int x = 0; x < CHUNKSIZE; x++) {
        for (int y = 0; y < CHUNKSIZE; y++) {
            if (map.chunks[0][0].tiles[x][y].players.size() > 0) {
                std::cout << "x" << " ";
            } 
            else {
                std::cout << "-" << " ";
            }  
        }
        std::cout << std::endl;
    }
}


int main() {

    Map map;
    Player player1("Duco");
    Player player2("Jelmer");

    map.placePlayer(player1);
    map.placePlayer(player2, 10, 13);

    print_map(map);

    player1.teleport(8, 6);

    map.updateChunks();

    print_map(map);
}