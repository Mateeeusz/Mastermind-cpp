#include "PCPlayer.h"
#include "HumanPlayer.h"
#include <algorithm>
#include <ctime>
#include <iostream>

PCPlayer::PCPlayer(std::string Name, std::string Color)
	: Player(Name)
{
	RemainingTurns = -1;

	if (Color.size())
	{
		ColorSet = Color;

		for (int i = 0; i < 4; ++i)
		{
			if (ColorSet[i] == 'W') AmountOfWhite++;
			else AmountOfBlack++;
		}
	}
	else
	{
		std::srand(std::time(nullptr));

		for (int i = 0; i < 4; ++i)
		{
			if (std::rand() / ((RAND_MAX + 1u) / 2) == 0)
			{
				ColorSet += "W";
				AmountOfWhite++;
			}
			else
			{
				ColorSet += "B";
				AmountOfBlack++;
			}
		}
	}
}

void PCPlayer::RunTurn()
{
	std::string CurrentGuess = LinkedPlayer->ColorSet;

	std::transform(CurrentGuess.begin(), CurrentGuess.end(), CurrentGuess.begin(), ::toupper);

	int RightColorAndPlacement = 0;
	int RightColorWrongSpot = 0;

	int whites = AmountOfWhite;
	int blacks = AmountOfBlack;
	int WrontWhites = 0;
	int WrongBlacks = 0;

	if (CurrentGuess == ColorSet)
	{
		LinkedPlayer->bWonGame = true;
		return;
	}

	for (int i = 0; i < CurrentGuess.size(); i++)
	{
		if (CurrentGuess[i] == ColorSet[i])
		{
			RightColorAndPlacement++;
			if (CurrentGuess[i] == 'W')
			{
				whites--;
			}
			else if (CurrentGuess[i] == 'B') {
				blacks--;
			}
		}
		else
		{
			if (CurrentGuess[i] == 'W')
			{
				WrontWhites++;
			}
			else if (CurrentGuess[i] == 'B') {
				WrongBlacks++;
			}
		}
	}

	if (WrontWhites >= whites)
	{
		RightColorWrongSpot += whites;
	}
	else 
	{
		RightColorWrongSpot += WrontWhites;
	}

	if (WrongBlacks >= blacks) {
		RightColorWrongSpot += blacks;
	}
	else 
	{
		RightColorWrongSpot += WrongBlacks;
	}

	std::cout << "You have " << RightColorAndPlacement << " correct colors and positions.\n";
	std::cout << "You have " << RightColorWrongSpot << " right colors, but in the wrong positions.\n\n";
}
