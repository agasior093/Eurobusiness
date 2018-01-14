#pragma once


#include <array>
#include <memory>
#include "../include/FieldView.h"
#include "../include/ChanceView.h"
#include "../include/StartView.h"
#include "../include/PropertyView.h"
#include "../include/TaxView.h"
#include "../include/ParkingView.h"
#include "../include/JailVisitorView.h"
#include "../include/GoToJailView.h"
#include "../include/IndustryView.h"


namespace view {
	class GameBoard {	
		std::array < std::unique_ptr < view::Field>, BOARD_SIZE > m_board;
	public:
		GameBoard();
		~GameBoard() = default;

		Field& getField(size_t);
	};
}
