#include "../include/DiceView.h"

view::Dice::Dice() {
	m_dice.setSize(sf::Vector2f(DICE_WIDTH, DICE_HEIGHT));
	m_texture.loadFromFile(DICE_ONE_TEXTURE);
	m_dice.setTexture(&m_texture);
	m_buffer.loadFromFile(DICE_SOUND);
	m_sound.setBuffer(m_buffer);
}

sf::RectangleShape& view::Dice::get() { 
	return m_dice;
}

void view::Dice::setTexture(std::string filePath) { 
	m_texture.loadFromFile(filePath);
}

void view::Dice::changeTexture(unsigned number) {
	switch (number) {
	
	}
	std::string filePath = "resources//dice" + std::to_string(number) + ".png";
	m_texture.loadFromFile(filePath);
	m_dice.setTexture(&m_texture);
}

void view::Dice::playSound() {
	m_sound.play();
}