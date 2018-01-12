#include "../include/GameBoardView.h"


view::GameBoard::GameBoard() {
	m_board[0] = std::make_unique<view::Start>(675, 675);
	m_board[1] = std::make_unique<view::Property>(600, 675);
	m_board[2] = std::make_unique<view::Chance>(540, 675, ChanceType::RED);
	m_board[3] = std::make_unique<view::Property>(480, 675);
	m_board[4] = std::make_unique<view::Tax>(420, 675);
	m_board[5] = std::make_unique<view::Property>(360, 675);
	m_board[6] = std::make_unique<view::Property>(300, 675);
	m_board[7] = std::make_unique<view::Chance>(240, 675, ChanceType::BLUE);
	m_board[8] = std::make_unique<view::Property>(180, 675);
	m_board[9] = std::make_unique<view::Property>(120, 675);
	m_board[10] = std::make_unique<view::JailVisitor>(45, 675);

	m_board[11] = std::make_unique<view::Property>(45, 600);
	m_board[12] = std::make_unique<view::Property>(45, 540);
	m_board[13] = std::make_unique<view::Property>(45, 480);
	m_board[14] = std::make_unique<view::Property>(45, 420);
	m_board[15] = std::make_unique<view::Property>(45, 360);
	m_board[16] = std::make_unique<view::Property>(45, 300);
	m_board[17] = std::make_unique<view::Chance>(45, 240, ChanceType::RED);
	m_board[18] = std::make_unique<view::Property>(45, 180);
	m_board[19] = std::make_unique<view::Property>(45, 120);
	m_board[20] = std::make_unique<view::Parking>(45, 45);

	m_board[21] = std::make_unique<view::Property>(120 , 45);
	m_board[22] = std::make_unique<view::Chance>(180 , 45, ChanceType::BLUE);
	m_board[23] = std::make_unique<view::Property>(240 , 45);
	m_board[24] = std::make_unique<view::Property>(300 , 45);
	m_board[25] = std::make_unique<view::Property>(360 , 45);
	m_board[26] = std::make_unique<view::Property>(420 , 45);
	m_board[27] = std::make_unique<view::Property>(480 , 45);
	m_board[28] = std::make_unique<view::Property>(540 , 45);
	m_board[29] = std::make_unique<view::Property>(600 , 45);
	m_board[30] = std::make_unique<view::GoToJail>(675 , 45);

	m_board[31] = std::make_unique<view::Property>(675 , 120);
	m_board[32] = std::make_unique<view::Property>(675 , 180);
	m_board[33] = std::make_unique<view::Chance>(675 , 240, ChanceType::RED);
	m_board[34] = std::make_unique<view::Property>(675 , 300);
	m_board[35] = std::make_unique<view::Property>(675 , 360);
	m_board[36] = std::make_unique<view::Chance>(675 , 420, ChanceType::BLUE);
	m_board[37] = std::make_unique<view::Property>(675 , 480);
	m_board[38] = std::make_unique<view::Tax>(675 , 540);
	m_board[39] = std::make_unique<view::Property>(675 , 600);
}


view::Field& view::GameBoard::getField(size_t index) {
	return *(m_board[index].get());
}