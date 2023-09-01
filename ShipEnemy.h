#pragma once
#include <iostream>
#include "Enemy.h"
#include "SFML/Graphics.hpp"

class Eagle5 : public Enemy
{
public:
	Eagle5(Path* path, float tempsVieS);
	void fire(Ship* ship);
	void initHitBox();

private:
	FireStruct fireStruct;
};

class DixoveryOne : public Enemy
{
public:
	DixoveryOne(Path* path, float tempsVieS);
	void fire(Ship* ship);
	void initHitBox();

private:
	FireStruct fireStruct;
};

class PrawnMothership : public Enemy
{
public:
	PrawnMothership(Path* path, float tempsVieS);
	void fire(Ship* ship);
	void initHitBox();

private:
	FireStruct fireStruct;
};

class MondoshawanVessel : public Enemy
{
public:
	MondoshawanVessel(Path* path, float tempsVieS);
	void fire(Ship* ship);
	void initHitBox();

private:
	FireStruct fireStruct;
};

class Nostromo : public Enemy
{
public:
	Nostromo(Path* path, float tempsVieS);
	void fire(Ship* ship);

private:
	FireStruct fireStruct;
};

class Narada : public Enemy
{
public:
	Narada(Path* path, float tempsVieS);
	void fire(Ship* ship);

private:
	FireStruct fireStruct;
};

class MilleniumFalcon : public Enemy
{
public:
	MilleniumFalcon(Path* path, float tempsVieS);
	void fire(Ship* ship);

private:
	FireStruct fireStruct;
};