#include "ShipEnemy.h"
#include "Ressources.h"
#include "PlayingState.h"

Eagle5::Eagle5(Path* path, float tempsVieS) : Enemy(path, tempsVieS)
{
	fireStruct = {};

	maxHealth = 100;
	health = maxHealth;
	scoreDeath = 100;
	enemy = Ressources::Eagle5;
	scaleEntity = Ressources::infosEagle5.scale;
	sizePixel = sf::Vector2f(Ressources::infosEagle5.sizePixel);
	sizeRender = Ressources::getSizeRenderEagle5();


	initHitBox();
}
DixoveryOne::DixoveryOne(Path* path, float tempsVieS) : Enemy(path, tempsVieS)
{
	fireStruct = {};

	maxHealth = 200;
	health = maxHealth;
	scoreDeath = 200;
	enemy = Ressources::DixoveryOne;
	scaleEntity = Ressources::infosDixoveryOne.scale;
	sizePixel = sf::Vector2f(Ressources::infosDixoveryOne.sizePixel);
	sizeRender = Ressources::getSizeRenderDixoveryOne();

	initHitBox();
}
PrawnMothership::PrawnMothership(Path* path, float tempsVieS) : Enemy(path, tempsVieS)
{
	fireStruct = {};

	maxHealth = 300;
	health = maxHealth;
	scoreDeath = 300;
	enemy = Ressources::PrawnMothership;
	scaleEntity = Ressources::infosPrawnMothership.scale;
	sizePixel = sf::Vector2f(Ressources::infosPrawnMothership.sizePixel);
	sizeRender = Ressources::getSizeRenderPrawnMothership();
	
	initHitBox();
}
MondoshawanVessel::MondoshawanVessel(Path* path, float tempsVieS) : Enemy(path, tempsVieS)
{
	fireStruct = {};

	maxHealth = 4000;
	health = maxHealth;
	scoreDeath = 400;
	enemy = Ressources::MondoshawanVessel;
	scaleEntity = Ressources::infosMondoshawanVessel.scale;
	sizePixel = sf::Vector2f(Ressources::infosMondoshawanVessel.sizePixel);
	sizeRender = Ressources::getSizeRenderMondoshawanVessel();

	initHitBox();
}
Nostromo::Nostromo(Path* path, float tempsVieS) : Enemy(path, tempsVieS)
{
	fireStruct = {};

	maxHealth = 500;
	health = maxHealth;
	scoreDeath = 500;
	enemy = Ressources::Nostromo;
	scaleEntity = Ressources::infosNostromo.scale;
	sizePixel = sf::Vector2f(Ressources::infosNostromo.sizePixel);
	sizeRender = Ressources::getSizeRenderNostromo();

	initHitBox();
}
Narada::Narada(Path* path, float tempsVieS) : Enemy(path, tempsVieS)
{
	fireStruct = {};

	maxHealth = 600;
	health = maxHealth;
	scoreDeath = 600;
	enemy = Ressources::Narada;
	scaleEntity = Ressources::infosNarada.scale;
	sizePixel = sf::Vector2f(Ressources::infosNarada.sizePixel);
	sizeRender = Ressources::getSizeRenderNarada();

	initHitBox();
}
MilleniumFalcon::MilleniumFalcon(Path* path, float tempsVieS) : Enemy(path, tempsVieS)
{
	fireStruct = {};

	maxHealth = 1000;
	health = maxHealth;
	scoreDeath = 1000;
	enemy = Ressources::MilleniumFalcon;
	scaleEntity = Ressources::infosMilleniumFalcon.scale;
	sizePixel = sf::Vector2f(Ressources::infosMilleniumFalcon.sizePixel);
	sizeRender = Ressources::getSizeRenderMilleniumFalcon();

	initHitBox();
}

void Eagle5::fire(Ship* ship)
{
	fireStruct = { pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.2f };

	PlayingState::addFireEnemy(new FireTracking(fireStruct, getAngle(ship)));
	//PlayingState::addFireEnemy(new FireFollow(ship, pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.1f));
}
void DixoveryOne::fire(Ship* ship)
{
	fireStruct = { pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.2f };

	PlayingState::addFireEnemy(new FireTracking(fireStruct, getAngle(ship)));
}
void PrawnMothership::fire(Ship* ship)
{
	fireStruct = { pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.2f };

	PlayingState::addFireEnemy(new FireTracking(fireStruct, getAngle(ship)));
}
void MondoshawanVessel::fire(Ship* ship)
{
	fireStruct = { pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.1f };

	PlayingState::addFireEnemy(new FireFollow(ship, fireStruct));
	//PlayingState::addFireEnemy(new FireTracking(fireStruct, getAngle(ship)));
}
void Nostromo::fire(Ship* ship)
{
	fireStruct = { pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.2f };

	PlayingState::addFireEnemy(new FireTracking(fireStruct, getAngle(ship)));
}
void Narada::fire(Ship* ship)
{
	fireStruct = { pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.2f };

	PlayingState::addFireEnemy(new FireTracking(fireStruct, getAngle(ship)));
}
void MilleniumFalcon::fire(Ship* ship)
{
	fireStruct = { pos.x + sizeRender.x / 2, pos.y + sizeRender.y / 2, fireDegats, 0.2f };

	PlayingState::addFireEnemy(new FireTracking(fireStruct, getAngle(ship)));
}

void Eagle5::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(261, 107) - Ressources::infosEagle5.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(31, 31) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));


	updateHitBox();
}
void DixoveryOne::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(179, 89) - Ressources::infosDixoveryOne.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(53, 31) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	posRect = sf::Vector2i(189, 123) - Ressources::infosDixoveryOne.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(33, 11) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[1].second));


	updateHitBox();
}
void PrawnMothership::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(99, 103) - Ressources::infosPrawnMothership.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(47, 35) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	posRect = sf::Vector2i(145, 97) - Ressources::infosPrawnMothership.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(11, 29) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[1].second));

	posRect = sf::Vector2i(67, 97) - Ressources::infosPrawnMothership.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(11, 29) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[2].second));


	updateHitBox();
}
void MondoshawanVessel::initHitBox()
{
	sf::Vector2i posRect;

	posRect = sf::Vector2i(21, 65) - Ressources::infosMondoshawanVessel.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(37, 71) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[0].second));

	posRect = sf::Vector2i(57, 75) - Ressources::infosMondoshawanVessel.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(13, 47) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[1].second));

	posRect = sf::Vector2i(8, 75) - Ressources::infosMondoshawanVessel.posTexture;
	tabCoordHitBox.push_back(std::pair<sf::Vector2f, sf::Vector2f>{
		posRect, sf::Vector2f(13, 47) });
	tabHitBox.push_back(sf::RectangleShape(tabCoordHitBox[2].second));


	updateHitBox();
}


