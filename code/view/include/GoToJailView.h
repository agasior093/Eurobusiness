#pragma once

#include "../include/FieldView.h"

namespace view {
	class GoToJail : public Field {
		int m_rollCounter = 0;
	public:
		GoToJail(float positionX, float positionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 1000;
		}
		virtual ~GoToJail() = default;		
		virtual void activate(std::map<std::string, view::Button*>, logic::Player&) override;
		virtual void reset() override;
		virtual void roll() override;
	};
}
