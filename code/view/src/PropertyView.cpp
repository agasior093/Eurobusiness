#include "../include/PropertyView.h"

void view::Property::activate(std::map < std::string, view::Button*> buttons, logic::Player& player, logic::Field* property) {
	if (property->getOwner() == nullptr) {
		buttons["Buy"]->enable();		
	}
	else {
		buttons["Buy"]->disable();
	}
	
	if (player.getCurrentPayment() > 0) {
		buttons["Pay"]->enable();
	} 
	else {
		buttons["Pay"]->disable();
	}	
}

void view::Property::reset(std::map<std::string, view::Button*> buttons) {
	buttons["Pay"]->disable();
	buttons["Buy"]->disable();
}

void view::Property::loadBuildingTextures(sf::Texture houseTexture, sf::Texture hotelTexture) {	
	m_houseTexture = houseTexture;
	m_hotelTexture = hotelTexture;	

	m_houseOne.setTexture(&m_houseTexture);
	m_houseTwo.setTexture(&m_houseTexture);
	m_houseThree.setTexture(&m_houseTexture);
	m_houseFour.setTexture(&m_houseTexture);
	m_hotel.setTexture(&m_hotelTexture);

	m_houseOne.setSize(sf::Vector2f(20, 22));
	m_houseTwo.setSize(sf::Vector2f(20, 22));
	m_houseThree.setSize(sf::Vector2f(20, 22));
	m_houseFour.setSize(sf::Vector2f(20, 22));
	m_hotel.setSize(sf::Vector2f(35, 38));
}



