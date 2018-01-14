#pragma once

#include <vector>
#include "../include/Dice.h"
#include "../include/GameBoard.h"
#include "../include/PropertyManager.h"

namespace logic {
	class Game {
		logic::GameBoard m_gameBoard;
		logic::Dice m_diceOne, m_diceTwo;
		//logic::PropertyManager m_propertyManager;

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
		Game(const Game& src) { }
		~Game() = default;	

		bool m_stateBeforeThrow = true;

		void reset(); 
		void permissionToThrow(bool);

		void startTurn();
		void rollTheDice();
		std::string checkForDoubles();
		void setInMotion(unsigned);
		void activateNewPosition();
		bool canEndTurn();
		bool endTurn();		

		void jailRoll();
		void collectCash();

		//getters
		bool canThrow() const;
		bool canMove() const;
		bool isStateBeforeThrow() const;
		std::string passedStart() const;
		int getThrowsInCurrentTurn() const;
		int getDoublesInCurrentTurn() const;		
		int getTotalRollResult() const;

		//logic::PropertyManager& getPropertyManager();
		logic::Field& getActiveField();
		logic::Player& getActivePlayer();
		logic::Player& getPlayer(int);
		unsigned getActivePlayerID();
		logic::GameBoard& getBoard();
		logic::Dice& getDiceOne();
		logic::Dice& getDiceTwo();
	};
}

