#include "Setting.h"

// lire dans un fichier
int Setting::volume{ 10 };
bool Setting::affichageFPS{ false };
unsigned int Setting::coin{ 0 };

void Setting::setVolume(int newVolume)
{
	volume = newVolume;
}

int Setting::getVolume()
{
	return volume;
}

void Setting::setAffichageFps(bool affFPS)
{
	affichageFPS = affFPS;
}

bool Setting::getStateFPS()
{
	return affichageFPS;
}

void Setting::addCoin(int AddCoin)
{
	coin += AddCoin;
}

unsigned int Setting::getCoin()
{
	return coin;
}
