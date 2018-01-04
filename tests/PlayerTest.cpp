#include "pch.h"

#include "Player.cpp"
#include "DEFINITIONS.h"
#include <memory>


class PlayerTestable {
	std::shared_ptr<logic::Player> m_player;
	logic::Player m_player2;
public:
	PlayerTestable() {
		m_player = std::make_shared < logic::Player>(TEST_PLAYER_NAME);
	}	

	/* 
	logic::Player* get() {
		//return m_player.get();
	}*/

	std::shared_ptr<logic::Player> get() {
		return m_player;
	}
};

class PlayerTestSuite : public testing::Test {
public:
	PlayerTestable m_sut;
};

TEST_F(PlayerTestSuite, playerNameShouldEqualTEST_PLAYER_NAME) {
	auto player = m_sut.get();
	ASSERT_EQ(player->getName(), TEST_PLAYER_NAME);
}