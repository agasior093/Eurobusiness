#include "../include/Player.h"

std::string logic::Player::getName() {
	return m_name;
}

float logic::Player::getCash() {
	return m_cash;
}

float logic::Player::getCurrentPayment() {
	return m_currentPayment;
}

int logic::Player::getPosition() {
	return m_position;
}

int logic::Player::getTargetPosition() {
	return m_targetPosition;
}

bool logic::Player::isMoving() {
	return m_isMoving;
}

int logic::Player::getTurnsLeftInJail() {
	return m_turnsLeftInJail;
}

int logic::Player::getOutOfJailCards() {
	return m_outOfJailCards;
}