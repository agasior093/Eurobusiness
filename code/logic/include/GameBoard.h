#pragma once
#include <array>
#include <memory>
#include "DEFINITIONS.h"
#include "../include/Field.h"
#include "../include/Chance.h"
#include "../include/GoToJail.h"
#include "../include/Parking.h"
#include "../include/JailVisitor.h"
#include "../include/Property.h"
#include "../include/Start.h"
#include "../include/Tax.h"

namespace logic {
	class GameBoard {
		std::array < std::unique_ptr < logic::Field>, BOARD_SIZE > m_board;
	public:
		GameBoard();
		~GameBoard() = default;

		Field& getField(size_t);
	};
}
