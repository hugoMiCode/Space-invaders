#include "Item.h"
#include "PlayingState.h"

Item::Item() : Entity(posI.x, posI.y)
{
	sizeRender = sf::Vector2f();
	posI = sf::Vector2f();
	spriteItem = nullptr;
	tempsPause = 0;
	fonction = 0;
	score = 0; // default
	angle = 0.0f;
	speed = 0.08f;
	tempsPausePrec = PlayingState::getTempsPause();

	initHitBox();
}

void Item::update()
{
	tempsPause = PlayingState::getTempsPause() - tempsPausePrec;
	float t{ clockUpdate.getElapsedTime().asMilliseconds() - tempsPause * 1000 };

	sf::Vector2f newPos{ pathFire->path(t * speed, angle) };
	pos = sf::Vector2f(posI.x + newPos.x, posI.y + newPos.y);

	updateCenterRender();
	updateHitBox();
}

void Item::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i();
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, Ressources::getSizeRenderAllItem() });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	updateHitBox();
}

void Item::show(sf::RenderWindow* window)
{
	spriteItem->setPosition(pos);
	window->draw(*spriteItem);
}

void Item::move(float x, float y)
{
	pos.x += x;
	pos.y += y;
}

int Item::getFonction()
{
	return fonction;
}

int Item::getScore()
{
	return score;
}
