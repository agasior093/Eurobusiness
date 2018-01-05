#pragma once

#include <vector>
#include "../include/Dice.h"
#include "../include/Player.h"

namespace logic {
	class Game {
		//game objects
		Dice m_firstDice, m_secondDice;

		//players
		std::vector<Player> m_players;
		unsigned m_numberOfPlayers;
		unsigned m_activePlayer = 0;

		//current turn data
		bool m_canThrow = true;
		bool m_canMove = false;
		bool m_passedStart = false;
		unsigned m_throwsInCurrentTurn = 0;
		unsigned m_doublesInCurrentTurn = 0;		
		unsigned m_totalRollResult = 0;
				
	public:		
		Game(unsigned, std::vector<std::string>&);
		~Game() = default;	

		logic::Player& getActivePlayer();

		void reset(); 
		void permissionToThrow(bool);

		void startTurn();
		void rollTheDice();
		std::string checkForDoubles();
		void setInMotion(unsigned);
		bool canEndTurn();
		bool endTurn();
		

		//getters
		bool canThrow() const;
		bool canMove() const;
		unsigned getThrowsInCurrentTurn() const;
		unsigned getDoublesInCurrentTurn() const;
		unsigned getTotalRollResult() const;
	};
}