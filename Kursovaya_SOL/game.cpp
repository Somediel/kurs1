#include "game.h"


void menu(RenderWindow& win)
{
	Texture menu_but1, menu_but2, menu_but3, bg_menu;

	menu_but1.loadFromFile("images\\b1.png");
	menu_but2.loadFromFile("images\\b2.png");
	menu_but3.loadFromFile("images\\b3.png");
	bg_menu.loadFromFile("images\\back.png");

	Sprite new_game_button(menu_but1), load_game_button(menu_but2), close_game_button(menu_but3), background_menu(bg_menu);

	bool isMenu = 1;
	int menuNum = 0;

	new_game_button.setPosition(0, 0);
	load_game_button.setPosition(0, 0);
	close_game_button.setPosition(0, 0);

	while (isMenu)
	{
		new_game_button.setColor(Color::White);
		load_game_button.setColor(Color::White);
		close_game_button.setColor(Color::White);
		menuNum = 0;
		win.clear();

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(win))) { new_game_button.setColor(Color::Blue), menuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(win))) { new_game_button.setColor(Color::Blue), menuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(win))) { new_game_button.setColor(Color::Blue), menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			//if (menuNum == 2) win.draw;
			if (menuNum == 3) { win.close(); isMenu = false; };
		}

		win.draw(background_menu);
		win.draw(new_game_button);
		win.draw(load_game_button);
		win.draw(close_game_button);
	}
};
