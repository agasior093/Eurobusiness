#pragma once

#include "../include/FieldView.h"

namespace view {
	class GoToJail : public Field {
	public:
		GoToJail(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 1000;
		}
		virtual ~GoToJail() = default;		
		virtual void activate(std::map<std::string, view::Button*>, logic::Player&) override;
		virtual void roll(bool) override;
	};
}
