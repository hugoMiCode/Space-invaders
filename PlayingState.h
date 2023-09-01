#pragma once
#include "GameState.h"
#include "Engine.h"
#include "Ship.h"
#include "Ressources.h"
#include "Enemy.h"
#include "Fire.h"
#include "Level.h"
#include "Background.h"
#include "Foreground.h"
#include "Wave.h"
#include "Item.h"
#include "ItemType.h"
#include <iostream>
#include <deque>


class PlayingState : public GameState
{
public:
	~PlayingState();
	void init();
	void loop();
	void render(sf::RenderWindow* window);
	
	void key_pressed(int key, sf::RenderWindow* window);
	void joystick_pressed(int key, sf::RenderWindow* window);

	void addLevel();
	void show_item(sf::RenderWindow* window);

	static bool hitWall(sf::RenderWindow* window, Entity* entity);

	static void dropItem(Item* item);
	static void dropCoin(sf::Vector2f pos);
	void updateItem();
	static float getTempsPause();
	static bool hitBox(Entity* entity1, Entity* entity2);


	static void suprItem(unsigned int i);
	static void suprCoin(unsigned int i);
	static void suprFireShip(unsigned int i);
	static void suprFireEnemy(unsigned int i);
	void show_fire(sf::RenderWindow* window);
	void fire_update();
	void gameOver();

	static void checkHitEnemy(Ship* ship, Enemy* enemy);
	void checkHitShip();
	void checkHitCoin();
	void checkHitItem();
	static void addFireShip(Fire* fire);
	static void addFireEnemy(Fire* fire);
	static sf::Color getColorLife(float x);

private:
	int n;
	static float temps_pause;
	static float temps_pausePrec;
	static bool pause;
	static std::vector<Item*> items;
	static std::vector<std::pair<Coin*, sf::Clock>> coins;
	static std::vector<Fire*> fireEnemy;
	static std::vector<Fire*> fireShip;

	Ship* ship;
	Background* background;
	Foreground* forground;
	Level* level;
	sf::Clock clock_pause;

	InfosShip infosShip;
	sf::Image image;
};

