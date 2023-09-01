#include "BackgroundElements.h"
#include "Engine.h"
#include "PlayingState.h"

BackgroundElements::BackgroundElements(StructBackground structBack) : Entity(structBack.posX, -structBack.sizeRender.y)
{
	timeToAppear = structBack.timeToAppear;
}
BackgroundElements::BackgroundElements(float x, float y) : Entity(x, y)
{
}
ShootingStar::ShootingStar(StructBackground structBack) : BackgroundElements(structBack)
{
	spriteElement = structBack.spriteElement;
	sizeRender = structBack.sizeRender;
	sizePixel = sf::Vector2f(structBack.sizePixel);
	scaleEntity = structBack.scale;
	speedElement = structBack.speedElement;
	showTime = structBack.showTime;


	initHitBox();
}
Planet::Planet(StructBackground structBack) : BackgroundElements(structBack)
{
	spriteElement = structBack.spriteElement;
	sizeRender = structBack.sizeRender;
	sizePixel = sf::Vector2f(structBack.sizePixel);
	scaleEntity = structBack.scale;
	speedElement = structBack.speedElement;
	showTime = structBack.showTime;
	//timeToAppear = structBack.timeToAppear;

	initHitBox();
}
Cloud::Cloud(StructBackground structBack) : BackgroundElements(structBack)
{
	spriteElement = structBack.spriteElement;
	sizeRender = structBack.sizeRender;
	sizePixel = sf::Vector2f(structBack.sizePixel);
	scaleEntity = structBack.scale;
	speedElement = structBack.speedElement;
	showTime = structBack.showTime; 

}
Rain::Rain(float x, float y) : BackgroundElements(x, y)
{
	sizeRender = sf::Vector2f(1.f, 15.f);
	speedElement = 0.2f;
	showTime = 0.f;

	rain.setFillColor(sf::Color(147, 112, 219));
}



void BackgroundElements::update(float speed)
{
	tempsPause = PlayingState::getTempsPause();

	if (tempsPause != tempsPausePrec) {
		tempsPausePrec = tempsPause;
		clockUpdate.restart();
		clockShow.restart();
	}
	else
		timeOut += clockShow.restart().asMilliseconds();



	sf::Time timeUpdate{ clockUpdate.restart() };
	if ((!everOut || timeOut >= showTime * 1000) && timeToAppearClock.getElapsedTime().asSeconds() >= timeToAppear)
		move(0, speed * speedElement * timeUpdate.asMilliseconds());

	updateCenterRender();
	updateHitBox();
}

void BackgroundElements::show(sf::RenderWindow* window)
{
	if (pos.y >= 0 && pos.y + sizeRender.y <= window->getSize().y)
		in = true;
	else
		in = false;
	
	if (pos.y >= window->getSize().y)
		reset();
	else
		spriteElement.setPosition(pos);


	window->draw(spriteElement);
}
void Rain::update(float speed)
{
	tempsPause = PlayingState::getTempsPause();

	if (tempsPause != tempsPausePrec) {
		tempsPausePrec = tempsPause;
		clockUpdate.restart();
	}

	rain.setSize(sf::Vector2f(1, sizeRender.y + 4.f * speed));

	sf::Time timeUpdate{ clockUpdate.restart() };
	if (!everOut || clockShow.getElapsedTime().asSeconds() >= showTime)
		move(0, speed * speedElement * timeUpdate.asMilliseconds());
}
void Rain::show(sf::RenderWindow* window)
{
	if (pos.y >= window->getSize().y)
		reset();
	else
		rain.setPosition(pos);


	window->draw(rain);
}
void BackgroundElements::reset()
{
	pos.x = rand() % int(Engine::getWidowSize().x) - sizeRender.x / 2;
	pos.y = -sizeRender.y;
	everOut = true;
	clockShow.restart();
	timeOut = 0.f;
}
void ShootingStar::impacte()
{
	reset();
}
void Planet::impacte()
{
	//changer le sprite.
}


