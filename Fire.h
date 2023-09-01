#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Ship.h"
#include "Ressources.h"
#include <iostream>

class Fire : public Entity
{
public:
	Fire(FireStruct, float angleFire = 0.f);
	virtual ~Fire() { }

	virtual void update(Ship* ship); // pas tres jolie :/
	virtual void show(sf::RenderWindow* window) = 0;
	virtual void explo();
	virtual bool endTimeLife() { return false;  };
	bool hitWall(sf::RenderWindow* window);
	int getDegats();

protected:
	float speed;
	sf::Sprite* spriteFireBall = nullptr;
	sf::Vector2f posI;
	float angle;

private:
	int degats;
	sf::Clock clockUpdate;
};


class FireShip : public Fire
{
public:
	FireShip(FireStruct fireStruct, float angleFire);

	void show(sf::RenderWindow* window);
	//void initHitBox();
};
class RedFireShip : public FireShip
{
public:
	RedFireShip(FireStruct fireStruct, float angleFire = 0);

	void initHitBox();
};
class GreenFireShip : public FireShip
{
public:
	GreenFireShip(FireStruct fireStruct, float angleFire = 0);

	void initHitBox();
};
class FireBallShip : public FireShip
{
public:
	FireBallShip(FireStruct fireStruct, float angleFire = 0);

	void initHitBox();
};

class FireTracking : public Fire
{
public:
	FireTracking(FireStruct fireStruct, float angleFire);

	void show(sf::RenderWindow* window);
	void initHitBox();
};

class FireFollow : public Fire
{
public:
	FireFollow(Ship* shipFollowed, FireStruct fireStruct);

	void show(sf::RenderWindow* window);
	void update(Ship* ship);
	void explo();
	bool endTimeLife();

private:
	float vx;
	float vy;
	float tempsVie;
	float angle;
	Ship* ship;
	sf::Clock updateClock;
	sf::Clock lifeClock;
};