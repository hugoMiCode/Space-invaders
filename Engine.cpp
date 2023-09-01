#include "Engine.h"
#include "MainMenu.h"


sf::RenderWindow Engine::window;
sf::Color Engine::color;
sf::View Engine::view;
StateManager Engine::manager;

void Engine::init()
{
	sf::Vector2f sizeWindow(650, 800);
	window.create(sf::VideoMode(sizeWindow.x, sizeWindow.y), "Space invaders");
	view.setSize(sizeWindow);
	view.setCenter(sizeWindow.x / 2, sizeWindow.y / 2);
	manager.add_state(new MainMenu);
	color = sf::Color(55, 55, 100);
}

bool Engine::running()
{
	return window.isOpen();
}

void Engine::handle_events()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			manager.key_pressed(event.key.code, &window);
			break;
		case sf::Event::MouseButtonPressed:
			manager.mouse_pressed(event.key.code, &window);
			break;
		case sf::Event::MouseMoved:
			manager.mouse_move(event.key.code, &window);
			break;
		case sf::Event::KeyReleased:
			manager.key_released(event.key.code);
			break;
		case sf::Event::JoystickMoved:
			manager.joystick_move();
			break;
		case sf::Event::JoystickButtonPressed:
			for (unsigned int i{ 0 }; i < sf::Joystick::getButtonCount(0); i++)
				if (sf::Joystick::isButtonPressed(0, i))
					manager.joystick_pressed(i, &window);
			break;
		}
	}
	manager.loop();
}

void Engine::render()
{
	color = sf::Color(55, 55, 100);

	window.setView(view);
	window.setFramerateLimit(144);
	window.clear(color);
	manager.render(&window);
	window.display();
}

void Engine::closeGame()
{
	window.close();
}

sf::Color Engine::getColor()
{
	return color;
}

void Engine::setColor(sf::Color newColor)
{
	color = newColor;
}

void Engine::stateAdd(GameState* state)
{
	manager.add_state(state);
}

void Engine::stateSupr()
{
	manager.back();
}

sf::Vector2f Engine::getWidowSize()
{
	return (sf::Vector2f)window.getSize();
}
