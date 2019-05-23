#include "Game.h"

int Game::heroMetMonster()
{
	for (size_t i = 0; i < AMOUNT_OF_MONS; ++i)
	{
		if (hero->getX() == positions[i][0] && hero->getY() == positions[i][1])
		{
			return i;
		}
	}
	return -1;
}

Game::Game()
{
	hero = new Warrior("Ali");
	size_t posX;
	size_t posY;
	char buff[2] = { 0, };
	char monsterName[10];
	monsters = new Monster*[AMOUNT_OF_MONS];

	srand(time(NULL));
	size_t count_monster = 0;
	bool flag = false;
	while (count_monster < AMOUNT_OF_MONS)
	{
		posX = (rand() % (WIDTH - 2)) + 1;
		posY = (rand() % (HEIGHT - 2)) + 1;
		flag = true;
		for(size_t j = 0; j < count_monster; ++j)
		{
			if (positions[j][0] == posX && positions[j][1] == posY) {
				flag = false;
				break;
			}
		}
		if (flag) {
			positions[count_monster][0] = posX;
			positions[count_monster][1] = posY;
			++count_monster;
		}
	}
	for (size_t i = 0; i < AMOUNT_GOBLINS; ++i)
	{	
		monsters[i] = new Goblin("Goblin", positions[i][0], positions[i][1]);
		memset(monsterName, 0, 10);
	}
	for (size_t i = AMOUNT_GOBLINS; i < AMOUNT_GOBLINS+AMOUNT_DRAGONKIN; ++i)
	{
		monsters[i] = new Dragonkin("Dragonkin", positions[i][0], positions[i][1]);
		memset(monsterName, 0, 10);
	}
	for (size_t i = AMOUNT_GOBLINS + AMOUNT_DRAGONKIN; i < AMOUNT_OF_MONS; ++i)
	{
		monsters[i] = new DeathKnight("DeathKnight", positions[i][0], positions[i][1]);
		memset(monsterName, 0, 10);
	}
}

Game::~Game()
{
	delete hero;
	for (size_t i = 0; i < AMOUNT_OF_MONS; ++i)
	{
		delete monsters[i];
	}
	delete[] monsters;
}

void Game::start()
{
	mainLoop();
}

void Game::mainLoop()
{
	update();
	char key;
	bool arrow;

	while (true) 
	{
		Sleep(1);
		arrow = false;
		if (_kbhit())
		{
			key = _getch();
			if (key == -32 || key == 0)
			{
				arrow = true;
				key = _getch();
			}
			if (arrow && key == UP_ARROW)
			{
				hero->moveUp();
			}
			else if (arrow && key == DOWN_ARROW) 
			{
				hero->moveDown();
			}
			else if (arrow && key == LEFT_ARROW) 
			{
				hero->moveLeft();
			}
			else if (arrow && key == RIGHT_ARROW)
			{
				hero->moveRight();
			}
			int index = heroMetMonster();
			std::cout << index << std::endl;
			if (index != (-1))
			{
				battle(monsters[index]);
			}
			update();
		}
	
	}
}

void Game::Init()
{
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			frame[i][j] = ' ';
		}
	}
	for (size_t i = 0; i < HEIGHT; ++i)
	{
		frame[i][0] = '|';
		frame[i][WIDTH - 1] = '|';
	}
	for (size_t i = 0; i < WIDTH; ++i)
	{
		frame[0][i] = '-';
		frame[HEIGHT - 1][i] = '-';
	}
	for (size_t i = 0; i < AMOUNT_GOBLINS; ++i)
	{
		frame[positions[i][1]][positions[i][0]] = 'G';
	}
	for (size_t i = AMOUNT_GOBLINS; i < AMOUNT_GOBLINS + AMOUNT_DRAGONKIN; ++i)
	{
		frame[positions[i][1]][positions[i][0]] = 'D';
	}
	for (size_t i = AMOUNT_GOBLINS + AMOUNT_DRAGONKIN; i < AMOUNT_OF_MONS; ++i)
	{
		frame[positions[i][1]][positions[i][0]] = 'K';
	}
	frame[hero->getY()][hero->getX()] = (char)236;
}

void Game::update()
{
	system("cls");

	Init();
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			std::cout << frame[i][j];
		}
		std::cout << std::endl;
	}
}

void Game::menu()
{

}

void Game::battle(Monster * monster)
{
	char optionHero;
	system("cls");
	while (hero->getHP() > 0.0 && monster->getHP() > 0.0)
	{
		hero->printInfo();
		std::cout << std::endl;
		monster->printInfo();
		int optionMonster = rand() % 2;
		std::cout << "Do you want to attack(a) or to defend(d)?" << std::endl;
		std::cin >> optionHero;
		if (optionHero == 'a')
		{
			if (optionMonster == 0)                  // monster attacks
			{
				monster->decreaseHP(hero->getAttack());
				hero->decreaseHP(monster->getAttack(hero));
			}
			else                                    // monster defends
			{
				monster->defend(hero->getAttack());
			}	
		}
		else if (optionHero == 'd')
		{
			if (optionMonster == 0)                  // monster attacks
			{
				hero->defend(monster->getAttack(hero));
			}
			else                                    // monster defends
			{
				hero->defend(0);
				monster->defend(0);
			}
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
		}
	}
}

