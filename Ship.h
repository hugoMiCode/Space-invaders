#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "Entity.h"
#include <deque>

struct FireStruct
{
	float posFireX;
	float posFireY;
	int fireDegats;
	float speed;
	/*
	sf::Sprite* sprite_bullet;
	sf::Vector2f sizeRenderBullet;
	*/
};

class Ship : public Entity
{
public:
	Ship(InfosShip infosShip);
	virtual ~Ship() {}

	virtual void fire() = 0;
	bool canFire();

	void update(sf::RenderWindow* window);
	virtual void show(sf::RenderWindow* window);
	void collisions(sf::RenderWindow* window);
	bool isDead();
	void hit(float degats);

	float getMaxHealth();
	float getHealth();
	float getShield();
	float getMaxShield();
	int getScore();
	int getAmmunition();
	int getAmmunitionMax();
	int getCurrentFireMode();
	int getMaxFireMode();
	static float getDepView();

	void addScore(int scoreAdd);
	void addShield(float shieldAdd);
	void addHealth(float healthAdd);
	void addAmmu(float ammuAdd);
	void addFireMode(int newFireMode = 0);
	void setFrequency(float newFrequency);
	void setAmmunitinmax(int newAmmunitinmax);

protected:
	sf::Sprite* spriteShip;
	//sf::Sprite* spriteBullet;
	//sf::Vector2f sizeRenderBullet;
	int maxFireMode;
	int fireMode;
	int ammunition;
	int ammunitionMax;
	float frequencyFire;
	float frequencyReload;
	int score;
	float speedFire;
	float shield;
	float shieldMax;
	sf::Clock clockCanFire;
	sf::Clock clockCanReload;
	sf::Clock clockHealth;
	sf::Clock clockMove;
	sf::Sound* soundFire;
	sf::Sound* soundHit;
	FireStruct fireStruct;
	FireStruct fireStruct5;
	FireStruct fireStruct_5;
	FireStruct fireStruct10;
	FireStruct fireStruct_10;

	static float depViewX;
};

class PurpleShip : public Ship
{
public:
	PurpleShip(InfosShip infosShip);

	void fire();
	void initHitBox();
};

class RedShip : public Ship
{
public:
	RedShip(InfosShip infosShip);

	void fire();
	void initHitBox();
};

class OrangeShip : public Ship
{
public:
	OrangeShip(InfosShip infosShip);

	void fire();
	void initHitBox();
};
