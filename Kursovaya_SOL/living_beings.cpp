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


void living_beings::Moving(RenderWindow& window, Sprite flat, Sprite display)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
	{
		// x -= 0.5
		right = 0, up = 0, down = 0;
		IntRect bound_figure(700, 300, 55, 133);
		this->sprite.move(-1, 0);
		this->x -= 1;
		//this->sprite.setTextureRect(bound_figure);
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
