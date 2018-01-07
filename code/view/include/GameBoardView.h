#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include <array>

namespace view {
	class GameBoard {	
		std::array<sf::Vector2f, BOARD_SIZE> m_board;
	public:
		GameBoard();
		~GameBoard() = default;

		std::array<sf::Vector2f, BOARD_SIZE>& get();
	};
}
