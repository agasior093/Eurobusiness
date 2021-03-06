#pragma once

#include "view\include\GameView.h"
#include <vector>
#include <string>
#include <iostream>

class NewGame {
	unsigned m_numberOfPlayers;
	std::vector<std::string> m_playerNames;
public:
	NewGame() {}
	~NewGame() = default;

	void start();
};
