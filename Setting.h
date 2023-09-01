#pragma once

class Setting
{
public:
	static void setVolume(int newVolume);
	static int getVolume();

	static void setAffichageFps(bool affFPS);
	static bool getStateFPS();

	static void addCoin(int AddCoin);
	static unsigned int getCoin();

private:
	static int volume;
	static bool affichageFPS;
	static unsigned int coin;
};
