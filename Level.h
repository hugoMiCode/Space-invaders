#pragma once
#include "Wave.h"
#include "Fire.h"
#include "Ship.h"
#include "SFML/Graphics.hpp"
#include <deque>

class Level
{
public:
	Level(int n);
	void update();
	void show_entity(sf::RenderWindow* window);
	void checkHitEnemy(Ship* ship);
	void fire(Ship* ship);
	void suprWave(int i);
	bool isEmpty();

private:
	std::deque<std::unique_ptr<Wave>> waves;
};

