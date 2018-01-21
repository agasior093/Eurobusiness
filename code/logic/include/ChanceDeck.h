#pragma once
#include <array>
#include <functional>
#include "DEFINITIONS.h"
#include <iostream>

namespace logic {
	using deck = std::array<std::function<void()>, CHANCE_DECK_SIZE>;

	class ChanceDeck {
	public:
		virtual std::function<void()> getTopCard();
		deck m_deck;
	protected:
		virtual void shuffleDeck();
		virtual void moveTopCardToBottom();
	};
}
