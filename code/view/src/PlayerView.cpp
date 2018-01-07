#include "../include/PlayerView.h"

void view::Player::create() {
	m_token.setRadius(10);
	m_token.setPosition(630, 630);
	m_token.setFillColor(sf::Color::Red);
	m_token.setOutlineColor(sf::Color::Black);
	m_token.setOutlineThickness(2);
	m_token.setOrigin({ 20, 20 });
}

bool view::Player::isMoving() const {
	return m_isMoving;
}

void view::Player::setInMotion(int positions) {
	m_targetPosition += positions;
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

sf::CircleShape& view::Player::get() {
	return m_token;
}

float view::Player::getStep() const {
	return m_position - static_cast<std::size_t>(m_position);
}

sf::Vector2f view::Player::getJumpOffSet() const {
	sf::Vector2f jumpOffset(0, 25.f * (2.f * ((m_position - static_cast<std::size_t>(m_position)) - .5)) * (2.f * ((m_position - static_cast<std::size_t>(m_position)) - .5)));
	return jumpOffset;
}

float view::Player::getPosition() const {
	return m_position;
}