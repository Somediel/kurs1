#include "living_beings.h"


living_beings::living_beings()
{
	// name;
	//std::cin >> gender;//переписать через выбор пола на кнопочку

	this->view.loadFromFile("images\\girl_1.png");
	this->sprite.setTexture(this->view);
	this->x = 700;
	this->y = 300;
	this->sprite.setPosition(x, y);
	this->energy = 100000;
	this->hygiene = 100000;
	this->playful = 100000;
	this->fullness = 100000;
	this->need = 100000;
}

void living_beings::SetFullness(float full)
{
	this->fullness = full;
}

float living_beings::GetFullness()
{
	return this->fullness;
}

void living_beings::SetEnergy(float energy_sleep)
{
	this->energy = energy_sleep;
}

float living_beings::GetEnergy()
{
	return this->energy;
}

void living_beings::SetNeed(float needness)
{
	this->need = needness;
}

float living_beings::GetNeed()
{
	return this->need;
}

void living_beings::SetHygiene(float hyg)
{
	this->hygiene = hyg;
}

float living_beings::GetHygiene()
{
	return this->hygiene;
}

void living_beings::SetPlayful(float playfullness)
{
	this->playful = playfullness;
}

float living_beings::GetPlayful()
{
	return this->playful;
}


void living_beings::Moving(RenderWindow& window, Sprite flat, Sprite display)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
	{
		// x -= 0.5
		right = 0, up = 0, down = 0;
		this->sprite.move(-1, 0);
		this->x -= 1;
		switch (left % 320)
		{
		case 0:
			this->view.loadFromFile("images\\wbl1.png");
			break;
		case 80:
			this->view.loadFromFile("images\\sbl.png");
			break;
		case 160:
			this->view.loadFromFile("images\\wbl2.png");
			break;
		case 240:
			this->view.loadFromFile("images\\sbl.png");
			break;
		}
		left++;
	}
	if((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
		// x += 0.5
		left = 0, up = 0, down = 0;
		this->sprite.move(1, 0);
		this->x += 1;
		switch (right % 320)
		{
		case 0:
			this->view.loadFromFile("images\\wbr1.png");
			break;
		case 80:
			this->view.loadFromFile("images\\sbr.png");
			break;
		case 160:
			this->view.loadFromFile("images\\wbr2.png");
			break;
		case 240:
			this->view.loadFromFile("images\\sbr.png");
			break;
		}
		right++;

	}
	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
	{
			// y -= 0.5
			this->sprite.move(0, -1);
			this->y -= 1;
			switch (up % 320)
			{
			case 0:
				this->view.loadFromFile("images\\zw1.png");
				break;
			case 80:
				this->view.loadFromFile("images\\zs.png");
				break;
			case 160:
				this->view.loadFromFile("images\\zw2.png");
				break;
			case 240:
				this->view.loadFromFile("images\\zs.png");
				break;
			}
			up++;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
	{
		// y += 0.5
		left = 0, right = 0, up = 0;
		this->sprite.move(0, 1);
		this->y += 1;
		switch (down % 320)
		{
		case 0:
			this->view.loadFromFile("images\\fs1.png");
			break;
		case 80:
			this->view.loadFromFile("images\\fs.png");
			break;
		case 160:
			this->view.loadFromFile("images\\fs2.png");
			break;
		case 240:
			this->view.loadFromFile("images\\fs.png");
			break;
		}
		down++;
	}
	window.draw(this->sprite);
}
