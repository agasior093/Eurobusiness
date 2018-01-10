#pragma once

#include "../include/FieldView.h"

namespace view {
	class Chance : public Field {
	public:
		Chance(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_picture.setTextureRect(sf::IntRect(200, 0, 200, 300));
		}
		virtual ~Chance() = default;
	};
}
