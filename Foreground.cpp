 #include "Foreground.h"
#include "Setting.h"
#include "PlayingState.h"

Foreground::Foreground()
{
	posWindow = sf::Vector2f(Engine::view.getViewport().left, Engine::view.getViewport().top);
	clockGame.restart();
	minutes = 0;
	frames = 0;
	bordure = 20.;
	wide = 200;
	spaceTextBar = 5.;
	outline = 3.;
	charSize = 20;
	posText = bordure + wide + spaceTextBar;
	fps_s = "Undefine";
	iconUpgrade = Ressources::itemUpgrade;
	float scale{ 0.32f };
	iconUpgrade.setScale(scale, scale);


	font = Ressources::font_JAi_____;
}

void Foreground::show(sf::RenderWindow* window, Ship* ship)
{
	updateView(window);
	if (Setting::getStateFPS())
		fps(window);
	lifeBar(window, ship);
	shieldBar(window, ship);
	ammunition(window, ship);
	timer(window);
	score(window, ship);
	coin(window);
	modeFire(window, ship);
}

void Foreground::lifeBar(sf::RenderWindow* window, Ship* ship)
{
	sf::Vector2f sizeMax{ wide - 2 * outline, 20 };
	sf::Vector2f posLifeBar{ bordure, 20 };
	float healthShip{ ship->getHealth() };
	float ratio{ healthShip / ship->getMaxHealth() };

	sf::RectangleShape health_bar;
	health_bar.setPosition(sf::Vector2f(posLifeBar.x + outline + posWindow.x, posLifeBar.y + posWindow.y));
	health_bar.setSize(sf::Vector2f(ratio * sizeMax.x, sizeMax.y));
	health_bar.setFillColor(PlayingState::getColorLife(ratio));

	sf::RectangleShape health_bar_outline;
	health_bar_outline.setSize(sizeMax);
	health_bar_outline.setPosition(health_bar.getPosition());
	health_bar_outline.setFillColor(sf::Color::Transparent);
	health_bar_outline.setOutlineThickness(outline);
	health_bar_outline.setOutlineColor(sf::Color(100, 100, 100));

	sf::Text textHealth("", font, charSize);
	textHealth.setPosition(posText + posWindow.x, posLifeBar.y - 8);


	if (healthShip < 10)
		textHealth.setString("0" + std::to_string(int(healthShip)));
	else 
		textHealth.setString(std::to_string(int(healthShip)));


	window->draw(textHealth);
	window->draw(health_bar_outline);
	window->draw(health_bar);
}

void Foreground::shieldBar(sf::RenderWindow* window, Ship* ship)
{
	sf::Vector2f sizeMax(wide - 2 * outline, 15);
	sf::Vector2f posShieldBar{ bordure, 48 };
	float shieldShip{ ship->getShield() };

	sf::RectangleShape shield_bar;
	shield_bar.setPosition(sf::Vector2f(posShieldBar.x + posWindow.x + outline, posShieldBar.y + posWindow.y));
	shield_bar.setSize(sf::Vector2f(shieldShip / ship->getMaxShield() * sizeMax.x, sizeMax.y));
	shield_bar.setFillColor(sf::Color(68, 146, 234));

	sf::RectangleShape shield_bar_outline;
	shield_bar_outline.setPosition(shield_bar.getPosition());
	shield_bar_outline.setSize(sizeMax);
	shield_bar_outline.setOutlineColor(sf::Color(100, 100, 100));
	shield_bar_outline.setOutlineThickness(outline);
	shield_bar_outline.setFillColor(sf::Color::Transparent);


	sf::Text textShield("", font, charSize);
	textShield.setPosition(posText + posWindow.x, posShieldBar.y - 8);


	if (shieldShip < 10)
		textShield.setString("0" + std::to_string(int(shieldShip)));
	else
		textShield.setString(std::to_string(int(shieldShip)));


	window->draw(textShield);
	window->draw(shield_bar_outline);
	window->draw(shield_bar);
}

void Foreground::timer(sf::RenderWindow* window)
{
	sf::Text textTimer("", font, 25);
	textTimer.setPosition(window->getSize().x / 2 - 25 + posWindow.x, 12 + posWindow.y);


	int tempsGame{ (int)clockGame.getElapsedTime().asSeconds() - (int)PlayingState::getTempsPause() };

	minutes = tempsGame / 60;
	secondes = tempsGame % 60;

	if (secondes < 10)
		textTimer.setString(std::to_string(minutes) + ":0" + std::to_string(secondes));
	else
		textTimer.setString(std::to_string(minutes) + ":" + std::to_string(secondes));

	window->draw(textTimer);
}

void Foreground::score(sf::RenderWindow* window, Ship* ship)
{
	std::string score{ std::to_string((int)ship->getScore()) };
	sf::Text textScore("", font, 25);

	textScore.setPosition(window->getSize().x - 215 + posWindow.x, 12 + posWindow.y);
	int scoreShip{ ship->getScore() };

	if (scoreShip == 0)
		textScore.setString("Score : 000000");
	else if (scoreShip < 10)
		textScore.setString("Score : 00000" + score);
	else if (scoreShip < 100)
		textScore.setString("Score : 0000" + score);
	else if (scoreShip < 1000)
		textScore.setString("Score : 000" + score);
	else if (scoreShip < 10000)
		textScore.setString("Score : 00" + score);
	else if (scoreShip < 100000)
		textScore.setString("Score : 0" + score);
	else if (scoreShip < 1000000)
		textScore.setString("Score : " + score);
	else if (scoreShip > 999999)
		textScore.setString("Score : 999999");


	window->draw(textScore);
}

void Foreground::ammunition(sf::RenderWindow* window, Ship* ship)
{
	sf::RectangleShape rectAmmunition;
	int ammunition = ship->getAmmunition();
	int ammunitionMax = ship->getAmmunitionMax();
	sf::Vector2f posAmmun{ bordure, 70 };
	sf::Vector2f sizeBar{ wide, 8 };


	rectAmmunition.setPosition(sf::Vector2f(posAmmun.x + posWindow.x, posAmmun.y + posWindow.y));
	rectAmmunition.setSize(sf::Vector2f(float(ammunition) / float(ammunitionMax) * sizeBar.x, sizeBar.y));
	rectAmmunition.setFillColor(sf::Color::Yellow);


	std::string amun{ std::to_string(ammunition) + "/" + std::to_string(ammunitionMax) };

	sf::Text textAmmu("", font, charSize);
	textAmmu.setPosition(posText + posWindow.x, posAmmun.y + posWindow.y - 6);
	textAmmu.setCharacterSize(charSize);
	textAmmu.setString(amun);



	window->draw(textAmmu);
	window->draw(rectAmmunition);
}

void Foreground::fps(sf::RenderWindow* window)
{
	frames++;

	if (frames_clock.getElapsedTime().asSeconds() >= 1) {
		fps_s = std::to_string(frames);
		frames = 0;
		frames_clock.restart();
	}

	sf::Text textFps("", font, 12);
	textFps.setPosition(bordure + posWindow.x, posWindow.y);
	textFps.setCharacterSize(12);
	textFps.setString("FPS : " + fps_s);


	window->draw(textFps);
}

void Foreground::updateView(sf::RenderWindow* window)
{
	posWindow = sf::Vector2f(Engine::view.getCenter().x - Engine::getWidowSize().x / 2, Engine::view.getViewport().top);
}

void Foreground::coin(sf::RenderWindow* window)
{
	sf::Sprite spriteCoin(Ressources::coin);
	spriteCoin.setTextureRect(sf::IntRect(Ressources::infosCoin.posTexture, Ressources::infosCoin.sizePixel));
	spriteCoin.setPosition(window->getSize().x - 179 + posWindow.x, 50 + posWindow.y);

	std::string coinInfo{ ": " + std::to_string(Setting::getCoin()) };
	sf::Text textCoin("", font, 25);
	textCoin.setString(coinInfo);
	textCoin.setPosition(spriteCoin.getPosition().x + 50, spriteCoin.getPosition().y);

	window->draw(spriteCoin);
	window->draw(textCoin);
}

void Foreground::modeFire(sf::RenderWindow* window, Ship* ship)
{
	int currentFireMode{ ship->getCurrentFireMode() };
	int maxFireMode{ ship->getMaxFireMode() };
	float espaceIconUpgrade{ wide / float(maxFireMode) };
	int colorG{ 100 };

	for (int i{ 0 }; i < maxFireMode; i++) {
		sf::Vector2f coord{ bordure + espaceIconUpgrade * float(i) + posWindow.x, 85 + posWindow.y };

		if (i < currentFireMode)
			iconUpgrade.setColor(sf::Color::Yellow);
		else
			iconUpgrade.setColor(sf::Color(colorG, colorG, colorG));

		iconUpgrade.setPosition(coord);

		window->draw(iconUpgrade);
	}
}
