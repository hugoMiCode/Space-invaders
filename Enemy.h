#pragma once
#include "Entity.h"

#include "Ressources.h"
#include "Path.h"
#include "Ship.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <random>
#include <ctime>


class Enemy : public Entity
{
public:
	
	Enemy(Path* path, float tempsVieAsSeconds);
	virtual ~Enemy() {}

	void update();
	void show(sf::RenderWindow* window);
	void hit(float degats);
	virtual void fire(Ship* ship) = 0;
	void canFire(Ship* ship);
	void dropItem();

	bool checkDropItem();
	bool isDead();
	void checkHit(Ship* ship);
	bool checkLive();
	bool ckeckWindow();

	float getScoredeath();
	int getDegats();
	sf::Clock getClockLastHit();

	void setColor(sf::Color colorSprite);

protected:
	int pbFire;
	int pbItem;
	int fonctionItem;

	float tempsVieS;
	float tempsAffichageLifeBar;
	bool clearOut = false;
	float scoreDeath = 0.f;

	sf::Sprite enemy;
	sf::Sprite* spriteBullet = nullptr;
	sf::Vector2f sizeRenderBullet = sf::Vector2f();
	sf::RectangleShape health_bar;

	Path* path;
	Path* pathFire = nullptr;

	sf::Clock clockUpdate;
	sf::Clock clockFire;
	sf::Clock clockTempsVie;
	sf::Clock clockTempsAffichage;
};

