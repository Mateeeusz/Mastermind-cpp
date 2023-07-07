#pragma once

#include "Player.h"

class PCPlayer : public Player
{
public:
	PCPlayer(std::string Name, std::string Color);

	int AmountOfWhite = 0;
	int AmountOfBlack = 0;

	void RunTurn() override;
};

