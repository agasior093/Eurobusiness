#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
#include "Button.h"
#include "../code/logic/include/Player.h"
#include "../code/logic/include/Field.h"

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

		virtual void activate(std::map<std::string, view::Button*>, logic::Player&, logic::Field*) {}
		virtual void reset(std::map<std::string, view::Button*> buttons) {}
		virtual void roll() {}

		sf::Vector2f getPosition() {
			return m_position;
		}

		int getTexturePosition() {
			return m_texturePositionX;
		}
	};
}
