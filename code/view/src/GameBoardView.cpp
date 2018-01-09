#include "../include/GameBoardView.h"

view::GameBoard::GameBoard() {
	m_board[0] = { 675, 675 };
	m_board[1] = { 600, 675 };
	m_board[2] = { 540, 675 };
	m_board[3] = { 480, 675 };
	m_board[4] = { 420, 675 };
	m_board[5] = { 360, 675 };
	m_board[6] = { 300, 675 };
	m_board[7] = { 240, 675 };
	m_board[8] = { 180, 675 };
	m_board[9] = { 120, 675 };
	m_board[10] = { 45, 675 };

	m_board[11] = { 45, 600 };
	m_board[12] = { 45, 540 };
	m_board[13] = { 45, 480 };
	m_board[14] = { 45, 420 };
	m_board[15] = { 45, 360 };
	m_board[16] = { 45, 300 };
	m_board[17] = { 45, 240 };
	m_board[18] = { 45, 180 };
	m_board[19] = { 45, 120 };
	m_board[20] = { 45, 45 };

	m_board[21] = { 120 , 45 };
	m_board[22] = { 180 , 45 };
	m_board[23] = { 240 , 45 };
	m_board[24] = { 300 , 45 };
	m_board[25] = { 360 , 45 };
	m_board[26] = { 420 , 45 };
	m_board[27] = { 480 , 45 };
	m_board[28] = { 540 , 45 };
	m_board[29] = { 600 , 45 };
	m_board[30] = { 675 , 45 };

	m_board[31] = { 675 , 120 };
	m_board[32] = { 675 , 180 };
	m_board[33] = { 675 , 240 };
	m_board[34] = { 675 , 300 };
	m_board[35] = { 675 , 360 };
	m_board[36] = { 675 , 420 };
	m_board[37] = { 675 , 480 };
	m_board[38] = { 675 , 540 };
	m_board[39] = { 675 , 600 };
}

std::array<sf::Vector2f, BOARD_SIZE>& view::GameBoard::get() {
	return m_board;
}