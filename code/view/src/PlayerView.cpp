#include "../include/PlayerView.h"
#include <iostream>

view::Player::Player(logic::Player& player) {
	m_player = &player;
		
	if (!m_texture.loadFromFile(PLAYER_LABEL)) {
		std::cout << "Can't load texture.\n";
	}	
}

void view::Player::create(sf::Color color, 
	float labelPositionX, float labelPositionY) {
	
	m_token.setFillColor(color);
	m_token.setRadius(10);
	m_token.setPosition(STARTING_POSITION_X, STARTING_POSITION_Y);
	m_token.setOutlineColor(sf::Color::Black);
	m_token.setOutlineThickness(2);
	m_token.setOrigin({ 20, 20 });

	m_label.setSize(sf::Vector2f(PLAYER_LABEL_WIDTH, PLAYER_LABEL_HEIGHT));
	m_label.setTexture(&m_texture);
	m_label.setPosition(labelPositionX, labelPositionY);	
}

void view::Player::setTargetPosition() {
	m_targetPosition += m_player->getPositionDifference();
	m_isMoving = true;
}

void view::Player::setPosition(int positions) {
	m_position += positions;
	if ((m_position += .001f) > 40)
		m_position -= 40;
}

void view::Player::move() {
	if ((m_position += .001f) > 40) {
		m_position -= 40;
		m_targetPosition -= 40;
	}

	if (m_position >= m_targetPosition) {
		m_isMoving = false;
		m_position = m_targetPosition;
	}
}

void view::Player::updateLabel() {
	if (m_player->isActive()) {
		m_label.setTextureRect(sf::IntRect(0, 0, 140, 70));
	}
	else {
		m_label.setTextureRect(sf::IntRect(0, 70, 140, 70));
	}
}

//getters
std::string view::Player::getPlayerInfo() {	
	std::string info =
		"         " + m_player->getName() + "\n" +
		"Cash: " + toStringWithPrecision(m_player->getCash()) + "$\n" +
		"Payment: " + toStringWithPrecision(m_player->getCurrentPayment()) + "$\n";
	return info;	
}
sf::CircleShape& view::Player::getToken() {
	return m_token;
}
sf::CircleShape view::Player::getTokenCopy() {
	return m_token;
}
sf::RectangleShape& view::Player::getLabel() {
	return m_label;
}
float view::Player::getStep() const {
	return m_position - static_cast<std::size_t>(m_position);
}
sf::Vector2f view::Player::getJumpOffSet() const {
	sf::Vector2f jumpOffset(0, 25.f * (2.f * ((m_position - static_cast<std::size_t>(m_position)) - .5f)) * (2.f * ((m_position - static_cast<std::size_t>(m_position)) - .5f)));
	return jumpOffset;
}
float view::Player::getPosition() const {
	return m_position;
}
bool view::Player::isMoving() const {
	return m_isMoving;
}



