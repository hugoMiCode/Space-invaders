#include "Background.h"
#include "PlayingState.h"
#include "Engine.h"
#include "Animation.h"
#include "Ship.h"

bool Background::acc;
bool Background::finAcc;

Background::Background()
{
	tempsPause = 0.f;
	tempsPausePrec = 0.f;
	tempsAcc = 0.f;

	acc = false;
	speed = 1.f;
	/*
		spriteElement = Ressources::planet_1;
		sizeRender = Ressources::getSizeRenderPlanet();
		scaleEntity = Ressources::infosPlanet_1.scale;
		speedElement = 0.1f;
		showTime = 2.f;
	*/

	/*
		sf::Sprite spriteElement
		sf::Vector2f sizeRender
		sf::Vector2i sizePixel
		int posX
		float scale
		float speedElement
		float showTime
		float timeToAppear
	*/
	StructBackground sPlanet_1{
		Ressources::planet_1,
		Ressources::getSizeRenderPlanet_1(),
		Ressources::infosPlanet_1.sizePixel,
		500,
		Ressources::infosPlanet_1.scale,
		0.1f,
		5.f,
		0.f
	};
	StructBackground sPlanetRouge{
		Ressources::planetRouge,
		Ressources::getSizeRenderPlanetRouge(),
		Ressources::infosPlanetRouge.sizePixel,
		200,
		Ressources::infosPlanetRouge.scale,
		0.06f,
		0.f,
		0.f
	};
	StructBackground sPlanetBleu{
		Ressources::planetBleu,
		Ressources::getSizeRenderPlanetBleu(),
		Ressources::infosPlanetBleu.sizePixel,
		-10,
		Ressources::infosPlanetBleu.scale,
		0.1f,
		40.f,
		10.f
	};
	StructBackground sShootingStar{
		Ressources::shootingStar,
		Ressources::getSizeRenderShootingStar(),
		Ressources::infosShootingStar.sizePixel,
		250,
		Ressources::infosShootingStar.scale,
		1.f,
		40.f,
		10.f
	};

	StructBackground sCloud{
		Ressources::cloud,
		Ressources::getSizeRenderCloud(),
		Ressources::infosCloud.sizePixel,
		50,
		Ressources::infosCloud.scale,
		0.02f,
		30.f,
		0.f
	};

	for (unsigned int i{ 0 }; i < 30; i++)
		rains.push_back(new Rain(rand() % int(Engine::getWidowSize().x + Ship::getDepView()) - Ship::getDepView() / 2,
								 rand() % int(Engine::getWidowSize().y)));

	planets.push_back(new Planet(sPlanetRouge));
	planets.push_back(new Planet(sPlanet_1));
	planets.push_back(new Planet(sPlanetBleu));

	shootingStars.push_back(new ShootingStar(sShootingStar));

	cloud.push_back(new Cloud(sCloud));


	spaceBackground1 = Ressources::spaceBackground;
	spaceBackground2 = Ressources::spaceBackground;

	spaceBackgroundSizeY = Ressources::infosSpaceBackground.sizePixel.y;

	spaceBackground2.setPosition(sf::Vector2f(-Ship::getDepView(), 0));
	spaceBackground1.setPosition(sf::Vector2f(-Ship::getDepView(), -spaceBackgroundSizeY));
}

void Background::show(sf::RenderWindow* window)
{
	window->draw(spaceBackground2);
	window->draw(spaceBackground1);
	Animation::showAtomicBomb(window);


	for (unsigned int i{ 0 }; i < planets.size(); i++)
		planets[i]->show(window);

	for (unsigned int i{ 0 }; i < rains.size(); i++)
		rains[i]->show(window);

	for (unsigned int i{ 0 }; i < shootingStars.size(); i++)
		shootingStars[i]->show(window);

	for (unsigned int i{ 0 }; i < cloud.size(); i++)
		cloud[i]->show(window);
}

void Background::update()
{
	tempsPause = PlayingState::getTempsPause();

	if (tempsPause != tempsPausePrec) {
		tempsPausePrec = tempsPause;
		backClock.restart();
		accClock.restart();
	}
	if (tempsPause == tempsPausePrec)
		tempsAcc += accClock.restart().asMicroseconds();


	sf::Time time = backClock.restart();

	if (finAcc)
		finAcc = false;

	if (acc) {
		speed = normal(tempsAcc / 1000000.f);
		if (tempsAcc > 5 * 1000000.f) {
			finAcc = true;
			acc = false;
		}
	}
	else {
		speed = 1;
		tempsAcc = 0.f;
	}

	for (unsigned int i{ 0 }; i < shootingStars.size(); i++) {
		shootingStars[i]->update(speed);

		for (unsigned int j{ 0 }; j < planets.size(); j++)
			if (planets[j]->isIn() && shootingStars[i]->isIn() && PlayingState::hitBox(planets[j], shootingStars[i])) {
				Animation::atomicBomb(shootingStars[i]->getCenterRender());
				planets[j]->impacte();
				shootingStars[i]->impacte();
			}
	}

	for (unsigned int i{ 0 }; i < rains.size(); i++)
		rains[i]->update(speed);

	for (unsigned int i{ 0 }; i < planets.size(); i++)
		planets[i]->update(speed);

	for (unsigned int i{ 0 }; i < cloud.size(); i++)
		cloud[i]->update(speed);

	if (spaceBackground1.getPosition().y > Engine::getWidowSize().y)
		spaceBackground1.setPosition(sf::Vector2f(-Ship::getDepView(), spaceBackground2.getPosition().y - spaceBackgroundSizeY));
	if (spaceBackground2.getPosition().y > Engine::getWidowSize().y)
		spaceBackground2.setPosition(sf::Vector2f(-Ship::getDepView(), spaceBackground1.getPosition().y - spaceBackgroundSizeY));

	spaceBackground1.move(0, speed * 0.08f * time.asMilliseconds());
	spaceBackground2.move(0, speed * 0.08f * time.asMilliseconds());
}

float Background::normal(float x)
{
	return (0.3989f * exp(-0.5f * pow(x - 2, 2))) * 15 + 1;
}

void Background::setAcc(bool ac)
{
	acc = ac;
}

bool Background::getAcc()
{
	return acc;
}

bool Background::getFinAcc()
{
	return finAcc;
}