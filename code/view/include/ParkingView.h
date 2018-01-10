#pragma once

#include "../include/FieldView.h"

namespace view {
	class Parking : public Field {
	public:
		Parking(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_picture.setTextureRect(sf::IntRect(800, 0, 200, 300));
		}
		virtual ~Parking() = default;
	};
}

