#include "helper/includes.hpp"
#include "systems/systemManager.hpp"
#include "world/block/blockList.hpp"

int main() {
    // World game(400, 400);

    initBlocks();

    SystemManager sys;
    sys.start();

    return 0;
}