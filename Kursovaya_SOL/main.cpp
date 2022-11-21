#include <SFML/Graphics.hpp>
#include "game.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1366, 768), "Essence");

    Event Mouse_click_start{};

    Image back_;
    back_.loadFromFile("images\\back.png");

    Texture back;
    back.loadFromImage(back_);

    Sprite background;
    background.setTexture(back);
    background.setPosition(0, 0);
    
    RectangleShape start_button(Vector2f(170, 30));
    start_button.setOrigin(Vector2f(21, -2));
    start_button.setPosition(1010, 360);
    start_button.setFillColor(Color::White);

    Text start_button_caption;
    Font mainFont;

    mainFont.loadFromFile("fonts\\arialmt.ttf");
    start_button_caption.setFont(mainFont);
    start_button_caption.setString("Load game");
    start_button_caption.setFillColor(Color(188, 110, 194));
    start_button_caption.setScale(0.8,0.8);
    start_button_caption.setPosition(start_button.getPosition());
    
    /*
    Image boy_proba;
    boy_proba.loadFromFile("images\\Boy_Proba.png");

    Texture boy_texture;
    boy_texture.loadFromImage(boy_proba);

    Sprite boy_sprite;
    boy_sprite.setTexture(boy_texture);
    boy_sprite.setPosition(50,25);
    */

    while (window.isOpen())
    {
        Event event;
        int num = 0;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(start_button);
        //window.draw(boy_sprite);
        window.draw(start_button_caption);
        window.display(); 

    }

    return 0;
}