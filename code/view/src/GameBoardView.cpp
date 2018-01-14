#include "../include/GameBoardView.h"


view::GameBoard::GameBoard() {
	m_board[0] = std::make_unique<view::Start>(675.f, 675.f);
	m_board[1] = std::make_unique<view::Property>(600.f, 675.f, 618.f, 632.f);
	m_board[2] = std::make_unique<view::Chance>(540.f, 675.f, ChanceType::RED);
	m_board[3] = std::make_unique<view::Property>(480.f, 675.f, 498.f, 632.f);
	m_board[4] = std::make_unique<view::Tax>(420.f, 675.f);
	m_board[5] = std::make_unique<view::Property>(360.f, 675.f, 378.f, 632.f);
	m_board[6] = std::make_unique<view::Property>(300.f, 675.f, 318.f, 632.f);
	m_board[7] = std::make_unique<view::Chance>(240.f, 675.f, ChanceType::BLUE);
	m_board[8] = std::make_unique<view::Property>(180.f, 675.f, 198.f, 632.f);
	m_board[9] = std::make_unique<view::Property>(120.f, 675.f, 138.f, 632.f);
	m_board[10] = std::make_unique<view::JailVisitor>(45.f, 675.f);

	m_board[11] = std::make_unique<view::Property>(45.f, 600.f, 78.f, 618.f);
	m_board[12] = std::make_unique<view::Industry>(45.f, 540.f, 78.f, 558.f);
	m_board[13] = std::make_unique<view::Property>(45.f, 480.f, 78.f, 498.f);
	m_board[14] = std::make_unique<view::Property>(45.f, 420.f, 78.f, 438.f);
	m_board[15] = std::make_unique<view::Property>(45.f, 360.f, 78.f, 378.f);
	m_board[16] = std::make_unique<view::Property>(45.f, 300.f, 78.f, 318.f);
	m_board[17] = std::make_unique<view::Chance>(45.f, 240.f, ChanceType::RED);
	m_board[18] = std::make_unique<view::Property>(45.f, 180.f, 78.f, 198.f);
	m_board[19] = std::make_unique<view::Property>(45.f, 120.f, 78.f, 138.f);
	m_board[20] = std::make_unique<view::Parking>(45.f, 45.f);

	m_board[21] = std::make_unique<view::Property>(120.f, 45.f, 92.f, 78.f);
	m_board[22] = std::make_unique<view::Chance>(180.f, 45.f, ChanceType::BLUE);
	m_board[23] = std::make_unique<view::Property>(240.f, 45.f, 212.f, 78.f);
	m_board[24] = std::make_unique<view::Property>(300.f, 45.f, 272.f, 78.f);
	m_board[25] = std::make_unique<view::Property>(360.f, 45.f, 332.f, 78.f);
	m_board[26] = std::make_unique<view::Property>(420.f, 45.f, 392.f, 78.f);
	m_board[27] = std::make_unique<view::Property>(480.f, 45.f, 452.f, 78.f);
	m_board[28] = std::make_unique<view::Industry>(540.f, 45.f, 512.f, 78.f);
	m_board[29] = std::make_unique<view::Property>(600.f, 45.f, 572.f, 78.f);
	m_board[30] = std::make_unique<view::GoToJail>(675.f, 45.f);

	m_board[31] = std::make_unique<view::Property>(675.f, 120.f, 632.f, 92.f);
	m_board[32] = std::make_unique<view::Property>(675.f, 180.f, 632.f, 152.f);
	m_board[33] = std::make_unique<view::Chance>(675.f, 240.f, ChanceType::RED);
	m_board[34] = std::make_unique<view::Property>(675.f, 300.f, 632.f, 272.f);
	m_board[35] = std::make_unique<view::Property>(675.f, 360.f, 632.f, 332.f);
	m_board[36] = std::make_unique<view::Chance>(675.f, 420.f, ChanceType::BLUE);
	m_board[37] = std::make_unique<view::Property>(675.f, 480.f, 632.f, 452.f);
	m_board[38] = std::make_unique<view::Tax>(675.f, 540.f);
	m_board[39] = std::make_unique<view::Property>(675.f, 600.f, 632.f, 572.f);
}


view::Field& view::GameBoard::getField(size_t index) {
	return *(m_board[index].get());
}