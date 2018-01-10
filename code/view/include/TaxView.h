#pragma once

#include "../include/FieldView.h"

namespace view {
	class Tax : public Field {
	public:
		Tax(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 1200;
		}
		virtual ~Tax() = default;		
	};
}
