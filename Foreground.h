#pragma once
#include "SFML/Graphics.hpp"
#include "Ship.h"

#include <iostream>
#include <string>

class Foreground
{
public:
	Foreground();
	void show(sf::RenderWindow* window, Ship* ship);
	void lifeBar(sf::RenderWindow* window, Ship* ship);
	void shieldBar(sf::RenderWindow* window, Ship* ship);
	void timer(sf::RenderWindow* window);
	void score(sf::RenderWindow* window, Ship* ship);
	void ammunition(sf::RenderWindow* window, Ship* ship);
	void fps(sf::RenderWindow* window);
	void updateView(sf::RenderWindow* window);
	void coin(sf::RenderWindow* window);
	void modeFire(sf::RenderWindow* window, Ship* ship);

private:
	sf::Sprite iconUpgrade;
	sf::Vector2f posWindow;
	unsigned int frames;
	std::string fps_s;
	sf::Clock frames_clock;
	sf::Clock clockGame;
	int minutes;
	int secondes;
	int charSize;
	float bordure;
	float wide;
	float outline;
	float spaceTextBar;
	float posText;
	sf::Font font;
};

