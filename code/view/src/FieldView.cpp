#include "../include/FieldView.h"


sf::Vector2f view::Field::getPosition() {
	return m_position;
}

sf::Sprite& view::Field::getPicture() {
	return m_picture;
}
