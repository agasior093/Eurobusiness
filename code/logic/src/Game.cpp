#include "../include/Game.h"

logic::Game::Game(size_t numberOfPlayers, std::vector<std::string>& playerNames)
	: m_numberOfPlayers(numberOfPlayers) {
	for (size_t i = 0; i < numberOfPlayers; ++i) {
		m_players.emplace_back(Player(playerNames[i]));
	}
}

logic::Player& logic::Game::getActivePlayer() {
	return m_players[m_activePlayer];
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

unsigned logic::Game::rollTheDice() {
	m_throwsInCurrentTurn++;
	int firstThrow = m_dice.roll();
	int secondThrow = m_dice.roll();
	m_totalRollResult += firstThrow + secondThrow;
	if (firstThrow == secondThrow) m_doublesInCurrentTurn++;
}

std::string logic::Game::checkForDoubles() {
	std::string message;
		if (m_doublesInCurrentTurn == 0 && m_throwsInCurrentTurn == 1) {
			getActivePlayer().allowRollTheDice(false);
			getActivePlayer().allowMove(false);
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