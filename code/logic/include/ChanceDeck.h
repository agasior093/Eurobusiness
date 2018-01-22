#pragma once
#include <array>
#include <functional>
#include "DEFINITIONS.h"
#include <iostream>

#include "../include/Player.h"

namespace logic {	
	using function = std::function<void(logic::Player&, std::string&) > ;
	using deck = std::array<function, CHANCE_DECK_SIZE>;

	class ChanceDeck {
	public:
		virtual function getTopCard();
		deck m_deck;
	protected:
		virtual void shuffleDeck();
		virtual void moveTopCardToBottom();

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}
