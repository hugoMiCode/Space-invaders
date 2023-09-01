#pragma once
#include "Item.h"

class UpFireMode : public Item
{
public:
	UpFireMode(sf::Vector2f pos);

};

class Shield : public Item
{
public:
	Shield(sf::Vector2f pos);
};

class Life : public Item
{
public:
	Life(sf::Vector2f pos);
};

class Coin : public Item
{
public:
	Coin(sf::Vector2f pos);

	void setSpriteRect(sf::IntRect rect);
	int getCoinValue() { return coinValue; }
private:
	int coinValue;
};

class Ammo : public Item
{
public:
	Ammo(sf::Vector2f pos);
};

class RedShipItem : public Item
{
public:
	RedShipItem(sf::Vector2f pos);

};

class PurpleShipItem : public Item
{
public:
	PurpleShipItem(sf::Vector2f pos);

};

class OrangeShipItem : public Item
{
public:
	OrangeShipItem(sf::Vector2f pos);

};

