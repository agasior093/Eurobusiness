#pragma once

#include "../include/FieldView.h"

namespace view {
	class JailVisitor : public Field {
	public:
		JailVisitor(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_picture.setTextureRect(sf::IntRect(600, 0, 200, 300));
		}
		virtual ~JailVisitor() = default;
	};
}
