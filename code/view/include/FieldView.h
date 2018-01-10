#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"

namespace view {
	class Field {
	protected:
		sf::Vector2f m_position;	
		sf::Texture m_texture;
		sf::Sprite m_picture;
	public:
		Field() {}
		Field(float, float);
		virtual ~Field() = default;

		virtual sf::Vector2f getPosition() const;
		virtual sf::Sprite& getPicture();		
	};
}
