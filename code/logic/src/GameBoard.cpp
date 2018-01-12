#include "../include/GameBoard.h"

logic::GameBoard::GameBoard() {
	m_board[0] = std::make_unique<logic::Start>();
	m_board[1] = std::make_unique<logic::City>("Warna", GroupName::Bulgaria, true, 120.f, 100.f, 25.f);
	m_board[2] = std::make_unique<logic::Chance>(ChanceType::RED);
	m_board[3] = std::make_unique<logic::City>("Sofia", GroupName::Bulgaria, true, 140.f, 100.f, 35.f);
	m_board[4] = std::make_unique<logic::Tax>("Paid parking", 400);
	m_board[5] = std::make_unique<logic::City>("South station", GroupName::Railways, false, 400.f, 0.f, 100.f);
	m_board[6] = std::make_unique<logic::City>("Katowice", GroupName::Poland, true, 200.f, 100.f, 50.f);
	m_board[7] = std::make_unique<logic::Chance>(ChanceType::BLUE);
	m_board[8] = std::make_unique<logic::City>("Wroclaw", GroupName::Poland, true, 220.f, 100.f, 60.f);
	m_board[9] = std::make_unique<logic::City>("Warsaw", GroupName::Poland, true, 240.f, 100.f, 75.f);
	m_board[10] = std::make_unique<logic::JailVisitor>();

	m_board[11] = std::make_unique<logic::City>("Valencia", GroupName::Spain, true, 310.f, 200.f, 90.f);
	m_board[12] = std::make_unique<logic::Industry>("Power plant", false, 400.f);
	m_board[13] = std::make_unique<logic::City>("Barcelona", GroupName::Spain, true, 330.f, 200.f, 110.f);
	m_board[14] = std::make_unique<logic::City>("Madrit", GroupName::Spain, true, 350.f, 200.f, 120.f);
	m_board[15] = std::make_unique<logic::City>("West station", GroupName::Railways, false, 400.f, 0.f, 100.f);
	m_board[16] = std::make_unique<logic::City>("Venice", GroupName::Italy, true, 405.f, 200.f, 140.f);
	m_board[17] = std::make_unique<logic::Chance>(ChanceType::RED);
	m_board[18] = std::make_unique<logic::City>("Mediolan", GroupName::Italy, true, 430.f, 200.f, 160.f);
	m_board[19] = std::make_unique<logic::City>("Rome", GroupName::Italy, true, 450.f, 200.f, 190.f);
	m_board[20] = std::make_unique<logic::Parking>();

	m_board[21] = std::make_unique<logic::City>("Lyon", GroupName::France, true, 520.f, 300.f, 230.f);
	m_board[22] = std::make_unique<logic::Chance>(ChanceType::BLUE);
	m_board[23] = std::make_unique<logic::City>("Marseille", GroupName::France, true, 550.f, 300.f, 260.f);
	m_board[24] = std::make_unique<logic::City>("Paris", GroupName::France, true, 580.f, 300.f, 290.f);
	m_board[25] = std::make_unique<logic::City>("North station", GroupName::Railways, false, 400.f, 0.f, 100.f);
	m_board[26] = std::make_unique<logic::City>("Oxford", GroupName::England, true, 620.f, 300.f, 330.f);
	m_board[27] = std::make_unique<logic::City>("Liverpool", GroupName::England, true, 640.f, 300.f, 360.f);
	m_board[28] = std::make_unique<logic::Industry>("Water supply", false, 400.f);
	m_board[29] = std::make_unique<logic::City>("London", GroupName::England, true, 670.f, 300.f, 390.f);
	m_board[30] = std::make_unique<logic::GoToJail>();

	m_board[31] = std::make_unique<logic::City>("Sochi", GroupName::Russia, true, 710.f, 400.f, 410.f);
	m_board[32] = std::make_unique<logic::City>("Petersburg", GroupName::Russia, true, 725.f, 400.f, 435.f);
	m_board[33] = std::make_unique<logic::Chance>(ChanceType::RED);
	m_board[34] = std::make_unique<logic::City>("Moscow", GroupName::Russia, true, 750.f, 400.f, 460.f);
	m_board[35] = std::make_unique<logic::City>("East station", GroupName::Railways, true, 400.f, 0.f, 100.f);
	m_board[36] = std::make_unique<logic::Chance>(ChanceType::BLUE);
	m_board[37] = std::make_unique<logic::City>("Munich", GroupName::Germany, true, 810.f, 400.f, 500.f);
	m_board[38] = std::make_unique<logic::Tax>("Income tax", 200);
	m_board[39] = std::make_unique<logic::City>("Berlin", GroupName::Germany, true, 850.f, 400.f, 550.f);
}

logic::Field& logic::GameBoard::getField(size_t index) {
	return *(m_board[index].get());
}