#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
#include "Button.h"
#include "../code/logic/include/Player.h"
#include "../code/logic/include/Field.h"

namespace view {
	class Field {		
	protected:
		sf::Vector2f m_position;			
		int m_texturePositionX;
		sf::Texture m_houseTexture;
		sf::Texture m_hotelTexture;
		sf::RectangleShape m_ownerSign;
		sf::RectangleShape m_houseOne;
		sf::RectangleShape m_houseTwo;
		sf::RectangleShape m_houseThree;
		sf::RectangleShape m_houseFour;
		sf::RectangleShape m_hotel;

	public:
		Field(float positionX, float positionY)
			: m_position({ positionX, positionY })
		{			
			
		}
		virtual ~Field() = default;

		virtual void activate(std::map<std::string, view::Button*>, logic::Player&, logic::Field*) {}
		virtual void reset(std::map<std::string, view::Button*> buttons) {}
		virtual void roll() {}
		virtual void loadBuildingTextures(sf::Texture, sf::Texture) {}
		
		virtual sf::RectangleShape& getOwnerSign() { return m_ownerSign; }
		virtual sf::RectangleShape& getHouseOne() { return m_houseOne; }
		virtual sf::RectangleShape& getHouseTwo() { return m_houseTwo; }
		virtual sf::RectangleShape& getHouseThree() { return m_houseThree; }
		virtual sf::RectangleShape& getHouseFour() { return m_houseFour; }
		virtual sf::RectangleShape& getHotel() { return m_hotel; }
		sf::Vector2f getPosition() { return m_position; }
		int getTexturePosition() { return m_texturePositionX; }
	};
}
