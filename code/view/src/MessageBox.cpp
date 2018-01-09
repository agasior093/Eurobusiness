#include "../include/MessageBox.h"

void view::MessageBox::create(float positionX, float positionY, int size, sf::Color color, std::string text) {
	m_font.loadFromFile(CANDARA_FONT_FILE);
	m_messageBox.setFont(m_font);
	m_messageBox.setPosition(positionX, positionY);
	m_messageBox.setCharacterSize(size);
	m_messageBox.setString(text);
	m_messageBox.setFillColor(color);
}

void view::MessageBox::changeText(std::string text) { 
	m_messageBox.setString(text); 
}

sf::Text& view::MessageBox::get() { 
	return m_messageBox; 
}
