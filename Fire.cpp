#include "Fire.h"
#include "PlayingState.h"
#include "Animation.h"


Fire::Fire(FireStruct fireStruct, float angleFire) : Entity(fireStruct.posFireX, fireStruct.posFireY)
{
	spriteFireBall = nullptr;
	sizeRender = sf::Vector2f();
	posI = sf::Vector2f();
	degats = fireStruct.fireDegats;
	speed = fireStruct.speed;

	angle = angleFire + 180;

	tempsPausePrec = PlayingState::getTempsPause();
}

void Fire::update(Ship* ship)
{
	tempsPause = PlayingState::getTempsPause() - tempsPausePrec;
	float t{ clockUpdate.getElapsedTime().asMilliseconds() - tempsPause * 1000 };

	sf::Vector2f newPos(pathFire->path(t * speed, angle));
	pos = sf::Vector2f(posI.x + newPos.x, posI.y + newPos.y);

	updateHitBox();
	updateCenterRender();
}

void Fire::explo()
{
	Animation::hit(centerRender);
}

bool Fire::hitWall(sf::RenderWindow* window)
{
	return pos.x + Ship::getDepView() <= -sizeRender.x
		|| pos.y <= -sizeRender.y
		|| pos.x >= window->getSize().x + Ship::getDepView()
		|| pos.y >= window->getSize().y;
}

int Fire::getDegats()
{
	return degats;
}

FireShip::FireShip(FireStruct fireStruct, float angleFire) : Fire(fireStruct, angleFire)
{
	spriteFireBall = nullptr;
	sizeRender = sf::Vector2f();
}
RedFireShip::RedFireShip(FireStruct fireStruct, float angleFire) : FireShip(fireStruct, angleFire)
{
	spriteFireBall = &Ressources::redLaser;
	sizeRender = Ressources::getSizeRenderRedLaser();
	scaleEntity = Ressources::infosRedLaser.scale;
	posI = sf::Vector2f(fireStruct.posFireX - sizeRender.x / 2, fireStruct.posFireY + sizeRender.y / 2);

	initHitBox();
}
GreenFireShip::GreenFireShip(FireStruct fireStruct, float angleFire) : FireShip(fireStruct, angleFire)
{
	spriteFireBall = &Ressources::greenLaser;
	sizeRender = Ressources::getSizeRenderGreenLaser();
	scaleEntity = Ressources::infosGreenLaser.scale;
	posI = sf::Vector2f(fireStruct.posFireX - sizeRender.x / 2, fireStruct.posFireY + sizeRender.y / 2);

	initHitBox();
}
FireBallShip::FireBallShip(FireStruct fireStruct, float angleFire) : FireShip(fireStruct, angleFire)
{
	spriteFireBall = &Ressources::fireBallShip;
	sizeRender = Ressources::getSizeRenderFireBallShip();
	scaleEntity = Ressources::infosFireBallShip.scale;
	posI = sf::Vector2f(fireStruct.posFireX - sizeRender.x / 2, fireStruct.posFireY + sizeRender.y / 2);

	initHitBox();
}
FireTracking::FireTracking(FireStruct fireStruct, float angleFire) : Fire(fireStruct, angleFire) 
{
	spriteFireBall = &Ressources::fireBallEnemy;
	sizeRender = Ressources::getSizeRenderFireBallEnemy();
	scaleEntity = Ressources::infosFireBallEnemy.scale;
	posI = sf::Vector2f(fireStruct.posFireX - sizeRender.x / 2, fireStruct.posFireY + sizeRender.y / 2);

	initHitBox();
}
FireFollow::FireFollow(Ship* shipFollowed, FireStruct fireStruct) : Fire(fireStruct)
{
	spriteFireBall = &Ressources::fireMissile;
	sizeRender = Ressources::getSizeRenderFireMissile();
	sizePixel = Ressources::getSizePixelMissile();
	vx = 0.0f;
	vy = 0.0f;
	angle = 0.0f;
	ship = shipFollowed;
	tempsVie = 7.0f;

	initHitBox();
}

void FireShip::show(sf::RenderWindow* window)
{
	spriteFireBall->setPosition(pos);

	spriteFireBall->setOrigin(sizePixel.x / 2, sizePixel.y / 2);
	spriteFireBall->setRotation(-angle + 180);
	spriteFireBall->setOrigin(0, 0);

	window->draw(*spriteFireBall);
}
void FireTracking::show(sf::RenderWindow* window)
{
	spriteFireBall->setPosition(pos);
	window->draw(*spriteFireBall);
}
void FireFollow::show(sf::RenderWindow* window)
{
	spriteFireBall->setPosition(pos);

	window->draw(*spriteFireBall);
}

void FireFollow::update(Ship* aShip)
{		
	this->ship = aShip;
	angle = getAngle(aShip);


	tempsPause = PlayingState::getTempsPause();

	if (tempsPause != tempsPausePrec) {
		tempsPausePrec = tempsPause;
		updateClock.restart();
	}

	sf::Time t{ updateClock.restart() };

	vx = sin(rad(angle + 180)) * t.asMilliseconds() * speed;
	vy = cos(rad(angle + 180)) * t.asMilliseconds() * speed;
	
	pos.x += vx;
	pos.y += vy;	

	updateCenterRender();
	updateHitBox();
}


void RedFireShip::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(11, 128) - Ressources::infosRedLaser.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(4, 11) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	updateHitBox();
}
void GreenFireShip::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(46, 61) - Ressources::infosGreenLaser.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(3, 18) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	updateHitBox();
}
void FireBallShip::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(368, 1472) - Ressources::infosFireBallShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(33, 25) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	posRect = sf::Vector2i(376, 1464) - Ressources::infosFireBallShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(17, 9) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[1].second));

	updateHitBox();
}
void FireTracking::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(200, 200) - Ressources::infosFireBallEnemy.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(200, 200) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	updateHitBox();
}

void FireFollow::explo()
{
	Animation::explosion(centerRender);
}

bool FireFollow::endTimeLife()
{
	return lifeClock.getElapsedTime().asSeconds() - tempsPause >= tempsVie;
}

