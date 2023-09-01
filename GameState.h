#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class GameState
{
public:
	virtual ~GameState() { }
	virtual void init() {}
	virtual void loop() = 0;
	virtual void render(sf::RenderWindow* window) = 0;
	virtual void key_pressed(int key, sf::RenderWindow* window) {};
	virtual void mouse_pressed(int key, sf::RenderWindow* window) {};
	virtual void mouse_move(int key, sf::RenderWindow* window) {};
	virtual void joystick_move() {};
	virtual void joystick_pressed(int key, sf::RenderWindow* window) {};
	virtual void key_released(int key) {};
};



