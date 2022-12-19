#include "game.h"


void menu(RenderWindow& win)
{
	
	Text start_button_caption, close_button_caption;
	Font mainFont;

	Texture menu_but1, menu_but3, bg_menu;

	bg_menu.loadFromFile("images\\back.png");

	RectangleShape new_game_button, close_game_button;
	Sprite background_menu(bg_menu);

	bool isMenu = 1;
	int menuNum = 0;

	new_game_button.setPosition(950, 110);
	new_game_button.setSize(Vector2f(170, 50));
	close_game_button.setPosition(950, 210);
	close_game_button.setSize(Vector2f(170, 50));

	mainFont.loadFromFile("fonts\\arialmt.ttf");
	start_button_caption.setFont(mainFont);
	start_button_caption.setString("Start game");
	start_button_caption.setFillColor(Color(188, 110, 194));
	start_button_caption.setScale(0.8, 0.8);
	start_button_caption.setPosition(new_game_button.getPosition());
	start_button_caption.setCharacterSize(40);

	mainFont.loadFromFile("fonts\\arialmt.ttf");
	close_button_caption.setFont(mainFont);
	close_button_caption.setString("Close game");
	close_button_caption.setFillColor(Color(188, 110, 194));
	close_button_caption.setScale(0.8, 0.8);
	close_button_caption.setPosition(close_game_button.getPosition());
	close_button_caption.setCharacterSize(40);


	while (win.isOpen())
	{
		new_game_button.setFillColor(Color::White);
		close_game_button.setFillColor(Color::White);
		menuNum = 0;
		if (IntRect(950, 110, 170, 50).contains(Mouse::getPosition(win))) { new_game_button.setFillColor(Color(204,204,204)), menuNum = 1; }
		if (IntRect(950, 210, 170, 50).contains(Mouse::getPosition(win))) { close_game_button.setFillColor(Color(204, 204, 204)), menuNum = 3; }

		sf::Event event;
		while (win.pollEvent(event))
		{
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
			if (menuNum == 3) { win.close(); isMenu = false; };
		}

		win.clear();
		win.draw(background_menu);
		win.draw(new_game_button);
		win.draw(close_game_button);
		win.draw(start_button_caption);
		win.draw(close_button_caption);
		win.display();
	}

	
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void game(RenderWindow& job)
{
	Font mainFont;

	Texture close_but;

	RectangleShape close_button;
	bool flag = false;

	
	int kx, ky;
	Texture flat, display;

	flat.loadFromFile("images\\day.png");
	display.loadFromFile("images\\display.png");
	
	Sprite flat_texture(flat), display_texture(display);

	flat_texture.setPosition(0, 0);
	display_texture.setPosition(0, 0);

	living_beings girl_1;
	std::vector<walls> rectangles(10);
	rectangles[0].setWH(46, 252);
	rectangles[1].setWH(36, 384);
	rectangles[2].setWH(46, 416);
	rectangles[3].setWH(46, 416);
	rectangles[4].setWH(38, 264);
	rectangles[5].setWH(44, 270);

	rectangles[6].setWH(125, 36);
	rectangles[7].setWH(312, 36);
	rectangles[8].setWH(212, 36);
	rectangles[9].setWH(166, 40);

	items_interior* limits[26];
	limits[0] = new items_interior();
	for (int i = 2; i < 15; i++) {
		
		if ((i != 5) && (i != 13) && (i != 1) && (i != 6 ) && i!=3 && i!=4 && i != 12 && i !=14 && i != 10)
			limits[i] = new items_interior();
	}

	bed k;
	limits[15] = &k;

	sink_bath s;
	limits[5] = &s;

	sink_kitch sk;
	limits[17] = &sk;

	computer lt;
	limits[13] = &lt;

	tv t;
	limits[20] = &t;

	bookshelf bs;
	limits[10] = &bs;

	bath bb;
	limits[25] = &bb;

	toilet tt;
	limits[6] = &tt;

	fridge fr;
	limits[21] = &fr;

	left_chair lc;
	limits[22] = &lc;

	right_chair rc;
	limits[23] = &rc;

	seats ac1, ac2, ac3, ac4, ac5, ac6;
	limits[1]= & ac1;
	limits[3] = &ac2;
	limits[4] = &ac3;
	limits[12] = &ac4;
	limits[14] = &ac5;
	limits[16] = &ac6;

	stove stv;
	limits[19] = &stv;

	for (int i = 17; i < 26; i++) 
	{
		if ((i != 5) && (i != 25) && (i != 20) && (i != 6) && i != 21 && i != 17 && i != 22 && i != 23 && i != 19)
			limits[i] = new items_interior();
	}
	ac1.k = 5;
	ac2.k = 4;
	ac3.k = 6;
	ac4.k = 2;
	ac5.k = 3;
	ac6.k = 1;


	limits[0]->walking_limit.setWH(224, 97);   // шкаф
	limits[1]->walking_limit.setWH(55, 68);    // левый стул на балконе
	limits[2]->walking_limit.setWH(79, 218);   // стол на балконе
	limits[3]->walking_limit.setWH(64, 46);    // нижний стул на балконе
	limits[4]->walking_limit.setWH(123, 331);  // диван на балконе
	limits[5]->walking_limit.setWH(104, 41);   // раковина в ванной
	limits[6]->walking_limit.setWH(54, 69);    // туалет
	limits[7]->walking_limit.setWH(40, 105);   // тумбочка в прихожей
	limits[8]->walking_limit.setWH(53, 158);   // шкаф для обуви в прихожей
	limits[9]->walking_limit.setWH(204, 80);   // шкаф в прихожей
	limits[10]->walking_limit.setWH(266, 101); // книжный шкаф в зале
	limits[11]->walking_limit.setWH(303, 106); // диван в зале
	limits[12]->walking_limit.setWH(56, 69);   // левый стул в зале 
	limits[13]->walking_limit.setWH(199, 109); // стол в зале, ноутбук
	limits[14]->walking_limit.setWH(68, 85);   // правый стул в зале 
	limits[15]->walking_limit.setWH(238, 74);  // кровать
	limits[16]->walking_limit.setWH(90, 67);   // кресло в зале
	limits[17]->walking_limit.setWH(67, 70);   // лев.часть раковины на кухне
	limits[18]->walking_limit.setWH(54, 368);  // прав.часть раковины на кухне
	limits[19]->walking_limit.setWH(96, 87);   // плита
	limits[20]->walking_limit.setWH(49, 165);  // телевизор
	limits[21]->walking_limit.setWH(95, 102);  // холодильник
	limits[22]->walking_limit.setWH(59, 63);   // нижний стул на кухне
	limits[23]->walking_limit.setWH(59, 48);   // левый стул на кухне
	limits[24]->walking_limit.setWH(112, 209); // стол на кухне
	limits[25]->walking_limit.setWH(100, 377);  // ванная

	std::vector<RectangleShape> demand(5);
	demand[0].setPosition(90, 645);  //energy
	demand[1].setPosition(410, 595); //hygiene
	demand[2].setPosition(410, 647); //playful
	demand[3].setPosition(90, 593); //fullness
	demand[4].setPosition(90, 696); //need

	for (int i = 0; i < 5; i++) {
		demand[i].setFillColor(Color::White);
	}

	while (job.isOpen())
	{
		sf::Event event;
		while (job.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				job.close();

		}
		if (IntRect(1132, 594, 204, 35).contains(Mouse::getPosition(job)))
		{
			flag = true;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (flag == true)
			{
				job.clear();
				job.close();
			}
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

		if ((girl_1.sprite.getPosition().y - 0.5 < 50 + flat_texture.getPosition().y) && (Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
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

		limits[0]->walking_limit.limitation_obj(job, 121 + flat_texture.getPosition().x, 93 + flat_texture.getPosition().y);    // шкаф
		limits[1]->walking_limit.limitation_obj(job, 205 + flat_texture.getPosition().x, 585 + flat_texture.getPosition().y);   // левый стул на балконе
		limits[2]->walking_limit.limitation_obj(job, 264 + flat_texture.getPosition().x, 507 + flat_texture.getPosition().y);   // стол на балконе
		limits[3]->walking_limit.limitation_obj(job, 269 + flat_texture.getPosition().x, 732 + flat_texture.getPosition().y);   // нижний стул на балконе
		limits[4]->walking_limit.limitation_obj(job, 239 + flat_texture.getPosition().x, 928 + flat_texture.getPosition().y);   // диван на балконе
		limits[5]->walking_limit.limitation_obj(job, 1068 + flat_texture.getPosition().x, 102 + flat_texture.getPosition().y);  // раковина в ванной
		limits[6]->walking_limit.limitation_obj(job, 1210 + flat_texture.getPosition().x, 90 + flat_texture.getPosition().y);   // туалет
		limits[7]->walking_limit.limitation_obj(job, 1240 + flat_texture.getPosition().x, 636 + flat_texture.getPosition().y);  // тумбочка в прихожей
		limits[8]->walking_limit.limitation_obj(job, 1226 + flat_texture.getPosition().x, 999 + flat_texture.getPosition().y);  // шкаф для обуви в прихожей
		limits[9]->walking_limit.limitation_obj(job, 1064 + flat_texture.getPosition().x, 1200 + flat_texture.getPosition().y); // шкаф в прихожей
		limits[10]->walking_limit.limitation_obj(job, 764 + flat_texture.getPosition().x, 1183 + flat_texture.getPosition().y); // книжный шкаф в зале
		limits[11]->walking_limit.limitation_obj(job, 415 + flat_texture.getPosition().x, 1178 + flat_texture.getPosition().y); // диван в зале
		limits[12]->walking_limit.limitation_obj(job, 391 + flat_texture.getPosition().x, 1042 + flat_texture.getPosition().y); // левый стул в зале 
		limits[13]->walking_limit.limitation_obj(job, 461 + flat_texture.getPosition().x, 1017 + flat_texture.getPosition().y); // стол в зале, ноутбук
		limits[14]->walking_limit.limitation_obj(job, 668 + flat_texture.getPosition().x, 1035 + flat_texture.getPosition().y); // правый стул в зале 
		limits[15]->walking_limit.limitation_obj(job, 785 + flat_texture.getPosition().x, 673 + flat_texture.getPosition().y);  // кровать
		limits[16]->walking_limit.limitation_obj(job, 686 + flat_texture.getPosition().x, 601 + flat_texture.getPosition().y);  // кресло в зале
		limits[17]->walking_limit.limitation_obj(job, 787 + flat_texture.getPosition().x, 106 + flat_texture.getPosition().y);  // лев.часть раковины на кухне
		limits[18]->walking_limit.limitation_obj(job, 853 + flat_texture.getPosition().x, 106 + flat_texture.getPosition().y);  // прав.часть раковины на кухне
		limits[19]->walking_limit.limitation_obj(job, 635 + flat_texture.getPosition().x, 94 + flat_texture.getPosition().y);   // плита
		limits[20]->walking_limit.limitation_obj(job, 391 + flat_texture.getPosition().x, 613 + flat_texture.getPosition().y);  // телевизор
		limits[21]->walking_limit.limitation_obj(job, 378 + flat_texture.getPosition().x, 455 + flat_texture.getPosition().y);  // холодильник
		limits[22]->walking_limit.limitation_obj(job, 397 + flat_texture.getPosition().x, 151 + flat_texture.getPosition().y);  // левый стул на кухне
		limits[23]->walking_limit.limitation_obj(job, 485 + flat_texture.getPosition().x, 303 + flat_texture.getPosition().y);  // нижний стул на кухне
		limits[24]->walking_limit.limitation_obj(job, 459 + flat_texture.getPosition().x, 91 + flat_texture.getPosition().y);   // стол на кухне
		limits[25]->walking_limit.limitation_obj(job, 930 + flat_texture.getPosition().x, 104 + flat_texture.getPosition().y); // ванная

		for (int i = 0; i < 26; i++)
		{
			limits[i]->setUse_Zone();
		}


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
		for (int i = 0; i < 26; i++) {
			if (limits[i]->walking_limit.stop1_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//-0.5 х
				girl_1.sprite.move(-1, 0);
				job.draw(girl_1.sprite);
			}
			if (limits[i]->walking_limit.stop2_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//0.5 х
				girl_1.sprite.move(1, 0);
				job.draw(girl_1.sprite);
			}
			if (limits[i]->walking_limit.stop3_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//0.5 у
				girl_1.sprite.move(0, 1);
				job.draw(girl_1.sprite);
			}
			if (limits[i]->walking_limit.stop4_obj(girl_1.sprite.getPosition().x, girl_1.sprite.getPosition().y))
			{
				//-0.5 у
				girl_1.sprite.move(0, -1);
				job.draw(girl_1.sprite);
			}
		}

		for (int i = 0; i < 26; i++) {
			if (limits[i]->Check_Zone(girl_1.sprite.getPosition().x + 27, girl_1.sprite.getPosition().y + 100) && limits[i]->Check_Zone(Mouse::getPosition().x, Mouse::getPosition().y) && Mouse::isButtonPressed(Mouse::Left) || limits[i]->flag == true)
			{
				if (limits[i]->flag == false)
				{
					limits[i]->flag = true;
					kx = girl_1.sprite.getPosition().x;
					ky = girl_1.sprite.getPosition().y;
				}

				Sprite k;
				girl_1.sprite.setPosition(-1000, -1000);
				limits[i]->doThings();
				job.draw(limits[i]->sprite);

				switch (limits[i]->boost_number) 
				{
				case 1:
					if (limits[i]->flag && girl_1.energy < 100000)
						girl_1.energy += 5;
					break;

				case 2:
					if (limits[i]->flag && girl_1.hygiene < 100000)
						girl_1.hygiene += 5;
					break;
				
				case 3:
					if (limits[i]->flag && girl_1.playful < 100000)
						girl_1.playful += 5;
					break;
					
				case 4:
					if (limits[i]->flag && girl_1.fullness < 100000)
						girl_1.fullness += 5;
					break;

				case 5:
					if (limits[i]->flag && girl_1.need < 100000)
						girl_1.need += 5;
					break;

				}
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					girl_1.sprite.setPosition(kx, ky);
					limits[i]->flag = false;
				}
			}
		}
		job.draw(display_texture);

		Vector2f Size;
		Size.x = 2 * girl_1.energy / 1000;
		Size.y = 35;
		demand[0].setSize(Size);
		job.draw(demand[0]);

		Size.x = 2.03 * girl_1.hygiene / 1000;
		Size.y = 35;
		demand[1].setSize(Size);
		job.draw(demand[1]);

		Size.x = 2.03 * girl_1.playful / 1000;
		Size.y = 35;
		demand[2].setSize(Size);
		job.draw(demand[2]);

		Size.x = 2.03 * girl_1.fullness / 1000;
		Size.y = 35;
		demand[3].setSize(Size);
		job.draw(demand[3]);

		Size.x = 2.03 * girl_1.need / 1000;
		Size.y = 35;
		demand[4].setSize(Size);
		job.draw(demand[4]);
		
		girl_1.energy -= 1;
		girl_1.hygiene -= 1;
		girl_1.playful -= 1;
		girl_1.fullness -= 1;
		girl_1.need -= 1;

		//limits[21]->walking_limit.limit_obj.setFillColor(Color::Blue);
		//job.draw(limits[21]->walking_limit.limit_obj);

		job.draw(close_button);
		job.display();

	}
}



