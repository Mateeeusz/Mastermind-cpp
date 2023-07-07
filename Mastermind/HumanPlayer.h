#pragma once

#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(std::string Name, int AmountOfTurns);

	void RunTurn() override;
};

