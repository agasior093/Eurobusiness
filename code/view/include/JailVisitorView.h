#pragma once

#include "../include/FieldView.h"

namespace view {
	class JailVisitor : public Field {
	public:
		JailVisitor(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 600;
		}
		virtual ~JailVisitor() = default;		
	};
}
