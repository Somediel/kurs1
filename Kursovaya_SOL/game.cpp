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

	while (isMenu)
	{
		new_game_button.setColor(Color::White);
		load_game_button.setColor(Color::White);
		close_game_button.setColor(Color::White);
		menuNum = 0;
		win.clear();

		if (IntRect(1000, 110, 170, 30).contains(Mouse::getPosition(win))) { new_game_button.setColor(Color(204,204,204)), menuNum = 1; }
		if (IntRect(1000, 160, 170, 30).contains(Mouse::getPosition(win))) { load_game_button.setColor(Color(204, 204, 204)), menuNum = 2; }
		if (IntRect(1000, 210, 170, 30).contains(Mouse::getPosition(win))) { close_game_button.setColor(Color(204, 204, 204)), menuNum = 3; }

		mainFont.loadFromFile("fonts\\arialmt.ttf");
		start_button_caption.setFont(mainFont);
		start_button_caption.setString("Load game");
		start_button_caption.setFillColor(Color(188, 110, 194));
		start_button_caption.setScale(0.8, 0.8);
		start_button_caption.setPosition(new_game_button.getPosition());


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				isMenu = false;
				win.close();

				RenderWindow window1(VideoMode(1366, 768), "Essence");

				game(window1);
				
			}
			//if (menuNum == 2) win.draw;
			if (menuNum == 3) { win.close(); isMenu = false; };
		}

		win.draw(background_menu);
		win.draw(new_game_button);
		win.draw(load_game_button);
		win.draw(close_game_button);
		win.display();
	}

	
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void game(RenderWindow& job)
{
	while (true)
	{
		Texture flat, display, girl_1;

		flat.loadFromFile("images\\flat.png");
		display.loadFromFile("images\\display.png");
		girl_1.loadFromFile("images\\girl_1.png");

		Sprite flat_texture(flat), display_texture(display), girl_11(girl_1);

		flat_texture.setPosition(0, 0);
		display_texture.setPosition(0, 0);
		girl_11.setPosition(700, 300);

		job.clear();
		job.draw(flat_texture);
		job.draw(display_texture);
		job.draw(girl_11);
		job.display();
	}
}
