#pragma once
#include "SFML/Graphics.hpp"
#include "BackgroundElements.h"
#include <random>
#include <cmath>
#include <vector>


class Background
{
public:
	Background();
	void show(sf::RenderWindow* window);
	void update();
	float normal(float x);
	static void setAcc(bool acc);
	static bool getAcc();
	static bool getFinAcc();

private:
	std::vector<Rain*> rains;
	std::vector<ShootingStar*> shootingStars;
	std::vector<Planet*> planets;
	std::vector<Cloud*> cloud;

	sf::Sprite spaceBackground1;
	sf::Sprite spaceBackground2;

	sf::Clock backClock;
	sf::Clock accClock;

	float speed;
	float spaceBackgroundSizeY;
	float tempsPause;
	float tempsPausePrec;
	float tempsAcc;

	static bool acc;
	static bool finAcc;
};

