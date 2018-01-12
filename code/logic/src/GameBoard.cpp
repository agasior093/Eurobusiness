#include "../include/GameBoard.h"

logic::GameBoard::GameBoard() {
	m_board[0] = std::make_unique<logic::Start>();
	m_board[1] = std::make_unique<logic::Property>("Warna", GroupName::Bulgaria, true, 120.f, 100.f, 25.f);
	m_board[2] = std::make_unique<logic::Chance>(ChanceType::RED);
	m_board[3] = std::make_unique<logic::Property>("Sofia", GroupName::Bulgaria, true, 140.f, 100.f, 35.f);
	m_board[4] = std::make_unique<logic::Tax>();
	m_board[5] = std::make_unique<logic::Property>("South station", GroupName::Railways, false, 400.f, 0.f, 100.f);
	m_board[6] = std::make_unique<logic::Property>("Katowice", GroupName::Poland, true, 200.f, 100.f, 50.f);
	m_board[7] = std::make_unique<logic::Chance>(ChanceType::BLUE);
	m_board[8] = std::make_unique<logic::Property>("Wroclaw", GroupName::Poland, true, 220.f, 100.f, 60.f);
	m_board[9] = std::make_unique<logic::Property>("Warsaw", GroupName::Poland, true, 240.f, 100.f, 75.f);
	m_board[10] = std::make_unique<logic::JailVisitor>();

	m_board[11] = std::make_unique<logic::Property>("Valencia", GroupName::Spain, true, 310.f, 200.f, 90.f);
	m_board[12] = std::make_unique<logic::Property>("Power plant", GroupName::Industries, false, 400.f, 0.f, 100.f);
	m_board[13] = std::make_unique<logic::Property>("Barcelona", GroupName::Spain, true, 330.f, 200.f, 110.f);
	m_board[14] = std::make_unique<logic::Property>("Madrit", GroupName::Spain, true, 350.f, 200.f, 120.f);
	m_board[15] = std::make_unique<logic::Property>("West station", GroupName::Railways, false, 400.f, 0.f, 100.f);
	m_board[16] = std::make_unique<logic::Property>("Venice", GroupName::Italy, true, 405.f, 200.f, 140.f);
	m_board[17] = std::make_unique<logic::Chance>(ChanceType::RED);
	m_board[18] = std::make_unique<logic::Property>("Mediolan", GroupName::Italy, true, 430.f, 200.f, 160.f);
	m_board[19] = std::make_unique<logic::Property>("Rome", GroupName::Italy, true, 450.f, 200.f, 190.f);
	m_board[20] = std::make_unique<logic::Parking>();

	m_board[21] = std::make_unique<logic::Property>("Lyon", GroupName::France, true, 520.f, 300.f, 230.f);
	m_board[22] = std::make_unique<logic::Chance>(ChanceType::BLUE);
	m_board[23] = std::make_unique<logic::Property>("Marseille", GroupName::France, true, 550.f, 300.f, 260.f);
	m_board[24] = std::make_unique<logic::Property>("Paris", GroupName::France, true, 580.f, 300.f, 290.f);
	m_board[25] = std::make_unique<logic::Property>("North station", GroupName::Railways, false, 400.f, 0.f, 100.f);
	m_board[26] = std::make_unique<logic::Property>("Oxford", GroupName::England, true, 620.f, 300.f, 330.f);
	m_board[27] = std::make_unique<logic::Property>("Liverpool", GroupName::England, true, 640.f, 300.f, 360.f);
	m_board[28] = std::make_unique<logic::Property>("Water supply", GroupName::Industries, true, 400.f, 0.f, 100.f);
	m_board[29] = std::make_unique<logic::Property>("London", GroupName::England, true, 670.f, 300.f, 390.f);
	m_board[30] = std::make_unique<logic::GoToJail>();

	m_board[31] = std::make_unique<logic::Property>("Sochi", GroupName::Russia, true, 710.f, 400.f, 410.f);
	m_board[32] = std::make_unique<logic::Property>("Petersburg", GroupName::Russia, true, 725.f, 400.f, 435.f);
	m_board[33] = std::make_unique<logic::Chance>(ChanceType::RED);
	m_board[34] = std::make_unique<logic::Property>("Moscow", GroupName::Russia, true, 750.f, 400.f, 460.f);
	m_board[35] = std::make_unique<logic::Property>("East station", GroupName::Railways, true, 400.f, 0.f, 100.f);
	m_board[36] = std::make_unique<logic::Chance>(ChanceType::BLUE);
	m_board[37] = std::make_unique<logic::Property>("Munich", GroupName::Germany, true, 810.f, 400.f, 500.f);
	m_board[38] = std::make_unique<logic::Tax>();
	m_board[39] = std::make_unique<logic::Property>("Berlin", GroupName::Germany, true, 850.f, 400.f, 550.f);
}

logic::Field& logic::GameBoard::getField(size_t index) {
	return *(m_board[index].get());
}