#include "../include/Game.h"
#include <iostream>

logic::Game::Game(std::vector<std::string>& playerNames)
	: m_numberOfPlayers(playerNames.size()) {
	for (size_t i = 0; i < playerNames.size(); ++i) {
		m_players.emplace_back(Player(playerNames[i]));
	}
	m_players[0].setAsActive(true);
}

void logic::Game::reset() {
	m_throwsInCurrentTurn = 0;
	m_doublesInCurrentTurn = 0;
	m_totalRollResult = 0;
	m_canMove = false;
	m_canThrow = true;
}

void logic::Game::startTurn() {
	
	unsigned oldPosition = getActivePlayer().getPosition();

	rollTheDice();
	checkForDoubles();
	if (m_canMove == true) {		
		getActivePlayer().incrementPosition(m_totalRollResult);
	}	

	unsigned newPosition = getActivePlayer().getPosition();
	if (newPosition < oldPosition && getActivePlayer().getTurnsLeftInJail() == 0) {
		m_passedStart = true;
	}	
}

void logic::Game::rollTheDice() {
	m_throwsInCurrentTurn++; 
	m_diceOne.rollNewNumber();
	m_diceTwo.rollNewNumber();
	int diceOneResult = m_diceOne.getCurrentNumber();
	int diceTwoResult = m_diceTwo.getCurrentNumber();
	m_totalRollResult += diceOneResult + diceTwoResult;
	if (diceOneResult == diceTwoResult) m_doublesInCurrentTurn++;
}

std::string logic::Game::checkForDoubles() {
	std::string message;
		if (m_doublesInCurrentTurn == 0 && m_throwsInCurrentTurn == 1) {
			m_canThrow = false;
			m_canMove = true;			
		}

		if (m_doublesInCurrentTurn == 1 && m_throwsInCurrentTurn == 1) {
			message = "Doubles! Roll again.";			
			m_canThrow = true;
			m_canMove = false;
		}

		if (m_doublesInCurrentTurn == 1 && m_throwsInCurrentTurn == 2) {			
			m_canThrow = false;
			m_canMove = true;
		}

		if (m_doublesInCurrentTurn == 2 && m_throwsInCurrentTurn == 2) {
			message = "Doubles again! You are going to jail.";
			m_canThrow = false;
			m_canMove = false;
			getActivePlayer().lockInJail();
		}
		return message;
	}
	
void logic::Game::setInMotion(unsigned number) {	
	m_players[m_activePlayer].incrementPosition(number);
}

bool logic::Game::canEndTurn() {
	//player need to roll the dice first or be in prison (cant roll then)
	//cant currently be in move
	//cant have any unregulated payments

	if ((!m_canThrow || getActivePlayer().getTurnsLeftInJail() > 0)
		//&& !getActivePlayer().isMoving() move that to presentation part
		&& getActivePlayer().getCurrentPayment() == 0) {
		return true;
	}
	else {
		return false;
	}	
}

bool logic::Game::endTurn() {
	//std::string message;

	if(canEndTurn()) {
		//switch to next player
		m_players[m_activePlayer].setAsActive(false);
		m_activePlayer++;
		if (m_activePlayer > m_numberOfPlayers - 1) {
			m_activePlayer = 0;
		}
		m_players[m_activePlayer].setAsActive(true);

		//reset game data
		reset();
					
		//if is in jail, decrement turns left in jail
		if (getActivePlayer().getTurnsLeftInJail() > 0) {
			getActivePlayer().decrementTurnsInJail();
		}

		//set new message about active player
		//message = getActivePlayer().getPlayerInfo();
		//move that to View	
		return true;
	}
	else {
		return false;
	}
	
}

void logic::Game::permissionToThrow(bool argument) {
	m_canThrow = argument;
}

//inline getters
logic::Player& logic::Game::getActivePlayer() {
	return m_players[m_activePlayer];
}
logic::Player& logic::Game::getPlayer(int index) {
	return m_players[index];
}
unsigned logic::Game::getActivePlayerID() {
	return m_activePlayer;
}
bool logic::Game::canThrow() const {
	return m_canThrow;
}
bool logic::Game::canMove() const { 
	return m_canMove; 
}
int logic::Game::getThrowsInCurrentTurn() const {
	return m_throwsInCurrentTurn;
}
int logic::Game::getDoublesInCurrentTurn() const{
	return m_doublesInCurrentTurn;
}
int logic::Game::getTotalRollResult() const{
	return m_totalRollResult;
}
logic::Dice& logic::Game::getDiceOne()  {
	return m_diceOne;
}
logic::Dice& logic::Game::getDiceTwo() {
	return m_diceTwo;
}
