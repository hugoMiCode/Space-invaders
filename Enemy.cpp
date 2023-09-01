#include "Enemy.h"
#include "Animation.h"
#include "PlayingState.h"

Enemy::Enemy(Path* path, float tempsVieAsSeconds) : Entity(pos.x, pos.y)
{
	fireDegats = 20;
	tempsAffichageLifeBar = 4.f;

	pbFire = 50;
	pbItem = 100;
	fonctionItem = rand() % 7 - 2;

	tempsPausePrec = PlayingState::getTempsPause();


	tempsVieS = tempsVieAsSeconds;
	this->path = path;
}

void Enemy::update()
{
	tempsPause = PlayingState::getTempsPause() - tempsPausePrec;
	float t{ clockUpdate.getElapsedTime().asSeconds() - tempsPause };

	updateHitBox();
	updateCenterRender();

	if (!clearOut) {
		sf::Vector3f newPos(path->path(t, sizeRender));

		if (newPos.z) {
			if (!ckeckWindow())
				dead = true;
			else if (checkLive()) {
				clockUpdate.restart();
				clearOut = true;
				path = new Path("fire");
			}
		}
		else
			pos = sf::Vector2f(newPos.x, newPos.y);
	}
	else {

		sf::Vector2f newPos(path->path(t * 0.1, 180));
		pos = sf::Vector2f(pos.x + newPos.x,
			pos.y + newPos.y);

		if (!ckeckWindow())
			dead = true;
	}
}

void Enemy::show(sf::RenderWindow* window)
{
	if (health != maxHealth && clockTempsAffichage.getElapsedTime().asSeconds() - tempsPause < tempsAffichageLifeBar) {
		health_bar.setPosition(pos.x, pos.y - 6);
		health_bar.setSize(sf::Vector2f(health / maxHealth * sizeRender.x, 4));
		health_bar.setFillColor(PlayingState::getColorLife((health / maxHealth)));
		window->draw(health_bar);
	}

	enemy.setPosition(pos);
	window->draw(enemy);
}

void Enemy::checkHit(Ship* ship)
{
	PlayingState::checkHitEnemy(ship, this);
}

bool Enemy::checkLive()
{
	return tempsVieS <= clockTempsVie.getElapsedTime().asSeconds() - tempsPause;
}

bool Enemy::ckeckWindow()
{
	return pos.x + sizeRender.x + Ship::getDepView() >= 0
		&& pos.y + sizeRender.y >= 0
		&& pos.x + Ship::getDepView() <= Engine::getWidowSize().x
		&& pos.y <= Engine::getWidowSize().y;
}

void Enemy::hit(float degats)
{
	health -= degats;
	clockTempsAffichage.restart();

	if (health <= 0) {
		dead = true;
		health = 0;

		Animation::explosion(centerRender);
		PlayingState::dropCoin(centerRender);

		if (checkDropItem())
			dropItem();
	}
}

void Enemy::canFire(Ship* ship)
{
	int nombre_aleatoire = 0;
	nombre_aleatoire = rand() % 100;


	if (clockFire.getElapsedTime().asSeconds() - tempsPause >= 3) {
		clockFire.restart();

		if (nombre_aleatoire <= pbFire)
			fire(ship);
	}
}

void Enemy::dropItem()
{
	switch (fonctionItem)
	{
	case -2:
		PlayingState::dropItem(new PurpleShipItem(centerRender));
		break;
	case -1:
		PlayingState::dropItem(new RedShipItem(centerRender));
		break;
	case 0:
		PlayingState::dropItem(new OrangeShipItem(centerRender));
		break;
	case 1:
		PlayingState::dropItem(new UpFireMode(centerRender));
		break;
	case 2:
		PlayingState::dropItem(new Shield(centerRender));
		break;
	case 3:
		PlayingState::dropItem(new Life(centerRender));
		break;
	case 4:
		PlayingState::dropItem(new Ammo(centerRender));
		break;
	}
}

bool Enemy::checkDropItem()
{
	//ne pas mettre de rand() !!
	return rand() % 100 <= pbItem;
}

bool Enemy::isDead()
{
	return dead;
}

float Enemy::getScoredeath()
{
	return scoreDeath;
}

int Enemy::getDegats()
{
	return fireDegats;
}

sf::Clock Enemy::getClockLastHit()
{
	return clockTempsAffichage;
}

void Enemy::setColor(sf::Color colorSprite)
{
	enemy.setColor(colorSprite);
}
