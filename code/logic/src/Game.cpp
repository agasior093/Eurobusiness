#include "../include/Game.h"

logic::Game::Game(unsigned numberOfPlayers, std::vector<std::string>& playerNames)
	: m_numberOfPlayers(numberOfPlayers) {
	for (unsigned i = 0; i < numberOfPlayers; ++i) {
		m_players.emplace_back(Player(playerNames[i]));
	}
}

logic::Player& logic::Game::getActivePlayer() {
	return m_players[m_activePlayer];
}

void logic::Game::reset() {
	m_throwsInCurrentTurn = 0;
	m_doublesInCurrentTurn = 0;
	m_totalRollResult = 0;
}

void logic::Game::startTurn() {
	unsigned oldPosition = getActivePlayer().getPosition();

	rollTheDice();
	checkForDoubles();
	if (getActivePlayer().canMove() == true) setInMotion(m_totalRollResult);
	getActivePlayer().allowMove(false);

	unsigned newPosition = getActivePlayer().getPosition();
	if (newPosition < oldPosition && getActivePlayer().getTurnsLeftInJail() == 0) {
		m_passedStart = true;
	}
}

void logic::Game::rollTheDice() {
	m_throwsInCurrentTurn++;
	int firstThrow = m_firstDice.roll();
	int secondThrow = m_secondDice.roll();
	m_totalRollResult += firstThrow + secondThrow;
	if (firstThrow == secondThrow) m_doublesInCurrentTurn++;
}

std::string logic::Game::checkForDoubles() {
	std::string message;
		if (m_doublesInCurrentTurn == 0 && m_throwsInCurrentTurn == 1) {
			getActivePlayer().allowRollTheDice(false);
			getActivePlayer().allowMove(true);
		}

		if (m_doublesInCurrentTurn == 1 && m_throwsInCurrentTurn == 1) {
			message = "Doubles! Roll again.";
			getActivePlayer().allowRollTheDice(true);
			getActivePlayer().allowMove(false);
		}

		if (m_doublesInCurrentTurn == 1 && m_throwsInCurrentTurn == 2) {
			getActivePlayer().allowRollTheDice(false);
			getActivePlayer().allowMove(true);
		}

		if (m_doublesInCurrentTurn == 2 && m_throwsInCurrentTurn == 2) {
			message = "Doubles again! You are going to jail.";
			getActivePlayer().allowRollTheDice(false);
			getActivePlayer().allowMove(false);
			getActivePlayer().lockInJail();
		}
		return message;
	}
	
void logic::Game::setInMotion(unsigned number) {
	m_players[m_activePlayer].startMoving();
	m_players[m_activePlayer].incrementPosition(number);
}

bool logic::Game::canEndTurn() {
	//player need to roll the dice first or be in prison (cant roll then)
	//cant currently be in move
	//cant have any unregulated payments
	if ((!getActivePlayer().canRollTheDice() || getActivePlayer().getTurnsLeftInJail() > 0)
		&& !getActivePlayer().isMoving()
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
		m_activePlayer++;
		if (m_activePlayer > m_numberOfPlayers - 1) {
			m_activePlayer = 0;
		}

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

//inline getters
unsigned logic::Game::getThrowsInCurrentTurn() const {
	return m_throwsInCurrentTurn;
}
unsigned logic::Game::getDoublesInCurrentTurn() const{
	return m_doublesInCurrentTurn;
}
unsigned logic::Game::getTotalRollResult() const{
	return m_totalRollResult;
}