#pragma once

#include "../include/FieldView.h"

namespace view {
	class Property : public Field {		
	public:
		Property(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 1200;
		}
		virtual ~Property() = default;	
	};
}