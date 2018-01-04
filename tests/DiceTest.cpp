
#include "pch.h"

#include "Dice.cpp"

class DiceTestable {
	logic::Dice m_dice;
public:
	logic::Dice& get() {
		return m_dice;
	}
};

class DiceTestSuite : public testing::Test {
public:
	DiceTestable m_sut;
};

TEST_F(DiceTestSuite, shouldGenerateValueFromOneToSix) {
	auto dice = m_sut.get();	
	int randomNumber = dice.roll();
	ASSERT_LE(randomNumber, 6);
	ASSERT_GE(randomNumber, 1);	
}

