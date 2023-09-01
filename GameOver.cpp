#include "GameOver.h"
#include "Engine.h"
#include "Ressources.h"

void GameOver::init()
{
	supr = false;
	textGameOver.setFont(Ressources::font_JAi_____);
	textGameOver.setString("-GAME OVER- ");
	textGameOver.setCharacterSize(80);
	textGameOver.setOrigin(textGameOver.getGlobalBounds().width / 2.f, textGameOver.getGlobalBounds().height / 2.f);
	textGameOver.setPosition(Engine::getWidowSize().x / 2.f, 50);
	textGameOver.setOutlineThickness(2);
	textGameOver.setOutlineColor(sf::Color::Red);

	textClickToRestart.setFont(Ressources::font_lasercorps);
	textClickToRestart.setString("click to return to the menu");
	textClickToRestart.setCharacterSize(20);
	textClickToRestart.setOrigin(textClickToRestart.getGlobalBounds().width / 2.f, textClickToRestart.getGlobalBounds().height / 2.f);
	textClickToRestart.setPosition(Engine::getWidowSize() / 2.f);
}

void GameOver::loop()
{
}

void GameOver::render(sf::RenderWindow* window)
{
	window->draw(textClickToRestart);
	window->draw(textGameOver);
}

void GameOver::joystick_pressed(int key)
{
	if (!supr && clockAction.getElapsedTime().asSeconds() > 1) {
		Engine::stateSupr();
		Engine::stateSupr();
		supr = true;
	}
}

void GameOver::key_pressed(int key)
{
	if (!supr && clockAction.getElapsedTime().asSeconds() > 1) {
		Engine::stateSupr();
		Engine::stateSupr();
		supr = true;
	}
}

void GameOver::mouse_pressed(int key, sf::RenderWindow* window)
{
	if (sf::Mouse::getPosition(*window).y >= 0
		&& sf::Mouse::getPosition(*window).y <= window->getSize().y
		&& sf::Mouse::getPosition(*window).x >= 0
		&& sf::Mouse::getPosition(*window).x <= window->getSize().x
		&& clockAction.getElapsedTime().asSeconds() > 1) {
		switch (key)
		{
		case sf::Mouse::Left:
			if (!supr) {
				Engine::stateSupr();
				Engine::stateSupr();
				supr = true;
			}
			break;
		}
	}
}
