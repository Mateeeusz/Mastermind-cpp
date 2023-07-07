#pragma once

#include <vector>
#include <string>

class Player;

class Mastermind
{
public:
	Mastermind(bool InbRandomizeColorsForEachPlayer);

	void BeginGame();

	void FinishGame(const Player& Winner);

	void SaveState();

	bool TryLoadState();

	std::vector<Player*> Players;

	std::string Color = "";

	int AmountOfPlayers = 0;

	int AmountOfPlayerTurns = 10;

	bool bRandomizeColorsForEachPlayer;
};

