#pragma once
#include "GameState.h"
#include "Engine.h"

class Pause : public GameState
{
public:
	Pause(sf::Image image);
	void init();
	void loop();
	void render(sf::RenderWindow* window);
	void key_pressed(int key, sf::RenderWindow* window);
	void mouse_pressed(int key, sf::RenderWindow* window);
	void mouse_move(int key, sf::RenderWindow* window);
	void mouse_control(sf::Vector2f pos, sf::RenderWindow* window, int i);
	void joystick_move();
	void joystick_pressed(int key, sf::RenderWindow* window);
	void barSound(float x, float y);
	void selected_control();

private:
	static unsigned short int const options_count{ 2 };
	int characterSize;
	int selected;
	float quitTime;
	bool joystick;
	bool back;
	bool quitPause;

	std::string options[options_count];

	sf::Font font_title;
	sf::Font font_options;

	sf::Text compteur;
	sf::Text title;
	sf::Text option;
	sf::Text quitter;
	sf::Text retour;
	sf::Text setting;

	sf::Clock quitClock;
	sf::Color color;
	sf::Texture texturePause;
	sf::Sprite spritePause;
	/*
	sf::RectangleShape boutton;
	sf::RectangleShape bouttonSelecter;
	*/
	sf::RectangleShape volumeBar;
	sf::RectangleShape barOutline;
	sf::RectangleShape barHighlight;
	sf::RectangleShape barSetting;

	sf::Vector3f pos_options;
	sf::Vector2f posRetour;
	sf::Vector2f posQuitter;
	sf::Vector2f sizeVolumeBar;
	sf::Vector2f sizeVolumeBarI;
};

