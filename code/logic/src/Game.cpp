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
	m_passedStart = false;
}

void logic::Game::startTurn() {
	
	unsigned oldPosition = getActivePlayer().getPosition();

	rollTheDice();
	checkForDoubles();
	if (m_canMove == true) {		
		m_stateBeforeThrow = false;
		setInMotion(5);
	}	
	//activate new position only after player changes old position or after end turn if he is in jail,
	//because then he cant move, but position needs to be updated
	
	unsigned newPosition = getActivePlayer().getPosition();
	if(oldPosition != newPosition) activateNewPosition();
	if (newPosition < oldPosition && getActivePlayer().getTurnsLeftInJail() == 0) {
		m_passedStart = true;			
	}
	else {
		m_passedStart = false;		
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
			message = "Doubles again! You are going to jail.\nThere is nothing you can do to avoid prison.";
			m_canThrow = false;
			m_canMove = false;
			getActivePlayer().sendToJail(true);
		}
		return message;
	}
	
void logic::Game::setInMotion(unsigned number) {	
	getActivePlayer().incrementPosition(number);	
}
void logic::Game::activateNewPosition() {
	m_gameBoard.getField(getActivePlayer().getPosition()).activate(getActivePlayer());
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
	if(canEndTurn()) {
		auto previousPosition = getActivePlayer().getPosition();
		//send player to jail if needed
		if (getActivePlayer().isSentToJail()) {
			getActivePlayer().lockInJail();
			getActivePlayer().sendToJail(false);
		}		
		
		//switch to next player
		getActivePlayer().setAsActive(false);
		m_activePlayer++;
		if (m_activePlayer > m_numberOfPlayers - 1) {
			m_activePlayer = 0;
		}
		getActivePlayer().setAsActive(true);

		//reset game data
		reset();
		m_gameBoard.getField(previousPosition).reset();

		//if in jail
		if (getActivePlayer().getTurnsLeftInJail() > 0) {	
			activateNewPosition();
			m_canThrow = false;
			m_canMove = false;
			getActivePlayer().decrementTurnsInJail();
		}		
		m_stateBeforeThrow = true;
		return true;
	}
	else {
		return false;
	}
	
}

void logic::Game::permissionToThrow(bool argument) {
	m_canThrow = argument;
}

void logic::Game::collectCash() {
	getActivePlayer().addCash(PASSED_START_CASH);	
	m_passedStart = false;
}

void logic::Game::jailRoll() {
	m_diceOne.rollNewNumber();
	m_diceTwo.rollNewNumber();
	m_gameBoard.getField(30).checkRollResult(m_diceOne.getCurrentNumber(), m_diceTwo.getCurrentNumber(), getActivePlayer());		
}



//inline getters

//logic::PropertyManager& logic::Game::getPropertyManager() {
//return m_propertyManager;
//}

bool logic::Game::isStateBeforeThrow() const {
	return m_stateBeforeThrow;
}
logic::GameBoard& logic::Game::getBoard() {
	return m_gameBoard;
}
logic::Field& logic::Game::getActiveField() {
	return m_gameBoard.getField(getActivePlayer().getPosition());
}
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
std::string logic::Game::passedStart() const { 	
	if (m_passedStart == true) {		
		return "Click 'Collect' to collect\ncash for passing the start.\n";
	} 
	else {
		return "";
	}
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
