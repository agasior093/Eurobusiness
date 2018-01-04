#pragma once
#include <random>
#include <chrono>

namespace logic {
	class Dice {
		std::default_random_engine rng;
	public:
		Dice() {
			rng.seed(static_cast<int>(std::chrono::system_clock::now().time_since_epoch().count()));
		}
		~Dice() = default;
		int roll();
	};
}