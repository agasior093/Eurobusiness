#include "../include/GameBoard.h"

logic::GameBoard::GameBoard() {
	m_board[0] = std::make_shared<logic::Field>(logic::Start());
	m_board[1] = std::shared_ptr<logic::Field>(new logic::Property("Warna", GroupName::Bulgaria, true, 120, 100, 25));
	m_board[2] = std::make_shared<logic::Field>(logic::Chance(ChanceType::RED));
	m_board[3] = std::make_shared<logic::Field>(logic::Property("Sofia", GroupName::Bulgaria, true, 140, 100, 35));
	m_board[4] = std::make_shared<logic::Field>(logic::Tax());
	m_board[5] = std::make_shared<logic::Field>(logic::Property("South station", GroupName::Railways, false, 400, 0, 100));
	m_board[6] = std::make_shared<logic::Field>(logic::Property("Katowice", GroupName::Poland, true, 200, 100, 50));
	m_board[7] = std::make_shared<logic::Field>(logic::Chance(ChanceType::BLUE));
	m_board[8] = std::make_shared<logic::Field>(logic::Property("Wroclaw", GroupName::Poland, true, 220, 100, 60));
	m_board[9] = std::make_shared<logic::Field>(logic::Property("Warsaw", GroupName::Poland, true, 240, 100, 75));
	m_board[10] = std::make_shared<logic::Field>(logic::JailVisitor());

	m_board[11] = std::make_shared<logic::Field>(logic::Property("Valencia", GroupName::Spain, true, 310, 200, 90));
	m_board[12] = std::make_shared<logic::Field>(logic::Property("Power plant", GroupName::Industries, false, 400, 0, 100));
	m_board[13] = std::make_shared<logic::Field>(logic::Property("Barcelona", GroupName::Spain, true, 330, 200, 110));
	m_board[14] = std::make_shared<logic::Field>(logic::Property("Madrit", GroupName::Spain, true, 350, 200, 120));
	m_board[15] = std::make_shared<logic::Field>(logic::Property("West station", GroupName::Railways, false, 400, 0, 100));
	m_board[16] = std::make_shared<logic::Field>(logic::Property("Venice", GroupName::Italy, true, 405, 200, 140));
	m_board[17] = std::make_shared<logic::Field>(logic::Chance(ChanceType::RED));
	m_board[18] = std::make_shared<logic::Field>(logic::Property("Mediolan", GroupName::Italy, true, 430, 200, 160));
	m_board[19] = std::make_shared<logic::Field>(logic::Property("Rome", GroupName::Italy, true, 450, 200, 190));
	m_board[20] = std::make_shared<logic::Field>(logic::Parking());

	m_board[21] = std::make_shared<logic::Field>(logic::Property("Lyon", GroupName::France, true, 520, 300, 230));
	m_board[22] = std::make_shared<logic::Field>(logic::Chance(ChanceType::BLUE));
	m_board[23] = std::make_shared<logic::Field>(logic::Property("Marseille", GroupName::France, true, 550, 300, 260));
	m_board[24] = std::make_shared<logic::Field>(logic::Property("Paris", GroupName::France, true, 580, 300, 290));
	m_board[25] = std::make_shared<logic::Field>(logic::Property("North station", GroupName::Railways, false, 400, 0, 100));
	m_board[26] = std::make_shared<logic::Field>(logic::Property("Oxford", GroupName::England, true, 620, 300, 330));
	m_board[27] = std::make_shared<logic::Field>(logic::Property("Liverpool", GroupName::England, true, 640, 300, 360));
	m_board[28] = std::make_shared<logic::Field>(logic::Property("Water supply", GroupName::Industries, true, 400, 0, 100));
	m_board[29] = std::make_shared<logic::Field>(logic::Property("London", GroupName::England, true, 670, 300, 390));
	m_board[30] = std::make_shared<logic::Field>(logic::GoToJail());

	m_board[31] = std::make_shared<logic::Field>(logic::Property("Sochi", GroupName::Russia, true, 710, 400, 410));
	m_board[32] = std::make_shared<logic::Field>(logic::Property("Petersburg", GroupName::Russia, true, 725, 400, 435));
	m_board[33] = std::make_shared<logic::Field>(logic::Chance(ChanceType::RED));
	m_board[34] = std::make_shared<logic::Field>(logic::Property("Moscow", GroupName::Russia, true, 750, 400, 460));
	m_board[35] = std::make_shared<logic::Field>(logic::Property("East station", GroupName::Railways, true, 400, 0, 100));
	m_board[36] = std::make_shared<logic::Field>(logic::Chance(ChanceType::BLUE));
	m_board[37] = std::make_shared<logic::Field>(logic::Property("Munich", GroupName::Germany, true, 810, 400, 500));
	m_board[38] = std::make_shared<logic::Field>(logic::Tax());
	m_board[39] = std::make_shared<logic::Field>(logic::Property("Berlin", GroupName::Germany, true, 850, 400, 550));
}

logic::Field& logic::GameBoard::getField(size_t index) {
	return *(m_board[index].get());
}