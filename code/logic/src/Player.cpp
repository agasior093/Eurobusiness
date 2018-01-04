#include "../include/Player.h"

void logic::Player::addCash(float amount) {
	m_cash += amount;
}

bool logic::Player::substractCash(float amount) {
	if (m_cash >= amount) {
		m_cash -= amount;
		return true;
	} 
	else {
		return false;
	}
}

void logic::Player::incrementPosition(int number) {
	m_position += number;
	if (m_position > 39) m_position -= 40;
}

void logic::Player::setPosition(int newPosition) {
	m_position = newPosition;
}

void logic::Player::setTargetPosition(int newPosition) {
	m_targetPosition = newPosition;
}

void logic::Player::setInMotion(bool argument) {
	m_isMoving = argument;
}

void logic::Player::lockInJail() {
	
	m_turnsLeftInJail = JAIL_TIME;
}

void logic::Player::decrementTurnsInJail() {
	if(m_turnsLeftInJail > 0) m_turnsLeftInJail--;
}

void logic::Player::addOutOfJailCard() {
	m_outOfJailCards++;
}

void logic::Player::useOutOfJailCard() {
	if (m_outOfJailCards > 0) {
		m_outOfJailCards--;
		m_turnsLeftInJail = 0;
	}
}

//getters
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