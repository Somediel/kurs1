#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1366, 768), "Essence");

    menu(window);

    return 0;
}