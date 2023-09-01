#include "Animation.h"

sf::Vector2i Animation::sizePixelExplosion;
sf::Sprite* Animation::spriteExplosion;
std::vector<std::pair<sf::Vector2f, sf::Clock>> Animation::coordExplosion;

sf::Vector2i Animation::sizePixelHit;
sf::Sprite* Animation::spriteHit;
std::vector<std::pair<sf::Vector2f, sf::Clock>> Animation::coordHit;

sf::Vector2i Animation::sizePixelGlitter;
sf::Sprite* Animation::spriteGlitter;
std::vector<std::pair<sf::Vector2f, sf::Clock>> Animation::coordGlitter;

sf::Vector2i Animation::sizePixelSmoke;
sf::Sprite* Animation::spriteSmoke;
std::vector<std::pair<sf::Vector2f, sf::Clock>> Animation::coordSmoke;

sf::Vector2i Animation::sizePixelAtomicBomb;
sf::Sprite* Animation::spriteAtomicBomb;
std::vector<std::pair<sf::Vector2f, sf::Clock>> Animation::coordAtomicBomb;


void Animation::init()
{
	sizePixelExplosion = Ressources::infosExplosion.sizePixel;
	sizePixelHit = Ressources::infosHit.sizePixel;
	sizePixelGlitter = Ressources::infosGlitter.sizePixel;
	sizePixelSmoke = Ressources::infosSmoke.sizePixel;
	sizePixelAtomicBomb = Ressources::infosAtomicBomb.sizePixel;

	spriteExplosion = &Ressources::explosion;
	spriteHit = &Ressources::hit;
	spriteGlitter = &Ressources::glitter;
	spriteSmoke = &Ressources::smoke;
	spriteAtomicBomb = &Ressources::atomicBomb;

	spriteExplosion->setOrigin(sf::Vector2f(Ressources::infosExplosion.sizePixel) / 2.f);
	spriteHit->setOrigin(sf::Vector2f(Ressources::infosHit.sizePixel) / 2.f);
	spriteGlitter->setOrigin(sf::Vector2f(Ressources::infosGlitter.sizePixel) / 2.f);
	spriteSmoke->setOrigin(sf::Vector2f(Ressources::infosSmoke.sizePixel) / 2.f);
	spriteAtomicBomb->setOrigin(sf::Vector2f(Ressources::infosAtomicBomb.sizePixel) / 2.f);
}


void Animation::explosion(sf::Vector2f pos)
{
	coordExplosion.push_back(std::pair<sf::Vector2f, sf::Clock>{ pos, sf::Clock() });
}

void Animation::hit(sf::Vector2f pos)
{
	coordHit.push_back(std::pair<sf::Vector2f, sf::Clock>{ pos, sf::Clock() });
}

void Animation::glitterItem(sf::Vector2f pos)
{
	coordGlitter.push_back(std::pair<sf::Vector2f, sf::Clock>{ pos, sf::Clock() });
}

void Animation::smoke(sf::Vector2f pos)
{
	coordSmoke.push_back(std::pair<sf::Vector2f, sf::Clock>{ pos, sf::Clock() });
}

void Animation::atomicBomb(sf::Vector2f pos)
{
	coordAtomicBomb.push_back(std::pair<sf::Vector2f, sf::Clock>{ pos, sf::Clock() });
}

void Animation::updateExplosion()
{
	if (!coordExplosion.empty())
		for (unsigned int i{ 0 }; i < coordExplosion.size(); i++) {
			int t{ coordExplosion[i].second.getElapsedTime().asMilliseconds() };
			int nbExplosion{ t / 30 };
			sf::Vector2i vect{ nbExplosion % Ressources::infosExplosion.sizeAnim.x, nbExplosion / Ressources::infosExplosion.sizeAnim.x };
			spriteExplosion->setTextureRect(sf::IntRect(vect.x * sizePixelExplosion.x, vect.y * sizePixelExplosion.y, sizePixelExplosion.x, sizePixelExplosion.y));

			if (nbExplosion >= Ressources::infosExplosion.sizeAnim.x * Ressources::infosExplosion.sizeAnim.y - 1)
				suprExplosion(i);
		}
}
void Animation::updateHit()
{
	if (!coordHit.empty())
		for (unsigned int i{ 0 }; i < coordHit.size(); i++) {
			int t{ coordHit[i].second.getElapsedTime().asMilliseconds() };
			int nbHit{ t / 15 };
			sf::Vector2i vect{ nbHit % Ressources::infosHit.sizeAnim.x, nbHit / Ressources::infosHit.sizeAnim.x };
			spriteHit->setTextureRect(sf::IntRect(vect.x * sizePixelHit.x, vect.y * sizePixelHit.y, sizePixelHit.x, sizePixelHit.y));

			if (nbHit >= Ressources::infosHit.sizeAnim.x * Ressources::infosHit.sizeAnim.y - 1)
				suprHit(i);
		}
}
void Animation::updateGlitter()
{
	if (!coordGlitter.empty())
		for (unsigned int i{ 0 }; i < coordGlitter.size(); i++) {
			int t{ coordGlitter[i].second.getElapsedTime().asMilliseconds() };
			int nbGlitter{ t / 50 };
			sf::Vector2i anim{ nbGlitter % Ressources::infosGlitter.sizeAnim.x, nbGlitter / Ressources::infosGlitter.sizeAnim.x };
			spriteGlitter->setTextureRect(sf::IntRect(anim.x * sizePixelGlitter.x, (2 + anim.y) * sizePixelGlitter.y, sizePixelGlitter.x, sizePixelGlitter.y));
		
			if (nbGlitter >= Ressources::infosGlitter.sizeAnim.x * Ressources::infosGlitter.sizeAnim.y - 1)
				suprGlitter(i);
		}
}

void Animation::updateSmoke()
{
	if (!coordSmoke.empty())
		for (unsigned int i{ 0 }; i < coordSmoke.size(); i++) {
			int t{ coordSmoke[i].second.getElapsedTime().asMilliseconds() };
			int nbSmoke{ t / 17 };
			sf::Vector2i anim{ nbSmoke % Ressources::infosSmoke.sizeAnim.x, nbSmoke / Ressources::infosSmoke.sizeAnim.x };
			spriteSmoke->setTextureRect(sf::IntRect(anim.x * sizePixelSmoke.x,  anim.y * sizePixelSmoke.y, sizePixelSmoke.x, sizePixelSmoke.y));

			if (nbSmoke >= Ressources::infosSmoke.sizeAnim.x * Ressources::infosSmoke.sizeAnim.y - 1)
				suprSmoke(i);
		}
}

void Animation::updateAtomicBomb()
{
	if (!coordAtomicBomb.empty())
		for (unsigned int i{ 0 }; i < coordAtomicBomb.size(); i++) {
			int t{ coordAtomicBomb[i].second.getElapsedTime().asMilliseconds() };
			int nbAtomicBomb{ t / 20 };
			sf::Vector2i anim{ nbAtomicBomb % Ressources::infosAtomicBomb.sizeAnim.x, nbAtomicBomb / Ressources::infosAtomicBomb.sizeAnim.x };
			spriteAtomicBomb->setTextureRect(sf::IntRect(anim.x * sizePixelAtomicBomb.x, anim.y * sizePixelAtomicBomb.y, sizePixelAtomicBomb.x, sizePixelAtomicBomb.y));

			if (nbAtomicBomb >= Ressources::infosAtomicBomb.sizeAnim.x * Ressources::infosAtomicBomb.sizeAnim.y - 1)
				suprAtomicBomb(i);
		}
}

void Animation::updateHitShip(std::vector<Enemy*> enemys)
{
	if (!enemys.empty())
		for (unsigned int i{ 0 }; i < enemys.size(); i++)
			if (enemys[i]->getClockLastHit().getElapsedTime().asMilliseconds() <= 50)
				enemys[i]->setColor(sf::Color(220, 20, 60));
			else
				enemys[i]->setColor(sf::Color::White);
}

void Animation::updateCoin(std::vector<std::pair<Coin*, sf::Clock>>& coins)
{
	sf::Vector2i sizePixelCoin{ Ressources::infosCoin.sizePixel };
	if (!coins.empty())
		for (unsigned int i{ 0 }; i < coins.size(); i++) {
			int t{ coins[i].second.getElapsedTime().asMilliseconds() };
			int nbCoin{ t / 100 };
			int anim{ nbCoin % 6 };
			coins[i].first->setSpriteRect(sf::IntRect(Ressources::infosCoin.posTexture.x + anim * sizePixelCoin.x, Ressources::infosCoin.posTexture.y, sizePixelCoin.x, sizePixelCoin.y));
		}
}


void Animation::suprExplosion(unsigned int i)
{
	coordExplosion.erase(coordExplosion.begin() + i);
}
void Animation::suprHit(unsigned int i)
{
	coordHit.erase(coordHit.begin() + i);
}
void Animation::suprGlitter(unsigned int i)
{
	coordGlitter.erase(coordGlitter.begin() + i);
}

void Animation::suprSmoke(unsigned int i)
{
	coordSmoke.erase(coordSmoke.begin() + i);
}

void Animation::suprAtomicBomb(unsigned int i)
{
	coordAtomicBomb.erase(coordAtomicBomb.begin() + i);
}

void Animation::showExplosion(sf::RenderWindow* window)
{
	updateExplosion();

	if (!coordExplosion.empty())
		for (unsigned int i{ 0 }; i < coordExplosion.size(); i++) {
			spriteExplosion->setPosition(coordExplosion[i].first);
			window->draw(*spriteExplosion);
		}
}
void Animation::showHit(sf::RenderWindow* window)
{
	updateHit();

	if (!coordHit.empty())
		for (unsigned int i{ 0 }; i < coordHit.size(); i++) {
			spriteHit->setPosition(coordHit[i].first);
			window->draw(*spriteHit);
		}
}
void Animation::showGlitter(sf::RenderWindow* window)
{
	updateGlitter();

	if (!coordGlitter.empty())
		for (unsigned int i{ 0 }; i < coordGlitter.size(); i++) {
			spriteGlitter->setPosition(coordGlitter[i].first);
			window->draw(*spriteGlitter);
		}
}

void Animation::showSmoke(sf::RenderWindow* window, sf::Vector2f pos)
{
	updateSmoke();

	if (!coordSmoke.empty())
		for (unsigned int i{ 0 }; i < coordSmoke.size(); i++) {
			spriteSmoke->setPosition(pos); // coordSmoke[i].first
			window->draw(*spriteSmoke);
		}
}

void Animation::showAtomicBomb(sf::RenderWindow* window)
{
	updateAtomicBomb();

	if (!coordAtomicBomb.empty())
		for (unsigned int i{ 0 }; i < coordAtomicBomb.size(); i++) {
			spriteAtomicBomb->setPosition(coordAtomicBomb[i].first);
			window->draw(*spriteAtomicBomb);
		}
}
