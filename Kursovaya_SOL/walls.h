#pragma once
#include <SFML/Graphics.hpp>
#include "living_beings.h"
using namespace sf;

class walls
{
public:
	walls();
	RectangleShape bound;
	int w, h;
	int x, y;
	void setWH(int W, int H);
	void limitation(RenderWindow& window, int x, int y);

	bool stop1(int user_x, int user_y);
	bool stop2(int user_x, int user_y);
	bool stop3(int user_x, int user_y);
	bool stop4(int user_x, int user_y);
};

