#pragma once

#include <vector>
#include "../include/Dice.h"
#include "../include/Player.h"
#include "../include/GameBoard.h"

namespace logic {
	class Game {
		logic::GameBoard m_gameBoard;
		logic::Dice m_diceOne, m_diceTwo;	

		//players
		std::vector<logic::Player> m_players;
		unsigned m_numberOfPlayers;
		unsigned m_activePlayer = 0;

		//current turn data
		bool m_canThrow = true;
		bool m_canMove = false;
		bool m_passedStart = false;
		int m_throwsInCurrentTurn = 0;
		int m_doublesInCurrentTurn = 0;		
		int m_totalRollResult = 0;
						
	public:		
		Game(std::vector<std::string>&);
		~Game() = default;	

		logic::Player& getActivePlayer();
		logic::Player& getPlayer(int);
		unsigned getActivePlayerID();

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
		int getThrowsInCurrentTurn() const;
		int getDoublesInCurrentTurn() const;		
		int getTotalRollResult() const;

		logic::GameBoard& getBoard();
		logic::Dice& getDiceOne();
		logic::Dice& getDiceTwo();
	};
}

