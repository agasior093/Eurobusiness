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
		: m_game(NUMBER_OF_TEST_PLAYERS, m_playerNames.getNames())
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
		game.setInMotion(game.getTotalRollResult());
	} while (game.getThrowsInCurrentTurn() != 1 && game.getDoublesInCurrentTurn() != 0  );

	ASSERT_EQ(game.getActivePlayer().canRollTheDice(), false);
	ASSERT_EQ(game.getActivePlayer().canMove(), true);		
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
			ASSERT_EQ(game.getActivePlayer().canRollTheDice(), true);
			ASSERT_EQ(game.getActivePlayer().canMove(), false);			
		}
	} while (game.getThrowsInCurrentTurn() != 2 && game.getDoublesInCurrentTurn() != 1);

	game.setInMotion(game.getTotalRollResult());
	ASSERT_EQ(game.getActivePlayer().canRollTheDice(), false);
	ASSERT_EQ(game.getActivePlayer().canMove(), true);	
	ASSERT_EQ(game.getActivePlayer().isMoving(), true);
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

	ASSERT_EQ(game.getActivePlayer().canRollTheDice(), false);
	ASSERT_EQ(game.getActivePlayer().canMove(), false);
	ASSERT_EQ(game.getActivePlayer().getPosition(), JAIL_POSITION);
	ASSERT_EQ(game.getActivePlayer().getTurnsLeftInJail(), JAIL_TIME);
}

TEST_F(GameTestSuite, shouldIncrementNumberOfThrowsAndCheckForDoubles) {
	auto game = m_sut.get();

	game.rollTheDice();
	game.checkForDoubles();
	ASSERT_EQ(game.getThrowsInCurrentTurn(), 1);
	if (game.getDoublesInCurrentTurn() == 0) {
		ASSERT_EQ(game.getActivePlayer().canRollTheDice(), false);
		ASSERT_EQ(game.getActivePlayer().canMove(), true);
	}

	if (game.getDoublesInCurrentTurn() == 1) {
		ASSERT_EQ(game.getActivePlayer().canRollTheDice(), true);
		ASSERT_EQ(game.getActivePlayer().canMove(), false);
	}

	game.rollTheDice();
	game.checkForDoubles();
	ASSERT_EQ(game.getThrowsInCurrentTurn(), 2);
	if (game.getDoublesInCurrentTurn() == 1) {
		ASSERT_EQ(game.getActivePlayer().canRollTheDice(), false);
		ASSERT_EQ(game.getActivePlayer().canMove(), true);
	}

	if (game.getDoublesInCurrentTurn() == 2) {
		ASSERT_EQ(game.getActivePlayer().canRollTheDice(), false);
		ASSERT_EQ(game.getActivePlayer().canMove(), false);
	}
}