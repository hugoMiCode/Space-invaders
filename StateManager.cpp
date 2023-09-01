#include "StateManager.h"
#include <iostream>

void StateManager::add_state(GameState* state)
{
	states2.push_back(state);
	states2[states2.size() - 1]->init();
	/*
	states.push(state);
	states.top()->init();
	*/
}

void StateManager::back()
{
	states2[states2.size() - 1]->~GameState();
	states2.pop_back();
	//states.pop();
}

void StateManager::loop() 
{
	states2[states2.size() - 1]->loop();
	//states.top()->loop();
}

void StateManager::render(sf::RenderWindow* window)
{
	states2[states2.size() - 1]->render(window);
	//states.top()->render(window);
}

void StateManager::key_pressed(int key, sf::RenderWindow* window)
{
	states2[states2.size() - 1]->key_pressed(key, window);
	//states.top()->key_pressed(key);
}

void StateManager::mouse_pressed(int key, sf::RenderWindow* window)
{
	states2[states2.size() - 1]->mouse_pressed(key, window);
	//states.top()->mouse_pressed(key, window);
}

void StateManager::mouse_move(int key, sf::RenderWindow* window)
{
	states2[states2.size() - 1]->mouse_move(key, window);
	//states.top()->mouse_move(key, window);
}

void StateManager::joystick_move()
{
	states2[states2.size() - 1]->joystick_move();
	//states.top()->joystick_move();
}

void StateManager::joystick_pressed(int key, sf::RenderWindow* window)
{
	states2[states2.size() - 1]->joystick_pressed(key, window);
	//states.top()->joystick_pressed(key);
}

void StateManager::key_released(int key)
{
	states2[states2.size() - 1]->key_released(key);
	//states.top()->key_released(key);
}

