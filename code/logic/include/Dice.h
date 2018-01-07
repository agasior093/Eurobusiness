#pragma once
#include <random>
#include <chrono>

namespace logic {
	class Dice {
		std::default_random_engine rng;
		int m_currentNumber;
	public:
		Dice() {
			rng.seed(static_cast<int>(std::chrono::system_clock::now().time_since_epoch().count()));
		}
		~Dice() = default;
		void rollNewNumber();
		int getCurrentNumber() const;
	};
}