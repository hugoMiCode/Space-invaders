#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "StateManager.h"

class Engine
{
public:
	static void init();
	static bool running();
	static void handle_events();
	static void render();
	static void closeGame();
	static void setColor(sf::Color newColor);
	static void stateAdd(GameState* state);
	static void stateSupr();
	static sf::Vector2f getWidowSize();
	static sf::Color getColor();
	static sf::View view;

private:
	static sf::RenderWindow window;
	static StateManager manager;
	static sf::Color color;
};
