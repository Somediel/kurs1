#pragma once
#include "interior.h"
#include <SFML/Graphics.hpp>
#include "living_beings.h"

using namespace sf;

class items_interior
{
public:
	int boost_number = 0;
	bool flag;
	Texture view;
	Sprite sprite;
	float anim_timer = 0, current_frame = 0;
	Clock clock;
	float time = clock.getElapsedTime().asSeconds();
	interior walking_limit;
	int use_zoneW, use_zoneH, use_zoneX, use_zoneY;
	items_interior();
	virtual void setUse_Zone();
	bool Check_Zone(int x, int y);
	//void changing_day_night();
	
	virtual void doThings() {  }
};

class seats : public items_interior
{
public:
	seats();

	int k;
	int count_Draw = 0;
	virtual void doThings();
	void setUse_Zone();
};

class bed : public items_interior
{
public:
	bed();
	int sleep = 0;
	virtual void doThings();
	
};

class sink_bath : public items_interior
{
public:
	sink_bath();
	int count_Draw = 0;
	int hygiene = 0;
	virtual void doThings();
};

class sink_kitch : public items_interior
{
public:
	sink_kitch();
	int count_Draw = 0;
	int hygiene = 0;
	virtual void doThings();
};

class bath : public items_interior
{
public:
	bath();
	int count_Draw = 0;
	int hygiene = 0;
	virtual void doThings();
	void setUse_Zone();
};

class computer : public items_interior
{
public:
	computer();
	int count_Draw = 0;
	int playful = 0;
	virtual void doThings();
};

class tv : public items_interior
{
public:
	tv();
	int count_Draw = 0;
	int playful = 0;
	virtual void doThings();
};

class bookshelf : public items_interior
{
public:
	bookshelf();
	int count_Draw = 0;
	int playful = 0;
	virtual void doThings();
	void setUse_Zone();
};

class fridge : public items_interior
{
public:
	fridge();
	int fullness = 0;
	virtual void doThings();
	int count_Draw = 0;
	void setUse_Zone();
};

class left_chair : public items_interior
{
public:
	left_chair();
	int fullness = 0;
	virtual void doThings();
	int count_Draw = 0;
	void setUse_Zone();
};

class right_chair : public items_interior
{
public:
	right_chair();
	int fullness = 0;
	virtual void doThings();
	int count_Draw = 0;
	void setUse_Zone();
};

class stove : public items_interior
{
public:
	stove();
	virtual void doThings();
	int count_Draw = 0;
	void setUse_Zone();
};

class toilet : public items_interior
{
public:
	toilet();
	int need = 0;
	virtual void doThings();
};
