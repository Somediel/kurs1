#include "interior.h"

interior::interior()
{
	this->limit_obj.setFillColor(Color::Red);
}

void interior::limitation_obj(RenderWindow& window, int X, int Y)
{
	this->limit_obj.setPosition(X, Y);
	x = X;
	y = Y;
	//window.draw(limit_obj);
}

void interior::setWH(int W, int H)
{
	limit_obj.setSize(sf::Vector2f(W, H));
	w = W;
	h = H;
}

bool interior::stop1_obj(int user_x, int user_y)
{
	if (user_x + 55.5 >= x && user_x <= x + w && (user_y + 133 >= y && user_y + 133 <= y + h || user_y + 100 >= y && user_y + 100 <= y + h) && ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))))
	{
		return true;
	}
	else
		return false;
}

bool interior::stop2_obj(int user_x, int user_y)
{
	if (user_x - 0.5 <= x + w && user_x >= x && (user_y + 133 >= y && user_y + 133 <= y + h || user_y + 100 >= y && user_y + 100 <= y + h) && ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))))
	{
		return true;
	}
	else
		return false;
}

bool interior::stop3_obj(int user_x, int user_y)
{
	if (user_y + 99.5 <= y + h && user_y + 133 >= y && (user_x + 55 >= x && user_x + 55 <= x + w || user_x >= x && user_x <= x + w || user_x <= x && user_x >= x + w) && ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))))
	{
		return true;
	}
	else
		return false;
}


bool interior::stop4_obj(int user_x, int user_y)
{
	if (user_y + 133.5 >= y && user_y + 100 <= y && (user_x + 55 >= x && user_x + 55 <= x + w || user_x >= x && user_x <= x + w || user_x <= x && user_x >= x + w) && ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))))
	{
		return true;
	}
	else
		return false;
}
