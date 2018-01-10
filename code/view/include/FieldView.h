#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"

namespace view {
	class Field {
	protected:
		sf::Vector2f m_position;			
		int m_texturePositionX;
	public:
		Field(float positionX, float positionY)
			: m_position({ positionX, positionY })
		{			
			
		}
		virtual ~Field() = default;

		sf::Vector2f getPosition() {
			return m_position;
		}

		int getTexturePosition() {
			return m_texturePositionX;
		}
	};
}
