#include "pch.h"

#include "Player.cpp"
#include "TEST_DEFINITIONS.h"
#include "C:\Users\aleks\Desktop\Eurobusiness\Eurobusiness\code\DEFINITIONS.h"
#include <memory>


class PlayerTestable {
	std::shared_ptr<logic::Player> m_player;
	logic::Player m_player2; //cant create player like that, return him and use in tests
public:
	PlayerTestable() {
		m_player = std::make_shared < logic::Player>(TEST_PLAYER_INITIAL_NAME);
	}	

	
	logic::Player* get() {
		return m_player.get();
	}
		/*  which function is better?
	std::shared_ptr<logic::Player> get() {
		return m_player;
	}*/
};

class PlayerTestSuite : public testing::Test {
public:
	PlayerTestable m_sut;
	PlayerTestable m_sut2;
};

TEST_F(PlayerTestSuite, playerMembersShouldBeInitialisedWithInitialValues) {	
	auto player = m_sut.get();

	ASSERT_EQ(player->getName(), TEST_PLAYER_INITIAL_NAME);
	ASSERT_EQ(player->canRollTheDice(), TEST_PLAYER_INITIAL_CAN_ROLL_THE_DICE);
	ASSERT_EQ(player->canMove(), TEST_PLAYER_INITIAL_CAN_MOVE);
	ASSERT_EQ(player->getCash(), TEST_PLAYER_INITIAL_CASH);
	ASSERT_EQ(player->getCurrentPayment(), TEST_PLAYER_INITIAL_CURRENT_PAYMENT);
	ASSERT_EQ(player->getLoanHolder(), nullptr);
	ASSERT_EQ(player->getPosition(), TEST_PLAYER_INITIAL_POSITION);
	ASSERT_EQ(player->getTargetPosition(), TEST_PLAYER_INITIAL_TARGET_POSITION);
	ASSERT_EQ(player->isMoving(), TEST_PLAYER_INITIAL_IN_MOVE);
	ASSERT_EQ(player->getTurnsLeftInJail(), TEST_PLAYER_INITIAL_TURNS_IN_JAIL);
	ASSERT_EQ(player->getOutOfJailCards(), TEST_PLAYER_INITIAL_JAIL_CARDS);
}

TEST_F(PlayerTestSuite, shouldIncrementPlayerCash) {
	auto player = m_sut.get();

	float amount = 500;
	player->addCash(amount);
	ASSERT_EQ(player->getCash(), TEST_PLAYER_INITIAL_CASH + amount);
}

TEST_F(PlayerTestSuite, shouldDecrementPlayerCashIfPossible) {
	auto player = m_sut.get();

	float amount = 1500;	
	ASSERT_EQ(player->substractCash(amount), true);
	ASSERT_EQ(player->getCash(), TEST_PLAYER_INITIAL_CASH - amount);

	ASSERT_EQ(player->substractCash(amount), true);
	ASSERT_EQ(player->getCash(), TEST_PLAYER_INITIAL_CASH - amount*2);

	ASSERT_EQ(player->substractCash(amount), false);
	ASSERT_EQ(player->getCash(), TEST_PLAYER_INITIAL_CASH - amount*2);
}

TEST_F(PlayerTestSuite, shouldHandleRollAndMovePermission) {
	auto player = m_sut.get();

	player->allowRollTheDice(false);
	ASSERT_EQ(player->canRollTheDice(), false);

	player->allowMove(false);
	ASSERT_EQ(player->canMove(), false);

	player->allowRollTheDice(true);
	ASSERT_EQ(player->canRollTheDice(), true);

	player->allowMove(true);
	ASSERT_EQ(player->canMove(), true);
}

TEST_F(PlayerTestSuite, shouldIncrementPlayerPositionAndResetAfterReachesEndOfBoard) {
	auto player = m_sut.get();

	int number = 11;
	player->incrementPosition(number);
	ASSERT_EQ(player->getPosition(), 11);
	
	player->incrementPosition(number);
	ASSERT_EQ(player->getPosition(), 22);
	
	player->incrementPosition(number);
	ASSERT_EQ(player->getPosition(), 33);

	player->incrementPosition(number);
	ASSERT_EQ(player->getPosition(), 4);
}

TEST_F(PlayerTestSuite, shouldChangePlayerPositionAndTargetPositon) {
	auto player = m_sut.get();

	int newPosition = 22;
	int newTargetPosition = 33;
	player->setPosition(newPosition);
	player->setTargetPosition(newTargetPosition);
	ASSERT_EQ(player->getPosition(), newPosition);
	ASSERT_EQ(player->getTargetPosition(), newTargetPosition);
}

TEST_F(PlayerTestSuite, shouldStartOrStopMoving) {
	auto player = m_sut.get();
	
	player->startMoving();
	ASSERT_EQ(player->isMoving(), true);
	
	player->stopMoving();
	ASSERT_EQ(player->isMoving(), false);
}

TEST_F(PlayerTestSuite, shouldSetTurnsInJailToThree) {
	auto player = m_sut.get();

	player->lockInJail();
	ASSERT_EQ(player->getTurnsLeftInJail(), JAIL_TIME);
}

TEST_F(PlayerTestSuite, shouldDecrementTurnsInJail) {
	auto player = m_sut.get();

	player->lockInJail();
	player->decrementTurnsInJail();
	ASSERT_EQ(player->getTurnsLeftInJail(), 2);

	player->decrementTurnsInJail();
	ASSERT_EQ(player->getTurnsLeftInJail(), 1);

	player->decrementTurnsInJail();
	ASSERT_EQ(player->getTurnsLeftInJail(), 0);

	player->decrementTurnsInJail();
	ASSERT_EQ(player->getTurnsLeftInJail(), 0);
}

TEST_F(PlayerTestSuite, shouldUseOutOfJailCardAndSetTurnsInJailToZero) {
	auto player = m_sut.get();

	player->addOutOfJailCard();
	player->lockInJail();
	ASSERT_EQ(player->getOutOfJailCards(), 1);
	ASSERT_EQ(player->getTurnsLeftInJail(), JAIL_TIME);

	player->useOutOfJailCard();
	ASSERT_EQ(player->getOutOfJailCards(), 0);
	ASSERT_EQ(player->getTurnsLeftInJail(), 0);
}

TEST_F(PlayerTestSuite, shouldNotUseOutOfJailCard) {
	auto player = m_sut.get();	

	player->lockInJail();
	ASSERT_EQ(player->getOutOfJailCards(), 0);
	ASSERT_EQ(player->getTurnsLeftInJail(), JAIL_TIME);

	player->useOutOfJailCard();
	ASSERT_EQ(player->getOutOfJailCards(), 0);
	ASSERT_EQ(player->getTurnsLeftInJail(), JAIL_TIME);
}

TEST_F(PlayerTestSuite, shouldCreateAndHandlePayment) {
	auto player1 = m_sut.get();
	auto player2 = m_sut2.get();

	float paymentValue = 1000;
	player1->createPayment(paymentValue, player2);
	ASSERT_EQ(player1->getCurrentPayment(), paymentValue);
	ASSERT_EQ(player1->getLoanHolder(), player2);

	ASSERT_EQ(player1->pay(), true);
	ASSERT_EQ(player1->getCash(), TEST_PLAYER_INITIAL_CASH - paymentValue);
	ASSERT_EQ(player1->getCurrentPayment(), 0);
	ASSERT_EQ(player1->getLoanHolder(), nullptr);
}

TEST_F(PlayerTestSuite, shouldCreatePaymentAndDontHandleIt) {
	auto player1 = m_sut.get();
	auto player2 = m_sut2.get();

	float paymentValue = 4000; //greater than initial cash
	player1->createPayment(paymentValue, player2);
	ASSERT_LT(player1->getCash(), player1->getCurrentPayment());
	ASSERT_EQ(player1->getCurrentPayment(), paymentValue);
	ASSERT_EQ(player1->getLoanHolder(), player2);

	ASSERT_EQ(player1->pay(), false);
	ASSERT_EQ(player1->getCash(), TEST_PLAYER_INITIAL_CASH);
	ASSERT_EQ(player1->getCurrentPayment(), paymentValue);
	ASSERT_EQ(player1->getLoanHolder(), player2);
}