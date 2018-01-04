#pragma once

#include "Dice.h"

namespace logic {
	class Game {
		Dice m_firstDice, m_secondDice;
	public:
		Game() = default;
		~Game() = default;
	};
}