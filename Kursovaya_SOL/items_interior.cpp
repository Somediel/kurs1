#include "items_interior.h"

items_interior::items_interior()
{
	this->flag = false;
}

seats::seats() : items_interior()
{
	this->flag = false;
}

void seats::doThings()
{
	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		this->count_Draw--;
	}
	if (Keyboard::isKeyPressed(Keyboard::E)) {
		this->count_Draw++;
	}
	switch (this->k)
	{
	case 1:
		this->view.loadFromFile("images\\hall_armchair.png");
		this->sprite.setTexture(this->view);
		this->sprite.setPosition(this->walking_limit.x - 3, this->walking_limit.y - 40);
		break;

	case 2:
		this->view.loadFromFile("images\\hall_chair_left.png");
		this->sprite.setTexture(this->view);
		this->sprite.setPosition(this->walking_limit.x - 4, this->walking_limit.y - 58);
		break;

	case 3:
		this->view.loadFromFile("images\\hall_chair_right.png");
		this->sprite.setTexture(this->view);
		this->sprite.setPosition(this->walking_limit.x - 3, this->walking_limit.y - 49);
		break;

	case 4:
		this->view.loadFromFile("images\\balcony_sit_back.png");
		this->sprite.setTexture(this->view);
		this->sprite.setPosition(this->walking_limit.x - 8, this->walking_limit.y - 227);
		break;

	case 5:
		this->view.loadFromFile("images\\balcony_sit_side.png");
		this->sprite.setTexture(this->view);
		this->sprite.setPosition(this->walking_limit.x - 8, this->walking_limit.y - 81);
		break;

	case 6:
		switch (this->count_Draw / 100 % 3)
		{
		case 0:
			this->view.loadFromFile("images\\balcony_sit_sofa.png");
			this->sprite.setTexture(this->view);
			this->sprite.setPosition(this->walking_limit.x - 10, this->walking_limit.y - 27);
			break;

		case 1:
			this->view.loadFromFile("images\\balcony_sit_sofa2.png");
			this->sprite.setTexture(this->view);
			this->sprite.setPosition(this->walking_limit.x - 10, this->walking_limit.y - 27);
			break;

		case 2:
			this->view.loadFromFile("images\\balcony_sit_sofa3.png");
			this->sprite.setTexture(this->view);
			this->sprite.setPosition(this->walking_limit.x - 10, this->walking_limit.y - 27);
			break;
		}
	}
	;
}

bed::bed() : items_interior()
{
	boost_number = 1;
	this->flag = false;
}

void bed::doThings()
{
		this->view.loadFromFile("images\\hall_bed.png");
		this->sprite.setTexture(this->view);
		this->sprite.setPosition(this->walking_limit.x - 9, this->walking_limit.y - 80);
}

sink_bath::sink_bath() : items_interior()
{
	boost_number = 2;
	this->flag = false;
}

void sink_bath::doThings()
{
	
	switch (this->count_Draw / 33 % 3) {
	case 0:
			this->view.loadFromFile("images\\bathroom_sink.png");
			break;
	case 1:
			this->view.loadFromFile("images\\bathroom_sink2.png");
			break;
	case 2:
			this->view.loadFromFile("images\\bathroom_sink3.png");
			break;
	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x +5, this->walking_limit.y - 45);
}

sink_kitch::sink_kitch() : items_interior()
{
	boost_number = 2;
	this->flag = false;
}

void sink_kitch::doThings()
{

	switch (this->count_Draw / 20 % 5) {
	case 0:
		this->view.loadFromFile("images\\kitchen_sink.png");
		break;

	case 1:
		this->view.loadFromFile("images\\kitchen_sink2.png");
		break;

	case 2:
		this->view.loadFromFile("images\\kitchen_sink3.png");
		break;

	case 3:
		this->view.loadFromFile("images\\kitchen_sink4.png");
		break;

	case 4:
		this->view.loadFromFile("images\\kitchen_sink5.png");
		break;
	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x - 2, this->walking_limit.y - 42);
}

bath::bath() : items_interior()
{
	boost_number = 2;
	this->flag = false;
};

void bath::doThings()
{

	switch (this->count_Draw / 33 % 3) {
	case 0:
		this->view.loadFromFile("images\\bath_bathroom.png");
		break;

	case 1:
		this->view.loadFromFile("images\\bath_bathroom2.png");
		break;

	case 2:
		this->view.loadFromFile("images\\bath_bathroom3.png");
		break;
	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x + 12, this->walking_limit.y- 14);
};


void bath::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 100;
	this->use_zoneH = this->walking_limit.h;
	this->use_zoneX = this->walking_limit.x;
	this->use_zoneY = this->walking_limit.y;
}

computer::computer() : items_interior()
{
	boost_number = 3;
	this->flag = false;
}

void computer::doThings()
{

	switch (this->count_Draw / 33 % 3) {
	case 0:
		this->view.loadFromFile("images\\hall_laptop_off.png");
		break;
	case 1:
		this->view.loadFromFile("images\\hall_laptop_on.png");
		break;
	case 2:
		this->view.loadFromFile("images\\hall_laptop_on2.png");
		break;
	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x - 57, this->walking_limit.y + 5);
};

tv::tv() : items_interior()
{
	boost_number = 3;
	this->flag = false;
}

void tv::doThings()
{

	switch (this->count_Draw / 33 % 2) 
	{
	case 0:
		this->view.loadFromFile("images\\hall_tv.png");
		break;

	case 1:
		this->view.loadFromFile("images\\hall_tv2.png");
		break;
	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x - 3 , this->walking_limit.y - 30);
}

bookshelf::bookshelf() : items_interior()
{
	boost_number = 3;
	this->flag = false;
}

void bookshelf::doThings()
{

	switch (this->count_Draw / 33 % 3) {
	case 0:
		this->view.loadFromFile("images\\hall_book.png");
		break;
	case 1:
		this->view.loadFromFile("images\\hall_book2.png");
		break;
	case 2:
		this->view.loadFromFile("images\\hall_book3.png");
		break;
	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x, this->walking_limit.y - 139);
};


toilet::toilet() : items_interior()
{
	boost_number = 5;
	this->flag = false;
}

void toilet::doThings()
{
	this->view.loadFromFile("images\\bathroom_toilet.png");
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x + 3, this->walking_limit.y - 25);
}

fridge::fridge() : items_interior()
{
	boost_number = 4;
	this->flag = false;
}

void fridge::doThings()
{
	switch (this->count_Draw / 33 % 3) {
	case 0:
		this->view.loadFromFile("images\\kitchen_fridge.png");
		break;

	case 1:
		this->view.loadFromFile("images\\kitchen_fridge2.png");
		break;

	case 2:
		this->view.loadFromFile("images\\kitchen_fridge3.png");
		break;

	case 3:
		this->view.loadFromFile("images\\kitchen_fridge4.png");
		break;

	case 4:
		this->view.loadFromFile("images\\kitchen_fridge5.png");
		break;

	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x - 2, this->walking_limit.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

left_chair::left_chair() : items_interior()
{
	boost_number = 4;
	this->flag = false;
}

void left_chair::doThings()
{
	switch (this->count_Draw / 30 % 9) 
	{
	case 0:
		this->view.loadFromFile("images\\kitchen_eat_side.png");
		break;

	case 1:
		this->view.loadFromFile("images\\kitchen_eat_side2.png");
		break;

	case 2:
		this->view.loadFromFile("images\\kitchen_eat_side3.png");
		break;

	case 3:
		this->view.loadFromFile("images\\kitchen_eat_side4.png");
		break;

	case 4:
		this->view.loadFromFile("images\\kitchen_eat_side5.png");
		break;

	case 5:
		this->view.loadFromFile("images\\kitchen_eat_side6.png");
		break;

	case 6:
		this->view.loadFromFile("images\\kitchen_eat_side7.png");
		break;

	case 7:
		this->view.loadFromFile("images\\kitchen_eat_side8.png");
		break;

	case 8:
		this->view.loadFromFile("images\\kitchen_eat_side9.png");
		break;
	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x - 5, this->walking_limit.y - 62);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

right_chair::right_chair() : items_interior()
{
	boost_number = 4;
	this->flag = false;
}

void right_chair::doThings()
{
	switch (this->count_Draw / 60 % 2)
	{
	case 0:
		this->view.loadFromFile("images\\kitchen_eat_back.png");
		break;

	case 1:
		this->view.loadFromFile("images\\kitchen_eat_back2.png");
		break;

	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x - 27, this->walking_limit.y - 214);
}

stove::stove() : items_interior()
{
	this->flag = false;
}

void stove::doThings()
{
	switch (this->count_Draw / 60 % 2)
	{
	case 0:
		this->view.loadFromFile("images\\kitchen_cooking.png");
		break;

	case 1:
		this->view.loadFromFile("images\\kitchen_cooking2.png");
		break;

	}
	this->count_Draw++;
	this->sprite.setTexture(this->view);
	this->sprite.setPosition(this->walking_limit.x - 4, this->walking_limit.y - 1);
}

void items_interior::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 50;
	this->use_zoneH = this->walking_limit.h + 50;
	this->use_zoneX = this->walking_limit.x - 25;
	this->use_zoneY = this->walking_limit.y - 25;
}

bool items_interior::Check_Zone(int x, int y)
{
	if ((x > this->use_zoneX && x < this->use_zoneX + this->use_zoneW) && (y > this->use_zoneY && y < this->use_zoneY + this->use_zoneH)) {
		return true;
	}
	return false;
	
}

void left_chair::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 150;
	this->use_zoneH = this->walking_limit.h + 150;
	this->use_zoneX = this->walking_limit.x;
	this->use_zoneY = this->walking_limit.y - 100;
}

void right_chair::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 120;
	this->use_zoneH = this->walking_limit.h + 120;
	this->use_zoneX = this->walking_limit.x + 50;
	this->use_zoneY = this->walking_limit.y - 50;
}

void fridge::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 100;
	this->use_zoneH = this->walking_limit.h + 100;
	this->use_zoneX = this->walking_limit.x - 20;
	this->use_zoneY = this->walking_limit.y - 20;
}

void stove::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 50;
	this->use_zoneH = this->walking_limit.h + 50;
	this->use_zoneX = this->walking_limit.x - 25;
	this->use_zoneY = this->walking_limit.y - 25;
}

void seats::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 100;
	this->use_zoneH = this->walking_limit.h + 100;
	this->use_zoneX = this->walking_limit.x - 50;
	this->use_zoneY = this->walking_limit.y - 50;
}

void bookshelf::setUse_Zone()
{
	this->use_zoneW = this->walking_limit.w + 100;
	this->use_zoneH = this->walking_limit.h + 100;
	this->use_zoneX = this->walking_limit.x - 50;
	this->use_zoneY = this->walking_limit.y - 50;
}