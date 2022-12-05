#include <SFML/Graphics.hpp>
#include "game.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1366, 768), "Essence");
    menu(window);

    return 0;
}