#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

struct InfosSprite {
	float scale;
	sf::Vector2i sizePixel;
	sf::Vector2i posTexture;
};

struct InfosSpriteItem {
	sf::Vector2i sizePixel;
	sf::Vector2f scale;
	sf::Vector2i posTexture;
};

struct InfosAnimation {
	float scale;
	sf::Vector2i sizePixel;
	sf::Vector2i posTexture;
	sf::Vector2i sizeAnim;
};

class Ressources
{
public:
	static void load();
	static void setSmooth();

	// Font 
	static sf::Font font_lasercorpsgradital;
	static sf::Font font_lasercorps;
	static sf::Font font_JAi_____;

	// Sound
	static sf::Sound soundFire;
	static sf::Sound soundHit;

	// ShipAlly
	static sf::Sprite ship;
	static sf::Sprite purpleShip;
	static sf::Sprite redShip;
	static sf::Sprite orangeShip;
	// ShipEnemy
	static sf::Sprite Eagle5;
	static sf::Sprite DixoveryOne;
	static sf::Sprite PrawnMothership;
	static sf::Sprite MondoshawanVessel;
	static sf::Sprite Nostromo;
	static sf::Sprite Narada;
	static sf::Sprite MilleniumFalcon;
	// Background
	static sf::Sprite spaceBackground;
	static sf::Sprite planet_1;
	static sf::Sprite planetRouge;
	static sf::Sprite planetBleu;
	static sf::Sprite shootingStar;
	static sf::Sprite cloud;
	// Fire
	static sf::Sprite fireBallShip;
	static sf::Sprite greenLaser;
	static sf::Sprite redLaser;
	static sf::Sprite fireBallEnemy;
	static sf::Sprite fireMissile;
	// Item
	static sf::Sprite redShipItem;
	static sf::Sprite heavyShipItem;
	static sf::Sprite orangeShipItem;
	static sf::Sprite itemUpgrade;
	static sf::Sprite shield;
	static sf::Sprite life;
	static sf::Sprite coin;
	static sf::Sprite ammo;
	// Animation
	static sf::Sprite explosion;
	static sf::Sprite hit;
	static sf::Sprite glitter;
	static sf::Sprite smoke;
	static sf::Sprite atomicBomb;


	// ShipAlly
	static sf::Vector2f getSizeRenderShip() { return sf::Vector2f(sizeShipDefault.x * scaleShip.x, sizeShipDefault.y * scaleShip.y); }
	static sf::Vector2f getSizeRenderPurpleShip() { return sf::Vector2f(infosPurpleShip.sizePixel) * infosPurpleShip.scale; }
	static sf::Vector2f getSizeRenderRedShip() { return sf::Vector2f(infosRedShip.sizePixel) * infosRedShip.scale; }
	static sf::Vector2f getSizeRenderOrangeShip() { return sf::Vector2f(infosOrangeShip.sizePixel) * infosOrangeShip.scale; }
	// ShipEnemy
	static sf::Vector2f getSizeRenderEagle5() { return sf::Vector2f(infosEagle5.sizePixel) * infosEagle5.scale; }
	static sf::Vector2f getSizeRenderDixoveryOne() { return sf::Vector2f(infosDixoveryOne.sizePixel) * infosDixoveryOne.scale; }
	static sf::Vector2f getSizeRenderPrawnMothership() { return sf::Vector2f(infosPrawnMothership.sizePixel) * infosPrawnMothership.scale; }
	static sf::Vector2f getSizeRenderMondoshawanVessel() { return sf::Vector2f(infosMondoshawanVessel.sizePixel) * infosMondoshawanVessel.scale; }
	static sf::Vector2f getSizeRenderNostromo() { return sf::Vector2f(infosNostromo.sizePixel) * infosNostromo.scale; }
	static sf::Vector2f getSizeRenderNarada() { return sf::Vector2f(infosNarada.sizePixel) * infosNarada.scale; }
	static sf::Vector2f getSizeRenderMilleniumFalcon() { return sf::Vector2f(infosMilleniumFalcon.sizePixel) * infosMilleniumFalcon.scale; }
	// Background
	static sf::Vector2f getSizeRenderPlanet_1() { return sf::Vector2f(infosPlanet_1.sizePixel) * infosPlanet_1.scale; }
	static sf::Vector2f getSizeRenderPlanetRouge() { return sf::Vector2f(infosPlanetRouge.sizePixel) * infosPlanetRouge.scale; }
	static sf::Vector2f getSizeRenderPlanetBleu() { return sf::Vector2f(infosPlanetBleu.sizePixel) * infosPlanetBleu.scale; }
	static sf::Vector2f getSizeRenderShootingStar() { return sf::Vector2f(infosShootingStar.sizePixel) * infosShootingStar.scale; }
	static sf::Vector2f getSizeRenderCloud() { return sf::Vector2f(infosCloud.sizePixel) * infosCloud.scale; }
	// Fire
	static sf::Vector2f getSizeRenderFireBallShip() { return sf::Vector2f(infosFireBallShip.sizePixel) * infosFireBallShip.scale; }
	static sf::Vector2f getSizeRenderGreenLaser() { return sf::Vector2f(infosGreenLaser.sizePixel) * infosGreenLaser.scale; }
	static sf::Vector2f getSizeRenderRedLaser() { return sf::Vector2f(infosRedLaser.sizePixel) * infosRedLaser.scale; }
	static sf::Vector2f getSizeRenderFireBallEnemy() { return sf::Vector2f(infosFireBallEnemy.sizePixel) * infosFireBallEnemy.scale; }
	static sf::Vector2f getSizeRenderFireMissile() { return sf::Vector2f(sizeFireMissile.x * scaleFireMissile.x, sizeFireMissile.y * scaleFireMissile.y); }
	// Item
	static sf::Vector2f getSizeRenderAllItem() { return sizeRenderItem; }
	static sf::Vector2f getSizeRenderCoin() { return sf::Vector2f(infosCoin.sizePixel.x * infosCoin.scale.x, infosCoin.sizePixel.y * infosCoin.scale.y); }
	
	// Animation
	static sf::Vector2f getSizeRenderExplosion() { return sf::Vector2f(infosExplosion.sizePixel) * infosExplosion.scale; }
	static sf::Vector2f getSizeRenderHit() { return sf::Vector2f(infosHit.sizePixel) * infosHit.scale; }
	static sf::Vector2f getSizeRenderGlitter() { return sf::Vector2f(infosGlitter.sizePixel) * infosGlitter.scale; }
	static sf::Vector2f getSizeRenderSmoke() { return sf::Vector2f(infosSmoke.sizePixel) * infosSmoke.scale; }
	static sf::Vector2f getSizeRenderAtomicBomb() { return sf::Vector2f(infosAtomicBomb.sizePixel) * infosAtomicBomb.scale; }

	static sf::Vector2f getSizePixelMissile() { return sizeFireMissile; }


	// ShipAlly
	static InfosSprite infosPurpleShip;
	static InfosSprite infosRedShip;
	static InfosSprite infosOrangeShip;
	// ShipEnemy
	static InfosSprite infosEagle5;
	static InfosSprite infosDixoveryOne;
	static InfosSprite infosPrawnMothership;
	static InfosSprite infosMondoshawanVessel;
	static InfosSprite infosNostromo;
	static InfosSprite infosNarada;
	static InfosSprite infosMilleniumFalcon;
	// Background
	static InfosSprite infosSpaceBackground;
	static InfosSprite infosPlanet_1;
	static InfosSprite infosPlanetRouge;
	static InfosSprite infosPlanetBleu;
	static InfosSprite infosShootingStar;
	static InfosSprite infosCloud;
	// Fire
	static InfosSprite infosFireBallEnemy;
	static InfosSprite infosFireBallShip;
	static InfosSprite infosRedLaser;
	static InfosSprite infosGreenLaser;
	// Item
	static InfosSpriteItem infosRedShipItem;
	static InfosSpriteItem infosPurpleShipItem;
	static InfosSpriteItem infosOrangeShipItem;
	static InfosSpriteItem infosUpgradeItem;
	static InfosSpriteItem infosShield;
	static InfosSpriteItem infosLife;
	static InfosSpriteItem infosCoin;
	static InfosSpriteItem infosAmmo;
	// Animation
	static InfosAnimation infosExplosion;
	static InfosAnimation infosHit;
	static InfosAnimation infosGlitter;
	static InfosAnimation infosSmoke;
	static InfosAnimation infosAtomicBomb;

	static InfosSprite infosGameOver;



public: ///////////// !!!!!!!METTRE EN PRIVATE ATTENTION!!!!!! ///////////////////////////
	// ShipAlly
	static sf::Vector2f scaleShip;
	// ShipEnemy
	// Background
	// Fire
	static sf::Vector2f scaleFireMissile;
	// Item
	// Animation

private:
	// ShipAlly
	static sf::Vector2f sizeRenderShip;
	static sf::Vector2f sizeShipDefault;
	// ShipEnemy
	// Background
	// Fire
	static sf::Vector2f sizeFireMissile;
	// Item
	static sf::Vector2f sizeRenderItem;
	// Animation


	// ShipAlly
	static sf::Texture texture_ship;
	static sf::Texture texture_fireBallShip;
	// ShipEnemy
	static sf::Texture texture_shipEnemy;
	// Background
	static sf::Texture texture_spaceBackground;
	static sf::Texture texture_planet_1;
	static sf::Texture texture_planetRouge;
	static sf::Texture texture_planetBleu;
	static sf::Texture texture_shootingStar;
	static sf::Texture texture_cloud;
	// Fire
	static sf::Texture texture_laserBullets;
	static sf::Texture texture_fireBallEnemy;
	static sf::Texture texture_fireMissile;
	// Item
	static sf::Texture texture_itemUpgrade;
	static sf::Texture texture_shield;
	static sf::Texture texture_life;
	static sf::Texture texture_coin;
	static sf::Texture texture_ammo;
	// Animation
	static sf::Texture texture_explosion;
	static sf::Texture texture_hit;
	static sf::Texture texture_glitter;
	static sf::Texture texture_smoke;
	static sf::Texture texture_atomicBomb;


	// Sound
	static sf::SoundBuffer buffer_soundFire;
	static sf::SoundBuffer buffer_soundHit;
};

