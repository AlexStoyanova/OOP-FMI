#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

#include "Constants.h"
#include "Warrior.h"
#include "Mage.h"
#include "Paladin.h"
#include "Goblin.h"
#include "Dragonkin.h"
#include "DeathKnight.h"

class Game
{
private:
	char frame[HEIGHT][WIDTH];
	size_t positions[20][2];
	Monster** monsters;
	Hero* hero;
private:
	int heroMetMonster();
	void mainLoop();
	void Init();
	void update();
	void menu();
	void battle(size_t index);
	bool generatePair(size_t& posX, size_t& posY, size_t size);
	void createHero();
	void loadHero();
public:
	Game();
	~Game();
	void start();


};

#endif
