#pragma once

#include "../include/FieldView.h"

namespace view {
	class Tax : public Field {
	public:
		Tax(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 1600;
		}
		virtual ~Tax() = default;		
		virtual void activate(std::map<std::string, view::Button*>, logic::Player&) override;
		virtual void reset(std::map<std::string, view::Button*> buttons) override;
	};
}
