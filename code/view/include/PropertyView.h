#pragma once

#include "../include/FieldView.h"

namespace view {
	class Property : public Field {		
	public:
		Property(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_picture.setTextureRect(sf::IntRect(200, 0, 200, 300));
		}
		virtual ~Property() = default;
	};
}