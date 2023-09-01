#pragma once

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>


class StateManager
{
public:
	void add_state(GameState* state);
	void back();

	void loop();
	void render(sf::RenderWindow* window);
	void key_pressed(int key, sf::RenderWindow* window);
	void mouse_pressed(int key, sf::RenderWindow* window);
	void mouse_move(int key, sf::RenderWindow* window);
	void joystick_move();
	void joystick_pressed(int key, sf::RenderWindow* window);
	void key_released(int key);

private:
	std::stack<GameState*> states;
	std::vector<GameState*> states2;
};


