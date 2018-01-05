#include "../include/InputManager.h"

bool view::InputManager::isSpriteClicked(view::Button button, sf::Event event, sf::RenderWindow &window) {
	if (!button.isEnabled()) {
		return false;
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::IntRect rect(static_cast<int>(button.getSprite().getPosition().x),
			static_cast<int>(button.getSprite().getPosition().y),
			static_cast<int>(button.getSprite().getGlobalBounds().width),
			static_cast<int>(button.getSprite().getGlobalBounds().height));
		if (rect.contains(sf::Mouse::getPosition(window))) {
			return true;
		}
	}
	return false;
}

sf::Vector2i view::InputManager::getMousePosition(sf::RenderWindow &window) {
	return sf::Mouse::getPosition(window); 
}