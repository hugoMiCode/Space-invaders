#include "Ressources.h"

// Font
sf::Font Ressources::font_lasercorpsgradital;
sf::Font Ressources::font_lasercorps;
sf::Font Ressources::font_JAi_____;


// Sound
sf::SoundBuffer Ressources::buffer_soundFire;
sf::SoundBuffer Ressources::buffer_soundHit;

sf::Sound Ressources::soundFire;
sf::Sound Ressources::soundHit;

// ShipAlly
sf::Texture Ressources::texture_ship;
// ShipEnemy
sf::Texture Ressources::texture_shipEnemy;
// Background
sf::Texture Ressources::texture_spaceBackground;
sf::Texture Ressources::texture_planet_1;
sf::Texture Ressources::texture_planetRouge;
sf::Texture Ressources::texture_planetBleu;
sf::Texture Ressources::texture_shootingStar;
sf::Texture Ressources::texture_cloud;
// Fire
sf::Texture Ressources::texture_fireBallShip;
sf::Texture Ressources::texture_laserBullets;
sf::Texture Ressources::texture_fireBallEnemy;
sf::Texture Ressources::texture_fireMissile;
// Item
sf::Texture Ressources::texture_itemUpgrade;
sf::Texture Ressources::texture_shield;
sf::Texture Ressources::texture_life;
sf::Texture Ressources::texture_coin;
sf::Texture Ressources::texture_ammo;
// Animation
sf::Texture Ressources::texture_explosion;
sf::Texture Ressources::texture_hit;
sf::Texture Ressources::texture_glitter;
sf::Texture Ressources::texture_smoke;
sf::Texture Ressources::texture_atomicBomb;


// ShipAlly
sf::Sprite Ressources::ship;
sf::Sprite Ressources::purpleShip;
sf::Sprite Ressources::redShip;
sf::Sprite Ressources::orangeShip;
// ShipEnemy
sf::Sprite Ressources::Eagle5;
sf::Sprite Ressources::DixoveryOne;
sf::Sprite Ressources::PrawnMothership;
sf::Sprite Ressources::MondoshawanVessel;
sf::Sprite Ressources::Nostromo;
sf::Sprite Ressources::Narada;
sf::Sprite Ressources::MilleniumFalcon;
// Background
sf::Sprite Ressources::spaceBackground;
sf::Sprite Ressources::planet_1;
sf::Sprite Ressources::planetRouge;
sf::Sprite Ressources::planetBleu;
sf::Sprite Ressources::shootingStar;
sf::Sprite Ressources::cloud;
// Fire
sf::Sprite Ressources::fireBallShip;
sf::Sprite Ressources::greenLaser;
sf::Sprite Ressources::redLaser;
sf::Sprite Ressources::fireBallEnemy;
sf::Sprite Ressources::fireMissile;
// Item
sf::Sprite Ressources::redShipItem;
sf::Sprite Ressources::heavyShipItem;
sf::Sprite Ressources::orangeShipItem;
sf::Sprite Ressources::itemUpgrade;
sf::Sprite Ressources::shield;
sf::Sprite Ressources::life;
sf::Sprite Ressources::coin;
sf::Sprite Ressources::ammo;
// Animation
sf::Sprite Ressources::explosion;
sf::Sprite Ressources::hit;
sf::Sprite Ressources::glitter;
sf::Sprite Ressources::smoke;
sf::Sprite Ressources::atomicBomb;


// ShipAlly
InfosSprite Ressources::infosPurpleShip{
	0.4f,
	sf::Vector2i(197, 173),
	sf::Vector2i(30, 1050)
};
InfosSprite Ressources::infosRedShip{
	0.6f,
	sf::Vector2i(129, 101),
	sf::Vector2i(64, 72)
};
InfosSprite Ressources::infosOrangeShip{
	0.6f,
	sf::Vector2i(97, 137),
	sf::Vector2i(80, 1332)
};
// ShipEnemy
InfosSprite Ressources::infosEagle5{
	1.f,
	sf::Vector2i(47, 47),
	sf::Vector2i(253, 99)
};
InfosSprite Ressources::infosDixoveryOne{
	1.f,
	sf::Vector2i(73, 71),
	sf::Vector2i(169, 75)
};
InfosSprite Ressources::infosPrawnMothership{
	1.f,
	sf::Vector2i(71, 55),
	sf::Vector2i(86, 90)
};
InfosSprite Ressources::infosMondoshawanVessel{
	1.f,
	sf::Vector2i(65, 85),
	sf::Vector2i(6, 60)
};
InfosSprite Ressources::infosNostromo{ // default
	1.f,
	sf::Vector2i(),
	sf::Vector2i()
};
InfosSprite Ressources::infosNarada{ // default
	1.f,
	sf::Vector2i(),
	sf::Vector2i()
};
InfosSprite Ressources::infosMilleniumFalcon{ // default
	1.f,
	sf::Vector2i(),
	sf::Vector2i()
};
// Background
InfosSprite Ressources::infosSpaceBackground{
	1.f,
	sf::Vector2i(1024, 1024),
	sf::Vector2i()
};
InfosSprite Ressources::infosPlanet_1{
	1.f,
	sf::Vector2i(100, 100),
	sf::Vector2i()
};
InfosSprite Ressources::infosPlanetRouge{
	0.3f,
	sf::Vector2i(708, 708),
	sf::Vector2i()
};
InfosSprite Ressources::infosPlanetBleu{
	0.35f,
	sf::Vector2i(1024, 1024),
	sf::Vector2i()
};
InfosSprite Ressources::infosShootingStar{
	1.f,
	sf::Vector2i(32, 32),
	sf::Vector2i()
};
InfosSprite Ressources::infosCloud{
	0.5f,
	sf::Vector2i(800, 800),
	sf::Vector2i()
};
// Fire
InfosSprite Ressources::infosFireBallEnemy{
	0.035f,
	sf::Vector2i(600, 580),
	sf::Vector2i()
};
InfosSprite Ressources::infosFireBallShip{
	0.37f,
	sf::Vector2i(33, 65),
	sf::Vector2i(368, 1464)
};
InfosSprite Ressources::infosRedLaser{
	1.f,
	sf::Vector2i(15, 19),
	sf::Vector2i(6, 124)
};
InfosSprite Ressources::infosGreenLaser{
	0.8f,
	sf::Vector2i(14, 26),
	sf::Vector2i(41, 57)
};
// Item
InfosSpriteItem Ressources::infosRedShipItem{
	sf::Vector2i(),
	sf::Vector2f(sizeRenderItem.x / infosRedShip.sizePixel.x, sizeRenderItem.y / infosRedShip.sizePixel.y),
	sf::Vector2i()
};
InfosSpriteItem Ressources::infosPurpleShipItem{
	sf::Vector2i(),
	sf::Vector2f(sizeRenderItem.x / infosPurpleShip.sizePixel.x, sizeRenderItem.y / infosPurpleShip.sizePixel.y),
	sf::Vector2i()
};
InfosSpriteItem Ressources::infosOrangeShipItem{
	sf::Vector2i(),
	sf::Vector2f(sizeRenderItem.x / infosOrangeShip.sizePixel.x, sizeRenderItem.y / infosOrangeShip.sizePixel.y),
	sf::Vector2i()
};
InfosSpriteItem Ressources::infosUpgradeItem{	
	sf::Vector2i(64, 64),
	sf::Vector2f(sizeRenderItem.x / infosUpgradeItem.sizePixel.x, sizeRenderItem.y / infosUpgradeItem.sizePixel.y),
	sf::Vector2i()
};
InfosSpriteItem Ressources::infosShield{	
	sf::Vector2i(64, 64),
	sf::Vector2f(sizeRenderItem.x / infosShield.sizePixel.x, sizeRenderItem.y / infosShield.sizePixel.y),
	sf::Vector2i()
};
InfosSpriteItem Ressources::infosLife{	
	sf::Vector2i(200, 200),
	sf::Vector2f(sizeRenderItem.x / infosLife.sizePixel.x, sizeRenderItem.y / infosLife.sizePixel.y),
	sf::Vector2i()
};
InfosSpriteItem Ressources::infosCoin{
	sf::Vector2i(61, 62),
	sf::Vector2f(0.4, 0.4),
	sf::Vector2i(141, 23)
};
InfosSpriteItem Ressources::infosAmmo{
	sf::Vector2i(512, 512),
	sf::Vector2f(sizeRenderItem.x / infosAmmo.sizePixel.x, sizeRenderItem.y / infosAmmo.sizePixel.y),
	sf::Vector2i()
};
// Animation
InfosAnimation Ressources::infosExplosion{
	0.3f,
	sf::Vector2i(192, 192),
	sf::Vector2i(),
	sf::Vector2i(5, 4)
};
InfosAnimation Ressources::infosHit{
	0.15f,
	sf::Vector2i(512, 512),
	sf::Vector2i(),
	sf::Vector2i(4, 3)
};
InfosAnimation Ressources::infosGlitter{
	0.35f,
	sf::Vector2i(192, 192),
	sf::Vector2i(),
	sf::Vector2i(5, 4)
};
InfosAnimation Ressources::infosSmoke{
	0.45f,
	sf::Vector2i(192, 192),
	sf::Vector2i(),
	sf::Vector2i(5, 5)
};
InfosAnimation Ressources::infosAtomicBomb{
	0.2f,
	sf::Vector2i(320, 233),
	sf::Vector2i(),
	sf::Vector2i(5, 5)
};

InfosSprite Ressources::infosGameOver{
	0.f,
	sf::Vector2i(518, 161),
	sf::Vector2i()
};


// ShipAlly
sf::Vector2f Ressources::sizeShipDefault{ 80, 80 };
// ShipEnemy
// Background
// Fire
sf::Vector2f Ressources::sizeFireMissile{ 39, 125 };
// Item
sf::Vector2f Ressources::sizeRenderItem{ 42, 42 }; // AllItem
// Animation



// ShipAlly
sf::Vector2f Ressources::scaleShip{ 1.0f, 1.0f };
// ShipEnemy
// Background
// Fire
sf::Vector2f Ressources::scaleFireMissile{ 0.4f, 0.4f };
// Item
// Animation


void Ressources::load()
{
	if (!font_lasercorpsgradital.loadFromFile("Ressources/Police/lasercorpsgradital.ttf")
		|| !font_lasercorps.loadFromFile("Ressources/Police/lasercorps.ttf")
		|| !font_JAi_____.loadFromFile("Ressources/Police/JAi_____.ttf"))
		std::cout << "Erreur de chargement de la police." << std::endl;

	if (!buffer_soundFire.loadFromFile("Ressources/Son/Blaster Star Wars 4.wav")
		|| !buffer_soundHit.loadFromFile("Ressources/Son/hitting sound.wav"))
		std::cout << "Erreur de chargement des sons." << std::endl;


	soundFire.setBuffer(buffer_soundFire);
	soundHit.setBuffer(buffer_soundHit);

	if (!texture_ship.loadFromFile("Ressources/Fire Ship/DurrrSpaceShip.png")
		|| !texture_shipEnemy.loadFromFile("Ressources/Fire Ship/sprite-enemy.png")
		|| !texture_itemUpgrade.loadFromFile("Ressources/Item/arrow-icon-upgrade.png")
		|| !texture_shield.loadFromFile("Ressources/Item/shield.png")
		|| !texture_coin.loadFromFile("Ressources/Animation/coin.png")
		|| !texture_explosion.loadFromFile("Ressources/Animation/explosion.png")
		|| !texture_hit.loadFromFile("Ressources/Animation/hitAnim.png")
		|| !texture_glitter.loadFromFile("Ressources/Animation/glitter.png")
		|| !texture_fireBallShip.loadFromFile("Ressources/Fire Ship/fireBall et ship.png")
		|| !texture_spaceBackground.loadFromFile("Ressources/Background/space background.png")
		|| !texture_fireBallEnemy.loadFromFile("Ressources/Fire Ship/redBall.png")
		|| !texture_fireMissile.loadFromFile("Ressources/Fire Ship/missile.png")
		|| !texture_planet_1.loadFromFile("Ressources/Background/planet_1.png")
		|| !texture_shootingStar.loadFromFile("Ressources/Background/etoitle_filante_V1.png")
		|| !texture_laserBullets.loadFromFile("Ressources/Fire Ship/laserBullets.png")
		|| !texture_smoke.loadFromFile("Ressources/Animation/particle effect.png")
		|| !texture_life.loadFromFile("Ressources/Item/croix.png")
		|| !texture_atomicBomb.loadFromFile("Ressources/Animation/atomic-bomb.png")
		|| !texture_planetRouge.loadFromFile("Ressources/Background/planet rouge.png")
		|| !texture_planetBleu.loadFromFile("Ressources/Background/planet bleu.png")
		|| !texture_ammo.loadFromFile("Ressources/Item/ammo icon.png")
		|| !texture_cloud.loadFromFile("Ressources/Background/nuage flou.png"))
		std::cout << "Erreur de chargement des textures." << std::endl;

	setSmooth();

	// ShipAlly
	ship.setTexture(texture_ship);
	purpleShip.setTexture(texture_fireBallShip);
	redShip.setTexture(texture_fireBallShip);
	orangeShip.setTexture(texture_fireBallShip);
	// ShipEnemy
	Eagle5.setTexture(texture_shipEnemy);
	DixoveryOne.setTexture(texture_shipEnemy);
	PrawnMothership.setTexture(texture_shipEnemy);
	MondoshawanVessel.setTexture(texture_shipEnemy);
	Nostromo.setTexture(texture_shipEnemy);
	Narada.setTexture(texture_shipEnemy);
	MilleniumFalcon.setTexture(texture_shipEnemy);
	// Background
	spaceBackground.setTexture(texture_spaceBackground);
	planet_1.setTexture(texture_planet_1);
	planetRouge.setTexture(texture_planetRouge);
	planetBleu.setTexture(texture_planetBleu);
	shootingStar.setTexture(texture_shootingStar);
	cloud.setTexture(texture_cloud);
	// Fire
	fireBallShip.setTexture(texture_fireBallShip);
	greenLaser.setTexture(texture_laserBullets);
	redLaser.setTexture(texture_laserBullets);
	fireBallEnemy.setTexture(texture_fireBallEnemy);
	fireMissile.setTexture(texture_fireMissile);
	// Item
	redShipItem.setTexture(texture_fireBallShip);
	heavyShipItem.setTexture(texture_fireBallShip);
	orangeShipItem.setTexture(texture_fireBallShip);
	itemUpgrade.setTexture(texture_itemUpgrade);
	shield.setTexture(texture_shield);
	life.setTexture(texture_life);
	coin.setTexture(texture_coin);
	ammo.setTexture(texture_ammo);
	// Animation
	explosion.setTexture(texture_explosion);
	hit.setTexture(texture_hit);
	glitter.setTexture(texture_glitter); glitter.setColor(sf::Color::Yellow);
	smoke.setTexture(texture_smoke);
	atomicBomb.setTexture(texture_atomicBomb);



	// ShipAlly
	ship.setTextureRect(sf::IntRect(0, 0, sizeShipDefault.x, sizeShipDefault.y));
	purpleShip.setTextureRect(sf::IntRect(infosPurpleShip.posTexture, infosPurpleShip.sizePixel));
	redShip.setTextureRect(sf::IntRect(infosRedShip.posTexture, infosRedShip.sizePixel));
	orangeShip.setTextureRect(sf::IntRect(infosOrangeShip.posTexture, infosOrangeShip.sizePixel));
	// ShipEnemy
	Eagle5.setTextureRect(sf::IntRect(infosEagle5.posTexture, infosEagle5.sizePixel));
	DixoveryOne.setTextureRect(sf::IntRect(infosDixoveryOne.posTexture, infosDixoveryOne.sizePixel));
	PrawnMothership.setTextureRect(sf::IntRect(infosPrawnMothership.posTexture, infosPrawnMothership.sizePixel));
	MondoshawanVessel.setTextureRect(sf::IntRect(infosMondoshawanVessel.posTexture, infosMondoshawanVessel.sizePixel));
	Nostromo.setTextureRect(sf::IntRect(infosNostromo.posTexture, infosNostromo.sizePixel));
	Narada.setTextureRect(sf::IntRect(infosNarada.posTexture, infosNarada.sizePixel));
	MilleniumFalcon.setTextureRect(sf::IntRect(infosMilleniumFalcon.posTexture, infosMilleniumFalcon.sizePixel));
	// Background
	spaceBackground.setTextureRect(sf::IntRect(infosSpaceBackground.posTexture, infosSpaceBackground.sizePixel));
	planet_1.setTextureRect(sf::IntRect(infosPlanet_1.posTexture, infosPlanet_1.sizePixel));
	planetRouge.setTextureRect(sf::IntRect(infosPlanetRouge.posTexture, infosPlanetRouge.sizePixel));
	planetBleu.setTextureRect(sf::IntRect(infosPlanetBleu.posTexture, infosPlanetBleu.sizePixel));
	shootingStar.setTextureRect(sf::IntRect(infosShootingStar.posTexture, infosShootingStar.sizePixel));
	cloud.setTextureRect(sf::IntRect(infosCloud.posTexture, infosCloud.sizePixel));
	// Fire
	fireBallShip.setTextureRect(sf::IntRect(infosFireBallShip.posTexture, infosFireBallShip.sizePixel));
	greenLaser.setTextureRect(sf::IntRect(infosGreenLaser.posTexture, infosGreenLaser.sizePixel));
	redLaser.setTextureRect(sf::IntRect(infosRedLaser.posTexture, infosRedLaser.sizePixel));
	fireBallEnemy.setTextureRect(sf::IntRect(infosFireBallEnemy.posTexture, infosFireBallEnemy.sizePixel));
	fireMissile.setTextureRect(sf::IntRect(59, 0, sizeFireMissile.x, sizeFireMissile.y));
	// Item
	redShipItem.setTextureRect(redShip.getTextureRect());
	heavyShipItem.setTextureRect(purpleShip.getTextureRect());
	orangeShipItem.setTextureRect(orangeShip.getTextureRect());
	itemUpgrade.setTextureRect(sf::IntRect(infosUpgradeItem.posTexture, infosUpgradeItem.sizePixel));
	shield.setTextureRect(sf::IntRect(infosShield.posTexture, infosShield.sizePixel));
	life.setTextureRect(sf::IntRect(infosLife.posTexture, infosLife.sizePixel));
	coin.setTextureRect(sf::IntRect(infosCoin.posTexture, infosCoin.sizePixel));
	ammo.setTextureRect(sf::IntRect(infosAmmo.posTexture, infosAmmo.sizePixel));
	// Animation


	// ShipAlly
	ship.setScale(scaleShip);
	purpleShip.setScale(sf::Vector2f(infosPurpleShip.scale, infosPurpleShip.scale));
	redShip.setScale(sf::Vector2f(infosRedShip.scale, infosRedShip.scale));
	orangeShip.setScale(sf::Vector2f(infosOrangeShip.scale, infosOrangeShip.scale));
	// ShipEnemy
	Eagle5.setScale(sf::Vector2f(infosEagle5.scale, infosEagle5.scale));
	DixoveryOne.setScale(sf::Vector2f(infosDixoveryOne.scale, infosDixoveryOne.scale));
	PrawnMothership.setScale(sf::Vector2f(infosPrawnMothership.scale, infosPrawnMothership.scale));
	MondoshawanVessel.setScale(sf::Vector2f(infosMondoshawanVessel.scale, infosMondoshawanVessel.scale));
	Nostromo.setScale(sf::Vector2f(infosNostromo.scale, infosNostromo.scale));
	Narada.setScale(sf::Vector2f(infosNarada.scale, infosNarada.scale));
	MilleniumFalcon.setScale(sf::Vector2f(infosMilleniumFalcon.scale, infosMilleniumFalcon.scale));
	// Background
	planet_1.setScale(sf::Vector2f(infosPlanet_1.scale, infosPlanet_1.scale));
	planetRouge.setScale(sf::Vector2f(infosPlanetRouge.scale, infosPlanetRouge.scale));
	planetBleu.setScale(sf::Vector2f(infosPlanetBleu.scale, infosPlanetBleu.scale));
	shootingStar.setScale(sf::Vector2f(infosShootingStar.scale, infosShootingStar.scale));
	cloud.setScale(sf::Vector2f(infosCloud.scale, infosCloud.scale));
	// Fire
	fireBallShip.setScale(sf::Vector2f(infosFireBallShip.scale, infosFireBallShip.scale));
	greenLaser.setScale(sf::Vector2f(infosGreenLaser.scale, infosGreenLaser.scale));
	redLaser.setScale(sf::Vector2f(infosRedLaser.scale, infosRedLaser.scale));
	fireBallEnemy.setScale(sf::Vector2f(infosFireBallEnemy.scale, infosFireBallEnemy.scale));
	fireMissile.setScale(scaleFireMissile);
	// Item
	redShipItem.setScale(infosRedShipItem.scale);
	heavyShipItem.setScale(infosPurpleShipItem.scale);
	orangeShipItem.setScale(infosOrangeShipItem.scale);
	itemUpgrade.setScale(infosUpgradeItem.scale);
	shield.setScale(infosShield.scale);
	life.setScale(infosLife.scale);
	coin.setScale(infosCoin.scale);
	ammo.setScale(infosAmmo.scale);
	// Animation
	explosion.setScale(sf::Vector2f(infosExplosion.scale, infosExplosion.scale));
	hit.setScale(sf::Vector2f(infosHit.scale, infosHit.scale));
	glitter.setScale(sf::Vector2f(infosGlitter.scale, infosGlitter.scale));
	smoke.setScale(sf::Vector2f(infosSmoke.scale, infosSmoke.scale));
	atomicBomb.setScale(sf::Vector2f(infosAtomicBomb.scale, infosAtomicBomb.scale));

}

void Ressources::setSmooth()
{
	texture_ship.setSmooth(true);
	texture_shipEnemy.setSmooth(true);
	texture_spaceBackground.setSmooth(true);
	texture_planet_1.setSmooth(true);
	texture_shootingStar.setSmooth(true);
	texture_fireBallShip.setSmooth(true);
	texture_laserBullets.setSmooth(true);
	texture_fireBallEnemy.setSmooth(true);
	texture_fireMissile.setSmooth(true);
	texture_itemUpgrade.setSmooth(true);
	texture_shield.setSmooth(true);
	texture_coin.setSmooth(true);
	texture_explosion.setSmooth(true);
	texture_hit.setSmooth(true);
	texture_glitter.setSmooth(true);
	texture_smoke.setSmooth(true);
	texture_life.setSmooth(true);
	texture_atomicBomb.setSmooth(true);
	texture_planetRouge.setSmooth(true);
	texture_planetBleu.setSmooth(true);
	texture_ammo.setSmooth(true);
	texture_cloud.setSmooth(true);
}
