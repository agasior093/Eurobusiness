#pragma once

#include "../include/FieldView.h"

namespace view {
	class Start : public Field {		
	public:
		Start(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 0;
		}
		virtual ~Start() = default;		
	};
}
