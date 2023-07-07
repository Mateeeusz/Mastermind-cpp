#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(std::string Name, int AmountOfTurns)
	: Player(Name)
{
	RemainingTurns = AmountOfTurns;
}

void HumanPlayer::RunTurn()
{
	ColorSet = "";
	bool invalid = false;
	do
	{
		std::cout << "You have " << RemainingTurns << " remaining turns left.\n";
		std::cout << PlayerName << " make your guess, the AI randomized 4 colors that are either white or black (example WWBB): ";
		invalid = false;

		std::cin >> ColorSet;
		if (ColorSet.size() != 4)
		{
			invalid = true;
		}
		for (auto ch : ColorSet)
		{
			if (std::toupper(ch) != 'W' && std::toupper(ch) != 'B')
			{
				invalid = true;
				break;
			}
		}
	} while (invalid);

	RemainingTurns--;
}
