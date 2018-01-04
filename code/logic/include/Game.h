#pragma once

#include <vector>
#include "../include/Dice.h"
#include "../include/Player.h"

namespace logic {
	class Game {
		//game objects
		Dice m_dice;

		//players
		std::vector<Player> m_players;
		unsigned m_numberOfPlayers;
		unsigned m_activePlayer = 0;

		//current turn data
		bool m_passedStart = false;
		unsigned m_doublesInCurrentTurn = 0;
		unsigned m_throwsInCurrentTurn = 0;
		unsigned m_totalRollResult = 0;
				
	public:
		Game(unsigned, std::vector<std::string>&);
		~Game() = default;	

		logic::Player& getActivePlayer();

		void startTurn();
		unsigned rollTheDice();
		std::string checkForDoubles();
		void setInMotion(unsigned);
	};
}