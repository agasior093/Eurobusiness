#include "pch.h"

#include "TEST_DEFINITIONS.h"
#include "Game.cpp"

struct PlayerNames {
	std::vector<std::string> m_playerNames;
	PlayerNames() {
		m_playerNames.emplace_back(TEST_PLAYER_INITIAL_NAME);
		m_playerNames.emplace_back(TEST_PLAYER_TWO_INITIAL_NAME);
	}	
	std::vector<std::string>& getNames() {
		return m_playerNames;
	}
};


class GameTestable {	
	PlayerNames m_playerNames;
	logic::Game m_game;	
public:
	GameTestable()
		: m_game(m_playerNames.getNames())
	{ }

	logic::Game& get() {
		return m_game;
	}
};

class GameTestSuite : public testing::Test {
public:
	GameTestable m_sut;
};

TEST_F(GameTestSuite, firstPlayerNameShouldEqualTestPlayerInitialName) {
	auto game = m_sut.get();
	ASSERT_EQ(game.getActivePlayer().getName(), TEST_PLAYER_INITIAL_NAME);
}

//first throw is not double, no second throw
TEST_F(GameTestSuite, shouldFinishAfterFirstRollAndMove) {
	auto game = m_sut.get();

	do {
		if (game.getThrowsInCurrentTurn() == 1) game.reset();
		game.rollTheDice();
		game.checkForDoubles();				
	} while (game.getDoublesInCurrentTurn() != 0);

	game.setInMotion(game.getTotalRollResult());
	ASSERT_EQ(game.canThrow(), false);
	ASSERT_EQ(game.canMove(), true);		
	ASSERT_EQ(game.getActivePlayer().getPosition(), game.getTotalRollResult());
}

//first throw is double, second throw is not
TEST_F(GameTestSuite, shouldFinishAfterSecondRollAndMove) {
	auto game = m_sut.get();

	do {
		if (game.getThrowsInCurrentTurn() == 2) game.reset();
		game.rollTheDice();
		game.checkForDoubles();
		if (game.getThrowsInCurrentTurn() == 1 && game.getDoublesInCurrentTurn() == 1) {
			ASSERT_EQ(game.canThrow(), true);
			ASSERT_EQ(game.canMove(), false);			
		}
	} while (game.getThrowsInCurrentTurn() != 2 && game.getDoublesInCurrentTurn() <= 1);

	ASSERT_EQ(game.canThrow(), false);
	ASSERT_EQ(game.canMove(), true);

	game.setInMotion(game.getTotalRollResult());
	
	ASSERT_EQ(game.getActivePlayer().getPosition(), game.getTotalRollResult());
}

//doubles in both throws
TEST_F(GameTestSuite, shouldFinishAfterSecondThrowAndLockPlayerInJail) {
	auto game = m_sut.get();

	do {
		if (game.getThrowsInCurrentTurn() == 2) game.reset();
		game.rollTheDice();
		game.checkForDoubles();		
	} while (game.getDoublesInCurrentTurn() != 2); 
	//if I add getThrowsInCurrentTurn() != 2 here, canMove = true and test fails

	ASSERT_EQ(game.canThrow(), false);
	ASSERT_EQ(game.canMove(), false);
	ASSERT_EQ(game.getActivePlayer().getPosition(), JAIL_POSITION);
	ASSERT_EQ(game.getActivePlayer().getTurnsLeftInJail(), JAIL_TIME);
}

TEST_F(GameTestSuite, shouldEndTurnIfPossible) {
	auto game = m_sut.get();
	
	ASSERT_EQ(game.endTurn(), false);

	//did throw but has unregulated payment
	game.permissionToThrow(false);
	game.getActivePlayer().createPayment(100, &game.getActivePlayer());
	auto previousPlayer = &game.getActivePlayer();
	ASSERT_EQ(game.endTurn(), false);
	auto currentPlayer = &game.getActivePlayer();
	ASSERT_EQ(previousPlayer, currentPlayer);

	//regulated his payment
	game.permissionToThrow(false);
	game.getActivePlayer().pay();
	previousPlayer = &game.getActivePlayer();
	ASSERT_EQ(game.endTurn(), true);
	currentPlayer = &game.getActivePlayer();
	ASSERT_NE(previousPlayer, currentPlayer);

	//didnt roll the dice but is in prison
	//game.getActivePlayer().allowRollTheDice(true);
	game.getActivePlayer().lockInJail();
	previousPlayer = &game.getActivePlayer();
	ASSERT_EQ(game.endTurn(), true);
	currentPlayer = &game.getActivePlayer();
	ASSERT_NE(previousPlayer, currentPlayer);
}

TEST_F(GameTestSuite, shouldDecreasePlayerTurnsInJail) {
	auto game = m_sut.get();
	auto playerInJail = &game.getActivePlayer();
	playerInJail->lockInJail();

	//player just got locked in jail, he can just end turn now,
	//but it will not decrase his turns in jail yet
	ASSERT_EQ(&game.getActivePlayer(), playerInJail);
	ASSERT_EQ(playerInJail->getTurnsLeftInJail(), 3);
	ASSERT_EQ(playerInJail->getPosition(), JAIL_POSITION);
	ASSERT_EQ(game.endTurn(), true);	
	ASSERT_EQ(playerInJail->getTurnsLeftInJail(), 3);
	auto otherPlayer = &game.getActivePlayer();

	//second player is ending his round
	ASSERT_EQ(&game.getActivePlayer(), otherPlayer);
	game.permissionToThrow(false);
	ASSERT_EQ(game.endTurn(), true);
	ASSERT_EQ(playerInJail->getTurnsLeftInJail(), 2);	
}

