#pragma once

#include "../include/FieldView.h"

namespace view {
	class Start : public Field {		
	public:
		Start(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_picture.setTextureRect(sf::IntRect(0, 0, 200, 300));
		}
		virtual ~Start() = default;
	};
}
