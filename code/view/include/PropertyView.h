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
		virtual void activate(std::map<std::string, view::Button*>, logic::Player&, logic::Field*) override;
		virtual void reset(std::map<std::string, view::Button*>) override;
	};
}