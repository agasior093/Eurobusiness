#pragma once

#include <SFML/Graphics.hpp>

namespace view {
	class State {
	public:
		virtual void initialise() = 0;
		virtual void handleUserInput() = 0;
		virtual void update(sf::Time dt) = 0;
		virtual void draw() = 0;
	};
}
