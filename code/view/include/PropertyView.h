#pragma once

#include "../include/FieldView.h"

namespace view {
	class Property : public Field {				
	public:
		Property(float positionX, float positionY, float signPositionX, float signPositionY)
			: Field(positionX, positionY)
		{
			m_texturePositionX = 1200;
			m_ownerSign.setFillColor(sf::Color::White);
			m_ownerSign.setOutlineColor(sf::Color::Black);
			m_ownerSign.setSize(sf::Vector2f(10, 10));
			m_ownerSign.setOutlineThickness(1);
			m_ownerSign.setPosition(signPositionX, signPositionY);
		}
		virtual ~Property() = default;	
		virtual void activate(std::map<std::string, view::Button*>, logic::Player&, logic::Field*) override;
		virtual void reset(std::map<std::string, view::Button*>) override;
		virtual void roll() override {}
	};
}