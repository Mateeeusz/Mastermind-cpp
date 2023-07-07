#include "Mastermind.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Mastermind Game.\n";

	std::string choice = "";
	do
	{
		std::cout << "Do you want to randomize the colors for each player or keep one static pair? (y/n)\n";
		std::cin >> choice;

		if (choice == "y" || choice == "Y" || choice == "n" || choice == "N") break;

	} while (1);

	bool bRandColors = false;

	if (choice == "y" || choice == "Y")
		bRandColors = true;

	Mastermind* ms = new Mastermind(bRandColors);

	ms->BeginGame();

	return 0;
}