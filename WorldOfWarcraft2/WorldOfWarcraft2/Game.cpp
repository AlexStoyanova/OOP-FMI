#include "Game.h"

const char* DB_FILE_NAME = "data.bin";

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
	hero = nullptr;
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
		flag = generatePair(posX, posY, count_monster);
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

	/*std::ifstream ifs(DB_FILE_NAME, std::ios::binary);
	if (!ifs.good())
	{
		numHeroInList = 0;
		std::ofstream ofs(DB_FILE_NAME, std::ios::binary);
		ofs.write((const char*)&numHeroInList, sizeof(size_t));
		ofs.close();
	}
	else
	{
		ifs.read((char*)&numHeroInList, sizeof(size_t));
	}
	ifs.close();*/
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
	menu();
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
			else if (key == EXIT)
			{
				return;
			}
			int index = heroMetMonster();
			if (index != (-1))
			{
				battle(index);
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
	int options = -1;
	bool arrow;
	char key;
	std::cout << "Welcome to the game WOW!" << std::endl;
	std::cout << "PLAY" << std::endl;
	std::cout << "NEW HERO" << std::endl;
	std::cout << "LOAD HERO" << std::endl;
	std::cout << "EXIT" << std::endl;
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
				options--;
				if (options == -1)
				{
					options = MAX_OPTIONS_IN_MENU - 1;
				}
			}
			else if (arrow && key == DOWN_ARROW)
			{
				options++;
				if (options == MAX_OPTIONS_IN_MENU)
				{
					options = 0;
				}
			}
			else if (key == ENTER)
			{
				if (options == 0)
				{
					if (hero != nullptr)
					{
						mainLoop();
						if (hero->getHP() > 0.0)
						{
							saveHeroInFile();
						}
					}
					else
					{
						std::cout << "Create a hero or load a previous one!" << std::endl;
						Sleep(1000);
					}
				}
				else if (options == 1)
				{
					createHero();
				}
				else if (options == 2)
				{
					loadHero();
				}
				else if (options == 3)
				{
					std::cout << "See you next time, friend!" << std::endl;
					Sleep(1);
					exit(0);
				}
			}
			system("cls");
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			int red = 12;
			int white = 15;
			if (options == 0)
			{
				SetConsoleTextAttribute(hConsole, red);
				std::cout << "PLAY" << std::endl;

				SetConsoleTextAttribute(hConsole, white);
				std::cout << "NEW HERO" << std::endl;
				std::cout << "LOAD HERO" << std::endl;
				std::cout << "EXIT" << std::endl;

			}
			else if (options == 1) 
			{
				SetConsoleTextAttribute(hConsole, white);
				std::cout << "PLAY" << std::endl;

				SetConsoleTextAttribute(hConsole, red);
				std::cout << "NEW HERO" << std::endl;
			
				SetConsoleTextAttribute(hConsole, white);
				std::cout << "LOAD HERO" << std::endl;
				std::cout << "EXIT" << std::endl;
			}
			else if (options == 2)
			{
				SetConsoleTextAttribute(hConsole, white);
				std::cout << "PLAY" << std::endl;
				std::cout << "NEW HERO" << std::endl;

				SetConsoleTextAttribute(hConsole, red);
				std::cout << "LOAD HERO" << std::endl;

				SetConsoleTextAttribute(hConsole, white);
				std::cout << "EXIT" << std::endl;
			}
			else if (options == 3)
			{
				SetConsoleTextAttribute(hConsole, white);
				std::cout << "PLAY" << std::endl;
				std::cout << "NEW HERO" << std::endl;
				std::cout << "LOAD HERO" << std::endl;

				SetConsoleTextAttribute(hConsole, red);
				std::cout << "EXIT" << std::endl;

				SetConsoleTextAttribute(hConsole, white);
			}
		}
	}
}

void Game::battle(size_t index)
{
	Monster* monster = monsters[index];
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
				std::cout << std::endl << "Monster attacks you!" << std::endl;
			}
			else                                    // monster defends
			{
				monster->defend(hero->getAttack());
				std::cout << std::endl << "Monster defends!" << std::endl;
			}	
		}
		else if (optionHero == 'd')
		{
			if (optionMonster == 0)                  // monster attacks
			{
				hero->defend(monster->getAttack(hero));
				std::cout << std::endl << "Monster attacks you!" << std::endl;
			}
			else                                    // monster defends
			{
				hero->defend(0);
				monster->defend(0);
				std::cout << std::endl << "Monster defends!" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
		}
	}
	if (monster->getHP() <= 0.0)
	{
		hero->increaseKilledMonsters();
		if (hero->getKilledMons() == (1 << hero->getLevel()))
		{
			hero->levelUp();
		}
		delete monster;
		size_t posX, posY;
		while (!generatePair(posX, posY, AMOUNT_OF_MONS));
		if (index < AMOUNT_GOBLINS)
		{
			monster = new Goblin("Goblin", posX, posY);
		}
		else if (index >= AMOUNT_GOBLINS && index < AMOUNT_GOBLINS + AMOUNT_DRAGONKIN)
		{
			monster = new Dragonkin("Dragonkin", posX, posY);
		}
		else
		{
			monster = new DeathKnight("DeathKnight", posX, posY);
		}
		positions[index][0] = posX;
		positions[index][1] = posY;
	}
}

bool Game::generatePair(size_t& posX, size_t& posY, size_t size)
{
	posX = (rand() % (WIDTH - 2)) + 1;
	posY = (rand() % (HEIGHT - 2)) + 1;
	for (size_t j = 0; j < size; ++j)
	{
		if (positions[j][0] == posX && positions[j][1] == posY) {
			return false;
		}
	}
	return true;
}

void Game::createHero()
{
	system("cls");
	std::cout << "Choose one of the heroes: " << std::endl;
	std::cout << "->Warrior" << std::endl;
	std::cout << "->Paladin" << std::endl;
	std::cout << "->Mage" << std::endl;
	int options = -1;
	bool arrow;
	char key;
	char nameHero[128];
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
				options--;
				if (options == -1)
				{
					options = MAX_OPTIONS_IN_HEROES_MENU - 1;
				}
			}
			else if (arrow && key == DOWN_ARROW)
			{
				options++;
				if (options == MAX_OPTIONS_IN_HEROES_MENU)
				{
					options = 0;
				}
			}
			else if (key == ENTER)
			{
				if (options == 0)
				{
					system("cls");
					std::cout << "Enter hero name: " << std::endl;
					std::cin.getline(nameHero, 128);
					hero = new Warrior(nameHero);
					return;
				}
				else if (options == 1)
				{
					system("cls");
					std::cout << "Enter hero name: " << std::endl;
					std::cin.getline(nameHero, 128);
					hero = new Paladin(nameHero);
					return;
				}
				else if (options == 2)
				{
					system("cls");
					std::cout << "Enter hero name: " << std::endl;
					std::cin.getline(nameHero, 128);
					hero = new Mage(nameHero);
					return;
				}
			}
			system("cls");
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			int red = 12;
			int white = 15;
			if (options == 0)
			{
				SetConsoleTextAttribute(hConsole, red);
				std::cout << "->Warrior" << std::endl;

				SetConsoleTextAttribute(hConsole, white);
				std::cout << "->Paladin" << std::endl;
				std::cout << "->Mage" << std::endl;
			}
			else if (options == 1)
			{
				SetConsoleTextAttribute(hConsole, white);
				std::cout << "->Warrior" << std::endl;

				SetConsoleTextAttribute(hConsole, red);
				std::cout << "->Paladin" << std::endl;

				SetConsoleTextAttribute(hConsole, white);
				std::cout << "->Mage" << std::endl;
			}
			else if (options == 2)
			{
				SetConsoleTextAttribute(hConsole, white);
				std::cout << "->Warrior" << std::endl;
				std::cout << "->Paladin" << std::endl;

				SetConsoleTextAttribute(hConsole, red);
				std::cout << "->Mage" << std::endl;

				SetConsoleTextAttribute(hConsole, white);
			}
		}
	}
}

void Game::loadHero()
{
	size_t tempNumHeroInList = 0;
	size_t allHeroesInList = 0;
	size_t lenHeroName = 0;
	char* tempHeroName;
	double tempHp = 0.0;
	double tempStrength = 0.0;
	double tempIntelligence = 0.0;
	size_t tempLevel = 0;
	size_t identificator = 0;
	char blank[5];

	std::ifstream ifs(DB_FILE_NAME, std::ios::binary);
	if (ifs.is_open())
	{
	//	ifs.read((char*)&allHeroesInList, sizeof(allHeroesInList));
		while (!ifs.eof())
		{
			ifs.read(blank, sizeof("\n"));
			if (ifs.eof())
			{
				break;
			}

		//	ifs.read((char*)&tempNumHeroInList, sizeof(tempNumHeroInList));

			ifs.read((char*)&lenHeroName, sizeof(lenHeroName));

			if (ifs.eof())
			{
				break;
			}

			tempHeroName = new char[lenHeroName + 1];

			ifs.read(tempHeroName, sizeof(lenHeroName));
			if (ifs.eof())
			{
				break;
			}

			tempHeroName[lenHeroName] = '\0';
			
			ifs.read((char*)&tempHp, sizeof(tempHp));
		
			ifs.read((char*)&tempStrength, sizeof(tempStrength));
		
			ifs.read((char*)&tempIntelligence, sizeof(tempIntelligence));
			
			ifs.read((char*)&tempLevel, sizeof(tempLevel));

		//	std::cout << tempNumHeroInList << " ";
			system("cls");
			printHero(tempHeroName, tempHp, tempStrength, tempIntelligence, tempLevel);
			Sleep(10000);
		}
	}
	system("cls");
	std::cout << "Choose hero by number: " << std::endl;
	std::cin >> identificator;

	ifs.close();
}

void Game::saveHeroInFile()
{
	std::ofstream ofs(DB_FILE_NAME, std::ios::binary | std::ios::app);
	if (ofs.is_open())
	{
	//	numHeroInList++;
	//	ofs.seekp(0, std::ios::beg);
	//  ofs.write((const char*)&numHeroInList, sizeof(numHeroInList));
	//  ofs.seekp(0, std::ios::end);
		hero->serialize(ofs, numHeroInList);
	}
	ofs.close();
}

void Game::printHero(const char* name, double& hp, double& strength, double& intelligence, size_t& level) const
{
	std::cout << "Hero name: " << name << ", HP: " << hp << ", strength: " << strength << ", intelligence: " 
		      << intelligence << ", level: " << level << std::endl;
}

