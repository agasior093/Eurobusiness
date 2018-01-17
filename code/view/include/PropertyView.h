#pragma once

#include "../include/FieldView.h"

namespace view {
	class Property : public Field {	
		float m_buildingPositionX;
		float m_buildingPositionY;
		int m_numberOfHouses = 0;
		int m_numberOfHotels = 0;

	public:
		Property(float positionX, float positionY, float signPositionX, float signPositionY, 
			float houseOnePositionX, float houseOnePositionY, float houseTwoPositionX, float houseTwoPositionY, 
			float houseThreePositionX, float houseThreePositionY, float houseFourPositionX, float houseFourPositionY, 
			float hotelPositionX, float hotelPositionY)
			: Field(positionX, positionY), m_buildingPositionX(m_position.x), m_buildingPositionY(m_position.y)
		{
			m_texturePositionX = 1200;
			m_ownerSign.setFillColor(sf::Color::White);
			m_ownerSign.setOutlineColor(sf::Color::Black);
			m_ownerSign.setSize(sf::Vector2f(10, 10));
			m_ownerSign.setOutlineThickness(1);
			m_ownerSign.setPosition(signPositionX, signPositionY);			
			m_houseOne.setPosition(sf::Vector2f(m_buildingPositionX + houseOnePositionX, m_buildingPositionY + houseOnePositionY));
			m_houseTwo.setPosition(sf::Vector2f(m_buildingPositionX + houseTwoPositionX, m_buildingPositionY + houseTwoPositionY));
			m_houseThree.setPosition(sf::Vector2f(m_buildingPositionX + houseThreePositionX, m_buildingPositionY + houseThreePositionY));
			m_houseFour.setPosition(sf::Vector2f(m_buildingPositionX + houseFourPositionX, m_buildingPositionY + houseFourPositionY));
			m_hotel.setPosition(sf::Vector2f(m_buildingPositionX + hotelPositionX, m_buildingPositionY + hotelPositionY));
		}

		virtual ~Property() = default;	
		virtual void activate(std::map<std::string, view::Button*>, logic::Player&, logic::Field*) override;
		virtual void reset(std::map<std::string, view::Button*>) override;
		virtual void roll() override {}
		virtual void loadBuildingTextures(sf::Texture, sf::Texture) override;
	};
}