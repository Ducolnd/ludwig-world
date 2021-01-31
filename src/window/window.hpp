#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>

class Window {
    public:
        Window(uint16_t x_size, uint16_t y_size, std::string title);
        
        void start();
};