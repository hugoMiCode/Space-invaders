#include "Entity.h"
Path* Entity::pathFire = new Path("fire");

Entity::Entity(float x, float y)
{
	pos = sf::Vector2f(x, y);
}

Entity::Entity(sf::Vector2f pos)
{
	this->pos = pos;
}

void Entity::initHitBox()
{
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>(sf::Vector2f(), sizePixel));
	tabHitBox.push_back(sf::RectangleShape(sizePixel));

	updateHitBox();
}

void Entity::updateHitBox()
{
	if (!tabHitBox.empty() && tabHitBox.size() == tabCoordHitBox.size())
		for (unsigned int i{ 0 }; i < tabHitBox.size(); i++) {
			sf::Vector2f posRender{ tabCoordHitBox[i].first * scaleEntity };
			sf::Vector2f sizeRender{ tabCoordHitBox[i].second * scaleEntity };

			tabHitBox[i].setPosition(pos + posRender);
			tabHitBox[i].setSize(sizeRender);

		}
}

void Entity::setPosition(float x, float y)
{
	pos = sf::Vector2f(x, y);
}

void Entity::setPosition(sf::Vector2f pos)
{
	this->pos = pos;
}

void Entity::setSize(float x, float y)
{
	sizeRender = sf::Vector2f(x, y);
}

void Entity::setSize(sf::Vector2f size)
{
	this->sizeRender = size;
}

void Entity::move(float x, float y)
{
	pos.x += x;
	pos.y += y;
}

void Entity::updateCenterRender()
{
	centerRender = sf::Vector2f(pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2);
}

sf::Vector2f Entity::getPosition()
{
	return pos;
}

sf::Vector2f Entity::getCenterRender()
{
	return centerRender;
}

sf::Vector2f Entity::getSizeRender()
{
	return sizeRender;
}

std::vector<sf::RectangleShape> Entity::getTabHitBox()
{
	return tabHitBox;
}

float Entity::getAngle(Entity* ship)
{
	float x1{ centerRender.x };
	float y1{ centerRender.y };

	float x2{ ship->getCenterRender().x };
	float y2{ ship->getCenterRender().y };


	if (x2 < x1)
		return (acos((y1 - y2) / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) * 180.f / 3.14159f);
	else
		return (-acos((y1 - y2) / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) * 180.f / 3.14159f);
}

float Entity::rad(float deg)
{
	return deg * 3.14159265 / 180;
}
