#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "world/world.hpp"

#include "helper/includes.hpp"
#include "helper/math.hpp"
#include "systems/systemManager.hpp"

int main() {
    // SystemManager sys;
    // sys.start();

    World world(5, 5);
    Chunk &c = world.bufferChunk(3,3);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Ludwig World", sf::Style::Default);

    TextureManager txm;
    txm.loadTexture(1, "../tileset/DawnLike/Characters/Humanoid0.png", getSpriteAt(0,6));
    txm.loadTexture("Demon", "../tileset/DawnLike/Characters/Demon0.png", getSpriteAt(0,0));


    while (window.isOpen()) {

        sf::Event Event{};
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));

        c.tiles[25][2][2] = 1;

        for (int i = 0; i < 32; i++) {
            for (int b = 0; b < 32; b++) {
                uint8_t t = c.tiles[25][i][b];

                if (t == 0) {
                    sf::Sprite s(txm.getRef("Human"));
                    s.setPosition(16 * i, 16 * b);
                    window.draw(s);
                } else if (t == 1) {
                    sf::Sprite s(txm.getRef("Demon"));
                    s.setPosition(16 * i, 16 * b);
                    window.draw(s);
                }
            }
        }

        window.display();

    }
    
    return 0;
}