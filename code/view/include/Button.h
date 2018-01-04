#pragma once

#include <SFML/Graphics.hpp>

class Button {
	bool m_enabled;
	sf::Sprite m_sprite;
	sf::Texture m_enabledTexture;
	sf::Texture m_disabledTexture;

public:
	Button()
		: m_enabled(true)
	{ }

	inline sf::Sprite& getSprite() {
		return m_sprite;
	}

	inline bool isEnabled() const {
		return m_enabled;
	}

	void setTextures(std::string enabledButtonFilePath, std::string disabledButtonFilePath);	//can change to sf::Texture	
	void enable();
	void disable();
};