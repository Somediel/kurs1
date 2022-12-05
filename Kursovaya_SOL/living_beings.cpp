#include "living_beings.h"


living_beings::living_beings()
{
	//std::cin >> name;
	//std::cin >> gender;//переписать через выбор пола на кнопочку

	this->view.loadFromFile("images\\girl_1.png");
	this->sprite.setTexture(this->view);
	this->x = 700;
	this->y = 300;
	this->sprite.setPosition(x, y);
}

void living_beings::SetRelationshipStatusBar(int scale_rs)
{
	this -> relationship = scale_rs;
}

int living_beings::GetRelationshipStatusBar()
{
	return this -> relationship;
}

void living_beings::SetFullness(int full)
{
	this->fullness = full;
}

int living_beings::GetFullness()
{
	return this->fullness;
}

void living_beings::SetEnergy(int energy_sleep)
{
	this->energy = energy_sleep;
}

int living_beings::GetEnergy()
{
	return this->energy;
}

void living_beings::SetNeed(int needness)
{
	this->need = needness;
}

int living_beings::GetNeed()
{
	return this->need;
}

void living_beings::SetHygiene(int hyg)
{
	this->hygiene = hyg;
}

int living_beings::GetHygiene()
{
	return this->hygiene;
}

void living_beings::SetPlayful(int playfullness)
{
	this->playful = playfullness;
}

int living_beings::GetPlayful()
{
	return this->playful;
}


void living_beings::Moving(RenderWindow& window)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		right = 0, up = 0, down = 0;
		IntRect bound_figure(700, 300, 55, 133);
		this->sprite.move(-0.05, 0);
		this->x -= 0.05;
		//this->sprite.setTextureRect(bound_figure);
		switch (left % 3200)
		{
		case 0:
			this->view.loadFromFile("images\\wbl1.png");
			break;
		case 800:
			this->view.loadFromFile("images\\sbl.png");
			break;
		case 1600:
			this->view.loadFromFile("images\\wbl2.png");
			break;
		case 2400:
			this->view.loadFromFile("images\\sbl.png");
			break;
		}
		left++;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		left = 0, up = 0, down = 0;
		this->sprite.move(0.05, 0);
		this->x += 0.05;
		switch (right % 3200)
		{
		case 0:
			this->view.loadFromFile("images\\wbr1.png");
			break;
		case 800:
			this->view.loadFromFile("images\\sbr.png");
			break;
		case 1600:
			this->view.loadFromFile("images\\wbr2.png");
			break;
		case 2400:
			this->view.loadFromFile("images\\sbr.png");
			break;
		}
		right++;

	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		left = 0, right = 0, down = 0;
		this->sprite.move(0, -0.05);
		this->y += 0.05;
		switch (up % 3200)
		{
		case 0:
			this->view.loadFromFile("images\\zw1.png");
			break;
		case 800:
			this->view.loadFromFile("images\\zs.png");
			break;
		case 1600:
			this->view.loadFromFile("images\\zw2.png");
			break;
		case 2400:
			this->view.loadFromFile("images\\zs.png");
			break;
		}
		up++;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		left = 0, right = 0, up = 0;
		this->sprite.move(0, 0.05);
		this->y -= 0.05;
		switch (down % 3200)
		{
		case 0:
			this->view.loadFromFile("images\\fs1.png");
			break;
		case 800:
			this->view.loadFromFile("images\\fs.png");
			break;
		case 1600:
			this->view.loadFromFile("images\\fs2.png");
			break;
		case 2400:
			this->view.loadFromFile("images\\fs.png");
			break;
		}
		down++;
	}
	window.draw(this->sprite);
}
