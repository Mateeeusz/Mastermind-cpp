#pragma once

#include <string>

class Player
{
public:
	Player(std::string Name);

	Player* LinkedPlayer;

	std::string PlayerName = "";

	std::string ColorSet = "";

	int RemainingTurns = 0;

	bool bWonGame = false;

	virtual void RunTurn() = 0;
};

