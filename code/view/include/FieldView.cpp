#pragma once

#include "../include/FieldView.h"

view::Field::Field(float positionX, float positionY) 	
{
	m_position = { positionX, positionY };
	if (!m_texture.loadFromFile(FIELD_BACKGROUNDS)) std::cout << "Can't load texture. \n";
	m_picture.setTexture(m_texture);
}

sf::Vector2f view::Field::getPosition() const {
	return m_position;
}

sf::Sprite& view::Field::getPicture() {
	return m_picture;
}
