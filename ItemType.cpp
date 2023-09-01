#include "ItemType.h"
#include "Ressources.h"

UpFireMode::UpFireMode(sf::Vector2f pos)
{
	spriteItem = &Ressources::itemUpgrade;
	//sizeRender = Ressources::getSizeRenderItemUpgrade();
	sizeRender = Ressources::getSizeRenderAllItem();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2.f, pos.y - sizeRender.y / 2.f);

	fonction = 1;
	score = 50;

	initHitBox();
}
Shield::Shield(sf::Vector2f pos)
{
	spriteItem = &Ressources::shield;
	//sizeRender = Ressources::getSizeRenderShield();
	sizeRender = Ressources::getSizeRenderAllItem();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2.f, pos.y - sizeRender.y / 2.f);

	donnee = 20;
	fonction = 2;
	score = 50;

	initHitBox();
}
Life::Life(sf::Vector2f pos)
{
	spriteItem = &Ressources::life;
	//sizeRender = Ressources::getSizeRenderLife();
	sizeRender = Ressources::getSizeRenderAllItem();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2.f, pos.y - sizeRender.y / 2.f);

	donnee = 20;
	fonction = 3;
	score = 50;

	initHitBox();
}

Coin::Coin(sf::Vector2f pos)
{
	spriteItem = &Ressources::coin;
	sizeRender = Ressources::getSizeRenderCoin();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2.f, pos.y - sizeRender.y / 2.f);

	coinValue = 1;
	score = 10;
	angle = rand() % 40 - 20;
	speed = 0.05f;

	initHitBox();
}

Ammo::Ammo(sf::Vector2f pos)
{
	spriteItem = &Ressources::ammo;
	sizeRender = Ressources::getSizeRenderAllItem();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2.f, pos.y - sizeRender.y / 2.f);

	donnee = 20;
	fonction = 4;
	score = 20;

	initHitBox();
}

void Coin::setSpriteRect(sf::IntRect rect)
{
	spriteItem->setTextureRect(rect);
}

RedShipItem::RedShipItem(sf::Vector2f pos)
{
	spriteItem = &Ressources::redShipItem;
	sizeRender = Ressources::getSizeRenderAllItem();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2, pos.y - sizeRender.y / 2);
	fonction = -1;
	score = 50;

	initHitBox();
}

PurpleShipItem::PurpleShipItem(sf::Vector2f pos)
{
	spriteItem = &Ressources::heavyShipItem;
	sizeRender = Ressources::getSizeRenderAllItem();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2, pos.y - sizeRender.y / 2);
	fonction = -2;
	score = 50;

	initHitBox();
}

OrangeShipItem::OrangeShipItem(sf::Vector2f pos)
{
	spriteItem = &Ressources::orangeShipItem;
	sizeRender = Ressources::getSizeRenderAllItem();
	posI = sf::Vector2f(pos.x - sizeRender.x / 2, pos.y - sizeRender.y / 2);
	fonction = 0;
	score = 50;

	initHitBox();
}