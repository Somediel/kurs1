#include "game.h"


void menu(RenderWindow& win)
{
	
	Text start_button_caption;
	Font mainFont;

	Texture menu_but1, menu_but2, menu_but3, bg_menu;

	menu_but1.loadFromFile("images\\b1.png");
	menu_but2.loadFromFile("images\\b2.png");
	menu_but3.loadFromFile("images\\b3.png");
	bg_menu.loadFromFile("images\\back.png");

	Sprite new_game_button(menu_but1), load_game_button(menu_but2), close_game_button(menu_but3), background_menu(bg_menu);

	bool isMenu = 1;
	int menuNum = 0;

	new_game_button.setPosition(1000, 110);
	load_game_button.setPosition(1000, 160);
	close_game_button.setPosition(1000, 210);
	mainFont.loadFromFile("fonts\\arialmt.ttf");
	start_button_caption.setFont(mainFont);
	start_button_caption.setString("Load game");
	start_button_caption.setFillColor(Color(188, 110, 194));
	start_button_caption.setScale(0.8, 0.8);
	start_button_caption.setPosition(new_game_button.getPosition());

	while (win.isOpen())
	{
		new_game_button.setColor(Color::White);
		load_game_button.setColor(Color::White);
		close_game_button.setColor(Color::White);
		menuNum = 0;
		if (IntRect(1000, 110, 170, 30).contains(Mouse::getPosition(win))) { new_game_button.setColor(Color(204,204,204)), menuNum = 1; }
		if (IntRect(1000, 160, 170, 30).contains(Mouse::getPosition(win))) { load_game_button.setColor(Color(204, 204, 204)), menuNum = 2; }
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
		win.draw(load_game_button);
		win.draw(close_game_button);
		win.display();
	}

	
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void game(RenderWindow& job)
{
	Texture flat, display;

	flat.loadFromFile("images\\flat.png");
	display.loadFromFile("images\\display.png");
	

	Sprite flat_texture(flat), display_texture(display);

	flat_texture.setPosition(0, 0);
	display_texture.setPosition(0, 0);
	living_beings girl_1;

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
		job.draw(display_texture);
		girl_1.Moving(job);
		job.display();

	}
}
