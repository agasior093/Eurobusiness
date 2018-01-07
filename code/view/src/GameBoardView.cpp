#include "../include/GameBoardView.h"

view::GameBoard::GameBoard() {
	m_board[0] = { 630, 630 };
	m_board[1] = { 570, 630 };
	m_board[2] = { 510, 630 };
	m_board[3] = { 450, 630 };
	m_board[4] = { 390, 630 };
	m_board[5] = { 330, 630 };
	m_board[6] = { 270, 630 };
	m_board[7] = { 210, 630 };
	m_board[8] = { 150, 630 };
	m_board[9] = { 90, 630 };
	m_board[10] = { 30, 630 };
	m_board[11] = { 30, 570 };
	m_board[12] = { 30, 510 };
	m_board[13] = { 30, 450 };
	m_board[14] = { 30, 390 };
	m_board[15] = { 30, 330 };
	m_board[16] = { 30, 270 };
	m_board[17] = { 30, 210 };
	m_board[18] = { 30, 150 };
	m_board[19] = { 30, 90 };
	m_board[20] = { 30, 30 };
	m_board[21] = { 60 , 30  };
	m_board[22] = { 150 , 30 };
	m_board[23] = { 210 , 30 };
	m_board[24] = { 270 , 30 };
	m_board[25] = { 330 , 30 };
	m_board[26] = { 390 , 30 };
	m_board[27] = { 450 , 30 };
	m_board[28] = { 510 , 30 };
	m_board[29] = { 570 , 30 };
	m_board[30] = { 630 , 30 };
	m_board[31] = { 630 , 60 };
	m_board[32] = { 630 , 150 };
	m_board[33] = { 630 , 210 };
	m_board[34] = { 630 , 270 };
	m_board[35] = { 630 , 330 };
	m_board[36] = { 630 , 390 };
	m_board[37] = { 630 , 450 };
	m_board[38] = { 630 , 510 };
	m_board[39] = { 630 , 570 };
}

std::array<sf::Vector2f, BOARD_SIZE>& view::GameBoard::get() {
	return m_board;
}