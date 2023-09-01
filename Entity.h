#pragma once
//#include "Ship.h"
#include "SFML/Graphics.hpp"
#include "Ressources.h"
#include "Path.h"

struct InfosShip
{
	int fireMode = 1;
	int ammunition = 0;
	int ammunitionMax = 0;
	int score = 0;
	float health = 0.0f;
	float maxHealth = 0.0f;
	float shield;
	float shieldMax;
	sf::Vector2f pos = sf::Vector2f();
};

class Entity
{
public:
	Entity(float x, float y); 
	Entity(sf::Vector2f pos);
	
	virtual void initHitBox();
	void updateHitBox();

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	void setSize(float x, float y);
	void setSize(sf::Vector2f size);
	void move(float x, float y);
	void updateCenterRender();
	sf::Vector2f getPosition();
	sf::Vector2f getCenterRender();
	sf::Vector2f getSizeRender();
	std::vector<sf::RectangleShape> getTabHitBox();
	float getAngle(Entity* ship);
	float rad(float deg);

protected:
	sf::Vector2f pos;
	float scaleEntity = 1.f;
	sf::Vector2f sizeRender = sf::Vector2f();
	sf::Vector2f sizePixel = sf::Vector2f();
	sf::Vector2f centerRender = sf::Vector2f();
	std::vector<sf::RectangleShape> tabHitBox;
	std::vector<std::pair<sf::Vector2f, sf::Vector2f>> tabCoordHitBox;

	static Path* pathFire;
	int fireDegats = 0;
	bool dead = false;
	float maxHealth = 0;
	float health = maxHealth;
	float tempsPause = 0;
	float tempsPausePrec = 0;
};