#pragma once
#include <vector>
#include "Ressources.h"
#include "ItemType.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Animation
{
public:
	static void init();

	static void explosion(sf::Vector2f pos);
	static void hit(sf::Vector2f pos);
	static void glitterItem(sf::Vector2f pos);
	static void smoke(sf::Vector2f pos);
	static void atomicBomb(sf::Vector2f pos);

	static void showExplosion(sf::RenderWindow* window);
	static void showHit(sf::RenderWindow* window);
	static void showGlitter(sf::RenderWindow* window);
	static void showSmoke(sf::RenderWindow* window, sf::Vector2f pos = sf::Vector2f());
	static void showAtomicBomb(sf::RenderWindow* window);

	static void updateHitShip(std::vector<Enemy*> enemys);
	static void updateCoin(std::vector<std::pair<Coin*, sf::Clock>>& coins);

private:
	static void updateExplosion();
	static void updateHit();
	static void updateGlitter();
	static void updateSmoke();
	static void updateAtomicBomb();

	static void suprExplosion(unsigned int i);
	static void suprHit(unsigned int i);
	static void suprGlitter(unsigned int i);
	static void suprSmoke(unsigned int i);
	static void suprAtomicBomb(unsigned int i);



	static sf::Vector2i sizePixelExplosion;
	static sf::Sprite* spriteExplosion;
	static std::vector<std::pair<sf::Vector2f, sf::Clock>> coordExplosion;
	
	static sf::Vector2i sizePixelHit;
	static sf::Sprite* spriteHit;
	static std::vector<std::pair<sf::Vector2f, sf::Clock>> coordHit;

	static sf::Vector2i sizePixelGlitter;
	static sf::Sprite* spriteGlitter;
	static std::vector<std::pair<sf::Vector2f, sf::Clock>> coordGlitter;

	static sf::Vector2i sizePixelSmoke;
	static sf::Sprite* spriteSmoke;
	static std::vector<std::pair<sf::Vector2f, sf::Clock>> coordSmoke;

	static sf::Vector2i sizePixelAtomicBomb;
	static sf::Sprite* spriteAtomicBomb;
	static std::vector<std::pair<sf::Vector2f, sf::Clock>> coordAtomicBomb;
};

