#include "walls.h"

walls::walls()
{
	this->bound.setFillColor(Color::Blue);
}

void walls::limitation( RenderWindow& window, int X,int Y)
{
	this->bound.setPosition(X, Y);
	x = X;
	y = Y;
	//window.draw(bound);
}

void walls::setWH(int W, int H)
{
	bound.setSize(sf::Vector2f(W, H));
	w = W;
	h = H;
}

bool walls::stop1(int user_x, int user_y)
{
	if (user_x + 55.5 >= x && user_x <= x + w && (user_y + 133 >= y && user_y + 133 <= y + h || user_y + 100 >= y && user_y + 100 <= y + h) && ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))))
	{
		return true;
	}
	else
		return false;
}

bool walls::stop2(int user_x, int user_y)
{
	if (user_x - 0.5 <= x + w && user_x >= x && (user_y + 133 >= y && user_y + 133 <= y + h || user_y + 100 >= y && user_y + 100 <= y + h) && ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))))
	{
		return true;
	}
	else
		return false;
}

bool walls::stop3(int user_x, int user_y)
{
	if (user_y + 99.5 <= y + h && user_y + 133 >= y && (user_x + 55 >= x && user_x + 55 <= x + w || user_x >= x && user_x <= x + w || user_x <= x && user_x >= x + w) && ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))))
	{
		return true;
	}
	else
		return false;
}


bool walls::stop4(int user_x, int user_y)
{
	if (user_y + 133.5 >= y && user_y + 100 <= y && (user_x + 55 >= x && user_x + 55 <= x + w || user_x >= x && user_x <= x + w || user_x <= x && user_x >= x + w) && ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))))
	{
		return true;
	}
	else
		return false;
}



