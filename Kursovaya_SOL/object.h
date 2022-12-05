#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
class object
{
public:


	object();

protected:

	sf::Texture view;
	void SetView(sf::Texture texture);
	sf::Texture GetView();
	sf::Sprite sprite;
	void SetSprite(sf::Sprite spr);
	sf::Sprite GetSprite();

	int x, y;
	void SetX(int valueX);
	int GetX();
	void SetY(int valueY);
	int GetY();

	int width, height;
	void SetWidth(int valueWidth);
	int GetWidth();
	void SetHeight(int valueHeight);
	int GetHeight();
};

