#include <iostream>
#include <fstream>
#include <string.h>
#include "Student.h"

int main()
{
	char command[32];
	bool notExit = true;
	while (notExit)
	{
		std::cout << "Enter command: " << std::endl;
		std::cin >> command;
		if (strcmp(command, "create") == 0)
		{
			create();
		}
		else if (strcmp(command, "sequentialSearch") == 0)
		{
			sequentialSearch();
		}
		else if (strcmp(command, "exit") == 0)
		{
			notExit = false;
		}
		else
		{
			std::cout << "This is not a command!" << std::endl;
		}
	}
	return 0;
}