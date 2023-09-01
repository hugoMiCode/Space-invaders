#include "Pause.h"
#include "PlayingState.h"
#include "Setting.h"
Pause::Pause(sf::Image image)
{
	quitPause = false;
	texturePause.loadFromImage(image);
	spritePause.setTexture(texturePause);
	compteur.setCharacterSize(80);
	compteur.setFont(Ressources::font_lasercorps);
	compteur.setPosition((Engine::getWidowSize().x - compteur.getCharacterSize()) / 2.f, (Engine::getWidowSize().y - compteur.getCharacterSize()) / 2.f);
	quitTime = 3.f;
}

void Pause::init()
{
	back = false;
	color = sf::Color(65, 105, 225);
	Engine::setColor(color);
	Engine::view.setCenter(Engine::getWidowSize().x / 2, Engine::getWidowSize().y / 2);
	Engine::view.setSize(Engine::getWidowSize());
	selected = 0;

	options[0] = "Volume : ";
	options[1] = "Affichage Fps : ";

	characterSize = 25;
	joystick = false;


	pos_options = sf::Vector3f(10, 200, 60);
	posRetour = sf::Vector2f(20, 20);
	posQuitter = sf::Vector2f(Engine::getWidowSize().x - 100, Engine::getWidowSize().y - 50);


	font_title = Ressources::font_lasercorps;
	font_options = Ressources::font_JAi_____;

	option.setFont(font_options);
	option.setCharacterSize(characterSize);

	quitter.setFont(font_options);
	quitter.setCharacterSize(characterSize);
	quitter.setPosition(posQuitter);
	quitter.setString("Quit");

	retour.setFont(font_options);
	retour.setCharacterSize(characterSize);
	retour.setPosition(posRetour);
	retour.setString("Back");

	setting.setFont(font_options);
	setting.setCharacterSize(characterSize + 5);
	setting.setPosition(pos_options.x, pos_options.y - pos_options.z);
	setting.setString("Setting : ");

	barSetting.setPosition(0, pos_options.y - pos_options.z + characterSize + 15);
	barSetting.setSize(sf::Vector2f(Engine::getWidowSize().x, 2));

	title.setFont(font_title);
	title.setString("-Pause-");
	title.setCharacterSize(50);

	//boutton.setSize(sf::Vector2f(10, 10));

	barHighlight.setFillColor(color);
	barHighlight.setOutlineThickness(2);

	sizeVolumeBarI = sf::Vector2f(300, characterSize);
	sizeVolumeBar = sf::Vector2f((float)Setting::getVolume() / (float)100 * sizeVolumeBarI.x, characterSize);
}

void Pause::loop()
{
	Setting::setVolume(sizeVolumeBar.x / sizeVolumeBarI.x * 100);
	options[0] = "Volume : " + std::to_string(Setting::getVolume()) + "%";

	switch (selected)
	{
	case 0:
		retour.setFillColor(sf::Color::White);
		quitter.setFillColor(sf::Color(168, 168, 168));
		barHighlight.setPosition(posRetour);
		barHighlight.setSize(sf::Vector2f(60, 35));
		break;
	case 1:
		retour.setFillColor(sf::Color(168, 168, 168));
		quitter.setFillColor(sf::Color(168, 168, 168));
		break;
	case 2:
		retour.setFillColor(sf::Color(168, 168, 168));
		quitter.setFillColor(sf::Color(168, 168, 168));
		break;
	case options_count + 1:
		retour.setFillColor(sf::Color(168, 168, 168));
		quitter.setFillColor(sf::Color::White);
		barHighlight.setPosition(posQuitter);
		barHighlight.setSize(sf::Vector2f(60, 35));
		break;
	}

	if (sizeVolumeBar.x < 0)
		sizeVolumeBar.x = 0;
	else if (sizeVolumeBar.x > sizeVolumeBarI.x)
		sizeVolumeBar.x = sizeVolumeBarI.x;

}

void Pause::render(sf::RenderWindow* window)
{
	if (!quitPause) {
		quitClock.restart();
		title.setPosition(window->getSize().x / 2 - 125, 50);

		for (unsigned short int i{ 0 }; i < options_count; i++) {
			sf::Vector2f pos(pos_options.x, pos_options.y + i * pos_options.z);
			option.setPosition(pos);
			option.setString(options[i]);

			mouse_control(pos, window, i);

			if (selected == i + 1) {
				option.setFillColor(sf::Color::White);
				barHighlight.setPosition(0, pos_options.y + i * pos_options.z);
				barHighlight.setSize(sf::Vector2f(window->getSize().x, 35));
				window->draw(barHighlight);
			}
			else
				option.setFillColor(sf::Color(168, 168, 168));

			if (i == 0)
				barSound(pos_options.x, pos_options.y + i * pos_options.z);

			window->draw(option);
		}

		window->draw(barOutline);
		window->draw(setting);
		window->draw(barSetting);
		window->draw(volumeBar);
		window->draw(title);
		window->draw(quitter);
		window->draw(retour);
	}
	else {
		compteur.setString(std::to_string(int(quitTime - quitClock.getElapsedTime().asSeconds())));

		window->draw(spritePause);
		window->draw(compteur);	
		
		if (quitClock.getElapsedTime().asSeconds() > quitTime)
			Engine::stateSupr();
	}
}

void Pause::key_pressed(int key, sf::RenderWindow* window)
{
	switch (key)
	{
	case sf::Keyboard::Escape:
		quitPause = true;
		break;
	case sf::Keyboard::Enter:
		selected_control();
		break;
	case sf::Keyboard::Up:
		if (selected > 0)
			selected--;
		break;
	case sf::Keyboard::Down:
		if (selected < options_count + 1)
			selected++;
		break;
	case sf::Keyboard::Left:
		if (selected == 1)
			sizeVolumeBar.x -= 10;
		break;
	case sf::Keyboard::Right:
		if (selected == 1)
			sizeVolumeBar.x += 10;
		break;
	}
}

void Pause::mouse_pressed(int key, sf::RenderWindow* window)
{
	if (sf::Mouse::getPosition(*window).y >= pos_options.z
		&& sf::Mouse::getPosition(*window).y <= pos_options.z + pos_options.y * options_count) {
		switch (key)
		{
		case sf::Mouse::Left:
			selected_control();
			break;
		}
}
}

void Pause::mouse_move(int key, sf::RenderWindow* window)
{
	float x1{ (float)sf::Mouse::getPosition(*window).x };
	float y1{ (float)sf::Mouse::getPosition(*window).y };

	float x2{ (float)volumeBar.getPosition().x };
	float y2{ (float)volumeBar.getPosition().y };


	if (x1 >= x2 && x1 <= x2 + sizeVolumeBarI.x && y1 >= y2 && y1 <= y2 + sizeVolumeBarI.y
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
		sizeVolumeBar.x = sf::Mouse::getPosition(*window).x - volumeBar.getPosition().x;
}

void Pause::mouse_control(sf::Vector2f pos, sf::RenderWindow* window, int i)
{
	float x1{ (float)sf::Mouse::getPosition(*window).x };
	float y1{ (float)sf::Mouse::getPosition(*window).y };

	float x2{ (float)posRetour.x };
	float y2{ (float)posRetour.y };

	float x3{ (float)posQuitter.x };
	float y3{ (float)posQuitter.y };


	if (y1 >= pos.y && y1 <= pos.y + characterSize && x1 > 0 && x1 < (signed)window->getSize().x)
		selected = i + 1;

//								+-- size de back, taille.x hitbox 
//								v						
	if (x1 >= x2 && x1 <= x2 + 100 && y1 >= y2 && y1 <= y2 + 50) { // <-- idem
		selected = 0;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !back) {
			back = true;
			selected_control();
		}
	}
	if (x1 >= x3 && x1 <= x3 + 100 && y1 >= y3 && y1 <= y3 + 50) {
		selected = options_count + 1;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			selected_control();
	}
}

void Pause::joystick_move()
{
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);


	if (y > 80 && selected < options_count + 1 && !joystick) {
		selected++;
		joystick = true;
	}
	else if (y < -80 && selected > 0 && !joystick) {
		selected--;
		joystick = true;
	}
	else if ((int)x == 0 && (int)y == 0)
		joystick = false;


	if (selected == 1) {
		if (x > 80 && selected < options_count + 1 && !joystick) {
			sizeVolumeBar.x += 10;
			joystick = true;
		}
		else if (x < -80 && selected > 0 && !joystick) {
			sizeVolumeBar.x -= 10;
			joystick = true;
		}
		else if ((int)x == 0 && (int)y == 0)
			joystick = false;
	}
}

void Pause::joystick_pressed(int key, sf::RenderWindow* window)
{
	switch (key)
	{
	case 7:
		quitPause = true;
		break;
	case 0:
		selected_control();
		break;
	}
}

void Pause::barSound(float x, float y)
{
	volumeBar.setPosition(x + 200, y + 5);
	volumeBar.setSize(sizeVolumeBar);
	volumeBar.setFillColor(sf::Color::Blue);

	barOutline.setPosition(x + 200, y + 5);
	barOutline.setSize(sizeVolumeBarI);
	barOutline.setFillColor(sf::Color(168, 168, 168));
}

void Pause::selected_control()
{
	switch (selected)
	{
	case 0:
		quitPause = true;
		break;
	case 1:
		if (Setting::getVolume() != 0)
			sizeVolumeBar.x = 0;
		else 
			sizeVolumeBar.x = sizeVolumeBarI.x;
		break;
	case 2:
		if (Setting::getStateFPS())
			Setting::setAffichageFps(false);
		else
			Setting::setAffichageFps(true);
		break;
	case options_count + 1:
		Engine::closeGame();
		break;
	}
}

