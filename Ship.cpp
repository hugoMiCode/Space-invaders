#include "Ship.h"
#include "PlayingState.h"
#include "Animation.h"
#include "Ressources.h"
#include "Setting.h"

float Ship::depViewX{ 50 };

Ship::Ship(InfosShip infosShip) : Entity(infosShip.pos)
{
	spriteShip = nullptr;
	sizeRender = sf::Vector2f();
	frequencyFire = 0;
	frequencyReload = 0;
	fireDegats = 0;
	speedFire = 0.8f;
	maxFireMode = 0;

	fireMode = infosShip.fireMode;
	score = infosShip.score;

	ammunitionMax = infosShip.ammunitionMax;
	ammunition = infosShip.ammunition;

	maxHealth = infosShip.maxHealth;
	health = infosShip.health;

	shieldMax = infosShip.shieldMax;
	shield = infosShip.shield;

	dead = false;

	fireStruct = {};
	fireStruct5 = {};
	fireStruct_5 = {};
	fireStruct10 = {};
	fireStruct_10 = {};

	soundFire = &Ressources::soundFire;
	soundHit = &Ressources::soundHit;

	tempsPausePrec = PlayingState::getTempsPause();
}

bool Ship::canFire()
{
	bool keyFire{
		sf::Joystick::isButtonPressed(0, 5)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
		|| sf::Mouse::isButtonPressed(sf::Mouse::Left)
	};

	if (ammunition < 0)
		ammunition = 0;
	else if (ammunition > ammunitionMax)
		ammunition = ammunitionMax;


	if (keyFire && ammunition > 0 && clockCanFire.getElapsedTime().asSeconds() > frequencyFire) {
		clockCanFire.restart();
		clockCanReload.restart();
		return true;
	}
	else if (ammunition < ammunitionMax && clockCanReload.getElapsedTime().asSeconds() > frequencyReload) {
		if (ammunition == 0)
			clockCanFire.restart();
		ammunition++;
		clockCanReload.restart();
	}

	return false;
}

bool Ship::isDead()
{
	return dead;
}

void Ship::update(sf::RenderWindow* window)
{
	bool bMove{ false };

	tempsPause = PlayingState::getTempsPause();
	if (tempsPause != tempsPausePrec) {
		clockMove.restart();
		tempsPausePrec = tempsPause;
	}


	float timeMove = clockMove.restart().asMilliseconds();
	float speedTest{ 0.35f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		move(0, -speedTest * timeMove);
		bMove = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		move(0, speedTest * timeMove);
		bMove = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		move(-speedTest * timeMove, 0);
		bMove = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move(speedTest * timeMove, 0);
		bMove = true;
	}

	if (sf::Joystick::isConnected(0) && !bMove) {
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X) * 0.01;
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) * 0.01;
		move(speedTest * x * timeMove, speedTest * y * timeMove);
	}

	float x{ float(sf::Mouse::getPosition(*window).x) };
	float y{ float(sf::Mouse::getPosition(*window).y) };

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)
		&& x >= 0 && y >= 0
		&& x <= int(window->getSize().x)
		&& y <= int(window->getSize().y))
		setPosition(x - sizeRender.x / 2, y - sizeRender.y / 2);

	float x1{ pos.x + sizeRender.x / 2.f };
	x1 /= window->getSize().x;
	x1 *= depViewX;
	x1 += (window->getSize().x - depViewX) / 2;

	Engine::view.setCenter(sf::Vector2f(x1, window->getSize().y / 2));
	Engine::view.setSize(Engine::getWidowSize());

	collisions(window);
	updateHitBox();
	updateCenterRender();
}

void Ship::show(sf::RenderWindow* window)
{
	spriteShip->setPosition(pos);
	window->draw(*spriteShip);
}

void Ship::collisions(sf::RenderWindow* window)
{
	if (pos.x < -depViewX / 2)
		pos.x = -depViewX / 2;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.x > window->getSize().x - sizeRender.x + depViewX / 2)
		pos.x = window->getSize().x - sizeRender.x + depViewX / 2;
	if (pos.y > window->getSize().y - sizeRender.y)
		pos.y = window->getSize().y - sizeRender.y;
}

void Ship::hit(float degats)
{
	if (clockHealth.getElapsedTime().asSeconds() > 0.3) {
		shield -= degats;
		if (shield < 0) {
			health += shield;
			shield = 0;
		}

		soundHit->setVolume(Setting::getVolume());
		soundHit->play();

		if (health <= 0) {
			health = 0;
			dead = true;
		}
		clockHealth.restart();
	}
}

float Ship::getMaxHealth()
{
	return maxHealth;
}

float Ship::getHealth()
{
	return health;
}

float Ship::getShield()
{
	return shield;
}

float Ship::getMaxShield()
{
	return shieldMax;
}

void Ship::addScore(int scoreAdd)
{
	score += scoreAdd;
	if (score < 0)
		score = 0;
}

void Ship::addShield(float shieldAdd)
{
	shield += shieldAdd;

	if (shield > shieldMax)
		shield = shieldMax;
}

void Ship::addHealth(float healthAdd)
{
	health += healthAdd;

	if (health > maxHealth)
		health = maxHealth;
}

void Ship::addAmmu(float ammuAdd)
{
	ammunition += ammuAdd;

	if (ammunition >= ammunitionMax)
		ammunition = ammunitionMax;
}

void Ship::addFireMode(int newFireMode)
{
	if (newFireMode == 0)
		fireMode++;
	else
		fireMode = newFireMode;

	if (fireMode > 10)
		fireMode = 10;
	else if (fireMode < 1)
		fireMode = 1;
}

int Ship::getScore()
{
	return score;
}

int Ship::getAmmunition()
{
	return ammunition;
}

int Ship::getAmmunitionMax()
{
	return ammunitionMax;
}

int Ship::getCurrentFireMode()
{
	return fireMode;
}

int Ship::getMaxFireMode()
{
	return maxFireMode;
}

float Ship::getDepView()
{
	return depViewX;
}

void Ship::setFrequency(float newFrequency)
{
	frequencyFire = newFrequency;
}

void Ship::setAmmunitinmax(int newAmmunitinmax)
{
	ammunitionMax = newAmmunitinmax;
}

PurpleShip::PurpleShip(InfosShip infosShip) : Ship(infosShip)
{
	spriteShip = &Ressources::purpleShip;
	sizeRender = Ressources::getSizeRenderPurpleShip();
	scaleEntity = Ressources::infosPurpleShip.scale;
	maxFireMode = 10;
	fireDegats = 15;
	frequencyFire = 0.11f;
	frequencyReload = 0.11f;
	ammunitionMax = 75;

	initHitBox();
}
RedShip::RedShip(InfosShip infosShip) : Ship(infosShip)
{
	spriteShip = &Ressources::redShip;
	sizeRender = Ressources::getSizeRenderRedShip();
	scaleEntity = Ressources::infosRedShip.scale;
	maxFireMode = 10;
	fireDegats = 30;
	frequencyFire = 0.15f;
	frequencyReload = 0.16f;
	ammunitionMax = 50;

	initHitBox();
}
OrangeShip::OrangeShip(InfosShip infosShip) : Ship(infosShip)
{
	spriteShip = &Ressources::orangeShip;
	sizeRender = Ressources::getSizeRenderOrangeShip();
	scaleEntity = Ressources::infosOrangeShip.scale;
	maxFireMode = 10;
	fireDegats = 20;
	frequencyFire = 0.15f;
	frequencyReload = 0.15f;
	ammunitionMax = 60;

	initHitBox();
}

void PurpleShip::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(100, 1092) - Ressources::infosPurpleShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(57, 125) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	posRect = sf::Vector2i(120, 1056) - Ressources::infosPurpleShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(17, 37) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[1].second));

	posRect = sf::Vector2i(68, 1136) - Ressources::infosPurpleShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(37, 33) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[2].second));

	posRect = sf::Vector2i(152, 1136) - Ressources::infosPurpleShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(37, 33) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[3].second));

	posRect = sf::Vector2i(188, 1151) - Ressources::infosPurpleShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(21, 21) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[4].second));

	posRect = sf::Vector2i(48, 1151) - Ressources::infosPurpleShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(21, 21) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[5].second));


	updateHitBox();
}
void RedShip::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(68, 124) - Ressources::infosRedShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(25, 33) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	posRect = sf::Vector2i(164, 124) - Ressources::infosRedShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(25, 33) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[1].second));

	posRect = sf::Vector2i(100, 140) - Ressources::infosRedShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(57, 29) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[2].second));

	posRect = sf::Vector2i(116, 112) - Ressources::infosRedShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(33, 29) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[3].second));

	posRect = sf::Vector2i(123, 88) - Ressources::infosRedShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(9, 25) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[4].second));


	updateHitBox();
}
void OrangeShip::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(84, 1380) - Ressources::infosOrangeShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{ 
		posRect, sf::Vector2f(25, 85) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	posRect = sf::Vector2i(148, 1380) - Ressources::infosOrangeShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{ 
		posRect, sf::Vector2f(25, 85) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[1].second));

	posRect = sf::Vector2i(112, 1348) - Ressources::infosOrangeShip.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{ 
		posRect, sf::Vector2f(33, 117) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[2].second));


	updateHitBox();
}

void RedShip::fire()
{
	soundFire->setVolume(Setting::getVolume());
	soundFire->play();

	fireStruct = { pos.x + sizeRender.x / 2.0f, pos.y, fireDegats, speedFire };
	fireStruct5 = { pos.x + sizeRender.x / 2.0f + 30, pos.y, fireDegats, speedFire };
	fireStruct_5 = { pos.x + sizeRender.x / 2.0f - 30, pos.y, fireDegats, speedFire };
	int angleFire{ 6 };

	switch (fireMode)
	{
	case 1:
		PlayingState::addFireShip(new FireBallShip(fireStruct));
		break;
	case 2:
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		break;
	case 3:
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		break;
	case 4:
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -angleFire));
		break;
	case 5:
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -angleFire));
		break;
	case 6:
		fireDegats = 35;
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -angleFire));
		break;
	case 7:
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -2 * angleFire));
		break;
	case 8:
		fireDegats = 40;
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -2 * angleFire));
		break;
	case 9:
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -2 * angleFire));
		break;
	case 10:
		fireDegats = 45;
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct_5));
		PlayingState::addFireShip(new FireBallShip(fireStruct));
		PlayingState::addFireShip(new FireBallShip(fireStruct5));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new FireBallShip(fireStruct5, -2 * angleFire));
		break;
	}
	ammunition--;
}
void PurpleShip::fire()
{
	soundFire->setVolume(Setting::getVolume());
	soundFire->play();

	fireStruct = { pos.x + sizeRender.x / 2.0f, pos.y, fireDegats, speedFire };
	fireStruct5 = { pos.x + sizeRender.x / 2.0f + 10, pos.y, fireDegats, speedFire };
	fireStruct_5 = { pos.x + sizeRender.x / 2.0f - 10, pos.y, fireDegats, speedFire };
	int angleFire{ 5 };

	switch (fireMode)
	{
	case 1:
		PlayingState::addFireShip(new GreenFireShip(fireStruct));
		break;
	case 2:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		break;
	case 3:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		break;
	case 4:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -angleFire));
		break;
	case 5:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -angleFire));
		break;
	case 6:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -2 * angleFire));
		break;
	case 7:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -2 * angleFire));
		break;
	case 8:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 3 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -3 * angleFire));
		break;
	case 9:
		fireDegats = 20;
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 3 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -3 * angleFire));
		break;
	case 10:
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 4 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 3 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, 2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5, angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct_5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -2 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -3 * angleFire));
		PlayingState::addFireShip(new GreenFireShip(fireStruct5, -4 * angleFire));
		break;
	}
	ammunition--;
}
void OrangeShip::fire()
{
	soundFire->setVolume(Setting::getVolume());
	soundFire->play();

	fireStruct = { pos.x + sizeRender.x / 2.0f, pos.y - 10, fireDegats, speedFire };
	fireStruct5 = { pos.x + sizeRender.x / 2.0f + 15, pos.y, fireDegats, speedFire };
	fireStruct_5 = { pos.x + sizeRender.x / 2.0f - 15, pos.y, fireDegats, speedFire };
	fireStruct10 = { pos.x + sizeRender.x / 2.0f + 30, pos.y + 10, fireDegats, speedFire };
	fireStruct_10 = { pos.x + sizeRender.x / 2.0f - 30, pos.y + 10, fireDegats, speedFire };


	switch (fireMode)
	{
	case 1:
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		break;
	case 2:
		fireDegats = 25;
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		break;
	case 3:
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		break;
	case 4:
		fireDegats = 30;
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		break;
	case 5:
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		break;
	case 6:
		fireDegats = 35;
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		break;
	case 7:
		fireDegats = 40;
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		break;
	case 8:
		PlayingState::addFireShip(new RedFireShip(fireStruct_10));
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		PlayingState::addFireShip(new RedFireShip(fireStruct10));
		break;
	case 9:
		fireDegats = 45;
		PlayingState::addFireShip(new RedFireShip(fireStruct_10));
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		PlayingState::addFireShip(new RedFireShip(fireStruct10));
		break;
	case 10:
		fireDegats = 50;
		PlayingState::addFireShip(new RedFireShip(fireStruct_10));
		PlayingState::addFireShip(new RedFireShip(fireStruct_5));
		PlayingState::addFireShip(new RedFireShip(fireStruct));
		PlayingState::addFireShip(new RedFireShip(fireStruct5));
		PlayingState::addFireShip(new RedFireShip(fireStruct10));
		break;
	}
	ammunition--;
}
