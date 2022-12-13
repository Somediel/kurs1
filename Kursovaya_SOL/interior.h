#pragma once
#include "object.h"
using namespace sf;

class interior : public object
{
public:
	interior();
	RectangleShape limit_obj;
	int w, h;
	int x, y;
	void setWH(int W, int H);
	void limitation_obj(RenderWindow& window, int x, int y);

	bool stop1_obj(int user_x, int user_y);
	bool stop2_obj(int user_x, int user_y);
	bool stop3_obj(int user_x, int user_y);
	bool stop4_obj(int user_x, int user_y);
};


