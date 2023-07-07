#include <iostream>
#include <limits>
#include <ctime>
#include <fstream>

#include "Mastermind.h"
#include "PCPlayer.h"
#include "HumanPlayer.h"

void Mastermind::SaveState()
{
	std::ofstream file;
	file.open("gamesaved.txt");
	file << AmountOfPlayers;
	file.close();
}

bool Mastermind::TryLoadState()
{
	std::ifstream file("gamesaved.txt");
	std::string line;
	while (std::getline(file, line)) 
	{
		if (std::isdigit(line[0]))
		{
			AmountOfPlayers = std::stoi(line);
			return true;
		}
		return false;
	}
}

Mastermind::Mastermind(bool InbRandomizeColorsForEachPlayer)
	: bRandomizeColorsForEachPlayer(InbRandomizeColorsForEachPlayer)
{
	std::cout << "For every player we will have a corresponding AI that will be the one randomizing colors.\n";

	std::string choice = "";

	do
	{
		std::cout << "Do you want to try to load previous amount of players? (y/n)\n";
		std::cin >> choice;

		if (choice == "y" || choice == "Y" || choice == "n" || choice == "N") break;

	} while (1);

	if (choice == "y" || choice == "Y")
		if (TryLoadState() && AmountOfPlayers > 0)
		{
			std::cout << "Successfully loaded previous state with " << AmountOfPlayers << " players.\n";
		}
		else
		{
			std::cout << "Failed loading players.\n";

			do
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "Enter amount of players(integer > 0): "; std::cin >> AmountOfPlayers;

			} while (!std::cin.good());
		}

	

	SaveState();

	if (!InbRandomizeColorsForEachPlayer)
	{
		std::srand(std::time(nullptr));

		for(int i = 0; i < 4; ++i)
			Color += std::rand() / ((RAND_MAX + 1u) / 2) == 0 ? "W" : "B";
	}
		
	std::string Name = "";
	for (int i = 0; i < AmountOfPlayers; ++i)
	{
		Name = "Player" + std::to_string(i);
		Players.push_back(new HumanPlayer(Name, AmountOfPlayerTurns));
		Name = "PC" + std::to_string(i);
		Players.push_back(new PCPlayer(Name, Color));
	}

	for (int i = 0; i < Players.size(); i += 2)
	{
		Players[i]->LinkedPlayer = Players[i + 1];
		Players[i + 1]->LinkedPlayer = Players[i];
	}
}

void Mastermind::BeginGame()
{
	for (int i = 0; i < Players.size(); i += 2)
	{
		while (Players[i]->RemainingTurns != 0)
		{
			Players[i]->RunTurn();
			Players[i + 1]->RunTurn();
			std::cout << Players[i + 1]->ColorSet;

			if (Players[i]->bWonGame)
			{
				FinishGame(*Players[i]);
				break;
			}

			if (Players[i]->RemainingTurns == 0)
			{
				std::cout << "\n\n" << Players[i]->PlayerName << " lost.\n\n";
			}
		}
	}
}

void Mastermind::FinishGame(const Player& Winner)
{
	std::cout << Winner.PlayerName << " after " << (AmountOfPlayerTurns - Winner.RemainingTurns) << " turns is a winner!\n\n";
}





