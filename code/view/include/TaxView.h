#pragma once

#include "../include/FieldView.h"

namespace view {
	class Tax : public Field {
	public:
		Tax(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_picture.setTextureRect(sf::IntRect(1200, 0, 200, 300));
		}
		virtual ~Tax() = default;
	};
}
