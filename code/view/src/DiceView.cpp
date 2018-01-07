#include "../include/DiceView.h"

view::Dice::Dice() {
	m_shape.setSize(sf::Vector2f(DICE_WIDTH, DICE_HEIGHT));

	if (!m_texture.loadFromFile(DICE_TEXTURE)) std::cout << "Can't load texture.\n";	
	m_shape.setTexture(&m_texture);
	m_shape.setTextureRect(sf::IntRect(0, 0, 55, 55));

	if (!m_buffer.loadFromFile(DICE_SOUND)) std::cout << "Can't load sound.\n";
	m_sound.setBuffer(m_buffer);
}

sf::RectangleShape& view::Dice::get() { 
	return m_shape;
}

void view::Dice::changeTexture(int newNumber) {
	switch (newNumber) {
		case 1: {
			m_shape.setTextureRect(sf::IntRect(0, 0, 55, 55));
			break;
		}
		case 2: {
			m_shape.setTextureRect(sf::IntRect(55, 0, 55, 55));
			break;
		}
		case 3: {
			m_shape.setTextureRect(sf::IntRect(110, 0, 55, 55));
			break;
		}
		case 4: {
			m_shape.setTextureRect(sf::IntRect(165, 0, 55, 55));
			break;
		}
		case 5: {
			m_shape.setTextureRect(sf::IntRect(220, 0, 55, 55));
			break;
		}
		case 6: {
			m_shape.setTextureRect(sf::IntRect(275, 0, 55, 55));
			break;
		}
	}	
}

void view::Dice::playSound() {
	m_sound.play();
}