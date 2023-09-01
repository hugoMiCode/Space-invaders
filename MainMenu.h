#pragma once

#include "GameState.h"
#include "Engine.h"
#include "PlayingState.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class MainMenu : public GameState
{
public:
	void init();
	void loop();
	void render(sf::RenderWindow* window);
	void key_pressed(int key, sf::RenderWindow* window);
	void mouse_pressed(int key, sf::RenderWindow* window);
	void mouse_control(sf::Vector2f pos, sf::RenderWindow* window);
	void joystick_move();
	void joystick_pressed(int key, sf::RenderWindow* window);
	void selected_control();


private:
	sf::Font font_title;
	sf::Font font_options;
	sf::Text title;
	sf::Text option;
	sf::Vector3f menusPos;
	short int selected;
	sf::RectangleShape selecter;
	bool joystick;
	static unsigned short int const options_count{ 3 };
	std::string options[options_count];
};





