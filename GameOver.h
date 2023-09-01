#pragma once
#include "GameState.h"
class GameOver : public GameState
{
	void init();
	void loop();
	void render(sf::RenderWindow* window);
	virtual void joystick_pressed(int key);
	virtual void key_pressed(int key);
	virtual void mouse_pressed(int key, sf::RenderWindow* window);

private:
	sf::Text textGameOver;
	sf::Text textClickToRestart;
	sf::Clock clockAction;
	bool supr;
};

