#pragma once

#include "../include/FieldView.h"

namespace view {
	enum class ChanceType {
		RED, BLUE
	};

	class Chance : public Field {
		ChanceType m_type;
	public:
		Chance(float positionX, float positionY, ChanceType type)
			: Field(positionX, positionY), m_type(type)
		{
			if (m_type == ChanceType::BLUE) {
				m_texturePositionX = 400;
			}
			else {
				m_texturePositionX = 200;
			}			
		}
		virtual ~Chance() = default;		
	};
}
