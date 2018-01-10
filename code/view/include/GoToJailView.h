#pragma once

#include "../include/FieldView.h"

namespace view {
	class GoToJail : public Field {
	public:
		GoToJail(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_picture.setTextureRect(sf::IntRect(1000, 0, 200, 300));
		}
		virtual ~GoToJail() = default;
	};
}
