#pragma once

#include "../include/FieldView.h"

namespace view {
	class Parking : public Field {
	public:
		Parking(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 400;
		}
		virtual ~Parking() = default;		
	};
}

