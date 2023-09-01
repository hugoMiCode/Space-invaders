#include "MainMenu.h"

void MainMenu::init()
{
	Ressources::load();
	Animation::init();
	options[0] = " -Play game-";
	options[1] = " -setting- ";
	options[2] = " -Quit game-";

	joystick = false;
	selected = 0;
	menusPos = sf::Vector3f(10, 70, 250);
	Engine::setColor(sf::Color(55, 55, 100));

	font_options = Ressources::font_lasercorps;
	font_title = Ressources::font_lasercorpsgradital;

	title.setFont(font_title);
	title.setString("Space invaders");
	title.setCharacterSize(55);
	title.setPosition(50, 50);

	option.setFont(font_options);
	option.setCharacterSize(45);

	selecter.setFillColor(Engine::getColor());
	selecter.setOutlineThickness(2);
	selecter.setOutlineColor(sf::Color::White);

}

void MainMenu::loop()
{
	Engine::view.setCenter(Engine::getWidowSize().x / 2, Engine::getWidowSize().y / 2);
	Engine::view.setSize(Engine::getWidowSize());
	int i{ rand() };
}

void MainMenu::render(sf::RenderWindow* window)
{
	for (short unsigned int i{ 0 }; i < options_count; i++) {
		sf::Vector2f pos(menusPos.x, menusPos.y * i + menusPos.z);

		option.setString(options[i]);
		option.setPosition(pos);
		option.setFillColor(sf::Color(148, 148, 148));

		selecter.setPosition(0, pos.y);
		selecter.setSize(sf::Vector2f(window->getSize().x, 60.0f));

		mouse_control(pos, window);


		if (i == selected) {
			option.setFillColor(sf::Color::White);
			window->draw(selecter);
		}

		window->draw(option);
	}

	window->draw(title);
}

void MainMenu::key_pressed(int key, sf::RenderWindow* window)
{
	if (key == sf::Keyboard::Up && selected > 0)
		selected--;
	else if (key == sf::Keyboard::Down && selected < options_count - 1)
		selected++;
	else if (key == sf::Keyboard::Enter)
		selected_control();
}

void MainMenu::mouse_pressed(int key, sf::RenderWindow* window)
{
	if (sf::Mouse::getPosition(*window).y >= menusPos.z
		&& sf::Mouse::getPosition(*window).y <= menusPos.z + menusPos.y * options_count)
		switch (key)
		{
		case sf::Mouse::Left:
			selected_control();
		}
}


void MainMenu::mouse_control(sf::Vector2f pos, sf::RenderWindow* window)
{
	if (sf::Mouse::getPosition(*window).y >= pos.y && sf::Mouse::getPosition(*window).y <= pos.y + menusPos.y
		&& sf::Mouse::getPosition(*window).x > 0 && sf::Mouse::getPosition(*window).x < (signed)window->getSize().x)
		selected = (pos.y - menusPos.z) / menusPos.y;
}

void MainMenu::joystick_move()
{
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);


	if (y > 80 && selected < options_count - 1 && !joystick) {
		selected++;
		joystick = true;
	}
	else if (y < -80 && selected > 0 && !joystick) {
		selected--;
		joystick = true;
	}
	else if ((int)x == 0 && (int)y == 0)
		joystick = false;
}

void MainMenu::joystick_pressed(int key, sf::RenderWindow* window)
{
	if (key == 0)
		selected_control();
}

void MainMenu::selected_control()
{
	switch (selected)
	{
	case 0:
		Engine::stateAdd(new PlayingState);
		break;
	case 1:
		std::cout << "setting" << std::endl;
		break;
	case 2:
		Engine::closeGame();
		break;
	}
}

