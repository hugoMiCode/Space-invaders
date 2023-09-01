#include "PlayingState.h"
#include "KeyControl.h"
#include "Pause.h"
#include "GameOver.h"
#include "ItemType.h"
#include "Setting.h"
#include "Animation.h"
#pragma warning(disable : 4996) 
float PlayingState::temps_pause{};
float PlayingState::temps_pausePrec{};
bool PlayingState::pause{};
std::vector<Item*> PlayingState::items{};
std::vector<std::pair<Coin*, sf::Clock>> PlayingState::coins{};
std::vector<Fire*> PlayingState::fireEnemy{};
std::vector<Fire*> PlayingState::fireShip{};

/*
	int fireMode;
	int ammunition;
	int ammunitionMax;
	float score;
	float health;
	float maxHealth;
*/
void PlayingState::init()
{
	int ammunition{ 750 };
	float health{ 100 };

	infosShip = { 
		1, ammunition, ammunition, 0, health, health, 0, 100,
		sf::Vector2f((Engine::getWidowSize().x - Ressources::getSizeRenderPurpleShip().x) / 2.f, 650)
	};

	n = 0;
	pause = false;
	temps_pause = 0;
	temps_pausePrec = 0;
	Engine::setColor(sf::Color(25, 25, 112));
	ship = new PurpleShip(infosShip);
	//ship = new RedShip(infosShip);
	//ship = new OrangeShip(infosShip);
	background = new Background();
	forground = new Foreground();
	level = new Level(n);
}

void PlayingState::loop()
{
	infosShip = { 
		ship->getCurrentFireMode(), 
		ship->getAmmunition(), 
		ship->getAmmunitionMax(), 
		ship->getScore(),
		ship->getHealth(), 
		ship->getMaxHealth(), 
		ship->getShield(), 
		ship->getMaxShield(), 
		ship->getPosition() 
	};


	if (pause) {
		temps_pause += clock_pause.getElapsedTime().asSeconds();
		pause = false;
	}

	level->update();
	
	level->checkHitEnemy(ship);
	checkHitShip();

	if (Background::getFinAcc())
		addLevel();

	if (level->isEmpty() && !Background::getAcc())
		Background::setAcc(true); // affichage wave(waveACC / WaveTotal)

	level->fire(ship);

	if (ship->canFire())
		ship->fire();
	fire_update();
	updateItem();
	Animation::updateCoin(coins);

	background->update();

	if (ship->isDead())
		gameOver();
}

void PlayingState::render(sf::RenderWindow* window)
{	
	Engine::setColor(sf::Color(25, 25, 112));

	ship->update(window);
	
	background->show(window);
	show_item(window);
	Animation::showExplosion(window);
	show_fire(window);
	level->show_entity(window);
	Animation::showHit(window);
	Animation::showGlitter(window);
	forground->show(window, ship);
	ship->show(window);
	Animation::showSmoke(window, ship->getCenterRender());
}

void PlayingState::key_pressed(int key, sf::RenderWindow* window)
{
	image = window->capture();
	if (key == sf::Keyboard::Escape) {
		clock_pause.restart();
		pause = true;
		Engine::stateAdd(new Pause(image));
	}
}

void PlayingState::joystick_pressed(int key, sf::RenderWindow* window)
{
	image = window->capture();
	if (key == 7) {
		clock_pause.restart();
		pause = true;
		Engine::stateAdd(new Pause(image));
	}
}

void PlayingState::addLevel()
{
	n++;
	level = new Level(n);
}

void PlayingState::dropItem(Item* item)
{
	items.push_back(item);
}

void PlayingState::dropCoin(sf::Vector2f pos)
{
	coins.push_back(std::pair<Coin*, sf::Clock>{ new Coin(pos), sf::Clock() });
}

void PlayingState::updateItem()
{
	if (!items.empty())
		for (Item* item : items)
			item->update();
	checkHitItem();
	

	if (!coins.empty())
		for (std::pair<Coin*, sf::Clock> coin : coins)
			coin.first->update();
	checkHitCoin();
}

void PlayingState::show_item(sf::RenderWindow* window)
{
	if (!items.empty())
		for (unsigned int i{ 0 }; i < items.size(); i++)
			if (hitWall(window, items[i]))
				suprItem(i);
			else
				items[i]->show(window);


	if (!coins.empty())
		for (unsigned int i{ 0 }; i < coins.size(); i++)
			if (hitWall(window, coins[i].first))
				suprCoin(i);
			else
				coins[i].first->show(window);
}

bool PlayingState::hitWall(sf::RenderWindow* window, Entity* entity)
{
	float x{ entity->getPosition().x };
	float y{ entity->getPosition().y };


	return x <= -entity->getSizeRender().x - Ship::getDepView()
		|| y <= -entity->getSizeRender().y
		|| x >= window->getSize().x + Ship::getDepView()
		|| y >= window->getSize().y;
}

float PlayingState::getTempsPause()
{
	return temps_pause;
}

bool PlayingState::hitBox(Entity* entity1, Entity* entity2)
{
	std::vector<sf::RectangleShape> hitBox1{ entity1->getTabHitBox() };
	std::vector<sf::RectangleShape> hitBox2{ entity2->getTabHitBox() };

	if (!hitBox1.empty() && !hitBox2.empty())
		for (unsigned int i{ 0 }; i < hitBox1.size(); i++)
			for (unsigned int j{ 0 }; j < hitBox2.size(); j++)
				if (hitBox1[i].getGlobalBounds().intersects(hitBox2[j].getGlobalBounds()))
					return true;

	return false;
}

void PlayingState::suprItem(unsigned int i)
{
	delete items[i];
	items.erase(items.begin() + i);
}

void PlayingState::suprCoin(unsigned int i)
{
	delete coins[i].first;
	coins.erase(coins.begin() + i);
}

void PlayingState::suprFireShip(unsigned int i)
{
	delete fireShip[i];
	fireShip.erase(fireShip.begin() + i);
}

void PlayingState::suprFireEnemy(unsigned int i)
{
	delete fireEnemy[i];
	fireEnemy.erase(fireEnemy.begin() + i);
}

void PlayingState::show_fire(sf::RenderWindow* window)
{
	if (!fireEnemy.empty())
		for (unsigned int i{ 0 }; i < fireEnemy.size(); i++)
			if (fireEnemy[i]->hitWall(window))
				suprFireEnemy(i);
			else if (fireEnemy[i]->endTimeLife()) {
				fireEnemy[i]->explo();
				suprFireEnemy(i);
			}
			else
				fireEnemy[i]->show(window);

	if (!fireShip.empty())
		for (unsigned short int i{ 0 }; i < fireShip.size(); i++)
			if (fireShip[i]->hitWall(window))
				suprFireShip(i);
			else
				fireShip[i]->show(window);
}

void PlayingState::fire_update()
{
	for (Fire* const fire : fireEnemy)
		fire->update(ship);
	for (Fire* const fire : fireShip)
		fire->update(ship);
}

void PlayingState::checkHitEnemy(Ship* ship, Enemy* enemy)
{
	if (hitBox(ship, enemy))
		ship->hit(10);


	if (!fireShip.empty())
		for (unsigned int i{ 0 }; i < fireShip.size(); i++)
			if (hitBox(fireShip[i], enemy)) {
				enemy->hit(fireShip[i]->getDegats());
				ship->addScore(10);

				if (enemy->isDead())
					ship->addScore(enemy->getScoredeath());
				else
					fireShip[i]->explo();

				suprFireShip(i);
			}
}

void PlayingState::checkHitShip()
{
	if (!fireEnemy.empty())
		for (unsigned int i{ 0 }; i < fireEnemy.size(); i++)
			if (hitBox(fireEnemy[i], ship)) {
				ship->hit(fireEnemy[i]->getDegats());
				ship->addScore(-50); // enlever la constante.
				fireEnemy[i]->explo();
				suprFireEnemy(i);
			}
}

void PlayingState::checkHitCoin()
{
	if (!coins.empty())
		for (unsigned int i{ 0 }; i < coins.size(); i++)
			if (hitBox(coins[i].first, ship)) {
				Setting::addCoin(coins[i].first->getCoinValue());
				ship->addScore(coins[i].first->getScore());
				Animation::glitterItem(coins[i].first->getCenterRender());
				suprCoin(i);
			}
}

void PlayingState::checkHitItem()
{
	if (!items.empty())
		for (unsigned int i{ 0 }; i < items.size(); i++)
			if (hitBox(items[i], ship)) {
				sf::Vector2f center{ ship->getCenterRender() };
				switch (items[i]->getFonction())
				{
				case -2:
					Animation::smoke(center);
					delete ship;
					ship = new PurpleShip(infosShip);
					break;
				case -1:
					Animation::smoke(center);
					delete ship;
					ship = new RedShip(infosShip);
					break;
				case 0:
					Animation::smoke(center);
					delete ship;
					ship = new OrangeShip(infosShip);
					break;
				case 1:
					ship->addFireMode();
					break;
				case 2:
					ship->addShield(items[i]->getDonne());
					break;
				case 3:
					ship->addHealth(items[i]->getDonne());
					break;
				case 4:
					ship->addAmmu(items[i]->getDonne());
					break;
				}
				Animation::glitterItem(items[i]->getCenterRender());
				ship->addScore(items[i]->getScore());
				suprItem(i);
			}
}

void PlayingState::gameOver()
{
	Engine::stateAdd(new GameOver);
}

void PlayingState::addFireShip(Fire* fire)
{
	fireShip.push_back(fire);
}

void PlayingState::addFireEnemy(Fire* fire)
{
	fireEnemy.push_back(fire);
}

sf::Color PlayingState::getColorLife(float x)
{
	float ratio{ x };
	int r{ 255 };
	int v{ 255 };
	int b{ 0 };

	if (x >= 0.5f) {
		ratio -= 0.5f;
		ratio *= 2.f;
		r = ratio * 255;
		r = 255 - r;
	}
	else {
		ratio *= 2;
		v = ratio * 255;
	}


	return sf::Color(r, v, b);
}

PlayingState::~PlayingState()
{
	if (!items.empty())
		for (unsigned int i{ 0 }; i < items.size(); i++)
			suprItem(i);
	if (!coins.empty())
		for (unsigned int i{ 0 }; i < coins.size(); i++)
			suprCoin(i);
	if (!fireEnemy.empty())
		for (unsigned int i{ 0 }; i < fireEnemy.size(); i++)
			suprFireEnemy(i);
	if (!fireShip.empty())
		for (unsigned int i{ 0 }; i < fireShip.size(); i++)
			suprFireShip(i);

	delete ship;
	delete background;
	delete forground;
	delete level;
}
