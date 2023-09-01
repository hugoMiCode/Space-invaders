//#include "Wave.h"
#include "PlayingState.h"
#include "Animation.h"

Wave::Wave(int nbentity, int lvlEntity, std::string path, float tempsAvApp, float tempsVieAsSeconds)
{
	entity = nbentity;
	this->path = new Path(path);
	this->lvlEntity = lvlEntity;
	this->tempsAvApp = tempsAvApp;
	tempsVieS = tempsVieAsSeconds;
	tempsPause = 0;
	tempsPausePrec = 0;
	spawnEnemy = 0;
}

void Wave::show(sf::RenderWindow* window)
{
	if (!enemys.empty())
		for (unsigned int i{ 0 }; i < enemys.size(); i++)
			enemys[i]->show(window);
}

void Wave::update()
{
	
	tempsPause = PlayingState::getTempsPause();

	if (tempsPause == tempsPausePrec)
		spawnEnemy += addEnemy.restart().asMicroseconds();
	else {
		tempsPausePrec = tempsPause;
		addEnemy.restart();
	}

	Animation::updateHitShip(enemys);

	if (entity != 0 && spawnEnemy > 0.8f * 1000000.f && clockApp.getElapsedTime().asSeconds() >= tempsAvApp) {
		switch (lvlEntity)
		{
		case 1:
			enemys.push_back(new Eagle5(path, tempsVieS));
			break;
		case 2:
			enemys.push_back(new DixoveryOne(path, tempsVieS));
			break;
		case 3:
			enemys.push_back(new PrawnMothership(path, tempsVieS));
			break;
		case 4:
			enemys.push_back(new MondoshawanVessel(path, tempsVieS));
			break;
		case 5:
			enemys.push_back(new Nostromo(path, tempsVieS));
			break;
		case 6:
			enemys.push_back(new Narada(path, tempsVieS));
			break;
		case 7:
			enemys.push_back(new MilleniumFalcon(path, tempsVieS));
			break;
		}
		spawnEnemy = 0;
		entity--;
	}
	
	if (!enemys.empty())
		for (unsigned int i{ 0 }; i < enemys.size(); i++)
			if (enemys[i]->isDead())
				supr_enemy(i);
			else 
				enemys[i]->update();
}

void Wave::checkHit(Ship* ship)
{
	if (!enemys.empty())
		for (unsigned int i{ 0 }; i < enemys.size(); i++) {
			enemys[i]->checkHit(ship);

			if (enemys[i]->isDead())
				ship->addScore(enemys[i]->getScoredeath());
		}
}

void Wave::fire(Ship* ship)
{
	if (!enemys.empty())
		for (unsigned int i{ 0 }; i < enemys.size(); i++)
			if (!enemys[i]->isDead())
				enemys[i]->canFire(ship);
}

void Wave::supr_enemy(unsigned int i)
{
	delete enemys[i];
	enemys.erase(enemys.begin() + i);
}

bool Wave::isEmpty()
{
	return enemys.empty();
}

int Wave::getEntity()
{
	return entity;
}
