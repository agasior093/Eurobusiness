#include "../include/GameBoard.h"

logic::GameBoard::GameBoard() {
	m_board[0] = std::unique_ptr<logic::Field>(new logic::Start());
	m_board[1] = std::unique_ptr<logic::Field>(new logic::Property("Warna", GroupName::Bulgaria, true, 120, 100, 25));
	m_board[2] = std::unique_ptr<logic::Field>(new logic::Chance(ChanceType::RED));
	m_board[3] = std::unique_ptr<logic::Field>(new logic::Property("Sofia", GroupName::Bulgaria, true, 140, 100, 35));
	m_board[4] = std::unique_ptr<logic::Field>(new logic::Tax());
	m_board[5] = std::unique_ptr<logic::Field>(new logic::Property("South station", GroupName::Railways, false, 400, 0, 100));
	m_board[6] = std::unique_ptr<logic::Field>(new logic::Property("Katowice", GroupName::Poland, true, 200, 100, 50));
	m_board[7] = std::unique_ptr<logic::Field>(new logic::Chance(ChanceType::BLUE));
	m_board[8] = std::unique_ptr<logic::Field>(new logic::Property("Wroclaw", GroupName::Poland, true, 220, 100, 60));
	m_board[9] = std::unique_ptr<logic::Field>(new logic::Property("Warsaw", GroupName::Poland, true, 240, 100, 75));
	m_board[10] = std::unique_ptr<logic::Field>(new logic::JailVisitor());

	m_board[11] = std::unique_ptr<logic::Field>(new logic::Property("Valencia", GroupName::Spain, true, 310, 200, 90));
	m_board[12] = std::unique_ptr<logic::Field>(new logic::Property("Power plant", GroupName::Industries, false, 400, 0, 100));
	m_board[13] = std::unique_ptr<logic::Field>(new logic::Property("Barcelona", GroupName::Spain, true, 330, 200, 110));
	m_board[14] = std::unique_ptr<logic::Field>(new logic::Property("Madrit", GroupName::Spain, true, 350, 200, 120));
	m_board[15] = std::unique_ptr<logic::Field>(new logic::Property("West station", GroupName::Railways, false, 400, 0, 100));
	m_board[16] = std::unique_ptr<logic::Field>(new logic::Property("Venice", GroupName::Italy, true, 405, 200, 140));
	m_board[17] = std::unique_ptr<logic::Field>(new logic::Chance(ChanceType::RED));
	m_board[18] = std::unique_ptr<logic::Field>(new logic::Property("Mediolan", GroupName::Italy, true, 430, 200, 160));
	m_board[19] = std::unique_ptr<logic::Field>(new logic::Property("Rome", GroupName::Italy, true, 450, 200, 190));
	m_board[20] = std::unique_ptr<logic::Field>(new logic::Parking());

	m_board[21] = std::unique_ptr<logic::Field>(new logic::Property("Lyon", GroupName::France, true, 520, 300, 230));
	m_board[22] = std::unique_ptr<logic::Field>(new logic::Chance(ChanceType::BLUE));
	m_board[23] = std::unique_ptr<logic::Field>(new logic::Property("Marseille", GroupName::France, true, 550, 300, 260));
	m_board[24] = std::unique_ptr<logic::Field>(new logic::Property("Paris", GroupName::France, true, 580, 300, 290));
	m_board[25] = std::unique_ptr<logic::Field>(new logic::Property("North station", GroupName::Railways, false, 400, 0, 100));
	m_board[26] = std::unique_ptr<logic::Field>(new logic::Property("Oxford", GroupName::England, true, 620, 300, 330));
	m_board[27] = std::unique_ptr<logic::Field>(new logic::Property("Liverpool", GroupName::England, true, 640, 300, 360));
	m_board[28] = std::unique_ptr<logic::Field>(new logic::Property("Water supply", GroupName::Industries, true, 400, 0, 100));
	m_board[29] = std::unique_ptr<logic::Field>(new logic::Property("London", GroupName::England, true, 670, 300, 390));
	m_board[30] = std::unique_ptr<logic::Field>(new logic::GoToJail());

	m_board[31] = std::unique_ptr<logic::Field>(new logic::Property("Sochi", GroupName::Russia, true, 710, 400, 410));
	m_board[32] = std::unique_ptr<logic::Field>(new logic::Property("Petersburg", GroupName::Russia, true, 725, 400, 435));
	m_board[33] = std::unique_ptr<logic::Field>(new logic::Chance(ChanceType::RED));
	m_board[34] = std::unique_ptr<logic::Field>(new logic::Property("Moscow", GroupName::Russia, true, 750, 400, 460));
	m_board[35] = std::unique_ptr<logic::Field>(new logic::Property("East station", GroupName::Railways, true, 400, 0, 100));
	m_board[36] = std::unique_ptr<logic::Field>(new logic::Chance(ChanceType::BLUE));
	m_board[37] = std::unique_ptr<logic::Field>(new logic::Property("Munich", GroupName::Germany, true, 810, 400, 500));
	m_board[38] = std::unique_ptr<logic::Field>(new logic::Tax());
	m_board[39] = std::unique_ptr<logic::Field>(new logic::Property("Berlin", GroupName::Germany, true, 850, 400, 550));
}

logic::Field& logic::GameBoard::getField(size_t index) {
	return *(m_board[index].get());
}