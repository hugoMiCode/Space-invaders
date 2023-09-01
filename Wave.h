#pragma once
#include <vector>
#include <deque>
#include "Enemy.h"
#include "Ship.h"
#include "Fire.h"
#include "Ressources.h"
#include "SFML/Graphics.hpp"
#include "ShipEnemy.h"

class Wave
{
public:
	Wave(int entity = 1, int lvlEntity = 1, std::string path = "default", float tempsAvApp = 0, float tempsVieAsSeconds = 20);
	~Wave() { delete path; }
	void show(sf::RenderWindow* window);
	void update();
	void checkHit(Ship* ship);
	void fire(Ship* ship);
	void supr_enemy(unsigned int i);
	bool isEmpty();
	int getEntity();

private:
	//std::vector<std::unique_ptr<Enemy>> enemys;
	std::vector<Enemy*> enemys;
	sf::Clock addEnemy;
	sf::Clock clockApp;
	int entity;
	Path* path;
	int lvlEntity;
	float spawnEnemy;
	float tempsVieS;
	float tempsAvApp;
	float tempsPause;
	float tempsPausePrec;
};

