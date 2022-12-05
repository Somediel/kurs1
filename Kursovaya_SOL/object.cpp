#include "object.h"

object::object()
{
}
void object::SetSprite(sf::Sprite spr)
{
	this -> sprite = spr;
}

sf::Sprite object::GetSprite()
{
	return this->sprite;
}

void object::SetView(sf::Texture texture)
{
	this -> view = texture;
}

sf::Texture object::GetView()
{
	return this->view;
}

void object::SetX(int valueX)
{
	this->x = valueX;
}

int object::GetX()
{
	return this -> x;
}

void object::SetY(int valueY)
{
	this->y = valueY;
}

int object::GetY()
{
	return this->y;
}

void object::SetWidth(int valueWidth)
{
	this->width = valueWidth;
}

int object::GetWidth()
{
	return this->width;
}

void object::SetHeight(int valueHeight)
{
	this->height = valueHeight;
}

int object::GetHeight()
{
	return this->height;
}
