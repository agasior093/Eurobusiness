#pragma once

#include <SFML/Graphics.hpp>

namespace view {
	class Button {
		bool m_enabled;
		sf::Sprite m_sprite;
		sf::Texture m_enabledTexture;
		sf::Texture m_disabledTexture;

	public:
		Button()
			: m_enabled(true)
		{ }
				
		void setTextures(sf::Texture, sf::Texture);		
		void enable();
		void disable();
		sf::Sprite& getSprite();
		bool isEnabled() const;
	};
}
