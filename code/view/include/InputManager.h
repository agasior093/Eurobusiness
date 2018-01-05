#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

namespace view {
	class InputManager {
	public:
		InputManager() {}
		~InputManager() {}
		bool isSpriteClicked(Button button, sf::Event, sf::RenderWindow &window);
		sf::Vector2i getMousePosition(sf::RenderWindow &window);
	};
}
