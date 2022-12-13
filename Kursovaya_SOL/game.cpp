#include "game.h"


void menu(RenderWindow& win)
{
	
	Text start_button_caption;
	Font mainFont;

	Texture menu_but1, /*menu_but2*/ menu_but3, bg_menu;

	menu_but1.loadFromFile("images\\b1.png");
	//menu_but2.loadFromFile("images\\b2.png");
	menu_but3.loadFromFile("images\\b3.png");
	bg_menu.loadFromFile("images\\back.png");

	Sprite new_game_button(menu_but1), /*load_game_button(menu_but2),*/ close_game_button(menu_but3), background_menu(bg_menu);

	bool isMenu = 1;
	int menuNum = 0;

	new_game_button.setPosition(1000, 110);
	//load_game_button.setPosition(1000, 160);
	close_game_button.setPosition(1000, 210);
	mainFont.loadFromFile("fonts\\arialmt.ttf");
	start_button_caption.setFont(mainFont);
	start_button_caption.setString("Start game");
	start_button_caption.setFillColor(Color(188, 110, 194));
	start_button_caption.setScale(0.8, 0.8);
	start_button_caption.setPosition(new_game_button.getPosition());

	while (win.isOpen())
	{
		new_game_button.setColor(Color::White);
		//load_game_button.setColor(Color::White);
		close_game_button.setColor(Color::White);
		menuNum = 0;
		if (IntRect(1000, 110, 170, 30).contains(Mouse::getPosition(win))) { new_game_button.setColor(Color(204,204,204)), menuNum = 1; }
		//if (IntRect(1000, 160, 170, 30).contains(Mouse::getPosition(win))) { load_game_button.setColor(Color(204, 204, 204)), menuNum = 2; }
		if (IntRect(1000, 210, 170, 30).contains(Mouse::getPosition(win))) { close_game_button.setColor(Color(204, 204, 204)), menuNum = 3; }

		sf::Event event;
		while (win.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				win.close();
		}


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				isMenu = false;
				win.clear();
				win.close();

				RenderWindow window1(VideoMode(1366, 768), "Essence");

				game(window1);
				break;
			}
			//if (menuNum == 2) win.draw;
			if (menuNum == 3) { win.close(); isMenu = false; };
		}

		win.clear();
		win.draw(background_menu);
		win.draw(new_game_button);
		//win.draw(load_game_button);
		win.draw(close_game_button);
		win.display();
	}

	
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void game(RenderWindow& job)
{
	Texture flat, display;

	flat.loadFromFile("images\\day.png");
	display.loadFromFile("images\\display.png");
	
	Sprite flat_texture(flat), display_texture(display);

	flat_texture.setPosition(0, 0);
	display_texture.setPosition(0, 0);

	living_beings girl_1;
	std::vector<walls> rectangles(10);
	rectangles[0].setWH(46, 252);
	rectangles[1].setWH(142, 384);
	rectangles[2].setWH(46, 416);
	rectangles[3].setWH(46, 416);
	rectangles[4].setWH(38, 264);
	rectangles[5].setWH(44, 270);

	rectangles[6].setWH(125, 36);
	rectangles[7].setWH(312, 36);
	rectangles[8].setWH(212, 36);
	rectangles[9].setWH(166, 40);

	std::vector<interior> limits(25);
	limits[0].setWH(224, 97);
	limits[1].setWH(55, 68);
	limits[2].setWH(79, 218);
	limits[3].setWH(64, 46);
	limits[4].setWH(123, 330);
	limits[5].setWH(104, 41);
	limits[6].setWH(54, 69);
	limits[7].setWH(40, 105);
	limits[8].setWH(53, 158);
	limits[9].setWH(204, 80);
	limits[10].setWH(266, 101); 
	limits[11].setWH(303, 106);
	limits[12].setWH(56, 69);
	limits[13].setWH(199, 109);
	limits[14].setWH(68, 85);
	limits[15].setWH(238, 156);
	limits[16].setWH(90, 67);
	limits[17].setWH(67, 70);
	limits[18].setWH(54, 368);
	limits[19].setWH(96, 87); 
	limits[20].setWH(49, 165);
	limits[21].setWH(95, 102);
	limits[22].setWH(59, 48);
	limits[23].setWH(59, 63);
	limits[24].setWH(112, 209);

	while (job.isOpen())
	{
		sf::Event event;
		while (job.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				job.close();

		}

		job.clear();
		job.draw(flat_texture);
		if ((girl_1.sprite.getPosition().y - 0.5 < 35) && (Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
		{
			flat_texture.move(0, 1);
			girl_1.sprite.move(0, 1);
			job.draw(girl_1.sprite);
		}
		else if ((girl_1.sprite.getPosition().y + 0.5 > 438) && (Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
		{
			flat_texture.move(0, -1);
			girl_1.sprite.move(0, -1);
			job.draw(girl_1.sprite);
		}

		if ((girl_1.sprite.getPosition().y - 0.5 < 50+flat_texture.getPosition().y ) && (Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
		{
			girl_1.sprite.move(0, 0.5);
			job.draw(girl_1.sprite);
		}
		else if ((girl_1.sprite.getPosition().y + 0.5 > 1150 + flat_texture.getPosition().y) && (Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
		{
			girl_1.sprite.move(0, -0.5);
			job.draw(girl_1.sprite);
		}
		else if ((girl_1.sprite.getPosition().x - 0.5 < 110) && (Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
		{
			girl_1.sprite.move(0.5, 0);
			job.draw(girl_1.sprite);

		}
		else if ((girl_1.sprite.getPosition().x + 0.5 > 1220) && (Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
		{
			girl_1.sprite.move(-0.5, 0);
			job.draw(girl_1.sprite);
		}
		else
		{
			girl_1.Moving(job, flat_texture, display_texture);
		}
		
		//вертикальные стены
		rectangles[0].limitation(job, 340 + flat_texture.getPosition().x, 100 + flat_texture.getPosition().y);
		rectangles[1].limitation(job, 907 + flat_texture.getPosition().x, 100 + flat_texture.getPosition().y);
		rectangles[2].limitation(job, 340 + flat_texture.getPosition().x, 412 + flat_texture.getPosition().y);
		rectangles[3].limitation(job, 340 + flat_texture.getPosition().x, 881 + flat_texture.getPosition().y);
		rectangles[4].limitation(job, 1010 + flat_texture.getPosition().x, 571 + flat_texture.getPosition().y);
		rectangles[5].limitation(job, 1010 + flat_texture.getPosition().x, 1024 + flat_texture.getPosition().y);

		//горизонтальные стены
		rectangles[6].limitation(job, 386 + flat_texture.getPosition().x, 571 + flat_texture.getPosition().y);
		rectangles[7].limitation(job, 710 + flat_texture.getPosition().x, 571 + flat_texture.getPosition().y);
		rectangles[8].limitation(job, 907 + flat_texture.getPosition().x, 475 + flat_texture.getPosition().y);
		rectangles[9].limitation(job, 1195 + flat_texture.getPosition().x, 475 + flat_texture.getPosition().y);

		limits[0].limitation_obj(job, 121 + flat_texture.getPosition().x, 93 + flat_texture.getPosition().y);
		limits[1].limitation_obj(job, 205 + flat_texture.getPosition().x, 585 + flat_texture.getPosition().y);
		limits[2].limitation_obj(job, 264 + flat_texture.getPosition().x, 507 + flat_texture.getPosition().y);
		limits[3].limitation_obj(job, 269 + flat_texture.getPosition().x, 732 + flat_texture.getPosition().y);
		limits[4].limitation_obj(job, 239 + flat_texture.getPosition().x, 928 + flat_texture.getPosition().y);
		limits[5].limitation_obj(job, 1068 + flat_texture.getPosition().x, 102 + flat_texture.getPosition().y);
		limits[6].limitation_obj(job, 1210 + flat_texture.getPosition().x, 90 + flat_texture.getPosition().y);
		limits[7].limitation_obj(job, 1240 + flat_texture.getPosition().x, 636 + flat_texture.getPosition().y);
		limits[8].limitation_obj(job, 1226 + flat_texture.getPosition().x, 999 + flat_texture.getPosition().y);
		limits[9].limitation_obj(job, 1064 + flat_texture.getPosition().x, 1200 + flat_texture.getPosition().y);
		limits[10].limitation_obj(job, 764 + flat_texture.getPosition().x, 1183 + flat_texture.getPosition().y);
		limits[11].limitation_obj(job, 415 + flat_texture.getPosition().x, 1178 + flat_texture.getPosition().y);
		limits[12].limitation_obj(job, 391 + flat_texture.getPosition().x, 1042 + flat_texture.getPosition().y);
		limits[13].limitation_obj(job, 461 + flat_texture.getPosition().x, 1022 + flat_texture.getPosition().y);
		limits[14].limitation_obj(job, 668 + flat_texture.getPosition().x, 1035 + flat_texture.getPosition().y);
		limits[15].limitation_obj(job, 785 + flat_texture.getPosition().x, 599 + flat_texture.getPosition().y);
		limits[16].limitation_obj(job, 686 + flat_texture.getPosition().x, 601 + flat_texture.getPosition().y);
		limits[17].limitation_obj(job, 787 + flat_texture.getPosition().x, 106 + flat_texture.getPosition().y);
		limits[18].limitation_obj(job, 853 + flat_texture.getPosition().x, 106 + flat_texture.getPosition().y);
		limits[19].limitation_obj(job, 635 + flat_texture.getPosition().x, 94 + flat_texture.getPosition().y);
		limits[20].limitation_obj(job, 391 + flat_texture.getPosition().x, 613 + flat_texture.getPosition().y);
		limits[21].limitation_obj(job, 378 + flat_texture.getPosition().x, 455 + flat_texture.getPosition().y);
		limits[22].limitation_obj(job, 485 + flat_texture.getPosition().x, 303 + flat_texture.getPosition().y);
		limits[23].limitation_obj(job, 397 + flat_texture.getPosition().x, 151 + flat_texture.getPosition().y);
		limits[24].limitation_obj(job, 459 + flat_texture.getPosition().x, 91 + flat_texture.getPosition().y);

		for (int i = 0; i < 10; i++) {
			if (rectangles[i].stop1(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//-0.5 х
				girl_1.sprite.move(-1, 0);
				job.draw(girl_1.sprite);
			}
			if (rectangles[i].stop2(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//0.5 х
				girl_1.sprite.move(1, 0);
				job.draw(girl_1.sprite);
			}
			if (rectangles[i].stop3(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//0.5 у
				girl_1.sprite.move(0, 1);
				job.draw(girl_1.sprite);
			}
			if (rectangles[i].stop4(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//-0.5 у
				girl_1.sprite.move(0, -1);
				job.draw(girl_1.sprite);
			}
		}

		//объекты
		for (int i = 0; i < 25; i++) {
			if (limits[i].stop1_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//-0.5 х
				girl_1.sprite.move(-1, 0);
				job.draw(girl_1.sprite);
			}
			if (limits[i].stop2_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//0.5 х
				girl_1.sprite.move(1, 0);
				job.draw(girl_1.sprite);
			}
			if (limits[i].stop3_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//0.5 у
				girl_1.sprite.move(0, 1);
				job.draw(girl_1.sprite);
			}
			if (limits[i].stop4_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//-0.5 у
				girl_1.sprite.move(0, -1);
				job.draw(girl_1.sprite);
			}
		}
		job.draw(display_texture);
		job.display();

	}
}



