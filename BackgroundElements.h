#pragma once
#include "Entity.h"

struct StructBackground
{
	sf::Sprite spriteElement;
	sf::Vector2f sizeRender;
	sf::Vector2i sizePixel;
	int posX;
	float scale;
	float speedElement = 1.f;
	float showTime = NULL;
	float timeToAppear = NULL;
};

class BackgroundElements : public Entity
{
public:
	BackgroundElements(StructBackground structBack);
	BackgroundElements(float x, float y);

	virtual void update(float speed);
	virtual void show(sf::RenderWindow* window);
	void reset();
	bool isIn() { return in; }
	virtual void impacte() {};

protected:
	bool everOut = false;
	bool in = false;
	float speedElement = 1.f;
	float showTime = NULL;
	float timeOut = NULL;
	float timeToAppear;
	sf::Sprite spriteElement;
	sf::Clock clockUpdate;
	sf::Clock clockShow;
	sf::Clock timeToAppearClock;
};

class ShootingStar : public BackgroundElements
{
public:
	ShootingStar(StructBackground structBack);

	void impacte();
};

class Planet : public BackgroundElements
{
public:
	Planet(StructBackground structBack);

	void impacte();
};

class Cloud : public BackgroundElements
{
public:
	Cloud(StructBackground structBack);
};

class Rain : public BackgroundElements
{
public:
	Rain(float x, float y);

	void update(float speed);
	void show(sf::RenderWindow* window);

private:
	sf::RectangleShape rain;
};



