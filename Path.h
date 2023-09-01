#pragma once
#include "SFML/Graphics.hpp"
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Path
{
public:
	Path(std::string path);
	~Path() {}

	sf::Vector2f path(float t, float angle = 0);
	sf::Vector3f path(float t, sf::Vector2f pos, float k = 1);

	sf::Vector2f fireShipEnemy(float t, float angle);
	sf::Vector2i pathEnemy(float t);

private:
	std::vector<sf::Vector3i> coord;

	std::string pathS;
	sf::Vector2i last;
	int ligne;
	bool endTab;
};

