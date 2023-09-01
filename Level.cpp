#include "Level.h"
#include "Background.h"

Level::Level(int n)
{
	switch (n)
	{
	case 0:
		//waves.push_back(new Wave(1, 4, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(10, 1, "Wall"));
		//waves.push_back(std::make_unique<Wave>(1, 1, "test2"));
		break;
	case 1:
		waves.push_back(std::make_unique<Wave>(10, 1, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 2, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 3, "I", 20));
		break;
	case 2:
		waves.push_back(std::make_unique<Wave>(10, 1, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 2, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 3, "I", 20));
		break;
	case 3:
		waves.push_back(std::make_unique<Wave>(1, 3, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(15, 2, "Wall"));
		break;
	case 4:
		waves.push_back(std::make_unique<Wave>(10, 3, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 2, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 4, "I", 20));
		break;
	case 5:
		waves.push_back(std::make_unique<Wave>(1, 4, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(15, 3, "Wall"));
		break;
	case 6:
		waves.push_back(std::make_unique<Wave>(10, 3, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 2, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 4, "I", 20));
		break;
	case 7:
		waves.push_back(std::make_unique<Wave>(1, 4, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(15, 2, "Wall"));
		break;
	case 8:
		waves.push_back(std::make_unique<Wave>(1, 4, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(15, 2, "Wall"));
		break;
	case 9:
		waves.push_back(std::make_unique<Wave>(10, 3, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 2, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 4, "I", 20));
		break;
	case 10:
		waves.push_back(std::make_unique<Wave>(10, 1, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 2, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 4, "I", 20));
		break;
	case 11:
		waves.push_back(std::make_unique<Wave>(1, 4, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(15, 2, "Wall"));
		break;
	case 12:
		waves.push_back(std::make_unique<Wave>(10, 3, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 2, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 4, "I", 20));
		break;
	case 13:
		waves.push_back(std::make_unique<Wave>(1, 4, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(15, 2, "Wall"));
		break;
	case 14:
		waves.push_back(std::make_unique<Wave>(10, 2, "lineH2"));
		waves.push_back(std::make_unique<Wave>(10, 3, "V", 10));
		waves.push_back(std::make_unique<Wave>(1, 4, "I", 20));
		break;
	case 15:
		waves.push_back(std::make_unique<Wave>(1, 4, "default", 0, 60));
		waves.push_back(std::make_unique<Wave>(15, 3, "Wall"));
		break;
	}
}

void Level::update()
{
	if (waves.size() != 0)
		for (unsigned int i{ 0 }; i < waves.size(); i++)
			waves[i]->update();
}

void Level::show_entity(sf::RenderWindow* window)
{
	if (waves.size() != 0)
		for (unsigned int i{ 0 }; i < waves.size(); i++)
			waves[i]->show(window);
}

void Level::checkHitEnemy(Ship* ship)
{
	if (waves.size() != 0)
		for (unsigned int i{ 0 }; i < waves.size(); i++) {
			waves[i]->checkHit(ship);
	
			if (waves[i]->isEmpty() && waves[i]->getEntity() == 0)
				suprWave(i);
		}
}

void Level::fire(Ship* ship)
{
	if (waves.size() != 0)
		for (unsigned int i{ 0 }; i < waves.size(); i++)
			waves[i]->fire(ship);
}

void Level::suprWave(int i)
{
	waves.erase(waves.begin() + i);
}

bool Level::isEmpty()
{
	return waves.empty();
}
