#pragma once
#include "Entity.h"
#include "Path.h"
#include <iostream>


class Item : public Entity
{
public:
	Item();
	~Item() {}
	void update();
	void initHitBox();
	virtual void show(sf::RenderWindow* window);
	void move(float x, float y);

	int getFonction();
	int getScore();
	int getDonne() { return donnee; }

protected:
	sf::Sprite* spriteItem;
	int fonction;
	float angle;
	float speed;
	int score;
	sf::Vector2f posI;
	int donnee = NULL;

private:
	sf::Clock clockUpdate;
	float tempsPause;
	float tempsPausePrec;
};

